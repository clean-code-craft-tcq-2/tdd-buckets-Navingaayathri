#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "test-framework/catch.hpp"
#include "Readings_sample.h"
#include "A2DConversion.h"

/********************************************* TDD part 1 ***************************************************/

SCENARIO("To sort the array of current samples") {
GIVEN ("An Unsorted array of current samples") {

  int inpCurrentSamples[11] = {15, 3, 3, 16, 2, 4, 10, 11, 12, 5, 17};
  int expCurrentSamples[11] = {2, 3, 3, 4, 5, 10, 11, 12, 15, 16, 17};

WHEN ("sortReadings() function is called with current samples array and count") {
  int (*realPtr) = sortReadings(inpCurrentSamples, 11);
THEN ("Gives the expected sorted array") {
    for (int i = 0; i < 11; i++)
    {
     REQUIRE(realPtr[i] == expCurrentSamples[i]);
    } 
   }
  }
 }
}

SCENARIO("To find the ranges and occurrences in the sorted array of current samples"){
GIVEN ("Sorted array of current samples") {
        int inpCurrentSamples[9]={15, 3, 16, 2, 4, 10, 5, 12, 11};
        chargingValueRange expOutput[3] = {{2, 5, 4}, {10, 12, 3}, {15, 16, 2}};
        RangeofSamples expRangeofSamplesCount = {expOutput, 3};

WHEN ("findchargingValueRange() is called with Charging values array and readingsCount") {
        RangeofSamples realRangeofSamples = findchargingValueRange(inpCurrentSamples, 9);
            
THEN ("Ranges and count of samples in the range will be displayed as the output") {
   REQUIRE(realRangeofSamples.RangeofSamplesCount == expRangeofSamplesCount.RangeofSamplesCount);
   int i;
   chargingValueRange *realchargingValueRange = realRangeofSamples.dataFormat;
     for (i = 0; i < expRangeofSamplesCount .RangeofSamplesCount; i++)
     {
       REQUIRE(realchargingValueRange[i].startValRange == expOutput[i].startValRange);
       REQUIRE(realchargingValueRange[i].endValRange == expOutput[i].endValRange);
       REQUIRE(realchargingValueRange[i].readingsCount == expOutput[i].readingsCount);
     }
    }
   }
 }
}
 
TEST_CASE("To test displayRangesandReadings function for printing the output")
{
    int inpCurrentSamples[9]={15, 3, 16, 2, 4, 10, 5, 12, 11};
    chargingValueRange chargingValues[3] = {{2, 5, 4}, {10, 12, 3}, {15, 16, 2}};
    RangeofSamples samplesRange = {chargingValues, 3};
    REQUIRE_NOTHROW(displayRangesandReadings(samplesRange));
}

/********************************************* TDD extension(part 2) ***************************************************/

SCENARIO("Test the conversion of 12 bit ADC values to real current values(0-10A)") {
GIVEN("Internal raw values from ADC sensor min:0, max:2^12-->4094") {
  int ADCInput[] = {64, 1000, 1146, 1220, 1560, 2048, 4094};
	int ADCInpSize = sizeof(ADCInput) / sizeof(ADCInput[0]);
	int expConvertedValues[] = {0, 2, 2, 2, 3, 5, 10};
	int phyCurrVal[ADCInpSize];
	int ADC_Factor = 12, currentValMax = 10;

WHEN("Internal value to Physical Value conversion function conversion InternalToPhysical() is called with input array, Resolution and Physical range") {
 phyValConversion(ADCInput, ADCInpSize, ADC_Factor, currentValMax, phyCurrVal);
THEN("The Physical value array is returned for the given internal array input ") {
	for(int i = 0; i < ADCInpSize; ++i)
	{
	REQUIRE(phyCurrVal[i] == expConvertedValues[i]);
	}
      }
    }
  }
}
/*
SCENARIO("Test the conversion of 10 bit ADC values to real current values(-15A to 15A)") {
GIVEN("Internal raw values from ADC sensor min:0, max:2^10-->1022") {
  int ADCInput[] = {300,550,1022};
	int ADCInpSize = sizeof(ADCInput) / sizeof(ADCInput[0]);
	int expConvertedValues[] = {4,8,15};
	int phyCurrVal[ADCInpSize];
	int ADC_Factor = 10, currentValMax = 15;

WHEN("Internal value to Physical Value conversion function conversion InternalToPhysical() is called with input array, Resolution and Physical range") {
 phyValConversion(ADCInput, ADCInpSize, ADC_Factor, currentValMax, phyCurrVal);
THEN("The Physical value array is returned for the given internal array input ") {
	for(int i = 0; i < ADCInpSize; ++i)
	{
	REQUIRE(phyCurrVal[i] == expConvertedValues[i]);
	}
      }
    }
  }
}*/
TEST_CASE("Test the conversion of 10 bit ADC values to real current values(-15A to 15A)")
{
        int ADCInput[] = {300,550,1022};
	int ADCInpSize = sizeof(ADCInput) / sizeof(ADCInput[0]);
	int expConvertedValues[] = {4,8,15};
	int phyCurrVal[ADCInpSize];
	int ADC_Factor = 10, currentValMax = 15;
	phyValConversion(ADCInput, ADCInpSize, ADC_Factor, currentValMax, phyCurrVal);
	for(int i = 0; i < ADCInpSize; ++i)
	{
	REQUIRE(phyCurrVal[i] == expConvertedValues[i]);
	}
}
