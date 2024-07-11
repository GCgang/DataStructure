#include "Polynomial.h"

#include <iostream>
#include <cassert>
#include <cstring> 
#include <math.h> // std::powf()

using namespace std;

Polynomial::Polynomial(int maxDegree)
{
    assert(maxDegree > 0);

    // 상수항 포함
    // ex) maxDegree가 2이면 c0*x^0 + c1*x^1 c2*x^2 3개의 항들
    mCapacity = maxDegree + 1;

    // 동적 메모리 할당
    mCoeffs = new float[mCapacity];

    // 0으로 초기화
    for (int i = 0; i < mCapacity; ++i)
        mCoeffs[i] = 0.0f;
}

Polynomial::Polynomial(const Polynomial& poly)
{
    mCapacity = poly.mCapacity;
    mCoeffs = new float[this->mCapacity];
    memcpy(mCoeffs, poly.mCoeffs, mCapacity);
}

Polynomial::~Polynomial()
{
    if (mCoeffs) delete[] mCoeffs;
}

int Polynomial::MaxDegree()
{
    return mCapacity - 1;
}

void Polynomial::NewTerm(const float coef, const int exp)
{
    assert(exp < mCapacity); // exp가 너무 크면 resize 하도록 구현할 수도 있음

    mCoeffs[exp] = coef;
}

Polynomial Polynomial::Add(const Polynomial& poly)
{
    assert(poly.mCapacity == mCapacity);

    Polynomial temp(MaxDegree());

    for (int i = 0; i < mCapacity; ++i)
    {
        if (mCoeffs[i] != 0.0f)
            temp.mCoeffs[i] = mCoeffs[i] + poly.mCoeffs[i];
    }
    return temp;
}

Polynomial Polynomial::Mult(const Polynomial& poly)
{
    assert(poly.mCapacity == mCapacity);

    Polynomial temp(MaxDegree());

    for (int i = 0; i < mCapacity; ++i)
    {
        if (mCoeffs[i] != 0.0f)
        {
            for (int j = 0; j < poly.mCapacity; ++j)
            {
                if (poly.mCoeffs[j] != 0.0f && i + j < poly.mCapacity)
                {
                    temp.mCoeffs[i+j] += mCoeffs[i] * poly.mCoeffs[j];
                }
            }
        }
    }
    return temp;
}

float Polynomial::Eval(float x)
{
    float tot = 0.0f;

    for (int i = 0; i < mCapacity; ++i)
    {
        if (mCoeffs[i] != 0.0f)
            tot += (mCoeffs[i] * powf(x, float(i)));
    }
    return tot;
}

void Polynomial::Print()
{
    bool isFirst = true;

    for (int i = 0; i < mCapacity; ++i)
    {
        if (mCoeffs[i] != 0.0f)
        {
            if (!isFirst)
                cout << " + ";
            cout << mCoeffs[i];

            if (i != 0)
                cout << "*" << "x^" << i;
            
            isFirst = false;
        }
    }
    cout << endl;
}