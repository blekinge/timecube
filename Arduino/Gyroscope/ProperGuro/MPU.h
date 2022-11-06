#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setupMPU() {
  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) {
    case MPU6050_RANGE_2_G:
      Serial.println("+-2G");
      break;
    case MPU6050_RANGE_4_G:
      Serial.println("+-4G");
      break;
    case MPU6050_RANGE_8_G:
      Serial.println("+-8G");
      break;
    case MPU6050_RANGE_16_G:
      Serial.println("+-16G");
      break;
  }

  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
    case MPU6050_RANGE_250_DEG:
      Serial.println("+- 250 deg/s");
      break;
    case MPU6050_RANGE_500_DEG:
      Serial.println("+- 500 deg/s");
      break;
    case MPU6050_RANGE_1000_DEG:
      Serial.println("+- 1000 deg/s");
      break;
    case MPU6050_RANGE_2000_DEG:
      Serial.println("+- 2000 deg/s");
      break;
  }

  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.print("Filter bandwidth set to: ");
  switch (mpu.getFilterBandwidth()) {
    case MPU6050_BAND_260_HZ:
      Serial.println("260 Hz");
      break;
    case MPU6050_BAND_184_HZ:
      Serial.println("184 Hz");
      break;
    case MPU6050_BAND_94_HZ:
      Serial.println("94 Hz");
      break;
    case MPU6050_BAND_44_HZ:
      Serial.println("44 Hz");
      break;
    case MPU6050_BAND_21_HZ:
      Serial.println("21 Hz");
      break;
    case MPU6050_BAND_10_HZ:
      Serial.println("10 Hz");
      break;
    case MPU6050_BAND_5_HZ:
      Serial.println("5 Hz");
      break;
  }
}



//TODO Define this
const float G2 = 8;


byte getReading() {
  /* Get new sensor events with the readings */
  //https://adafruit.github.io/Adafruit_CircuitPlayground/html/structsensors__event__t.html
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  //float ax = a.acceleration.x;
  //float ay = a.acceleration.y;
  //float az = a.acceleration.z;
  //Serial.print("accel");
  //Serial.println(a.acceleration.x);
  //Serial.println(a.acceleration.y);
  //Serial.println(a.acceleration.z);
  bool sides[] = {a.acceleration.x >= G2,
                  -a.acceleration.x >= G2,
                  a.acceleration.y >= G2,
                  -a.acceleration.y >= G2,
                  a.acceleration.z >= G2,
                  -a.acceleration.z >= G2
                 };
  //TODO check if multiple sides are true...
  for (byte i = 0; i < 6; i = i + 1) {
    if (sides[i]) {
      return i + 1;
    }
  }
  return 0;

}


byte getSideUp(byte currentSideUp) {
//  Serial.print("Attempting to getSideUp from current side =");
//  Serial.println(currentSideUp);
  byte sideUp1 = getReading();
  if (currentSideUp == sideUp1) {
    return sideUp1;
  } else {
    delay(500);
    return getSideUp(sideUp1);
  }
}
