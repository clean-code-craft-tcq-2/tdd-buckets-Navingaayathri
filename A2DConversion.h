#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findInternalMaxSens(int ADCFactor);
float executeConversion(int ADCInput, int ADCFactor, int currValMax);
int* convertADCinpToPhyValSens(int ADCInput[], int ADCFactor, int ADCInpSize, int* currValPhy, int currValMax);
void convertADCinpToPhyValSens2(int ADCInput[], int ADCFactor, int ADCInpSize, int* currValPhy, int currValMax);
