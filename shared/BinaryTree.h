#pragma once

#include <iostream>
#include <fstream>
#include <string> // BinaryTree 출력
#include "Queue.h"
#include "Stack.h"

template<typename T>
class BinaryTree
{
    public:
        struct Node
        {
            T item = T();
            Node* left = nullptr;
            Node* right = nullptr;
            
            Node(T value, Node* leftNode = nullptr, Node* rightNode = nullptr)
            : item(value), left(leftNode), right(rightNode) {}
        };
        

	// 디버깅 도구: 큐에서 주소 대신에 아이템 출력
	class MyQueue : public Queue<Node*>
	{
        public:
            void Print()
            {
                using namespace std;

                for (int i = (this->front_ + 1) % this->capacity_; i != (this->rear_ + 1) % this->capacity_; i = (i + 1) % this->capacity_)
                    cout << this->queue_[i]->item << " ";
                cout << endl;
            }
	};
    // 디버깅 도구: 스택에서 주소 대신에 아이템 출력
	class MyStack : public Stack<Node*>
	{
        public:
            void Print()
            {
                using namespace std;

                for (int i = 0; i < this->Size(); i++)
                    cout << this->stack_[i]->item << " ";
                cout << endl;
            }
	};    

    BinaryTree() {}

    BinaryTree(Node* root)
    {
        mRoot = root;
    }

    bool IsEmpty()
    {
        return mRoot == nullptr;
    }

    void Visit(Node* node)
    {
        using namespace std;
        cout << node->item << " ";
    }

    int Sum()
    {
        return Sum(mRoot);
    }

    int Sum(Node* node)
    {
        if (node == nullptr)
            return 0;
        return  node->item + Sum(node->left) + Sum(node->right);
    }

    int Height()
    {
        return Height(mRoot);
    }

    int Height(Node* node)
    {
        // todo
    }

    ~BinaryTree()
    {
        DeleteTree(mRoot);
    }

    void DeleteTree(Node* node)
    {
        if(node == nullptr)
            return ;
        DeleteTree(node->left);
        DeleteTree(node->right);
        delete node;
    }

    void Preorder()
    {
        Preorder(mRoot);
    }

    void Preorder(Node* node)
    {
        if (node == nullptr)
            return ;
        Visit(node);
        Preorder(node->left);
        Preorder(node->right);
    }

    void Inorder()
    {
        Inorder(mRoot);
    }

    void Inorder(Node* node)
    {
        if (node == nullptr)
            return ;
        Inorder(node->left);
        Visit(node);
        Inorder(node->right);

    }

    void Postorder()
    {
        Postorder(mRoot);
    }

    void Postorder(Node* node)
    {
        if (node == nullptr)
            return ;
        Postorder(node->left);
        Postorder(node->right);
        Visit(node);
    }

    void LevelOrder()
    {
        Queue<Node*> q;
        Node* current = mRoot;
        while(current)
        {
            Visit(current);
            // todo
        }
    }

    void IterPreorder()
    {
        if (!mRoot) return;

        Stack<Node*> s;
        s.Push(mRoot);

        while(!s.IsEmpty())
        {
            // todo
        }
    }

    void IterInorder()
    {
        if (!mRoot) return;

        Stack<Node*> s;

        Node* current = mRoot;
        while (current || !s.IsEmpty())
        {
            // todo
        }
    }

    void IterPostorder()
    {
        if (!mRoot) return ;

        Stack<Node*> s1, s2;
        s1.Push(mRoot);

        while (!s1.IsEmpty())
        {
            // todo
        }

        while (!s2.IsEmpty())
        {
            // todo
        }
    }
    void Print2D();
    void PrintLevel(int n);
    void DisplayLevel(Node* p, int lv, int d);

    protected:
        Node* mRoot = nullptr;
};

// 디버깅 편의 도구
// https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c
template<typename T>
void BinaryTree<T>::Print2D()
{
	using namespace std;
	int i = 0;
	while (i < Height()) {
		PrintLevel(i);
		i++;
		cout << endl;
	}
}

template<typename T>
void BinaryTree<T>::PrintLevel(int n) {
	using namespace std;
	Node* temp = mRoot;
	int val = (int)pow(2.0, Height() - n + 1.0);
	cout << setw(val) << "";
	DisplayLevel(temp, n, val);
}

template<typename T>
void BinaryTree<T>::DisplayLevel(Node* p, int lv, int d) {
	using namespace std;
	int disp = 2 * d;
	if (lv == 0) {
		if (p == NULL) {
			cout << "   ";
			cout << setw(disp - 3) << "";
			return;
		}
		else {
			int result = ((p->item <= 1) ? 1 : (int)log10(p->item) + 1);
			cout << " " << p->item << " ";
			cout << setw(static_cast<streamsize>(disp) - result - 2) << "";
		}
	}
	else
	{
		if (p == NULL && lv >= 1) {
			DisplayLevel(NULL, lv - 1, d);
			DisplayLevel(NULL, lv - 1, d);
		}
		else {
			DisplayLevel(p->left, lv - 1, d);
			DisplayLevel(p->right, lv - 1, d);
		}
	}
}