#include <LiquidCrystal.h>

int main(void){
  LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
  lcd.begin(16, 2);
  lcd.print("hello, world!");

  while(1){
    lcd.setCursor(0, 1);
    lcd.print(millis()/1000);
  }

  return 0;
}
