#include <stdio.h>
#include <stdlib.h>
#include "solarutils.h"

void test()
{
    int year = 2016;
    int month = 11;
    int day = 28;
    float lat = 45.502177;
    float lng = -73.567085;
    float utc_offset = -5.0;
    fprintf(stdout, "within for 5 and 21 yields %f \n", within(5, 21));
    fprintf(stdout, "within for -5 and 21 yields %f \n", within(-5, 21));
    fprintf(stdout, "within for 26 and 21 yields %f \n", within(26, 21));
    fprintf(stdout, "calculate_sunrise for %d %d %d %f %f %f yields %f \n", year, month, day, lat, lng, utc_offset, calculate_sunrise(year, month, day, lat, lng, utc_offset));
    fprintf(stdout, "calculate_sunset for %d %d %d %f %f %f yields %f \n", year, month, day, lat, lng, utc_offset, calculate_sunset(year, month, day, lat, lng, utc_offset));
}

int main(int argc, char* argv[])
{
    test();
}
