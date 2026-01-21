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
    int possibleMedian = INT_MAX;
    for (int i = 0; i < size; i++) {
        int currentNumber = *(numbers + i);
        int amountNumbersSmallerOrEqual = 0;
        int amountNumbersBiggerOrEqual = 0;
        
        for (int j = 0; j < size; j++) {
            int otherNumber = *(numbers + j);
            if (currentNumber <= otherNumber) {
                amountNumbersBiggerOrEqual++;
            }
            if (currentNumber >= otherNumber) {
                amountNumbersSmallerOrEqual++;
            }
        }
        if (amountNumbersBiggerOrEqual >= (size / 2) && 
            amountNumbersSmallerOrEqual >= (size / 2) && 
            currentNumber < possibleMedian) {
            possibleMedian = currentNumber;
        }
    }
    return possibleMedian;
}
int* CreateRange(int start, int end, int jump, int* sizeRange)
{
    *(sizeRange) = ((end - start) / jump) + 1;
    int* range = malloc(*(sizeRange) * sizeof *range);
    if (range == NULL) {
        printf("error with malloc");
        return NULL;
    }

    for (int i = 0; i < *(sizeRange); i++) {
        *(range + i) = start + jump * i;
    }
	return range;
}
char* PairArrays(char a[], char b[])
{
    int aLen = strlen(a);
    int bLen = strlen(b);

    char* pairedArray = malloc((aLen + bLen + 1) * sizeof *pairedArray);
    if (pairedArray == NULL) {
        printf("error in malloc\n");
        return NULL;
    }

    int maxStrLen = aLen >= bLen ? aLen : bLen;

    int currentIdx = 0;
    for (int i = 0; i < maxStrLen; i++) {
        if (i < aLen) {
            *(pairedArray + currentIdx) = *(a + i);
            currentIdx++;
        }
        if (i < bLen) {
            *(pairedArray + currentIdx) = *(b + i);
            currentIdx++;
        }
    }
    *(pairedArray + currentIdx) = '\0';

	return pairedArray;
}