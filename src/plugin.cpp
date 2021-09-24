#include <thread>
#include <windows.h>
#include <chrono>
#include <future>
#include <fstream>

#include "raiseWindow/raiseWindow.h"
#include "../rainmeter/RainmeterAPI.h"

struct Measure
{
  std::promise<void> exitSignal;
  std::thread th;
  Measure() {}
};

void raise(HWND b, HWND a, int rate, std::future<void> futureObj)
{
  while (futureObj.wait_for(std::chrono::milliseconds(1)) == std::future_status::timeout)
  {
    if (IsTopMost(a) && isAbove(a, b))
    {
      ShowWindow(b, SW_SHOW);
      raiseWindow(b, a);
    }
    if (!IsTopMost(a))
    {
      ShowWindow(b, SW_HIDE);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(rate));
  }
}

PLUGIN_EXPORT void Initialize(void **data, void *rm)
{
  Measure *measure = new Measure;
  *data = measure;

  std::future<void> futureObj = measure->exitSignal.get_future();

  HWND tray = getWindow(NULL, RmReadString(rm, L"TrayClass", L"Shell_SecondaryTrayWnd"));
  HWND widget = RmGetSkinWindow(rm);

  measure->th = std::thread(raise, widget, tray, RmReadInt(rm, L"Rate", 17), std::move(futureObj));
}

PLUGIN_EXPORT void Reload(void *data, void *rm, double *maxValue)
{
  Measure *measure = (Measure *)data;
}

PLUGIN_EXPORT double Update(void *data)
{
  return 0.0;
}

PLUGIN_EXPORT void Finalize(void *data)
{
  Measure *measure = (Measure *)data;

  measure->exitSignal.set_value();
  measure->th.join();

  delete measure;
}