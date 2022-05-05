#include "Readings_sample.h"
#include <stdbool.h>

/* Sort function for the given array of samples */
int* sortReadings(int *chargingValueArray, int readingsCount) 
{
    qsort(chargingValueArray, readingsCount, sizeof(int), cmpfunc);
    return chargingValueArray;
}	

/* Compare function for qsort */
int cmpfunc (const void * val1, const void * val2) 
{
   return ( *(int*)val1 - *(int*)val2 );
}

/* Function to find charging value samples range and occurences */
RangeofSamples findchargingValueRange(int *chargingValueArray, int readingsCount)
{
int *sortedChargingValues = sortReadings(chargingValueArray, readingsCount);
chargingValueRange *dataFormat = (chargingValueRange *)malloc(readingsCount * sizeof(chargingValueRange));
int startVal = sortedChargingValues[0], endVal = sortedChargingValues[0], Idx = 0, Cnt = 0;
for (int i = 0; i < readingsCount; i++)
{
if (sortedChargingValues[i] == startVal || sortedChargingValues[i] == endVal+1)
  {
    Cnt++;
    endVal = sortedChargingValues[i];
  }
else
  {
    dataFormat[Idx].startValRange = startVal;
    dataFormat[Idx].endValRange =endVal;
    dataFormat[Idx].readingsCount = Cnt;
    Idx++;
    Cnt = 1;
    startVal = sortedChargingValues[i];
    endVal = startVal;
  }
}

    dataFormat[Idx].startValRange = startVal;
    dataFormat[Idx].endValRange =endVal;
    dataFormat[Idx].readingsCount = Cnt;
    RangeofSamples samplesRange = {dataFormat, Idx+1};
    return samplesRange;
}

/* Display the samples range and occurences count in csv format on console */
void displayRangesandReadings(RangeofSamples samplesRange)
{
 printf("Range, Readings\n");
 chargingValueRange *dataFormat = samplesRange.dataFormat;
 for (int i = 0; i < samplesRange.RangeofSamplesCount; i++)
 {
 printf("%d-%d, %d\n", dataFormat[i].startValRange, dataFormat[i].endValRange, dataFormat[i].readingsCount);
 }
}
