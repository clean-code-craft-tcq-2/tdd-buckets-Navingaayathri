#include "Readings_sample.h"
#include <stdbool.h>

int* sortReadings(int *chargingValueArray, int readingsCount) 
{
    qsort(chargingValueArray, readingsCount, sizeof(int), cmpfunc);
    return chargingValueArray;
}	

int cmpfunc (const void * val1, const void * val2) 
{
   return ( *(int*)val1 - *(int*)val2 );
}

RangeofSamples findchargingValueRange(int *chargingValueArray, int readingsCount)
{
int *sortedChargingValues = sortReadings(chargingValueArray, readingsCount);
chargingValueRange *dataFormat1 = (chargingValueRange *)malloc(readingsCount * sizeof(chargingValueRange));
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
    dataFormat1[Idx].startValRange = startVal;
    dataFormat1[Idx].endValRange =endVal;
    dataFormat1[Idx].readingsCount = Cnt;
      Idx++;
    Cnt = 1;
    startVal = sortedChargingValues[i];
    endVal = startVal;
  }
}

    dataFormat1[Idx].startValRange = startVal;
    dataFormat1[Idx].endValRange =endVal;
    dataFormat1[Idx].readingsCount = Cnt;
    RangeofSamples samplesRange = {dataFormat1, Idx+1};
    return samplesRange;
}

void displayRangesandReadings(RangeofSamples samplesRange)
{
 printf("Range, Readings\n");
 chargingValueRange *dataFormat = samplesRange.dataFormat;
for (int i = 0; i < samplesRange.RangeofSamplesCount; i++)
 {
 printf("%d-%d, %d\n", dataFormat[i].startValRange, dataFormat[i].endValRange, dataFormat[i].readingsCount);
 }
}
