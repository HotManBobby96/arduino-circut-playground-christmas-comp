#include <Adafruit_CircuitPlayground.h>

bool microphoneCapture(int time) {
  float spl = CircuitPlayground.mic.soundPressureLevel(time);

  if (spl >= 75) {
    return true;
  } else {
    return false;
  }
}


// ABOVE IS THE MICROPHONE CODE

// BELOW IS THE LIGHT CODE

#define NEOPIX_PIN    A2
#define NUM_PIXELS    5

// use Adafruit_CPlay_NeoPixel to create a separate external NeoPixel strip
Adafruit_CPlay_NeoPixel strip = Adafruit_CPlay_NeoPixel(NUM_PIXELS, NEOPIX_PIN, NEO_GRB + NEO_KHZ800);


void lightShow(int time) {
 CircuitPlayground.clearPixels();
  
  // for the external NeoPixels, must use the Adafruit_CPlay_NeoPixel functions directly
  strip.clear();
  strip.show();

  delay(500);

 

  while(true) {
  bool result = microphoneCapture(time);

    if(result == true) {
      for(int i = 0; i < 12; i++) {
   CircuitPlayground.setPixelColor(i, random(0, 255), random(0, 255), random(0, 255));     

      }
  } else {
    for(int i = 0; i < 12; i++) {
   CircuitPlayground.setPixelColor(i, 0,   0,   0);     
    } // for
  } // if
  } // while
 

  delay(5000);
}

// MAIN STUFF

void setup() {
  // initialize the Circuit Playground as usual
  // this will initialize the onboard NeoPixels as well
  CircuitPlayground.begin();

  // initialize external NeoPixel strip separately
  strip.begin();


  
}

void loop() {

    int time = 50; // mili

    lightShow(time);
  
}
