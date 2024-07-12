#include "Array2D.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <cstring>

using namespace std;

Array2D::Array2D(int numRows, int numCols)
    : mNumRows(numRows)
    , mNumCols(numCols)
{
    mArrays = new float* [mNumRows];
    for (int r = 0; r < mNumRows; ++r)
    {
        mArrays[r] = new float[mNumCols];
        for (int c = 0; c < mNumCols; ++c)
        {
            mArrays[r][c] = 0.0f;
        }
    }
    // 0.0f 초기화: 배열의 포인터
    // for (int r = 0; r < mNumRows; ++r)
    // {
    //     float* row = mArrays[r];

    //     for (int c = 0; c < mNumCols; ++c)
    //     {
    //         row[c] = 0.0f;
    //     }
    // }
}

Array2D::Array2D(const Array2D& b)
    : mNumRows(b.mNumRows)
    , mNumCols(b.mNumCols)
{

    mArrays = new float*[mNumRows];
    for (int r = 0; r < mNumRows; ++r)
    {
        mArrays[r] = new float[mNumCols];
        for (int c = 0; c < mNumCols; ++c)
        {
            mArrays[r][c] = b.mArrays[r][c];
        }
    }
    // memcpy로 복사
    // for (int r = 0; r < mNumRows; ++r)
    //     memcpy(mArrays[r], b.mArrays[r], sizeof(float) * mNumCols);
}

Array2D::~Array2D()
{
    if (mArrays) {
        for (int r = 0; r < mNumRows; ++ r){
            delete[] mArrays[r];
        }
        delete[] mArrays;
    }
}

void Array2D::SetValue(int row, int col, float value)
{
    mArrays[row][col] = value;
}

float Array2D::GetValue(int row, int col) const
{
	return mArrays[row][col]; 
}

Array2D Array2D::Transpose()
{ 
    Array2D temp(mNumCols, mNumRows);

    for (int r = 0; r < mNumRows; ++r)
        for (int c = 0; c < mNumCols; ++c)
            temp.SetValue(c, r, GetValue(r, c));

    return temp;
}

Array2D Array2D::Add(const Array2D& b)
{
    assert(b.mNumRows == mNumRows);
    assert(b.mNumCols == mNumCols);

    Array2D temp(mNumRows, mNumCols);

    for (int r = 0; r < mNumRows; ++r)
        for (int c = 0; c < mNumCols; ++c)
            temp.SetValue(r, c, GetValue(r, c) + b.GetValue(r, c));

    return temp;
}

void Array2D::Print()
{
    for (int r = 0; r < mNumRows; ++r)
    {
        for (int c = 0; c < mNumCols; ++c)
            cout << GetValue(r, c) << " ";
        cout << endl;
    }
}