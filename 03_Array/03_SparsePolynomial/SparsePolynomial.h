#pragma once

struct Term
{
    float coef;
    int exp;
};

class SparsePolynomial
{
    public:
        SparsePolynomial() {}
        
        ~SparsePolynomial()
        {
            if (mTerms) delete[] mTerms;
        }

        void NewTerm(float coef, int exp);
        
        float Eval(float x);

        SparsePolynomial Add(const SparsePolynomial& poly);

        void Print();

    private:
        Term* mTerms = nullptr;
        int mCapacity = 0;
        int mNumTerms = 0;
};