#ifndef SOLAR_UTILS_H
#define SOLAR_UTILS_H

float deg_sin(float deg);

float deg_cos(float deg);

float deg_tan(float deg);

float deg_asin(float deg);

float deg_acos(float deg);

float deg_atan(float deg);

float within(float x, float period);

float calculate(int year, int month, int day, float lat, float lng, float utc_offset, int is_sunrise);

float calculate_sunrise(int year, int month, int day, float lat, float lng, int utc_offset);

float calculate_sunset(int year, int month, int day, float lat, float lng, int utc_offset);

#endif /* SOLAR_UTILS_H */
