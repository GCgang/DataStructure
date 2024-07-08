#include <iostream>
#include <cassert>

using namespace std;

int Sum(int* arr, int size)
{
    int sum = 0;
    
    for (int i = 0; i < size; ++i)
    {
        sum += arr[i];
    }

    return sum;
}

int RecurSum(int* arr, int size)
{
    if (size <= 0) 
        return 0;
    else
        return RecurSum(arr, size - 1) + arr[size - 1];
}


int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int size = sizeof(arr) / sizeof(arr[0]);
    assert(size > 0);

    cout << Sum(arr, size) << endl;
    cout << RecurSum(arr, size) << endl; 
    return 0;
}