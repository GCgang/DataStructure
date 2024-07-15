#pragma oncde

struct MatrixTerm
{
    int row;
    int col;
    int value;
};

class SparseMatrix
{
    public:
        SparseMatrix(int numRows, int numCols, int cpapcity);

        SparseMatrix(const SparseMatrix& b);

        ~SparseMatrix();

        void SetValue(int row, int col, float value);

        float GetValue(int row, int col) const;

        SparseMatrix Transpose();

        void PrintTerms();
        void Print();

    private:
        MatrixTerm* mTerms = nullptr;
        int mNumRows = 0;
        int mNumCols = 0;
        int mCapacity = 0;
        int mNumTerms = 0;
};