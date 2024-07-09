#include <iostream>
#include <iomanip>

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

int RecurBinarySearch(int* arr, int left, int right, int x)
{
    if (left <= right)
    {
        int middle = (left + right) / 2;
        PrintHelper(arr, 10, left, right);

        if (x == arr[middle])
            return middle;
        if (x < arr[middle])
            return RecurBinarySearch(arr, left, middle - 1, x);
        else if (x > arr[middle])
            return RecurBinarySearch(arr, middle + 1, right, x);
    }
    cout << "Not Found" << endl;
    return -1;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << BinarySearch(arr, size, -10) << endl;
	cout << RecurBinarySearch(arr, 0, size - 1, -10) << endl;

    return 0;
}