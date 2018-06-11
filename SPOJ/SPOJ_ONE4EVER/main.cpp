//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp (int)()
#define MODUL (int)(10e9+57)
#define len(x) (int)(x.length())
#define siz(x) (int)(x.size())
#define whole(x) x.begin(), x.end()
#define FORi(x, y) for(long i=x; i<=y; ++i)
#define FORj(x, y) for(long j=x; j<=y; ++j)
#define FORk(x, y) for(long k=x; k<=y; ++k)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORbi(x, y) for(int i=x; i>=y; --i)
#define FORlbi(x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef unsigned long long ull;
typedef long long ll;
long TEST;
ull a, b, m, k;

//=====================================
//Fast Multiplication
ll FastMul(ll a, ll b)
{
    if(!b) return 0;
    if(b==1) return a;
    if(b&1LL) return (FastMul(a, b>>1LL)*2+a)%m;
    else return (FastMul(a, b>>1LL)*2)%m;
}
//=====================================
//Class Matrix
class Matrix
{

public:

    ll val[2][2];

    Matrix()
    {
        val[0][0] = 0;
        val[0][1] = 0;
        val[1][0] = 0;
        val[1][1] = 0;
    }
    Matrix(ll UPL, ll UPR, ll LWL, ll LWR)
    {
        val[0][0] = UPL;
        val[0][1] = UPR;
        val[1][0] = LWL;
        val[1][1] = LWR;
    }

    Matrix operator * (const Matrix & x)
    {
        Matrix res;
        FORi(0, 1)
        {
            FORj(0, 1)
            {
                res.val[i][j] = 0;
                FORk(0, 1)
                {
                    res.val[i][j] = (res.val[i][j] + FastMul(val[i][k], x.val[k][j]))%m;
                }
            }
        }
        return res;
    }

};

/*
Matrix POWER(Matrix A, ull B)
{
    Matrix C = Matrix(1, 0, 0, 1);
    for(; B; B >>= 1, A = A * A)
    {
        if(B&1) C = C * A;
    }
    return C;
}
*/

Matrix POWER(Matrix A, ull B)
{
    if(B==1) return A;
    Matrix tmp = POWER(A, B>>1LL);
    tmp = tmp * tmp;
    return (B&1LL) ? (tmp * A) :tmp;
}

//Output
void Multitest()
{
    scanf("%lld%lld%lld%lld", &a, &b, &m, &k);
    if(k==1) cout << b%m << endl;
    else if(k==2) cout << FastMul(a+1, b) << endl;
    else
    {
        Matrix X = Matrix(a, 0, b%m, 1);
        Matrix Y = Matrix(b%m, 1, FastMul(a+1, b), 1);
        Matrix Result = Y * POWER(X, k-2);
        cout << Result.val[1][0] << endl;
    }
}


//Main Procedure
int main()
{
    scanf("%ld", &TEST);
    FORj(1, TEST)
    {
        Multitest();
    }
    return 0;
}
