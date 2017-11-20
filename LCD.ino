void LCD()
{
  lcd.setCursor(0, 0);    // set the cursor to column 0, line 1
  lcd.print("SF = ");     //speed brushless forward
  lcd.setCursor(5, 0);
  lcd.print (signal1);
  lcd.setCursor(0, 1);    // set the cursor to column 0, line 1
  lcd.print("SB = ");     //speed brushless backward
  lcd.setCursor(5, 1);
  lcd.print (signal2);
}

