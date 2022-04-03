#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "test-framework/catch.hpp"
#include "Readings_sample.h"


SCENARIO("To sort the array of current samples")
{
    GIVEN ("An Unsorted array of current samples"){

        int inpCurrentSamples[10] = {1, 3, 3, 16, 4, 10, 11, 12, 5, 17};
        int expCurrentSamples[10] = {1, 3, 3, 4, 5, 10, 11, 12, 16, 17};

    WHEN ("sortReadings() function is called with current samples array and count"){
            int(*realPtr) = sortReadings(inpCurrentSamples, 10);
	THEN ("Gives the expected sorted array"){
                for (int i = 0; i < 9; i++)
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
        int inpCurrentSamples[10] = {1, 3, 3, 16, 4, 10, 11, 12, 5, 17};
        chargingValueRange expOutput[3] = {{1, 5, 5}, {10, 12, 3}, {16, 17, 2}};
        RangeofSamples expRangeofSamplesCount = {expOutput, 3};

    WHEN ("findchargingValueRange() is called with Charging values array and readingsCount"){
        RangeofSamples realRangeofSamples = findchargingValueRange(inpCurrentSamples, 10);
            
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
    int inpCurrentSamples[10] = {1, 3, 3, 16, 4, 10, 11, 12, 5, 17};
    chargingValueRange chargingValues[3] = {{1, 5, 5}, {10, 12, 3}, {16, 17, 2}};
    RangeofSamples samplesRange = {chargingValues, 3};
    REQUIRE_NOTHROW(displayRangesandReadings(samplesRange));
}
