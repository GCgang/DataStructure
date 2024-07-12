#pragma once

class Array2D
{
    public:
        Array2D(int numRows, int numCols);

        Array2D(const Array2D& b);

        ~Array2D();

        void SetValue(int row, int col, float value);

        float GetValue(int row, int col) const;
    
        Array2D Transpose();

        Array2D Add(const Array2D& b);

        void Print();

    private:
        float** mArrays = nullptr;
        int mNumRows = 0;
        int mNumCols = 0;
};