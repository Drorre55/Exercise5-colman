#include "Utils.h"
#include <math.h>


void ToString(char* str, int number)
{
    int numberCopy = number;
    int amountOfDigits = 0;
    while (numberCopy > 0) {
        numberCopy /= 10;
        amountOfDigits++;
    }

    int currentDigitIdx = 0;
    for (int i = amountOfDigits - 1; i >= 0; i--) {
        int currentDigit = number / (int)(pow(10, i) + 0.1);
        *(str + currentDigitIdx) = currentDigit + '0';
        number %= (int)(pow(10, i) + 0.1);
        currentDigitIdx++;
    }
}
void Mystrcat(char* s, char* t)
{
}
int SumStr(char* str)
{
	return 0;
}
int Median(int* numbers, int size)
{
	return 0;
}
int* CreateRange(int start, int end, int jump, int* sizeRage)
{
	return NULL;
}
char* PairArrays(char a[], char b[])
{
	return NULL;
}