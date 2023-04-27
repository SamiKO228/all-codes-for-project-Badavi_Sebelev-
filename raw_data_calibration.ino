yaw   = atan2(2.0f * (q[1] * q[2] + q[0] * q[3]), q[0] * q[0] + q[1] * q[1] – q[2] * q[2] – q[3] * q[3]);
pitch = -asin(2.0f * (q[1] * q[3] – q[0] * q[2]));
roll  = atan2(2.0f * (q[0] * q[1] + q[2] * q[3]), q[0] * q[0] – q[1] * q[1] – q[2] * q[2] + q[3] * q[3]);
pitch *= 180.0f / PI;
yaw   *= 180.0f / PI;
yaw   += 1.34; /* Declination at Potheri, Chennail ,India  Model Used:    IGRF12    Help
Latitude:    12.823640° N
Longitude:    80.043518° E
Date    Declination
2016-04-09    1.34° W  changing by  0.06° E per year     (+ve for west )*/
readMagData(magCount);  // Read the x/y/z adc values
getMres();
//    magbias[0] = +470.;  // User environmental x-axis correction in milliGauss, should be automatically calculated
//    magbias[1] = +120.;  // User environmental x-axis correction in milliGauss
//    magbias[2] = +125.;  // User environmental x-axis correction in milliGauss
// Calculate the magnetometer values in milliGauss
// Include factory calibration per data sheet and user environmental corrections
mx = (float)magCount[0]*mRes*magCalibration[0] – magBias[0];  // get actual magnetometer value, this depends on scale being set
my = (float)magCount[1]*mRes*magCalibration[1] – magBias[1];
mz = (float)magCount[2]*mRes*magCalibration[2] – magBias[2];
}
