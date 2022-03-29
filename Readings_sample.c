#include "Readings_sample.h"

int checkValidReadings(int *chargingValueArray, int readingsCount)
{
  for (int i = 0; i < readingsCount; i++) 
  {
   if (chargingValueArray[i]>=0) 
   {
   sortReadings(chargingValueArray, readingsCount); 
   return 1;
   }
  return 0;
  }
}

int* sortReadings(int *chargingValueArray, int readingsCount) 
{
qsort(chargingValueArray, readingsCount, sizeof(int), cmpfunc);
return chargingValueArray;
}	

int cmpfunc (const void * val1, const void * val2) 
{
return ( *(int*)val1 - *(int*)val2 );
}

int countConsecutiveRange(int *consecutiveChargingValues, int valCount)
{
    int i, sampleDiff, Cnt;
    if(checkValidReadings(consecutiveChargingValues, valCount) == 1)
    {
	for(i = 0; i < valCount; i++)
	{
	sampleDiff = (consecutiveChargingValues[i+1] -  consecutiveChargingValues[i]);
	Cnt = (sampleDiff == 0) || (sampleDiff == 1) ? Cnt++ : Cnt;	
        }
        return Cnt;
    }
}

ChargingValueRange displayRangesandReadings(int MinVal, int MaxVal, int samplesCount)
{
ChargingValueRange chargingValueRange;
chargingValueRange.startVal=MinVal;
chargingValueRange.endVal=MaxVal;
chargingValueRange.RangeofSamplesCount= samplesCount;
printf("Range, Readings\n");
printf(" %d - %d , %d\n", MinVal, MaxVal, samplesCount); 
return chargingValueRange;
}
