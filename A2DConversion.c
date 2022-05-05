#include "A2DConversion.h"

/* Function to find the maximum internal raw value for the given resolution(factor) of ADC */
int findInternalMaxSens(int ADC_FACTOR, int value)
{
	return (pow(2,ADC_FACTOR) - value);
}

/* Conversion function to calculate physical value of current samples with maximum raw value of given resolution(factor) */
void convertADCinpToPhyValSens(int ADCInput[], int ADCInpSize, int ADC_Factor, int currentValMax, int* convertedVal)
{
	float currentValue;
	int   adcSensVal;	
	for (int i = 0; i < ADCInpSize ; ++i)
	{
		adcSensVal = (CURRENTVALMAX * ADCInput[i]);
		currentValue    = (adcSensVal/(findInternalMaxSens(ADC_Factor,2)));
		convertedVal[i] = round(currentValue);
		if(convertedVal[i] < 0)
		{
		convertedVal[i] = abs(convertedVal[i]);
		}
	}
}

/* Input raw values from ADC to physical value conversion */
void phyValConversion(int ADCInput[], int ADCInpSize, int ADC_Factor, int currentValMax, int* phyCurrVal)
{
	for (int i = 0; i< ADCInpSize; ++i)
	{
		if(ADCInput[i] < (findInternalMaxSens(ADC_FACTOR,1)))
		{
		convertADCinpToPhyValSens(ADCInput, ADCInpSize, ADC_Factor, currentValMax, phyCurrVal);
		}
		else
		{
		printf("Error : Invalid value!\n");
		}
	}
}
