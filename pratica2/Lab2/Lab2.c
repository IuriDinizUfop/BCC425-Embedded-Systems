// ****************** Lab2.c ***************
// Programa escrito por : <Coloque os nomes dos alunos da dupla>
// Date Created: 1/18/2017 
// Last Modified: 1/17/2021 
// Coloque os nomes dos alunos e matriculas
char Name[] = "Iuri da Silva Diniz & Raphael Iannini Dutra"; // nomes
char EID[] = "16.1.1521 & "; // matriculas

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
#define True 1
#define False 0

// Return the computed Mean
// Inputs: Data is an array of 16-bit unsigned distance measurements
//         N is the number of elements in the array
// Output: Average of the data
// Notes: you do not need to implement rounding
uint16_t Average(const uint16_t Data[],const uint32_t N){
// Replace this following line with your solution
  
    return 42;
}

// Convert temperature in Farenheit to temperature in Centigrade
// Inputs: temperature in Farenheit 
// Output: temperature in Centigrade
// Notes: you do not need to implement rounding
int16_t FtoC(int16_t const TinF){
// Replace this following line with your solution
  
  return 42;
}

// Return True of False based on whether the readings
// are an increasing monotonic series
// Inputs: Readings is an array of 16-bit distance measurements
//         N is the number of elements in the array
// Output: true if monotonic increasing, false if nonmonotonic
int IsMonotonic(uint16_t const Data[], int32_t const N){
// Replace this following line with your solution
  
   return 42;
}


