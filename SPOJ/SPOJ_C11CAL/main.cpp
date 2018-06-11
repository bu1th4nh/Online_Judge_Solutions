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
#define MODUL (int)(1e9+7)
#define len(x) (int)(x.length())
#define siz(x) (int)(x.size())
#define whole(x) x.begin(), x.end()
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORk(x, y) for(int k1=x; k1<=y; ++k1)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORbi(x, y) for(int i=x; i>=y; --i)
#define FORlbi(x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef unsigned long long ull;
typedef long long ll;
int k;
ll n;

//=====================================
//Modulo
ll mod(ll x)
{
    return((x%MODUL)+MODUL)%MODUL;
}

//=====================================
class Matrix
{

public:

    ll val[55][55];

    Matrix()
    {
        MEMS(val, 0);
    }
    Matrix(bool IsUnit)
    {
        if(IsUnit)
        {
            MEMS(val, 0);
            for(int i=k+1;i>=0;--i)
                for(int j=k+1;j>=0;--j)
                    val[i][j]=1;
        }
    }
    Matrix (int yyy, int xxx)
    {
        FORi(0, k)
        {
            val[i][0] = 1;
            FORj(1, i)
            {
                val[i][j] = mod(val[i-1][j-1]+val[i-1][j]);
            }
        }
        FORi(0, k) val[k+1][i] = val[k][i];
        val[k+1][k+1] = 1;
    }

    Matrix operator * (const Matrix & x)
    {
        Matrix res;
        FORi(0, k+1)
        {
            FORj(0, k+1)
            {
                res.val[i][j] = 0LL;
                FORk(0, k+1)
                {
                    res.val[i][j] += mod((val[i][k1])*x.val[k1][j]);
                }
                res.val[i][j] = mod(res.val[i][j]);
            }
        }
        return res;
    }
};


Matrix POWER(Matrix A, ll B)
{
    if(B==1) return A;
    Matrix tmp = POWER(A, B>>1LL);
    tmp = tmp * tmp;
    return (B&1LL) ? (tmp * A) :tmp;
}

//=====================================
//Functions and procedures

//Process
void Multitest()
{
    while(scanf("%lld%d", &n, &k)==2)
    {
        Matrix X = Matrix(0, 0);
        Matrix RES = POWER(X, n);
        printf("%lld\n", RES.val[k+1][0]);
    }
}

//Main Procedure
int main()
{
    Multitest();
    return 0;
}
