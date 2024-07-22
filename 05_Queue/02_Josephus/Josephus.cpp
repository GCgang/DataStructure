#include "../../shared/Queue.h"
#include <iostream>

using namespace std;

/*
N 명의 사람들이 한 줄로 서서 처형(execution)을 기다리고 있다. 특별한 규칙을 따라서 한 명씩 처형되는데 마지막까지 남는 사람 1명은 살려준다.

처음의 K - 1 명은 처형시키지 않고 다시 맨 뒤로 보낸다. 
그리고 K 번째 한 사람은 처형을 시킨다. 
이 과정을 마지막 1 명이 남을때까지 반복한다.
*/
int main()
{
	int n = 7, k = 3; // set n and k to the desired values

	Queue<int> q(n + 1);
	q.SetDebugFlag(false);

	// 처음에 n명 추가 (1, 2, ..., n)
	for (int i = 1; i <= n; i++)
		q.Enqueue(i);
	q.Print();

	// 마지막 한 명이 남을 때까지 반복
    while(q.Size() != 1)
	{
		// k-1 명은 맨 앞에서 뒤로 보내기
        int front = 0;
        for(int i = 0; i < k -  1; ++i) {
            front = q.Front();
            q.Dequeue();
            q.Enqueue(front);
        }

        q.Print();
		cout << "Executed " << q.Front() << endl;
		// k 번째 사람 처형
        q.Dequeue();
        q.Print(); // 남은 사람들

	}

	// 최후의 생존자 번호
	cout << "Survivor: " << q.Front() << endl;
	cout << "Survivor: " << q.Rear() << endl;
    return 0;
}