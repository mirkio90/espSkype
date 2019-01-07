//color definition
//RgbColor redc(colorSaturation, 0, 0);
//RgbColor greenc(0, colorSaturation, 0);
//RgbColor bluec(0, 0, colorSaturation);
//RgbColor purplec(138, 43, 226);
//RgbColor yellowc(200, colorSaturation, 0);
//
//
//RgbColor whitec(colorSaturation);
//RgbColor blackc(0);

//HslColor hslRed(redc);
//HslColor hslGreen(greenc);
//HslColor hslBlue(bluec);
//HslColor hslPurple(purplec);
//HslColor hslYellow(yellowc);
//HslColor hslWhite(whitec);
//HslColor hslBlack(blackc);
//
void green() {
  for(int i = 0; i < LED_NUMBER; i++){
    leds[i] = CRGB::Red;
    Serial.printf("\nturn on led %d",i);
    FastLED.show();
  }
}
//
void red() {
  for(int i = 0; i < LED_NUMBER; i++){
    leds[i] = CRGB::Green;
    Serial.printf("\nturn on led %d",i);
    FastLED.show();
  }
}
//
void purple() {
  for(int i = 0; i < LED_NUMBER; i++){
    leds[i] = CRGB::Purple;
    Serial.printf("\nturn on led %d",i);
    FastLED.show();
  }
}
//
void yellow() {
  for(int i = 0; i < LED_NUMBER; i++){
    leds[i] = CRGB::Yellow;
    Serial.printf("\nturn on led %d",i);
    FastLED.show();
  }
}
//
void off() {
  for(int i = 0; i < LED_NUMBER; i++){
    leds[i] = CRGB::Black;
    Serial.printf("\nturn off led %d",i);
    FastLED.show();
  }
}
//void personalColor(int R, int G, int B) {
//  RgbColor personal(R, G, B);
//  HslColor hslPersonal(personal);
//  
//  for(int i = 0; i < LED_NUMBER; i++){
//    strip.SetPixelColor(i, hslPersonal);
//  }
// 
//  strip.Show();
//}
//
//void redfadeinacall() {
//  strip.SetPixelColor(0, hslRed);
//  strip.SetPixelColor(1, hslRed);
//  strip.SetPixelColor(2, hslRed);
//  strip.SetPixelColor(3, hslRed);
//  strip.SetPixelColor(4, hslRed);
//  strip.SetPixelColor(5, hslRed);
//  strip.SetPixelColor(6, hslWhite);
//  strip.SetPixelColor(7, hslWhite);
//  strip.SetPixelColor(8, hslWhite);
//  strip.SetPixelColor(9, hslWhite);
//  strip.SetPixelColor(10, hslWhite);
//  strip.SetPixelColor(11, hslWhite);
//  
//  strip.Show();
//}
//
//void blueincomingcall() {
//   for(int i = 0; i < LED_NUMBER; i++){
//    strip.SetPixelColor(i, hslBlue);  
//  }
//  
//  strip.Show();
//}
//
//void black() {
//  for(int i = 0; i < 12; i++){
//    strip.SetPixelColor(i, hslBlack);  
//  }
//   
//  strip.Show();
//}
