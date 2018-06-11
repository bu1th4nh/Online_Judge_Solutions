/** \brief There's some problems in this class
 *
 * \param
 * \param
 * \return
 *
 */


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
#define MODUL (int)(111539786)
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
typedef unsigned long long ull;
typedef long long ll;
int TEST;
ll n;


//=====================================
//Class Matrix
class Matrix
{

public:

    int val[3][3];

    Matrix()
    {
        MEMS(val,0);
    }
    Matrix(int UPL, int UPR, int LWL, int LWR)
    {
        val[1][1] = UPL;
        val[1][2] = UPR;
        val[2][1] = LWL;
        val[2][2] = LWR;
    }

    Matrix operator * (const Matrix & x)
    {
        Matrix res;
        FORi(1, 2)
        {
            FORj(1, 2)
            {
                res.val[i][j] = 0;
                FORk(1, 2)
                {
                    res.val[i][j] = ((ll)val[i][k]*x.val[k][j] + res.val[i][j]) % MODUL;
                }
            }
        }
        return res;
    }

};
//Process
Matrix POWER(Matrix A, ll B)
{
    Matrix C = Matrix(1, 0, 0, 1);
    for(; B; B >>= 1, A = A * A)
    {
        if(B&1) C = C * A;
    }
    return C;
}
void Process()
{
    Matrix X = Matrix(1, 1, 1, 0);
    cin >> n;
    Matrix RES = POWER(X, n-1);
    RES.val[1][1] = (RES.val[1][1] + RES.val[1][2])%MODUL;
    cout << RES.val[1][1] << endl;
}



int main()
{
    scanf("%d", &TEST);
    FORk(1, TEST) Process();
    return 0;
}
