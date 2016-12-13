#ifndef SOLAR_UTILS_H
#define SOLAR_UTILS_H

//! An edition of Sine that uses degrees.
/*!
  \param deg The value in degrees on which to apply the function.
  \return The sine value
*/
float deg_sin(float deg);


//! An edition of Cosine that uses degrees.
/*!
  \param deg The value in degrees on which to apply the function.
  \return The sine value
*/
float deg_cos(float deg);

//! An edition of Tangent that uses degrees.
/*!
  \param deg The value in degrees on which to apply the function.
  \return The sine value
*/
float deg_tan(float deg);

//! An edition of Arcsine that uses degrees.
/*!
  \param deg The value in degrees on which to apply the function.
  \return The sine value
*/
float deg_asin(float deg);

//! An edition of Arccosine that uses degrees.
/*!
  \param deg The value in degrees on which to apply the function.
  \return The sine value
*/
float deg_acos(float deg);

//! An edition of Arctangent that uses degrees.
/*!
  \param deg The value in degrees on which to apply the function.
  \return The sine value
*/
float deg_atan(float deg);

//! A function that return a value incremented or decremented to be within the period.
/*!
  \param x the value to be within the period.
  \param period the period in which to be.
  \return the modified x value
*/
float within(float x, float period);

//! Calculates the time of sunrise or sunset.
/*!
  \param year the integer year
  \param month the integer month
  \param day the integer day
  \param lat the float latitude
  \param lng the float longitude
  \param utc_offset the UTC timezone offset to uses
  \param is_sunrise 1 indicates to calculate sunrise, 0 indicates to calculate sunset
  \return the approximated sunrise or sunset in hours
*/
float calculate(int year, int month, int day, float lat, float lng, float utc_offset, int is_sunrise);

//! Calculates the time of sunrise.
/*!
  \param year the integer year
  \param month the integer month
  \param day the integer day
  \param lat the float latitude
  \param lng the float longitude
  \param utc_offset the UTC timezone offset to uses
  \return the approximated sunrise in hours
*/
float calculate_sunrise(int year, int month, int day, float lat, float lng, int utc_offset);

//! Calculates the time of sunset.
/*!
  \param year the integer year
  \param month the integer month
  \param day the integer day
  \param lat the float latitude
  \param lng the float longitude
  \param utc_offset the UTC timezone offset to uses
  \return the approximated sunset in hours
*/
float calculate_sunset(int year, int month, int day, float lat, float lng, int utc_offset);

#endif /* SOLAR_UTILS_H */
