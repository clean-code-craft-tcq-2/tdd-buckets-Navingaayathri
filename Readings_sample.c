#include "Readings_sample.h"

bool checkValidReadings(int *chargingValueArray, int readingsCount)
{
  for (int i = 0; i < readingsCount; i++) 
  {
   if (chargingValueArray[i]>=0) 
   {
   sortReadings(chargingValueArray, readingsCount); 
   return true;
   }
   else 
   {
    return false;
   }
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

int checkConsecutiveRange(int *consecutiveChargingValues, int valCount, int sampleDiff)
{    
    if(checkValidReadings(consecutiveChargingValues, valCount) == true)
    {
     for(int i = 0; i < valCount; i++)
      {
       sampleDiff = (consecutiveChargingValues[i+1] -  consecutiveChargingValues[i]);
       return sampleDiff;
      }      
    }
}

int countConsecutiveRange(int *consecutiveChargingValues, int valCount, int Cnt)
{
     int sampleDiffval = checkConsecutiveRange(consecutiveChargingValues, valCount);
     if((sampleDiffval == 0) || (sampleDiffval == 1))
     Cnt++;
     return Cnt;    
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
