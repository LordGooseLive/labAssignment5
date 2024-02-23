//Arav Tulsi
//Dr. Neslisah Torosdagli
//COP3502C
//Lab Assignment 6

//Libraries
#include <stdio.h>
#include <stdlib.h> //added by student

//Student Implementation
int search(int numbers[], int low, int high, int value) // value index search (array, lowest index, highest index, search value)
{
	if (low > high) //invalid input or value absent
		return -1;

	int mid = (high + low)/2; //array midpoint

	if (numbers[mid] == value) //value found
		return (mid);
		//covers case (low == high)
	
	else if (numbers[mid] > value) //value smaller than midpoint
		return search (numbers, low, mid -1, value); //decrement midpoint to avoid reuse

	else if (numbers [mid] < value) //value larger than midpoint
		return search(numbers, mid +1 , high, value); //increment midpoint to avoid reuse
}

//Professor Provided code
void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void) //Driver code
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}