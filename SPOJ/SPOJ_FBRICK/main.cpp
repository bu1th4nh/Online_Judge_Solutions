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
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORk(x, y) for(int k=x; k<=y; ++k)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORbi(x, y) for(int i=x; i>=y; --i)
#define FORlbi(x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef long long ll;
ll A2, N, M;
int TEST;

//=====================================
//Modulo
ll mod(ll x)
{
    ll tmp = x%M;
    while(tmp<0) tmp+=M;
    return tmp;
}

//=====================================
//Class Matrix
class Matrix
{

public:

    ll val[5][5];

    Matrix()
    {
        MEMS(val, 0);
    }
    Matrix(ll valA2)
    {
        ll tmp1 = mod(4LL*valA2*valA2);
        ll tmp2 = mod(2LL*valA2);
        ll tmp3 = -mod(4LL*valA2);
        int cnt = 0;
        ll ARR[16] = {mod(1LL), tmp1, mod(1LL), tmp3, 0LL, tmp1, mod(1LL), tmp3, 0LL, mod(1LL), 0LL, 0LL, 0LL, tmp2, 0LL, mod(-1LL)};
        FORi(1, 4)
        {
            FORj(1, 4)
            {
                val[i][j] = ARR[cnt];
                ++cnt;
            }
        }
    }
    Matrix(ll Ti1, ll Ai1, ll Ai2)
    {
        val[1][1] = mod(Ti1);
        val[2][1] = mod(Ai1*Ai1);
        val[3][1] = mod(Ai2*Ai2);
        val[4][1] = mod(Ai2*Ai1);
    }
    Matrix(bool IsUnit)
    {
        if(IsUnit)
        {
            FORi(1, 4) val[i][i] = 1;
        }
    }

    Matrix operator * (const Matrix & x)
    {
        Matrix res;
        FORi(1, 4)
        {
            FORj(1, 4)
            {
                res.val[i][j] = 0LL;
                FORk(1, 4)
                {
                    res.val[i][j] = mod(res.val[i][j] +mod(mod(val[i][k])*mod(x.val[k][j])));
                }
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

void Multitest()
{
    scanf("%lld%lld%lld", &A2, &N, &M);
    if(N==1) printf("%lld\n", mod(1LL));
    else if(N==2) printf("%lld\n", mod(A2*A2+1LL));
    else
    {
        Matrix X = Matrix(A2);
        Matrix Y = Matrix(A2*A2 + 1LL, A2, 1LL);
        Matrix RES = POWER(X, N-2) * Y;
        ll RESULT = mod(RES.val[1][1]);
        printf("%lld\n", RESULT);
    }
}

int main()
{
    scanf("%d", &TEST);
    while(TEST--)
    {
        Multitest();
    }
    return 0;
}
