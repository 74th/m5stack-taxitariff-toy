// clang-format off
#include "main.hpp"
#include <M5Unified.h>
// clang-format on

uint32_t count;

void setup(void)
{
    auto cfg = M5.config();

    M5.begin(cfg); // M5デバイスの初期化

    M5.Display.setTextSize(3);         // テキストサイズを変更
    M5.Display.print("Hello World!!"); // 画面にHello World!!と1行表示
    Serial.println("Hello World!!");   // シリアルモニターにHello World!!と1行表示
    count = 0;                         // countを初期化
}

void loop(void)
{
    M5.Display.setCursor(0, 20);             // 文字の描画座標(カーソル位置)を設定
    M5.Display.printf("COUNT: %d\n", count); // countを画面に表示
    Serial.printf("COUNT: %d\n", count);     // countをシリアルに表示
    count++;                                 // countを1増やす
    delay(1000);                             // 1秒待つ
}
