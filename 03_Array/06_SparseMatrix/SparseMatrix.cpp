#include "SparseMatrix.h"

#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

SparseMatrix::SparseMatrix(int numRows, int numCols, int capacity)
    : mNumRows(numRows)
    , mNumCols(numCols)
    , mCapacity(capacity)
    , mNumTerms(0)
{
    mTerms = new MatrixTerm[mCapacity];
}

SparseMatrix::SparseMatrix(const SparseMatrix& b)
    : mNumRows(b.mNumRows)
    , mNumCols(b.mNumCols)
    , mCapacity(b.mCapacity)
    , mNumTerms(b.mNumTerms)
{
    if (b.mCapacity > 0)
    {
        mTerms = new MatrixTerm[mCapacity];
        memcpy(mTerms, b.mTerms, sizeof(MatrixTerm) * mNumTerms);
    }
}

SparseMatrix::~SparseMatrix()
{
    if (mTerms) delete[] mTerms;
}


void SparseMatrix::SetValue(int row, int col, float value)
{
    if (value == 0) return;

    int key = row * mNumCols + col;
    int i = 0;
    for (; i < mNumTerms; ++i)
    {
        int key_i = mTerms[i].row * mNumCols + mTerms[i].col;
        if (key_i == key) // 덮어쓰고 끝내기
        {
            mTerms[i].row = row;
            mTerms[i].col = col;
            mTerms[i].value = value;
            return ;
        }
        else if (key_i > key)
            break; // 여기서부터 뒤로 하나씩 밀고 추가
    }
    assert(mCapacity > mNumTerms);
    mNumTerms++;
    for (int j = mNumTerms - 1; j > i; --j)
        mTerms[j] = mTerms[j - 1];
    mTerms[i].row = row;
    mTerms[i].col = col;
    mTerms[i].value = value;
}

float SparseMatrix::GetValue(int row, int col) const
{
    // for (int i = 0; i < mNumTerms; ++i)
    //     if (mTerms[i].row == row && mTerms[i].col == col)
    //         return mTerms[i].value;
    // return 0.0f;

    // terms가 row와 col에 대해 정렬된 상태인 경우 검색을 더 빠르게 할 수 있다
    int key = row * mNumCols + col;
    for (int i = 0; i < mNumTerms; ++i)
    {
        int key_i = mTerms[i].row * mNumCols + mTerms[i].col;
        if (key_i == key)
            return mTerms[i].value;
        else if (key_i > key)
            return 0.0f;
    }
    return 0.0f;
}

SparseMatrix SparseMatrix::Transpose()
{
    SparseMatrix temp(mNumCols, mNumRows, mCapacity);

    // 정렬이 안된 상태
    // for (int r = 0; r < mNumRows; ++r)
    //     for (int c = 0; c < mNumCols; ++c)
    //         temp.SetValue(c, r, GetValue(r, c)); // O(mNumRows * mNumCols * mNumTerms)

    // temp 정렬 유지
    // for (int r = 0; r < temp.mNumRows; ++r)
    //     for (int c = 0; c < temp.mNumCols; ++c)
    //         temp.SetValue(r, c, GetValue(c, r));
    
    // O(mNumRows * mNumTerms)
    for (int r = 0; r < temp.mNumRows; ++r)
        for (int i = 0; i < mNumTerms; ++i)
        {
            if (mTerms[i].col == r)
            {
                temp.mTerms[temp.mNumTerms].row = mTerms[i].col;
                temp.mTerms[temp.mNumTerms].col = mTerms[i].row;
                temp.mTerms[temp.mNumTerms].value = mTerms[i].value;
                temp.mNumTerms++;
            }
        }
    return temp;
}

void SparseMatrix::PrintTerms()
{
    for (int i = 0; i < mNumTerms; ++i)
		cout << "(" << mTerms[i].row
		<< ", " << mTerms[i].col
		<< ", " << mTerms[i].value
		<< ")" << endl;
}

void SparseMatrix::Print()
{
    for (int r = 0; r < mNumRows; ++r)
    {
        for (int c = 0; c < mNumCols; ++c)
            cout << GetValue(r, c) << " ";
        cout << endl;
    }
}


