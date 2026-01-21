#include "Utils.h"

void Test1(char *str, int number, char* expected)
{
	printf("Test function ToString\n");
	ToString(str, number);

	if (strcmp(str, expected) != 0)
	{
		printf("Your Output is %s, Expected: %s (-3)\n", str, expected);
	}
}

void Test2(char *s1, char *s2, int s1Length, char *expected)
{
	printf("Test function Mystrcat\n");
	s1[s1Length] = 0;
	Mystrcat(s1, s2);

	if (strcmp(s1, expected) != 0)
	{
		printf("Your Output is %s, Expected: %s (-6)\n", s1, expected);
	}
}

void Test3(char *arr, int sum)
{
	printf("Test function SumStr\n");
	int tempSum = SumStr(arr);
	if (tempSum != sum)
	{
		printf("Your Output is %d, Expected: %d (-3)\n", tempSum, sum);
	}
}

void Test4(int *arr, int size, int mid)
{
	printf("Test function Median\n");
	int tMid = Median(arr, size);

	if (mid != tMid)
	{
		printf("Your Output is %d, Expected: %d (-4)\n", tMid, mid);
	}
}

void Test5(int start, int end, int jump, int wantedSize)
{
	printf("Test function CreateRange\n");
	int size;
	int* tempResult = CreateRange(start, end, jump, &size);

	if (tempResult == NULL)
	{
		printf("Can't allocate arr (-4)\n");
		return;
	}
	if (size != wantedSize)
	{
		printf("Your Output Size is %d, Expected Size : %d (-4)\n", size, wantedSize);
		return;
	}

	for (int i = 0; i < size; i++)
	{
		if (tempResult[i] != start + i*jump)
		{
			printf("Your Output In index %d is %d, Expected Output : %d (-4)\n", i, tempResult[i], start + i*jump);
			return;
		}
	}
}

void Test6(char *a, char *b, char *result)
{
	printf("Test function PairArrays\n");
	char* tempString = PairArrays(a, b);

	if (tempString == NULL)
	{
		printf("Can't allocate arr (-4)\n");
		return;
	}

	if (strcmp(tempString, result) != 0)
	{
		printf("Your Output is %s, Expected: %s (-4)\n", tempString, result);
	}
}
int main(){

	char s[MAX_SIZE] = { 0 };
	Test1(s, 111, "111");
	Test1(s, 59755, "59755");
	Test1(s, 001, "1");
	Test1(s, 100, "100");
	Test1(s, 1234, "1234");
	// 15 Points

	char s1[] = "abc    ";
	Test2(s1, "cde", 3, "abccde");
	char s2[] = "I Love     ";
	Test2(s2, "You", 7, "I Love You");
	char s3[] = "1234     ";
	Test2(s3, "5678", 4, "12345678");
	//18 Points

	Test3("ax3b5mt11f", 19);
	Test3("5$5$5", 15);
	Test3("1234", 1234);
	Test3("1$0!100", 101);
	Test3("1$1!1", 3);
	// 15 Points

	int a[] = { 1,1,1,1,1,1,1,1,1,1 };
	Test4(a, 10, 1);
	int b[] = { 1,2,1,2,1,2,2,2,1, 2 };
	Test4(b, 10, 2);
	int c[] = { -1,0,-1,0, -1,0,0,0,0,0 };
	Test4(c, 10, 0);
	// 12 Points

	Test5(1, 10, 1, 10);
	Test5(1, 10, 2, 5);
	Test5(2, 10, 2, 5);
	Test5(-1, 10, 3, 4);
	Test5(1, 10, 11, 1);
	// 20 Points

	Test6("135", "246", "123456");
	Test6("Hlo", "el", "Hello");
	Test6("I", " Love You", "I Love You");
	Test6("abc", "d", "adbc");
	Test6("11", "2", "121");
	// 20 Points

	printf("done");
	return 0;
}
