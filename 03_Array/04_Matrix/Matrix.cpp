#include "Matrix.h"
#include <algorithm>
#include <cassert>
#include <iostream>
#include <cstring>

using namespace std;

Matrix::Matrix(int numRows, int numCols)
    : mNumRows(numRows)
    , mNumCols(numCols)
{
    mValue = new float[mNumRows * mNumCols];
    for (int i = 0; i < mNumRows * mNumCols; ++i)
        mValue[i] = 0.0f;
}

Matrix::Matrix(const Matrix& b)
    : mNumRows(b.mNumRows)
    , mNumCols(b.mNumCols)
{
    int capacity = mNumRows * mNumCols;
    mValue = new float[capacity];
    memcpy(mValue, b.mValue, capacity);
}

Matrix::~Matrix()
{
    if (mValue) delete[] mValue;
}

void Matrix::SetValue(int row, int col, float value)
{
    mValue[row * mNumCols + col] = value;
}

float Matrix::GetValue(int row, int col) const
{
    return mValue[row * mNumCols + col];
}

Matrix Matrix::Transpose()
{ 
    Matrix temp(mNumCols, mNumRows);

    for (int r = 0; r < mNumRows; ++r)
        for (int c = 0; c < mNumCols; ++c)
            temp.SetValue(c, r, GetValue(r, c));

    return temp;
}

Matrix Matrix::Add(const Matrix& b)
{
    assert(b.mNumRows == mNumRows);
    assert(b.mNumCols == mNumCols);

    Matrix temp(mNumRows, mNumCols);

    for (int r = 0; r < mNumRows; ++r)
        for (int c = 0; c < mNumCols; ++c)
            temp.SetValue(r, c, GetValue(r, c) + b.GetValue(r, c));

    return temp;
}

void Matrix::Print()
{
    for (int r = 0; r < mNumRows; ++r)
    {
        for (int c = 0; c < mNumCols; ++c)
            cout << GetValue(r, c) << " ";
        cout << endl;
    }
}