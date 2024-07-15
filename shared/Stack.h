#pragma once

#include <cassert>
#include <iostream>

template<typename T> // 템플릿 사용
class Stack
{
    public:
        Stack(int capacity = 1)
        {
            assert(capacity > 0);
            Resize(capacity);
        }

        ~Stack()
        {
            if (mStack) delete[] mStack;
        }

        void Resize(int newCapacity)
        {
            T* newStack = new T[newCapacity];
            memcpy(newStack, mStack, sizeof(T) * Size());
            if (mStack) delete[] mStack;
            mStack = newStack;
            mCapacity = newCapacity;
        }

        bool IsEmpty() const
        {
            return mTop == -1;
        }

        int Size() const
        {
            return mTop + 1;
        }

        void Print()
        {
            using namespace std;

            for (int i = 0; i < Size(); i++)
                cout << mStack[i] << " ";
            cout << endl;
        }

        // Returns TOP element of stack.
        T& Top() const
        {
            assert(!IsEmpty());

            return mStack[mTop];
        }

        // Insert item into the TOP of the stack
        void Push(const T& item)
        {
            if (mCapacity <= Size()) Resize(mCapacity * 2);
            mStack[++mTop] = item;
        }

        // Delete the TOP element of the stack
        void Pop()
        {
            assert(!IsEmpty());

            mTop--;
            // mStack[mTop--].~T(); // 소멸자를 수동으로 호출
        }

    protected: // 뒤에서 상속해서 사용
        T* mStack = nullptr;
        int mTop = -1; // 0 아님
        int mCapacity = 0;
};