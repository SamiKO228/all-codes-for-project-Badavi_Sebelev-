yaw   = atan2(2.0f * (q[1] * q[2] + q[0] * q[3]), q[0] * q[0] + q[1] * q[1] – q[2] * q[2] – q[3] * q[3]);
pitch = -asin(2.0f * (q[1] * q[3] – q[0] * q[2]));
roll  = atan2(2.0f * (q[0] * q[1] + q[2] * q[3]), q[0] * q[0] – q[1] * q[1] – q[2] * q[2] + q[3] * q[3]);
pitch *= 180.0f / PI;
yaw   *= 180.0f / PI;
yaw   += 1.34; /* Declination at Potheri, Chennail ,India  Model Used:    IGRF12    Help
Latitude:    12.823640° N
Longitude:    80.043518° E
Date    Declination
2016-04-09    1.34° W  changing by  0.06° E per year (+ve for west )*/
roll  *= 180.0f / PI;
Serial.print(“Yaw, Pitch, Roll: “);
Serial.print(yaw+180, 2);
Serial.print(“, “);
Serial.print(pitch, 2);
Serial.print(“, “);
Serial.println(roll, 2);
