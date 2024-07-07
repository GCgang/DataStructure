#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cassert>

using namespace std;

void PrintHelper(int* arr, int size, int left, int right)
{
	cout << "[" << left << "," << right << "]" << endl;

	cout << "Indices: ";
	for (int i = left; i <= right; i++)
		cout << setw(2) << i << " ";
	cout << endl;

	cout << "Values : " << setw(2);
	for (int i = left; i <= right; i++)
		cout << setw(2) << arr[i] << " ";
	cout << endl;
}

int BinarySearch(int* arr, int size, int x)
{
    int left = 0;
    int right = size - 1;

    while(left <= right)
    {
        PrintHelper(arr, size, left, right);
        int middle = (left + right) / 2;

        if (x == arr[middle])
            return middle; // found
        else if (x < arr[middle])
            right = middle - 1;
        else if (x > arr[middle])
            left = middle + 1;
    }
    cout << "Not Found" << endl;
    return -1; // not found
}

int main()
{
    int arr[] = {0 ,1 ,2 ,3, 4, 5, 6, 7, 8, 9};
    // int arr[] = { 14, 100, 28, 2, 4, 5, 7, 132124, 5, 6, 8, 9, 10, 12, 13 };
    int size = sizeof(arr) / sizeof(arr[0]);

    assert(size > 0);
    sort(&arr[0], &arr[size]);

    BinarySearch(arr, size, 10);

    return 0;
}