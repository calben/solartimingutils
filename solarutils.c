#include <stdlib.h>
#include <math.h>
#include "solarutils.h"

#define DEG_TO_RAD_CONSTANT 0.01745329251

float deg_sin(float deg)
{
    return sin(deg * DEG_TO_RAD_CONSTANT);
}

float deg_cos(float deg)
{
    return cos(deg * DEG_TO_RAD_CONSTANT);
}

float deg_tan(float deg)
{
    return tan(deg * DEG_TO_RAD_CONSTANT);
}

float deg_asin(float deg)
{
    return asin(deg) / DEG_TO_RAD_CONSTANT;
}

float deg_acos(float deg)
{
    return acos(deg) / DEG_TO_RAD_CONSTANT;
}

float deg_atan(float deg)
{
    return atan(deg) / DEG_TO_RAD_CONSTANT;
}

// wrap x about period with positive and negative
float within(float x, float period)
{
    while (x < 0)
    {
        x += period;
    }
    while (x >= period)
    {
        x -= period;
    }
    return x;
}

float calculate(int year, int month, int day, float lat, float lng, float utc_offset, int is_sunrise)
{
    // generate day of the year
    float n1 = floor(275 * month / 9);
    float n2 = floor((month + 9) / 12);
    float n3 = 1 + floor((year - (4 * floor(year / 4)) + 2) / 3);
    float day_of_year = n1 - (n2 * n3) + day - 30;

    // approximate the time
    float approximate_time = 0.0;
    float lng_hour = lng / 15;
    if (is_sunrise)
    {
        approximate_time = day_of_year + ((6 - lng_hour) / 24);
    }
    else
    {
        approximate_time = day_of_year + ((18 - lng_hour) / 24);
    }

    // generate mean anomaly
    float mean_anomaly = (0.9856 * approximate_time) - 3.289;

    // true longitude
    float true_lng = mean_anomaly + (1.916 * deg_sin(mean_anomaly)) + (0.020 * deg_sin(2 * mean_anomaly)) + 282.634;
    true_lng = within(true_lng, 360);

    // generate right ascension
    float right_ascension = within(deg_atan(0.91764 * deg_tan(true_lng)), 360);

    float lquad = floor(true_lng / 90) * 90;
    float raquad = floor(right_ascension / 90) * 90;
    right_ascension = (right_ascension + (lquad - raquad)) / 15;

    // get local hour angle
    float deg_sin_dec = 0.39782 * deg_sin(true_lng);
    float deg_cos_dec = deg_cos(deg_asin(deg_sin_dec));
    float deg_cos_h = (-deg_sin_dec * deg_sin(lat)) / (deg_cos_dec * deg_cos(lat));

    if (deg_cos_h > 1 || deg_cos_h < -1) 
    {
        // this should only happen in the arctic or antarctic circles
        return 0.0f;
    }

    float local_hour_angle = 0;
    if (is_sunrise)
    {
        local_hour_angle = 360 - deg_acos(deg_cos_h);
    }
    else
    {
        local_hour_angle = deg_acos(deg_cos_h);
    }

    local_hour_angle /= 15;

    float time = local_hour_angle + right_ascension - (0.06571 * approximate_time) - 6.622;

    return within(time - lng_hour + utc_offset, 24);
}

// utc_offset is per quarter hour
float calculate_sunrise(int year, int month, int day, float lat, float lng, int utc_offset)
{
    return calculate(year, month, day, lat, lng, utc_offset / 4.0, 1);
}

// utc_offset is per quarter hour
float calculate_sunset(int year, int month, int day, float lat, float lng, int utc_offset)
{
    return calculate(year, month, day, lat, lng, utc_offset / 4.0, 0);
}
