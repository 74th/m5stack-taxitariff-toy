#include <Wire.h>
#include <SPIFFS.h>
#include <M5Unified.h>
#include <Adafruit_NeoPixel.h>

#define CHANGE_TARIFF_BUTTON_PIN G22
#define SWITCH_NEOPIXEL_PIN G21

void show_sign(uint8_t no);

uint32_t current_tarrif_state = 0;
bool current_tariff_button = HIGH;
Adafruit_NeoPixel pixels(1, SWITCH_NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup(void)
{
    auto cfg = M5.config();

    M5.begin(cfg);
    SPIFFS.begin();
    pinMode(CHANGE_TARIFF_BUTTON_PIN, INPUT_PULLUP);
    delay(100);

    current_tariff_button = digitalRead(CHANGE_TARIFF_BUTTON_PIN);
    pixels.begin();
    show_sign(0);
}

void show_sign(uint8_t no)
{
    pixels.clear();
    switch (no)
    {
        case 0:
            pixels.setPixelColor(0, pixels.Color(255, 0, 0));
            pixels.show();
            M5.Lcd.drawJpgFile(SPIFFS, "/unladen.jpg", 0, 0);
            break;
        case 1:
            pixels.setPixelColor(0, pixels.Color(255, 192, 0));
            pixels.show();
            M5.Lcd.drawJpgFile(SPIFFS, "/pickup.jpg", 0, 0);
            break;
        case 2:
            pixels.setPixelColor(0, pixels.Color(0, 0, 255));
            pixels.show();
            M5.Lcd.drawJpgFile(SPIFFS, "/deliver.jpg", 0, 0);
            break;
        case 3:
            pixels.setPixelColor(0, pixels.Color(255, 192, 0));
            pixels.show();
            M5.Lcd.drawJpgFile(SPIFFS, "/payment.jpg", 0, 0);
            break;
    }
}

bool tarrif_button_pushed(void){
    bool v = digitalRead(CHANGE_TARIFF_BUTTON_PIN);
    bool pushed = false;

    if(v == LOW && current_tariff_button == HIGH){
        pushed = true;
    }

    current_tariff_button = v;
    return pushed;
}

void loop(void)
{
    if(tarrif_button_pushed()){
        current_tarrif_state = (current_tarrif_state + 1) % 4;
        show_sign(current_tarrif_state);
    }

    delay(10);
}
