/*
 * Arduino Adafruit_BMP085 library API wrapper
 */

#include "mgos_arduino_bmp085.h"

Adafruit_BMP085 *mgos_bmp085_create() {
  return new Adafruit_BMP085();
}

void mgos_bmp085_close(Adafruit_BMP085 *bmp) {
  if (bmp != nullptr) {
    delete bmp;
    bmp = nullptr;
  }
}

bool mgos_bmp085_begin(Adafruit_BMP085 *bmp, int mode) {
  if (bmp == nullptr) return 0;
  return bmp->begin(mode);
}

double mgos_bmp085_read_temperature(Adafruit_BMP085 *bmp) {
  if (bmp == nullptr) return MGOS_BMP085_RES_FAIL;
  return bmp->readTemperature();
}

int mgos_bmp085_read_pressure(Adafruit_BMP085 *bmp) {
  if (bmp == nullptr) return MGOS_BMP085_RES_FAIL;
  return bmp->readPressure();
}

int mgos_bmp085_read_sealevel_pressure(Adafruit_BMP085 *bmp, double altitude_meters) {
  if (bmp == nullptr) return MGOS_BMP085_RES_FAIL;
  return bmp->readSealevelPressure(altitude_meters);
}

double mgos_bmp085_read_altitude(Adafruit_BMP085 *bmp, double seaLevelPressure) {
  if (bmp == nullptr) return MGOS_BMP085_RES_FAIL;
  return bmp->readAltitude(seaLevelPressure);
}
