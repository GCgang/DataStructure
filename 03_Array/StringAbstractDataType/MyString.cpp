#include "MyString.h"

using namespace std;

MyString::MyString()
    : mStr(nullptr)
    , mSize(0)
{
}

MyString::MyString(const char* init)
{
    mSize = 0;
    while (init[mSize] != '\0')
        mSize++;
    
    mStr = new char[mSize];
    memcpy(mStr, init, mSize);
}

MyString::MyString(const MyString& str)
{
    mSize = str.mSize;
    mStr = new char[mSize];
    memcpy(mStr, str.mStr, mSize);
}

MyString::~MyString()
{
    if (mStr != nullptr)
    {
        delete[] mStr;
        mStr = nullptr;
        mSize = 0;
    }
}

bool MyString::IsEmpty()
{
    return Length() == 0;
}

bool MyString::IsEqual(const MyString& str)
{
    if (this->mSize != str.mSize)
        return false;
    for (int i = 0; i < this->mSize; ++i)
        if (this->mStr[i] != str.mStr[i])
            return false;

    return true;
}

int MyString::Length()
{
    return mSize;
}

void MyString::Resize(int newSize)
{
    if (mSize != newSize)
    {
        char* newStr = new char[newSize];
        newSize < mSize ? memcpy(newStr, mStr, newSize) : memcpy(newStr, mStr, mSize);

        delete[] mStr;
        mStr = newStr;
        mSize = newSize;
    }
}

MyString MyString::Substr(int start, int num)
{
    assert(start + num - 1 < this->mSize);

    MyString temp;
    temp.Resize(num);

    for (int i = 0; i < num; ++i)
        temp.mStr[i] = this->mStr[start + i];

    return temp;
}

MyString MyString::Concat(MyString appStr)
{
    MyString temp;
    temp.Resize(this->mSize + appStr.mSize);

    memcpy(temp.mStr, this->mStr, this->mSize);
    memcpy(&temp.mStr[this->mSize], appStr.mStr, appStr.mSize);

    return temp;
}

MyString MyString::Insert(MyString t, int start)
{
    assert(start >= 0);
    assert(start <= this->mSize);

    MyString temp;

    temp.Resize(this->mSize + t.mSize);
    // 012345
    // "ABCDEF", Insert("123", 4)

    // "ABCD"
    for (int i = 0; i < start; ++i)
        temp.mStr[i] = this->mStr[i];
    
    // "123"
    for (int i = start; i < start + t.mSize; ++i)
        temp.mStr[i] = t.mStr[i - start];
    
    // "EF"
    for (int i = start + t.mSize; i < this->mSize + t.mSize; ++i)
        temp.mStr[i] = this->mStr[i - t.mSize];

    // "ABCD123EF"
    
    return temp;
}

int MyString::Find(MyString pat)
{
    for (int start = 0; start <= Length() - pat.Length(); ++start)
    {
        for (int j = 0; j < pat.Length(); ++j)
        {
            // 한 글자라도 일치하지 않으면 start 증가후 다시 검사
            if (mStr[start + j] != pat.mStr[j])
                break;

            // 모든 글자가 일치하면 start 반환
            if (j == pat.Length() - 1)
                return start;
        }
    }
    return -1;

    // 더 빠른 알고리즘: Kruth-Morris-Pratt
}

void MyString::Print()
{
    for (int i = 0; i < mSize; ++i)
        cout << mStr[i];
    cout << endl;
}