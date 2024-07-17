#pragma once

#include <cassert>
#include <iostream>
#include <iomanip>
#include <cstring>

template<typename T>
class Queue // Circular Qeueue
{
    public:
        Queue(int capacity = 2)
            : mCapacity(capacity)
            , mFront(0)
            , mRear(0)

        {
            assert(capacity > 0);
            mQueue = new T[mCapacity];
        }

        ~Queue()
        {
            if(mQueue) delete[] mQueue;
        }

        bool IsEmpty() const
        {
            return mFront == mRear;
        }

        bool IsFull() const
        {
            return (mRear + 1) % mCapacity == mFront;
        }

        T& Front() const
        {
            assert(!IsEmpty());

            return mQueue[(mFront + 1) % mCapacity];
        }

        T& Rear() const
        {
            assert(!IsEmpty());

            return mQueue[mRear];
        }

        int Size() const
        {
            if (mFront < mRear)
                return mRear - mFront;
            else if (mFront > mRear)
                return mCapacity - (mFront - mRear);
            else
                return 0;

            // if else 2가지 경우
            // if (mFront > mRear)
            //     return mCapacity - (mFront - mRear);
            // else
            //     return mRear - mFront; // rear와 front가 같으면 0
        }

        void Resize()
        {
            T* newQueue = new T[mCapacity * 2];
            // 반복문 구현
            int cnt = 1;
            for (int i = (mFront + 1) % mCapacity; i != (mRear + 1) % mCapacity; i = (i + 1) % mCapacity)
            {
                newQueue[cnt++] = mQueue[i];
            }
            mFront = 0;
            mRear = mCapacity - 1;
            mCapacity *= 2;
            delete[] mQueue;
            mQueue = newQueue;

            // memcpy 구현
            // if (mFront < mRear)
            // {
            //     memcpy(&newQueue[1], &mQueue[mFront + 1], sizeof(T) * (mRear - mFront));
            // }
            // else // mFront > mRear
            // {
            //     memcpy(&newQueue[1], &mQueue[mFront + 1], sizeof(T) * (mCapacity - mFront - 1));
            //     memcpy(&newQueue[mCapacity - mFront], mQueue, sizeof(T) * (mRear + 1));
            // }
            // mFront = 0;
            // mRear = mCapacity - 1;
            // mCapacity *= 2;
            // delete[] mQueue;
            // mQueue = newQueue;

            // Horowitz 교재 (newQueue에서 데이터를 앞에 한 칸 비우지 않고 채우는 방식)
            // int start = (mFront + 1) % mCapacity;
            // if (start < 2)
            // {
            //     memcpy(newQueue, mQueue + start, sizeof(T) * (mCapacity - 1));
            // }
            // else
            // {
            //     memcpy(newQueue, mQueue + start, sizeof(T) * (mCapacity - start));
            //     memcpy(newQueue + mCapacity - start, mQueue, sizeof(T) * (mRear + 1));
            // }
            // mFront = 2 * mCapacity - 1; // 새 크기의 마지막
            // mRear = mCapacity - 2;
            // mCapacity *= 2;
            // delete[] mQueue;
            // mQueue = newQueue;
        }

        void Enqueue(const T& item) // 맨뒤에 추가, Push()
        {
            if (IsFull())
                Resize();
            mRear = (mRear + 1) % mCapacity;
            mQueue[mRear] = item;
        }

        void Dequeue() // Queue 첫 요소 삭제, Pop()
        {
            assert(!IsEmpty());
            mFront = (mFront + 1) % mCapacity;

            // mQueue[mFront].T(); // 필요한 경우 소멸자 호춣
        }

        void Print()
        {
            using namespace std;

            for (int i = (mFront + 1) % mCapacity; i != (mRear + 1) % mCapacity; i = (i + 1) % mCapacity)
                cout << mQueue[i] << " ";
            cout << endl;

            if (mPrintDebug)
                PrintDebug();
        }

        void PrintDebug()
        {
            using namespace std;

            cout << "Cap = " << mCapacity << ", Size = " << Size();
            cout << endl;

            // front와 rear 위치 표시
            for (int i = 0; i < mCapacity; i++) {
                if (i == mFront) cout << " F ";
                else if (i == mRear) cout << " R ";
                else cout << "   ";
            }
            cout << endl;

            // 0 based index
            for (int i = 0; i < mCapacity; i++)
                cout << setw(2) << i << " ";
            cout << endl;

            if (mFront < mRear)
            {
                // front 앞 사용하지 않은 공간
                for (int i = 0; i < mFront + 1; i++)
                    cout << " - ";

                // 저장된 내용물
                for (int i = mFront + 1; i <= mRear; i++)
                    cout << setw(2) << mQueue[i] << " ";

                // rear 뒤 사용하지 않은 공간
                for (int i = mRear + 1; i < mCapacity; i++)
                    cout << " * ";

                cout << endl << endl;
            }
            else if (mFront > mRear)
            {
                // rear 이전에 저장된 내용물
                for (int i = 0; i <= mRear; i++)
                    cout << setw(2) << mQueue[i] << " ";

                // rear와 front 사이 사용하지 않은 공간
                for (int i = mRear + 1; i <= mFront; i++)
                    cout << " * ";

                // front 뒤 내용물
                for (int i = mFront + 1; i < mCapacity; i++)
                    cout << setw(2) << mQueue[i] << " ";

                cout << endl << endl;
            }
            else // 비었을 경우
            {
                for (int i = 0; i < mCapacity; i++)
                    cout << " - ";
                cout << endl << endl;
            }
        }

        void SetDebugFlag(bool flag)
        {
            mPrintDebug = flag;
        }

    protected:
        T* mQueue;
        int mFront = 0;
        int mRear = 0;
        int mCapacity;
        bool mPrintDebug = false;
};