#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

using std::setw;
using std::cout;
using std::endl;
using std::rand;
using std::srand;
using std::time;

void insertionSort(int array[], int size);

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

	for (int i = 0; i < SIZE; i++) {         
		for (int j = 0; j < sizear; j++) {              
			if (arr[j] > arr[largesI]) {                    
				if (i == 0)                               
					largesI = j;
				else if (arr[j] < arr[largestArr[i - 1]]) 
					largesI = j;
			}
			largestArr[i] = largesI;                  
		}

		largesI = 0;
		while (arr[largesI] >= arr[largestArr[i]]) {
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
	
	insertionSort(sortThisArray, SIZE);
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
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void insertionSort(int array[], int size) {
    for (int step = 1; step < size; step++) {
        int key = array[step];
        int j = step - 1;

       
        while (key < array[j] && j >= 0) { //(key >  array[j] && j >= 0) descending
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

