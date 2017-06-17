// Arduino Adafruit_BMP085 library API.

load('api_math.js');

let Adafruit_BMP085 = {
  // Error codes
  RES_FAIL: -100.0,

  _create: ffi('void *mgos_bmp085_create(void)'),
  _close: ffi('void mgos_bmp085_close(void *)'),
  _begin: ffi('bool mgos_bmp085_begin(void *, int)'),
  _rt: ffi('double mgos_bmp085_read_temperature(void *)'),
  _rp: ffi('int mgos_bmp085_read_pressure(void *)'),
  _rsp: ffi('int mgos_bmp085_read_sealevel_pressure(void *, double)'),
  _ra: ffi('double mgos_bmp085_read_altitude(void *, double)'),

  _proto: {
    // Close Adafruit_BMP085 handle. Return value: none.
    close: function() {
      return Adafruit_BMP085._close(this.bmp);
    },

    begin: function(mode) {
      return Adafruit_BMP085._begin(this.bmp, mode);
    },

    // Returns the temperature from the sensor in degrees C
    // or RES_FAIL if an operation failed.
    readTemperature: function() {
      return Math.round(Adafruit_BMP085._rt(this.bmp) * 10) / 10;
    },

    // Returns the pressure from the sensor in Pa
    // or RES_FAIL if an operation failed.
    readPressure: function() {
      return Adafruit_BMP085._rp(this.bmp);
    },

    readSeaLevelPressure: function(altitude_meters) {
      return Adafruit_BMP085._rsp(this.bmp, altitude_meters);
    },

    // Returns the altitude in meters calculated from the specified
    // atmospheric pressure (in Pa), and sea-level pressure (in Pa)
    // or RES_FAIL if an operation failed.
    // http://www.adafruit.com/datasheets/BST-BMP180-DS000-09.pdf, P.16
    readAltitude: function(lvl) {
      return Math.round(Adafruit_BMP085._ra(this.bmp, lvl) * 100) / 100;
    },
  },

  create: function() {
    let obj = Object.create(Adafruit_BMP085._proto);
    // Initialize Adafruit_BMP085 library.
    // Return value: handle opaque pointer.
    obj.bmp = Adafruit_BMP085._create();
    return obj;
  },
};
