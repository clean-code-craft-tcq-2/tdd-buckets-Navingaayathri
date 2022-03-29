#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct 
{
int startVal;
int endVal;
int RangeofSamplesCount;
}ChargingValueRange;

extern int checkValidReadings( int *chargingValueArray, int readingsCount);
extern int* sortReadings( int *chargingValueArray,  int readingsCount);
extern int cmpfunc (const void * val1, const void * val2);
extern int checkConsecutiveRange(int *consecutiveChargingValues, int valCount, int sampleDiff)
extern int countConsecutiveRange(int *consecutiveChargingValues, int valCount, int Cnt);
ChargingValueRange displayRangesandReadings(int MinVal,  int MaxVal, int samplesCount);
