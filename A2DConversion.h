#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findInternalMaxSens(int ADC_FACTOR, int value);
void convertADCinpToPhyValSens(int ADCInput[], int ADCInpSize, int ADC_Factor, int currentValMax, int* convertedVal);
void phyValConversion(int ADCInput[], int ADCInpSize, int ADC_Factor, int currentValMax, int* phyCurrVal);
