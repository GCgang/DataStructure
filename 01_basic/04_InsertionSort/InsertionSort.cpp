#include <iostream>

using namespace std;


struct Element
{
    int key;
    char value;
};

bool CheckSorted(int* arr, int size)
{
    for (int i = 0; i < size - 1; ++i) {
        if (arr[i] > arr[i + 1])
            return false;
    }
    return true;
}

void Print(int* arr, int size)
{
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Print(Element* arr, int size)
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
    // 오른쪽으로 하나씩 밀기
    {
        int arr[] = {1, 2, 4, 5, 3, 6};
        int size = sizeof(arr) / sizeof(arr[0]);

        Print(arr, size);

        int key = arr[4];
        for (int i = 4; i > 0; --i)
        {
            if (arr[i - 1] <= key)
                break;
            arr[i] = arr[i - 1]; 
            Print(arr, size);
        }
    }
    // Insertion Sort
    // 정렬이 된 배열에 새로운 값을 적당한 위치에 삽입하며 정렬하는 방식
    {
        //int arr[] = { 8, 3, 2, 5, 1, 2 };
        int arr[] = { 6, 5, 4, 3, 2, 1 }; // Worst
        //int arr[] = { 1, 2, 3, 4, 5, 6 }; // Best
        int size = sizeof(arr) / sizeof(arr[0]);

        for (int i = 1; i < size; ++i)
        {
            int j = i;
            int key = arr[i];
            // for 구현
            for (; j > 0; --j)
            {
                if (arr[j - 1] <= key)
                    break;
                arr[j] = arr[j - 1];
                Print(arr, size);
            }
            arr[j] = key;

            // while 구현
            // while (i > 0 && arr[j - 1] > key)
            // {
            //     arr[j] = arr[j - 1];
            //     Print(arr, size);
            //     --j;
            // }
            // arr[j] = key;
        }
        Print(arr, size);
    }
    return 0;
}