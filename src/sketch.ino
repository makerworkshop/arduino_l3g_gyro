#include <Wire.h>
#include <L3G.h>

#define MDPS_FACTOR 8.75

L3G gyro;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  if (!gyro.init())
  {
    Serial.println("Failed to autodetect gyro type!");
    while (1);
  }

  gyro.enableDefault();
}

int lastX, lastY, lastZ;
bool started = false;

void loop() {

  gyro.read();

  if (started) {
    Serial.print("G ");
    Serial.print("dX: ");
    Serial.print(int(((lastX - (int)gyro.g.x)*MDPS_FACTOR)/1000));
    Serial.print(" dY: ");
    Serial.print(int(((lastY - (int)gyro.g.y)*MDPS_FACTOR)/1000));
    Serial.print(" dZ: ");
    Serial.print(int(((lastZ - (int)gyro.g.z)*MDPS_FACTOR)/1000));
    Serial.println("");
  } else {
    started = true;
  }

  lastX = (int)gyro.g.x;
  lastY = (int)gyro.g.y;
  lastZ = (int)gyro.g.z;


  delay(100);
}
