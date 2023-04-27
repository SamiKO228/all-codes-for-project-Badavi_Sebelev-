readMagData(magCount);  // Read the x/y/z adc values
getMres();
magbias[0] = +470.;  // User environmental x-axis correction in milliGauss, should be automatically calculated
magbias[1] = +120.;  // User environmental x-axis correction in milliGauss    magbias[2] = +125.;  // User environmental x-axis correction in milliGauss
// Calculate the magnetometer values in milliGauss
// Include factory calibration per data sheet and user environmental corrections
mx = (float)magCount[0]*mRes*magCalibration[0] – magBias[0];  // get actual magnetometer value, this depends on scale being set
my = (float)magCount[1]*mRes*magCalibration[1] – magBias[1];
mz = (float)magCount[2]*mRes*magCalibration[2] – magBias[2];
}
delay(1000);
// Get magnetometer calibration from AK8963 ROM
initAK8963(magCalibration); Serial.println(“AK8963 initialized for active data mode….”); // Initialize device for active mode read of magnetometer
getMres();
//magcalMPU9250(magBias,magScale);  // commented call statement
if(SerialDebug) {
//  Serial.println(“Calibration values: “);
Serial.print(“X-Axis sensitivity adjustment value “); Serial.println(magCalibration[0], 2);
Serial.print(“Y-Axis sensitivity adjustment value “); Serial.println(magCalibration[1], 2);
Serial.print(“Z-Axis sensitivity adjustment value “); Serial.println(magCalibration[2], 2);
}
