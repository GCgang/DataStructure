#pragma once

#include <cassert>
#include <stdint.h>

template<typename T>
class SinglyLinkedList
{
    public:
        struct Node
        {
            T item = T();
            Node* next = nullptr;
        };

        SinglyLinkedList()
        {
        }

        SinglyLinkedList(const SinglyLinkedList& list)
        {
            Node* current = list.mFirst;
            while(current != nullptr)
            {
                this->PushBack(current->item);
                current = current->next;
            }
        }

        ~SinglyLinkedList()
        {
            Clear();
        }

        void Clear()
        {
            while (mFirst != nullptr)
            {
                PopFront();
            }
        }

        bool IsEmpty()
        {
            return mFirst == nullptr;
        }

        int Size()
        {
            int size = 0;
            Node* current = mFirst;
            while (current != nullptr)
            {
                current = current->next;
                size++;
            }
            return size;
        }

        T Front()
        {
            assert(mFirst);
            return mFirst->item;
        }

        T Back()
        {
            assert(mFirst);
            Node* current = mFirst;
            while (current->next != nullptr)
                current = current->next;
            return current->item;
        }

        Node* Find(T item)
        {
            Node* current = mFirst;
            while (current != nullptr)
            {
                if (current->item == item)
                    return current;
                current = current->next;
            }
            return current;  // nullptr
        }

        void InsertBack(Node* node, T item)
        {
            Node* temp = new Node;
            temp->item = item;
            temp->next = node->next;
            node->next = temp;
        }

        void Remove(Node* n)
        {
            assert(mFirst);
            if (mFirst == n)
            {
                mFirst = mFirst->next;
                delete n;
                return ;
            }
            Node* prev = mFirst;
            while (prev->next != nullptr)
            {
                if (prev->next == n)
                    break;
                prev = prev->next;
            }
            prev->next = n->next;
            delete n; 
        }

        void PushFront(T item)
        {
            Node* newNode = new Node;
            newNode->item = item;

            newNode->next = mFirst ;
            mFirst = newNode;
        }

        void PushBack(T item)
        {       
            Node* newNode = new Node;
            newNode->item = item;
            if (mFirst)
            {
                Node* current = mFirst;
                while (current->next != nullptr)
                    current = current->next;
                current->next = newNode;
                newNode->next = nullptr;
            }
            else
            {
                mFirst = newNode;
                newNode->next = nullptr;
            }
        }

        void PopFront()
        {
            if (IsEmpty())
            {
                using namespace std;
                cout << "Nothing to Pop is PopFront()" << endl;
                return ;
            }
            assert(mFirst);
            Node* temp = mFirst;
            mFirst = mFirst->next;
            delete temp;
        }

        void PopBack()
        {
            if (IsEmpty())
            {
                using namespace std;
                cout << "Nothing to Pop in PopBack()" << endl;
                return; 
            }
            assert(mFirst);
            if (mFirst->next == nullptr)
            {
                delete mFirst;
                mFirst = nullptr;
                return ;
            }
            Node* secondLast = mFirst;
            while (secondLast->next->next != nullptr)
                secondLast = secondLast->next;
            Node* temp = secondLast->next;
            secondLast->next = secondLast->next->next;
            delete temp;
        }

        void Reverse()
        {
            Node* current = mFirst;
            Node* prev = nullptr;

            while (current != nullptr)
            {
                Node* temp = prev;
                prev = current;
                current = current->next;
                prev->next = temp;
            }
            mFirst = prev;
        }

        void SetPrintDebug(bool flag)
        {
            mPrintDebug = flag;
        }

        void Print()
        {
            using namespace std;

            Node* current = mFirst;

            if (IsEmpty())
                cout << "Empty" << endl;
            else
            {
                cout << "Size = " << Size() << " ";

                while (current)
                {
                    if (mPrintDebug)
                    {
                        //cout << "[" << current << ", " << current->item << ", " << current->next << "]";

                        // 주소를 짧은 정수로 출력 (앞 부분은 대부분 동일하기때문에 뒷부분만 출력)
                        cout << "[" << reinterpret_cast<uintptr_t>(current) % 100000 << ", "
                            << current->item << ", "
                            << reinterpret_cast<uintptr_t>(current->next) % 100000 << "]";
                    }
                    else
                    {
                        cout << current->item;
                    }
                    if (current->next)
                        cout << " -> ";
                    else
                        cout << " -> NULL";
                    current = current->next;
                }
                cout << endl;
            }
        }
    protected:
        Node* mFirst = nullptr;
        bool mPrintDebug = false;
};