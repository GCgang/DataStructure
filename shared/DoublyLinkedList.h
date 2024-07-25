#pragma once

#include <cassert>
#include <stdint.h>
#include <algorithm>

template<typename T>
class DoublyLinkedList
{
    public:
        struct Node
        {
            T item = T();
            Node* left = nullptr;
            Node* right = nullptr;
        };

        DoublyLinkedList()
        {
        }

        DoublyLinkedList(const DoublyLinkedList& list)        
        {
            Node* current = list.mFirst;
            while (current != nullptr)
            {
                this->PushBack(current->item);
                current = current->right;
            }
        }

        ~DoublyLinkedList()
        {
            Clear();
        }

        void Clear()
        {
            while(mFirst)
                PopFront();
        }

        bool IsEmpty()
        {
            return mFirst == nullptr;
        }

        int Size()
        {
            int size = 0;
            Node* current = mFirst;

            while(current != nullptr)
            {
                current = current->right;
                size++;
            }
            return size;
        }

        void Print()
        {
            using namespace std;

            Node* current = mFirst;

            if (IsEmpty())
                cout << "Empty" << endl;
            else
            {
                cout << "Size = " << Size() << endl;

                cout << " Forward: ";
                while(true)
                {
                    cout << current->item << " ";

                    if (!current->right)
                        break;

                    current = current->right;
                }
                cout << endl;

                cout << "Backward: ";
                while(true)
                {
                    cout << current->item << " ";

                    if (!current->left)
                        break;

                    current = current->left;
                }
                cout << endl;
            }
        }

        Node* Find(T item)
        {
            Node* current = mFirst;
            while (current != nullptr)
            {
                if (current->item == item)
                    return current;
                current = current->right;
            }
            return nullptr;
        }

        void InsertBack(Node* node, T item)
        {
            if (IsEmpty())
            {
                PushBack(item);
            }
            else
            {
                Node* newNode = new Node;
                newNode->item = item;
                newNode->left = node;
                newNode->right = node->right;

                node->right = newNode;
                if (newNode->right)
                    newNode->right->left = newNode;
            }
        }

        void PushFront(T item)
        {
            Node* newNode = new Node;
            newNode->item = item;
            newNode->left = nullptr;
            newNode->right = mFirst;
            if (mFirst)
                mFirst->left = newNode;

            mFirst = newNode;
        }

        void PushBack(T item)
        {
            Node* newNode = new Node;
            newNode->item = item;
            if(mFirst)
            {
                Node* current = mFirst;
                while(current->right != nullptr)
                    current = current->right;
                newNode->left = current;
                newNode->right = nullptr;

                current->right = newNode;
            }
            else
                PushFront(item);
        }

        void PopFront()
        {
            if (IsEmpty())
            {
                using namespace std;
                cout << "Nothing to Pop in PopFront()" << endl;
                return;
            }
            assert(mFirst);

            Node* temp = mFirst;
            mFirst = mFirst->right;
            if (mFirst)
                mFirst->left = nullptr;
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
            if (mFirst->right == nullptr)
            {
                delete mFirst;
                mFirst = nullptr;
                return ;
            }
            assert(mFirst);
            Node* secondLast = mFirst;
            while (secondLast->right->right != nullptr)
                secondLast = secondLast->right;
            Node* temp =  secondLast->right;
            secondLast->right = nullptr;
            delete temp;
        }

        void Reverse()
        {
            if (IsEmpty())
                return ;
            else
            {
                Node* current = mFirst;
                Node* prev = nullptr;

                while (current != nullptr)
                {
                    prev = current;

                    current = current->right;

                    std::swap(prev->left, prev->right);
                }
                mFirst = prev;
            }
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
            while (current->right != nullptr)
                current = current->right;

            return current->item;
        }

    protected:
        Node* mFirst = nullptr;
};