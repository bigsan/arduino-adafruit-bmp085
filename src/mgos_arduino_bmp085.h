/*
 * Arduino Adafruit_BMP085 library API wrapper
 */

#include "Adafruit_BMP085.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define MGOS_BMP085_RES_FAIL -10000

// Initialize Adafruit_BMP085 library.
Adafruit_BMP085 *mgos_bmp085_create();

// Close Adafruit_BMP085 handle. Return value: none.
void mgos_bmp085_close(Adafruit_BMP085 *bmp);

bool mgos_bmp085_begin(Adafruit_BMP085 *bmp, int mode = BMP085_ULTRAHIGHRES);

// Returns the temperature from the sensor in degrees C
// or MGOS_BMP085_RES_FAIL if an operation failed.
double mgos_bmp085_read_temperature(Adafruit_BMP085 *bmp);

// Returns the pressure from the sensor in Pa
// or MGOS_BMP085_RES_FAIL if an operation failed.
int mgos_bmp085_read_pressure(Adafruit_BMP085 *bmp);

int mgos_bmp085_read_sealevel_pressure(Adafruit_BMP085 *bmp, double altitude_meters = 0);

// Returns the altitude in meters calculated from the specified
// atmospheric pressure (in Pa), and sea-level pressure (in Pa)
// or MGOS_BMP085_RES_FAIL if an operation failed.
// http://www.adafruit.com/datasheets/BST-BMP180-DS000-09.pdf, P.16
double mgos_bmp085_read_altitude(Adafruit_BMP085 *bmp, double seaLevelPressure = 101325);

#ifdef __cplusplus
}
#endif  /* __cplusplus */
