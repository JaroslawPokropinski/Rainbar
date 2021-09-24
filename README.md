# Rainbar
A plugin for rainmeter that places your widget just above the taskbar

## Usage
Place Rainbar.dll in Plugins directory.

Modify the skin you wanna use by adding:
```
[MeasureRainbar]
Measure=Plugin
Plugin=Rainbar
Rate=20
```
Optionaly you can provide parameter `TrayClass` to change the class of taskbar. By default it is set to `Shell_SecondaryTrayWnd` which is the second screen.
