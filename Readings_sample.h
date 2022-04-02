#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct 
{
int startValRange;
int endValRange;
int readingsCount;
}chargingValueRange;

typedef struct  
{
chargingValueRange *dataFormat;
int RangeofSamplesCount;
}RangeofSamples;

extren int checkValidReadings(int *chargingValueArray, int readingsCount);
extern int* sortReadings( int *chargingValueArray,  int readingsCount);
extern int cmpfunc (const void * val1, const void * val2);
RangeofSamples findchargingValueRange(int *chargingValueArray, int readingsCount);
void displayRangesandReadings(RangeofSamples samplesRange);
