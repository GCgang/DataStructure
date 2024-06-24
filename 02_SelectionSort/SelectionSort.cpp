#include <iostream>
#include <cassert>
#include <algorithm>
using namespace std;

bool CheckSorted(int* arr, int size)
{
    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
	return true;
}

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	// 3개 정렬
	{
        for (int k = 0; k < 3; ++k)
            for (int j = 0; j < 3; ++j)
                for (int i = 0; i < 3; ++i) {

                    int arr[3] = {i, j, k};
                    int size = sizeof(arr) / sizeof(arr[0]);

                    for (int e = 0; e < size; ++e) {
                        cout << arr[e] << " " << flush;
                    }

                    cout << " -> " << flush;

                    // TODO: 정렬 하기
                    if (arr[0] > arr[1]) {
                        swap(arr[0], arr[1]);
                    }
                    if (arr[1] > arr[2]) {
                        swap(arr[1], arr[2]);
                    }
                    if (arr[0] > arr[1]) {
                        swap(arr[0], arr[1]);
                    }
                    
                    for (int e = 0; e < size; ++e) {
                        cout << arr[e] << " " << flush;
                    }

                    cout << boolalpha;
                    cout << CheckSorted(arr, size);
                    cout << endl;
                }
	}

	// 가장 작은 수 찾기
	{
		int arr[] = { 8, 3, 2, 5, 1, 1, 2, 5, 8, 9 }; // 임의의 숫자들, 변경 가능
		int size = sizeof(arr) / sizeof(arr[0]);

		assert(size > 0); // size가 1이상이라고 가정
        int minNumber = arr[0];

        for (int i = 0; i < size; ++i) {
            minNumber = arr[i] < minNumber ? arr[i] : minNumber;
            // minNumber = min(arr[i], minNumber);
        }
		cout << "Minimum number is " << minNumber << endl;
	}

	// 가장 작은 수의 인덱스 찾기
	{
		int arr[] = { 8, 3, 2, 5, 1, 1, 2, 5, 8, 9 };
		int size = sizeof(arr) / sizeof(arr[0]);

		assert(size > 0); // size가 1이상이라고 가정
        int minIndex = 0;

        for (int i = 0; i < size; ++i) {
            minIndex = arr[i] < arr[minIndex] ? i : minIndex;
        }
		cout << "The index of min is " << minIndex << endl;
		cout << "Minimum number is " << arr[minIndex] << endl;
	}

	// Selection Sort
	{
		int arr[] = { 8, 3, 2, 5, 1, 1, 2, 5, 8, 9 };
		int size = sizeof(arr) / sizeof(arr[0]);

		for (int i = 0; i < size - 1; ++i)
		{
            int minIndex = i;
            for (int j = i + 1; j < size; ++j) {
                minIndex = arr[minIndex] < arr[j] ? minIndex : j;
            }
            swap(arr[i], arr[minIndex]);
		}
        Print(arr, size);
        cout << boolalpha;
        cout << CheckSorted(arr, size);
        cout << endl;
    }
	return 0;
}
