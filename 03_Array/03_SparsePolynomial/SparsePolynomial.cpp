#include "SparsePolynomial.h"

#include <iostream>
#include <cassert>
#include <algorithm>
#include <cstring>

using namespace std;

// 새로운 항을 추가할 때 자기 위치를 찾아서 넣어줘야 함

// exp항이 이미 존재하면 거기에 coef를 더해준다.
// 존재하지 않는다면 exp 오름 차순으로 정렬된 상태로 새로 추가한다.
void SparsePolynomial::NewTerm(float coef, int exp)
{
    if (coef == 0.0f) return; // 0이면 추가하지 않음

    if (mNumTerms >= mCapacity)
    {
        // capacity 증가
        mCapacity = mCapacity > 0 ? mCapacity * 2 : 1; // 2배 증가
        Term* newTerms = new Term[mCapacity];

        // 원래 가지고 있던 데이터 복사
        memcpy(newTerms, mTerms, sizeof(Term) * mNumTerms);

        // 메모리 교체
        if (mTerms) delete[] mTerms;
        mTerms = newTerms;
    }
    mTerms[mNumTerms].coef = coef;
    mTerms[mNumTerms].exp = exp;

    mNumTerms++;
}

float SparsePolynomial::Eval(float x)
{
    float tot = 0.0f;

    for (int i = 0; i < mNumTerms; ++i)
    {
        tot += (mTerms[i].coef * powf(x, float(mTerms[i].exp)));
    }
    return tot;
}

SparsePolynomial SparsePolynomial::Add(const SparsePolynomial& poly)
{
    // this와 poly의 mTerms가 exp의 오름차순으로 정렬되어 있다고 가정
	// 하나의 다항식 안에 exp가 중복되는 term이 없다라고 가정 (한 exp는 하나의 term만 존재)

	// 간단한 방법 (메모리를 더 사용하는 방법)
	// - 1. 최대 exp를 찾는다.
	// - 2. 필요한 크기의 Polynomial을 만든다. (Sparse 아님)
	// - 3. 더하면서 Polynomial에 업데이트 한다. 구조가 고정되어 있어서 쉽다.
	// - 4. Polynomial을 SparsePolynomial로 변환한다.

	SparsePolynomial temp;
    int i = 0;
    int j = 0;
    while ((i < mNumTerms) && (j < poly.mNumTerms))
    {
        if (mTerms[i].exp == poly.mTerms[j].exp)
        {
            float sum = mTerms[i].coef + poly.mTerms[j].coef;
            if (sum != 0.0f)
                temp.NewTerm(sum, mTerms[i].exp);
            i++;
            j++;
        }
        else if (mTerms[i].exp > poly.mTerms[j].exp)
        {
            temp.NewTerm(poly.mTerms[j].coef, poly.mTerms[j].exp);
            j++;
        }
        else if (mTerms[i].exp < poly.mTerms[j].exp)
        {
            temp.NewTerm(mTerms[i].coef, mTerms[i].exp);
            i++;
        }
    }
    // 남은 아이템 추가
    for (; i < mNumTerms; ++i)
        temp.NewTerm(mTerms[i].coef, mTerms[i].exp);
    for (; j < poly.mNumTerms; ++j)
        temp.NewTerm(poly.mTerms[j].coef, poly.mTerms[j].exp);

    return temp;
}

void SparsePolynomial::Print()
{
    bool isFirst = true;

    for (int i = 0; i < mNumTerms; ++i)
    {
        if (!isFirst)
            cout << " + ";
        
        cout << mTerms[i].coef;

        if (mTerms[i].exp != 0) cout << "*" << "x^" << mTerms[i].exp;

        isFirst = false;
    }
    cout << endl;
}
