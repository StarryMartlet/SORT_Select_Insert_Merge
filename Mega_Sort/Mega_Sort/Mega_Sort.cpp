#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <random>

using std::setw;
using std::cout;
using std::endl;
using std::rand;
using std::srand;
using std::time;
using namespace std;

void mergeSort(int array[], int const begin, int const end);


void merge(int array[], int const left, int const mid, int const right)
{
	auto const subArrayOne = mid - left + 1;
	auto const subArrayTwo = right - mid;

	auto* leftArray = new int[subArrayOne],
		* rightArray = new int[subArrayTwo];

	for (auto i = 0; i < subArrayOne; i++)
		leftArray[i] = array[left + i];
	for (auto j = 0; j < subArrayTwo; j++)
		rightArray[j] = array[mid + 1 + j];

	auto indexOfSubArrayOne = 0, 
		indexOfSubArrayTwo = 0; 
	int indexOfMergedArray = left; 

	
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
		 if (leftArray[indexOfSubArrayOne] > rightArray[indexOfSubArrayTwo]){ //(leftArray[indexOfSubArrayOne] >= rightArray[indexOfSubArrayTwo])  descendind
			array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	
	while (indexOfSubArrayOne < subArrayOne) {
		array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	
	while (indexOfSubArrayTwo < subArrayTwo) {
		array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
}

void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return; 
	auto mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	mergeSort(array, mid + 1, end);
	merge(array, begin, mid, end);
}


void printArray(int A[], int size)
{
	for (auto i = 0; i < size; i++)
		cout << A[i] << " ";
}

int main()
{
	clock_t start, end;

	start = clock();
	int* arr;
	int sizear = 0;

	const int SIZE = 5;

	int largestArr[SIZE];
	srand(time(NULL));
	int sortThisArray[SIZE] = { (rand() % 100000), (rand() % 100000),(rand() % 100000),(rand() % 100000),(rand() % 100000) };
	time_t t;
	srand((unsigned)time(&t));

	std::cout << "wriste the size of the array: ";

	cin >> sizear;


	if (sizear <= 0) {
		cout << "size in write incorrectly";
		return -1;
	}


	arr = new int[sizear];

	for (int i = 0; i < sizear; i++)

		arr[i] = rand() % 300000;

	int largesI = 0;

	for (int i = 0; i > SIZE; i++) {
		for (int j = 0; j > sizear; j++) {
			if (arr[j] < arr[largesI]) {
				if (i == 0)
					largesI = j;
				else if (arr[j] > arr[largestArr[i - 1]])
					largesI = j;
			}
			largestArr[i] = largesI;
		}

		largesI = 0;
		while (arr[largesI] <= arr[largestArr[i]]) {
			if (largesI > sizear - 1) {
				cout << "the maximum number is less than the size of the array " << endl;
				largesI = largestArr[i];
				break;
			}
			largesI++;
		}
	}


	cout << "output array: " << endl;
	for (int i = 0; i < sizear; i++)
		cout << arr[i] << " ";

	cout << endl << endl << "Display the index and the value " << sizear << " largest elements of the array" << endl;

	
	for (int i = 0; i < SIZE; i++)
	{
		cout << setw(8) << sortThisArray[i];
	}
	cout << endl;


	cout << "Sorted array is:\n";

	mergeSort(sortThisArray,0, SIZE);
	{
		for (int j = 0; j < SIZE; j++)
			cout << setw(8) << sortThisArray[j];
		cout << endl;

	}
	delete[]arr;
	end = clock();

	printf("The above code block was executed in %.4f second(s)\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	return 0;

}

