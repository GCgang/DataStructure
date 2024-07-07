#include <iostream>
#include <cassert>

using namespace std;

// 배열 arr에 x가 몇 번 나오는지 반환
int Count(int* arr, int size, int x);

// 배열 arr에 x가 있으면 index, 없으면 -1 반환
int SequentialSearch(int* arr, int size, int x); // Linear Search

// 정렬된 배열에서 x가 몇 번 나오는지 반환
int SortedCount(int* arr, int size, int x);
int SortedCountHelper(int* arr, int size, int x, int start);

// 정렬할 때 사용
void InsertionSort(int* arr, int size);

void Print(int* arr, int size);

int main()
{
    int arr[] = { 8, 1, 1, 3, 2, 5, 1, 2, 1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Count 9 = " << Count(arr, size, 9) << endl;
	cout << "Count 2 = " << Count(arr, size, 2) << endl;
	cout << "Count 8 = " << Count(arr, size, 8) << endl;
	cout << "Count 1 = " << Count(arr, size, 1) << endl;
	cout << endl;

	cout << "Search 2 = " << SequentialSearch(arr, size, 2) << endl;
	cout << "Search 5 = " << SequentialSearch(arr, size, 5) << endl;
	cout << "Search 9 = " << SequentialSearch(arr, size, 9) << endl;
	cout << endl;

	InsertionSort(arr, size);

	Print(arr, size);

	cout << "Sorted Count 9 = " << SortedCount(arr, size, 9) << endl;
	cout << "Sorted Count 2 = " << SortedCount(arr, size, 2) << endl;
	cout << "Sorted Count 8 = " << SortedCount(arr, size, 8) << endl;
	cout << "Sorted Count 1 = " << SortedCount(arr, size, 1) << endl;
	cout << endl;

    return 0;
}
int Count(int* arr, int size, int x)
{
    int cnt = 0;
    for (int i = 0; i < size; ++i)
        if (arr[i] == x)
            cnt++;
    return cnt;
}

int SequentialSearch(int* arr, int size, int x)
{
    for (int i = 0; i < size; ++i)
        if (arr[i] == x)
            return i;
    return -1;

    // Horowitz 교재
    // int i;
    // for (i = 0; i < size && arr[i] != x; ++i) { /* Do Nothing */};
    // if (i == size) return -1;
    // else return i;
}

int SortedCount(int* arr, int size, int x)
{
    int i = SequentialSearch(arr, size, x);

    if (i >= 0)
        return SortedCountHelper(arr, size, x, i + 1) + 1;
    else
        return 0;
}

int SortedCountHelper(int* arr, int size, int x, int start)
{
    int cnt = 0;
    for (int i = start; i < size; ++i)
        if (arr[i] == x)
            cnt++;
        else
            break;

    return cnt;
}

void InsertionSort(int* arr, int size)
{
    for (int i = 1; i < size; ++i)
    {
        int j = i;
        int key = arr[i];

        while (i > 0 && arr[j - 1] > key)
        {
            arr[j] = arr[j - 1]; 
            --j;
        }
        arr[j] = key;
    }
}

void Print(int* arr, int size)
{
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}