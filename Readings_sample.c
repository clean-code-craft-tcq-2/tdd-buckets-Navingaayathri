#include <stdio.h>
#include "Readings_sample.h"

int arr[] = {5,4,3,1,6,9,10,12,18,0,3,2,15};

int getMinVal(int arr[], int readingscount)
{
int MinVal= arr[0];
for(int i=1; i<readingscount; i++)
if(arr[i] < MinVal)
MinVal = arr[i];
return MinVal;
}

int getMaxVal(int arr[], int readingscount)
{
int MaxVal= arr[0];
for(int i=1; i<readingscount; i++)
if(arr[i] > MaxVal)
MaxVal = arr[i];
return MaxVal;
}

const char* detectRange(int arr[], int readingscount)
{
    int MinValSample, MaxValSample;
    MinValSample = getMinVal(arr, readingscount);
    MaxValSample = getMaxVal(arr, readingscount);
    readingscount = getreadingscount(arr);	
    char RangeofSampleReadings[25];
    printf("%s", RangeofSampleReadings);
    printf("%d-%d, %d", MinValSample, MaxValSample, readingscount);
    return "RangeofSampleReadings";
  }

int getreadingscount(int arr[])
{
int readingscount = sizeof(arr)/sizeof(arr[0]);
return readingscount;
}
