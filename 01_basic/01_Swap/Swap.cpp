#include <iostream>
#include <algorithm>
using namespace std;

// 포인터로 만들기
void MySwapPtr (int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// 레퍼런스로 만들기
void MySwapRef (int& a, int&b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

bool CheckSorted (int a, int b)
{
    return (a <= b ? true : false);
}

int main() 
{
    // Swap
    {
        int a = 3;
        int b = 2;
        int tmp;

        tmp = a;
        a = b;
        b = tmp;
        cout << "a: " << a << " " << "b: " << b << endl; // a: 2 b: 3

        MySwapPtr(&a, &b);
        cout << "a: " << a << " " << "b: " << b << endl; // a: 3 b: 2

        MySwapRef(a, b);
        cout << "a: " << a << " " << "b: " << b << endl; // a: 2 b: 3
    }

    // 정렬(Sorting)
    {
        int arr[] = { 3, 2 };
        int n = sizeof(arr) / sizeof(arr[0]);

        sort(arr, arr + n);
        for (auto i : arr) {
            cout << i << endl; // 2, 3
        }

        if (arr[0] > arr[1])
            MySwapRef(arr[0], arr[1]);
        cout << arr[0] << " " << arr[1] << endl; // 2 3
    }

    {
        int arr[2];
        for (int j = 0; j < 5; ++j) {
            for (int i = 0; i < 5; ++i) {
                arr[0] = i;
                arr[1] = j;

                // swap 사용
                if (arr[0] > arr[1]) {
                    swap(arr[0], arr[1]);
                }
                cout << boolalpha;
                cout << arr[0] << " " << arr[1] << " "
                << CheckSorted(arr[0], arr[1]) << endl;
            }
        }
    }

    return 0;
}