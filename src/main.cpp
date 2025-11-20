#include <SPIFFS.h>
#include <M5Unified.h>

void show_sign(uint8_t no);

uint32_t count;

void setup(void)
{
    auto cfg = M5.config();

    M5.begin(cfg);
    SPIFFS.begin();
}

void show_sign(uint8_t no)
{
    switch(no)
    {
        case 0:
            M5.Lcd.drawJpgFile(SPIFFS, "/unladen.jpg", 0, 0);
            break;
        case 1:
            M5.Lcd.drawJpgFile(SPIFFS, "/deliver.jpg", 0, 0);
            break;
    }
}

void loop(void)
{
    show_sign(0);
    delay(1000);
    show_sign(1);
    delay(1000);
}
