#include "Utils.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>


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
    *(str + currentDigitIdx) = '\0';
}
void Mystrcat(char* s, char* t)
{
    int sLen = strlen(s);
    int tLen = strlen(t);

    for (int i = 0; i < tLen; i++) {
        *(s + sLen + i) = *(t + i);
    }
    *(s + sLen + tLen) = '\0';
}
int SumStr(char* str)
{
    int length = strlen(str);
    int previousNeighborNumber = 0;
    int sum = 0;
    for (int i = 0; i <= length; i++) {
        char currentChar = *(str + i);
        int currentDigit = currentChar - '0';

        if (currentDigit >= 0 && currentDigit <= 9) {
            previousNeighborNumber = (previousNeighborNumber * 10) + currentDigit;
        }
        else {
            sum += previousNeighborNumber;
            previousNeighborNumber = 0;
        }
        

    }
	return sum;
}
int Median(int* numbers, int size)
{
    int* sortedNumbers = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        int minNumber = INT_MAX;
        int minNumberIdx = -1;
        for (int j = 0; j < size; j++) {
            int currentNumber = *(numbers + j);
            if (currentNumber < minNumber) {
                minNumber = currentNumber;
                minNumberIdx = j;
            }
        }
        *(numbers + minNumberIdx) = INT_MAX;
        *(sortedNumbers + i) = minNumber;
    }
    return *(sortedNumbers + (size / 2));
}
int* CreateRange(int start, int end, int jump, int* sizeRage)
{
	return NULL;
}
char* PairArrays(char a[], char b[])
{
	return NULL;
}