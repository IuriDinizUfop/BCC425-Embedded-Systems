// ****************** Lab2.c ***************
// Programa escrito por : <Coloque os nomes dos alunos da dupla>
// Date Created: 1/18/2017 
// Last Modified: 1/17/2021 
// Coloque os nomes dos alunos e matriculas
char Name[] = "Raphael Iannini Dutra dos Santos & Iuri da Silva Diniz"; // nomes
char EID[] = "XX.X.XXXX & XX.X.XXXX"; // matriculas

// Brief description of the Lab: 
// An embedded system is capturing temperature data from a
// sensor and performing analysis on the captured data.
// The controller part of the system is periodically capturing size
// readings of the temperature sensor. Your task is to write three
// analysis routines to help the controller perform its function
//   The three analysis subroutines are:
//    1. Calculate the mean of the temperature readings 
//       rounded down to the nearest integer
//    2. Convert from Centigrate to Farenheit using integer math 
//    3. Check if the captured readings are a non-increasing monotonic series
//       This simply means that the readings are sorted in non-increasing order.
//       We do not say "decreasing" because it is possible for consecutive values
//       to be the same, hence the term "non-increasing". The controller performs 
//       some remedial operation and the desired effect of the operation is to 
//       raise the the temperature of the sensed system. This routine helps 
//       verify whether this has indeed happened
#include <stdint.h>
#include <stdio.h>
#define True 1
#define False 0

// Return the computed Mean
// Inputs: Data is an array of 16-bit unsigned distance measurements
//         N is the number of elements in the array
// Output: Average of the data
// Notes: you do not need to implement rounding
uint16_t Average(const uint16_t Data[],const uint32_t N){
	int mean =0;
	if (Data[0]!=NULL)
		{		
			int sum=0;
			for(int i=0; i<N; i++){
				sum+= Data[i];
    }
				mean = (sum/N);
		}
	return mean;
}

// Convert temperature in Farenheit to temperature in Centigrade
// Inputs: temperature in Farenheit 
// Output: temperature in Centigrade
// Notes: you do not need to implement rounding
int16_t FtoC(int16_t const TinF){
	int TinC;
	//conversao
	float Conta = (float)((TinF-32)*5)/9;
	int ContaInt = Conta;
  float trunca = (Conta - ContaInt);
	if ( trunca > 0.5) //realizando a trunca
		TinC = ContaInt + 1;
	else
		TinC = ContaInt;
		
	return TinC;
}

// Return True of False based on whether the readings
// are an increasing monotonic series
// Inputs: Readings is an array of 16-bit distance measurements
//         N is the number of elements in the array
// Output: true if monotonic increasing, false if nonmonotonic
int IsMonotonic(uint16_t const Data[], int32_t const N){

	int flag;
	int j=1;
	if (N>1)
	{
		for (int i=0;i<N-1;i++)
		{
			if (Data[i]<=Data[j])
					flag = 1;
				else	{
								flag =0;
								break;
							}
				j++;
		}					
	}else
		flag=1;
	
	if (flag == 1)
		return True;
	else
		return False;	
}


