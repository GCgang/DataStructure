#include <iostream>
using namespace std;

struct Element
{
    int key;
    char value;
};

bool checkSorted(int* arr, int size)
{
    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}

void print(int* arr, int size)
{
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print(Element* arr, int size)
{
    for (int i = 0; i < size; ++i)
        cout << arr[i].key << " ";
    cout << endl;

    for (int i = 0; i < size; ++i)
        cout << arr[i].value << " ";
    cout << endl;
} 

int main()
{
    // int arr[] = { 5, 1, 4, 2, 8};
    // int arr[] = { 5, 4, 3, 2, 1}; // Worst Case
    int arr[] = { 1, 2, 3, 4, 5}; // Best Case
    int size = sizeof(arr) / sizeof(arr[0]);

    print(arr, size);
    cout << endl;

    // Bubble Sort
    // 인접한 두 원소를 비교하여 큰 값을 뒤로 옮기는 방식으로 구현
    {
        for (int i = 0; i < size - 1; ++i)
        {
            bool isSwapped = false;
            for (int j = 0; j < size - 1 - i; ++j)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    isSwapped = true;
                }
                print(arr, size);
            }
            cout << endl;
            if (isSwapped == false)
                break;
        }
    }
    // 안정성 확인 Stability
    // 키가 같은경우 value의 순서도 기존 순서와 같으므로 stable하다고 볼 수 있다
    {
        Element arr[] = { {2, 'a'}, {2, 'b'}, {1, 'c'} };
        int size = sizeof(arr) / sizeof(arr[0]);

        print(arr, size);

        for (int i = 0; i < size -1; ++i)
        {
            bool isSwapped = false;
            for (int j = 0; j < size - 1 - i; ++j)
            {
                if (arr[j].key > arr[j + 1].key)
                {
                    swap(arr[j], arr[j+1]);
                    isSwapped = true;
                }
            }
        }
        print(arr, size);
    }

    return 0;
}