#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "A2DConversion.h"

/* Function to find the maximum internal raw value for the given resolution(factor) of ADC */
int findInternalMaxSens(int ADCFactor)
{
  return (pow (2, ADCFactor) - 2);
}

/* Conversion function to calculate physical value of current samples with maximum raw value of given resolution(factor) */
float executeConversion(int ADCInput, int ADCFactor, int currValMax)
{
  float currValPhy, convertedVal;
  convertedVal = ADCInput / findInternalMaxSens(ADCFactor);
  currValPhy = ((currValMax * convertedVal) /(findInternalMaxSens(ADCFactor)));
  return currValPhy;
}

int* convertADCinpToPhyValSens(int ADCInput[], int ADCFactor, int ADCInpSize, int* currValPhy, int currValMax)
{
 for (int i = 0; i<ADCInpSize; i++)
 {	
  float convertedVal;
  convertedVal = executeConversion(ADCInput[i], ADCFactor, currValMax);
  currValPhy[i] = round(convertedVal);
  if (currValPhy[i] < 0)
  currValPhy[i] = (int)abs(currValPhy[i]);
 }
  return currValPhy;
}

/* Input raw values from ADC to physical value conversion */
int* convertADCinpToPhyValSens2(int ADCInput[], int ADCFactor, int ADCInpSize, int* currValPhy, int currValMax)
{
int invalidVal =  (pow (2, ADCFactor) - 1);
 for (int i = 0; i<ADCInpSize-1; i++)
  {
   if(ADCInput[i] <= (findInternalMaxSens(ADCFactor)) && (ADCInput[i]!= invalidVal))
   {
     currValPhy = convertADCinpToPhyValSens(ADCInput, ADCFactor, ADCInpSize, currValPhy, currValMax);
    }
    else
    {
    printf("Error : Invalid value!\n");
   }
 }     
  return currValPhy;
}
