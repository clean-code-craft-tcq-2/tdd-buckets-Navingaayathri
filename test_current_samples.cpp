#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "test-framework/catch.hpp"
#include "Readings_sample.h"


SCENARIO("To sort the array of current samples")
{
    GIVEN ("An Unsorted array of current samples"){

        int inpCurrentSamples[11] = {15, 3, 3, 16, 2, 4, 10, 11, 12, 5, 17};
        int expCurrentSamples[11] = {2, 3, 3, 4, 5, 10, 11, 12, 15, 16, 17};

    WHEN ("sortReadings() function is called with current samples array and count"){
            int(*realPtr) = sortReadings(inpCurrentSamples, 11);
	THEN ("Gives the expected sorted array"){
                for (int i = 0; i < 10; i++)
                {
                    REQUIRE(realPtr[i] == expCurrentSamples[i]);
                } 
             }
           }
         }
      }

SCENARIO("To find the ranges and occurrences in the sorted array of current samples")
{
    GIVEN ("Sorted array of current samples"){
        int inpCurrentSamples[11] = {15, 3, 3, 16, 2, 4, 10, 11, 12, 5, 17};
        chargingValueRange expOutput[3] = {{2, 5, 5}, {10, 12, 3}, {15, 17, 3}};
        RangeofSamples expRangeofSamplesCount = {expOutput, 3};

    WHEN ("findchargingValueRange() is called with Charging values array and readingsCount"){
        RangeofSamples realRangeofSamples = findchargingValueRange(inpCurrentSamples, 11);
            
    THEN ("Ranges and count of samples in the range will be displayed as the output"){
         REQUIRE(realRangeofSamples.RangeofSamplesCount == expRangeofSamplesCount.RangeofSamplesCount);
         int i;
         chargingValueRange *realchargingValueRange = realRangeofSamples.dataFormat;
         for (i = 0; i < realRangeofSamples .RangeofSamplesCount; i++){
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
    int inpCurrentSamples[11] = {15, 3, 3, 16, 2, 4, 10, 11, 12, 5, 17};
    chargingValueRange chargingValues[3] = {{2, 5, 5}, {10, 12, 3}, {15, 17, 3}};
    RangeofSamples samplesRange = {chargingValues, 3};
    REQUIRE_NOTHROW(displayRangesandReadings(samplesRange));
}
