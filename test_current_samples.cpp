#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test-framework/catch.hpp"
#include "Readings_sample.h"

TEST_CASE("To check the input current readings are valid and find consecutive Charging Values") 
{
  int inputCurrentSamples[] = {4,5};
  int valCount = sizeof(consecutiveChargingValues) / sizeof(consecutiveChargingValues[0]);
  REQUIRE(checkValidReadings(consecutiveChargingValues,valCount) == 1);
  REQUIRE(countConsecutiveRange(consecutiveChargingValues, valCount) == 2);
}

TEST_CASE("To check the input current readings are invalid") 
{
  int consecutiveChargingValues[] = {-8, 2 ,-4, -2, -1, 3, 5, 6};
  int valCount = sizeof(consecutiveChargingValues) / sizeof(consecutiveChargingValues[0]);
  REQUIRE(checkValidReadings(consecutiveChargingValues,valCount) == 0);
}

TEST_CASE("TO test the ranges are consecutive") 
{
  int consecutiveChargingValues[] = {3, 3, 5, 4, 10, 11, 12};
  int valCount = sizeof(consecutiveChargingValues) / sizeof(consecutiveChargingValues[0]);
  REQUIRE(checkValidReadings(consecutiveChargingValues,valCount) == 1);
}
