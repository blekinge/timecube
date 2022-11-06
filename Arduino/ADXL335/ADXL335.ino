// macro definitions of Analog read pins
#define X_AXIS_PIN A0
#define Y_AXIS_PIN A1
#define Z_AXIS_PIN A2

#include <ADXL335.h>



ADXL335 accelerometer;
void setup() {
    Serial.begin(9600);
    accelerometer.begin();
}
void loop() {
    int x, y, z;
    accelerometer.getXYZ(&x, &y, &z);
    Serial.println("value of X/Y/Z: ");
    Serial.println(x);
    Serial.println(y);
    Serial.println(z);
    float ax, ay, az;
    accelerometer.getAcceleration(&ax, &ay, &az);
    Serial.println("accleration of X/Y/Z: ");
    Serial.print(ax);
    Serial.println(" g");
    Serial.print(ay);
    Serial.println(" g");
    Serial.print(az);
    Serial.println(" g");
    delay(500);
}
