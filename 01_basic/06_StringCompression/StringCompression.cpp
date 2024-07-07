#include <iostream>
#include <cassert>
using namespace std;


void InsertionSort(char* arr, int size)
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

int main()
{
    /*
    #1
    - 어떤 알파벳에 몇 번 나오는지 출력
    - ex) aaabbccdddeeeff -> a3b2c2d3e3f2
    - 알파벳은 총 26 글자
    */
    // char arr[] = "ababcdfdceeefda";
    // char arr[] = "a";
    char arr[] = "ababcdfdceeefda";
    int size = sizeof(arr) - 1;

    // 글자는 하나 이상이라고 가정
    assert(size >= 1);

	cout << arr << endl;

    int  alpha[26] = { 0 };
    for (int i = 0; i < size; ++i)
        alpha[int(arr[i]) - 97]++;

    for (int i = 0; i < 26; ++i)
    {
        if (alpha[i] > 0)
            cout << char(i + 97) << alpha[i];
    }
    cout << endl;

    // 정렬 후 
    InsertionSort(arr, size);

	cout << arr << endl;

	char c = arr[0];
	int count = 1;

	for (int i = 1; i < size; i++)
	{
		if (arr[i] == c)
		{
			count++;
		}
		else
		{
            cout << c << count;
            c = arr[i];
            count = 1;
		}
	}

	cout << c << count << endl; // 마지막 count 출력

    return 0;
}