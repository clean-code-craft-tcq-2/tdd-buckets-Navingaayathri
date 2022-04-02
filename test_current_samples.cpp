#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "test-framework/catch.hpp"
#include "Readings_sample.h"


Scenario : To sort the array of current samples
{
    Given : An Unsorted array of current samples
		int inpCurrentSamples[11] = {4, 7, 1, 3, 2, 7, 5, 6, 9, 10, 50};
        int expCurrentSamples[11] = {1, 2, 3, 4, 5, 6, 7, 7, 9, 10, 50};

    When : sortReadings() function is called with current samples array and count
            int(*realPtr) = sortReadings(inpCurrentSamples, 11);
	Then : Gives the expected sorted array
                for (int i = 0; i < 10; i++)
                {
                    CHECK(realPtr[i] == expCurrentSamples[i]);
                }


Scenario : To find the ranges and occurrences in the sorted array of current samples
{
    Given :Sorted array of current samples
        int inpCurrentSamples[7] = {3, 3, 5, 4, 10, 11, 12};
        chargingValueRange expOutput[2] = {{3, 5, 4}, {10, 12, 3}};
        RangeofSamples expRangeofSamplesCount = {expOutput, 2};

    When : findchargingValueRange() is called with Charging values array and readingsCount
        RangeofSamples realRangeofSamples = findchargingValueRange(inpCurrentSamples, 7);
            
	Then : 

    CHECK(realRangeofSamplesCount.RangeofSamplesCount == expRangeofSamplesCount.RangeofSamplesCount);

                int isEqual = 1;
                chargingValueRange *realchargingValueRange = realRangeofSamplesCount.readingRanges;
                for (int i = 0; i < realRangeofSamplesCount.RangeofSamplesCount; i++)
                {
                    CHECK(realchargingValueRange[i].startValRange == expchargingValueRange[i].startValRange);
                    CHECK(realchargingValueRange[i].endValRange == expchargingValueRange[i].endValRange);
                    CHECK(realchargingValueRange[i].readingsCount == expchargingValueRange[i].readingsCount);
                }
 
TEST_CASE("To test displayRangesandReadings function for printing the output")
{
    int inpCurrentSamples[7] = {3, 3, 5, 4, 10, 11, 12};
    chargingValueRange expOutput[2] = {{3, 5, 4}, {10, 12, 3}};
    RangeofSamples expRangeofSamplesCount = {expOutput, 2};
    REQUIRE(printReadingRangeList(readingRangeList));
}
