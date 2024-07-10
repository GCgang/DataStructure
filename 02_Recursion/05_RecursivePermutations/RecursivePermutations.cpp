#include <iostream>
#include <algorithm>

using namespace std;

void RecurPermutations(char* arr, int left, int right) // abc  0 2 abc  1 2  acb  2 2 acb  abc  
{
	// arr[left], ..., arr[right]

    if (left == right)
    {
        for (int i = 0; i <= right; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }
    else
    {
        for (int i = left; i <= right; ++i)
		{
			swap(arr[left], arr[i]);

			RecurPermutations(arr, left + 1, right);

			swap(arr[left], arr[i]);
		}
    }

}

int main()
{
	/* a 한 글자의 순열 (Permutations)

		a
	*/

	/* ab 두 글자의 순열 (Permutations)

		a b
		b a
	*/

	/*  abc 3 글자의 순열 (Permutations)

		a b c
		a c b
		b a c
		b c a
		c b a
		c a b
	*/

	// Permutations
	char arr[] = "abcd";

	RecurPermutations(arr, 0, 0);
	cout << endl;

    RecurPermutations(arr, 0, 1);
	cout << endl;

	RecurPermutations(arr, 0, 2);
	cout << endl;

    RecurPermutations(arr, 0, 3);
	cout << endl;

    return 0;
}