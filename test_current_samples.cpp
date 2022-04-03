#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "test-framework/catch.hpp"
#include "Readings_sample.h"


SCENARIO("To sort the array of current samples")
{
    GIVEN ("An Unsorted array of current samples"){

        int inpCurrentSamples[11] = {4, 7, 1, 3, 2, 7, 5, 6, 9, 10, 50};
        int expCurrentSamples[11] = {1, 2, 3, 4, 5, 6, 7, 7, 9, 10, 50};

    WHEN ("sortReadings() function is called with current samples array and count"){
            int(*realPtr) = sortReadings(inpCurrentSamples, 11);
	THEN ("Gives the expected sorted array"){
                for (int i = 0; i < 10; i++)
                {
                    CHECK(realPtr[i] == expCurrentSamples[i]);
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
        RangeofSamples realRangeofSamples = findchargingValueRange(inpCurrentSamples, 7);
            
    THEN ("Ranges and count of samples in the range will be displayed as the output"){
         CHECK(realRangeofSamples.RangeofSamplesCount == expRangeofSamplesCount.RangeofSamplesCount);
         int i;
         chargingValueRange *realchargingValueRange = realRangeofSamples.dataFormat;
         for (i = 0; i < realRangeofSamples .RangeofSamplesCount; i++){
            CHECK(realchargingValueRange[i].startValRange == expOutput[i].startValRange);
            CHECK(realchargingValueRange[i].endValRange == expOutput[i].endValRange);
            CHECK(realchargingValueRange[i].readingsCount == expOutput[i].readingsCount);
             }
          }
       }
   }
}
 
TEST_CASE("To test displayRangesandReadings function for printing the output")
{
    int inpCurrentSamples[10] = {1, 3, 3, 16, 4, 10, 11, 12, 5, 17};
    chargingValueRange dataFormat[3] = {{1, 5, 5}, {10, 12, 3}, {16, 17, 2}};
    RangeofSamples samplesRange = {chargingValues, 3};
    REQUIRE_NOTHROW(displayRangesandReadings(samplesRange));
}
