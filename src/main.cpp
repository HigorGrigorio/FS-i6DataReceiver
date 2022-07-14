#include <Arduino.h>
#include <PWM.h>

PWM channels[4];

void setup()
{
    Serial.begin(9600);

    channels[0].setPin(2);
    channels[1].setPin(4);
    channels[2].setPin(7);
    channels[3].setPin(8);

    channels[0].calculateOffSet();
    channels[1].calculateOffSet();
    channels[2].calculateOffSet();
    channels[3].calculateOffSet();


    Serial.println(String("channel {1} offset: ") + String(channels[0].getOffset()));
    Serial.println(String("channel {2} offset: ") + String(channels[1].getOffset()));
    Serial.println(String("channel {3} offset: ") + String(channels[2].getOffset()));
    Serial.println(String("channel {4} offset: ") + String(channels[3].getOffset()));

    delay(2000);
}

void loop()
{
    Serial.print(String("channel 1: ") + String(channels[0].read()) + "   ");
    Serial.print(String("channel 2: ") + String(channels[1].read()) + "   ");
    Serial.print(String("channel 3: ") + String(channels[2].read()) + "   ");
    Serial.println(String("channel 4: ") + String(channels[3].read()));
    Serial.flush();
}