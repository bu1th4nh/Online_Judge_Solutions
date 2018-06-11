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
ll N, M;

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
                    res.val[i][j] = (res.val[i][j] +((val[i][k])*(x.val[k][j])))%M;
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

int main()
{
    cin >> N >> M;
    Matrix X;
    X.val[1][2] = X.val[2][3] = X.val[3][4] = 1;
    X.val[4][2] = X.val[4][3] = X.val[4][4] = 1;
    switch (N)
    {
        case 0: {cout << 1; break;}
        case 1: {cout << 1; break;}
        case 2: {cout << 2; break;}
        case 3: {cout << 4; break;}
        default:
            {
                Matrix RES = POWER(X, N);
                cout << RES.val[4][4];
                break;
            }
    }
    return 0;
}
