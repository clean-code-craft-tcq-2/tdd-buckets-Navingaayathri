#pragma once

#include <stdio.h>

typedef struct 
{
int startVal;
int endVal;
int RangeofSamplesCount;
}ChargingValueRange;

extern int checkValidReadings(extern int *chargingValueArray, extern int readingsCount);
extern int* sortReadings(extern int *chargingValueArray, extern int readingsCount);
extern int cmpfunc (const void * val1, const void * val2);
extern int countConsecutiveRange(extern int *consecutiveChargingValues, extern int valCount);
ChargingValueRange displayRangesandReadings(extern int MinVal, extern int MaxVal, extern int samplesCount);
