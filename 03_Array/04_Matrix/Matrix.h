#pragma once

class Matrix
{
    public:
        Matrix(int numRows, int numCols);
        
        Matrix(const Matrix& b);
        
        ~Matrix();
        
        void SetValue(int row, int col, float value);

        float GetValue(int row, int col) const;

        Matrix Transpose();

        Matrix Add(const Matrix& b);

        void Print();

    private:
        float* mValue = nullptr;
        int mNumRows = 0;
        int mNumCols = 0;
};