#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void displayError(void);
int findInternalMaxSens(int ADC_FACTOR, int value);
void convertADCinpToPhyValSens(int ADCInput[], int ADCInpSize, int ADC_FACTOR, int CURRENTVALMAX, int* convertedVal);
void phyValConversion(int ADCInput[], int ADCInpSize, int ADC_FACTOR, int CURRENTVALMAX, int* phyCurrVal);
