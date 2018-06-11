/** \brief Uncompleted. Still have problem
 *
 * \param
 * \param
 * \return
 *
 */

//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cassert>
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
#define MODUL (int)(1e9)
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



#define MAX_SIZE 10
#define MOD 1000000000
int size;

struct Matrix{
    long long X[MAX_SIZE][MAX_SIZE];

    Matrix(){}

    void init(){
        memset(X,0,sizeof(X));
        for(int i = 0;i<size;++i) X[i][i] = 1;
    }
}aux;

void mult(Matrix &m, Matrix &m1, Matrix &m2){
    memset(m.X,0,sizeof(m.X));

    for(int i = 0;i<size;++i)
        for(int j = 0;j<size;++j)
            for(int k = 0;k<size;++k)
                m.X[i][k] = (m.X[i][k]+m1.X[i][j]*m2.X[j][k])%MOD;
}

Matrix pow(Matrix &M0, int n){
	Matrix ret;
	ret.init();

	if(n==0) return ret;
	if(n==1) return M0;

	Matrix P = M0;

	while(n!=0){
	    if(n & 1){
	        aux = ret;
	        mult(ret,aux,P);
	    }

	    n >>= 1;

	    aux = P;
	    mult(P,aux,aux);
	}

    return ret;
}

int main(){
    int T,b[10],c[10],n;
    Matrix M0,ret;

    scanf("%d",&T);

    while(T--){
        scanf("%d",&size);

        for(int i = 0;i<size;++i) scanf("%d",&b[i]);
        for(int i = 0;i<size;++i) b[i] %= MOD;
        for(int i = 0;i<size;++i) scanf("%d",&c[i]);

        scanf("%d",&n);
        --n;

        if(n<size) printf("%d\n",b[n]);
        else{
            memset(M0.X,0,sizeof(M0.X));

            for(int i = 0;i<size;++i) M0.X[0][i] = c[i];
            for(int i = 1;i<size;++i) M0.X[i][i-1] = 1;

            ret = pow(M0,n-size+1);

            long long ans = 0;

            for(int i = 0;i<size;++i)
                ans = (ans+ret.X[0][i]*b[size-1-i])%MOD;

            printf("%lld\n",ans);
        }
    }

    return 0;
}

/*
//=====================================
//Typedef
typedef unsigned long long ull;
typedef vector<int> vi;
typedef long long ll;
int nB, n;
vi b, c;
int TEST;

//=====================================
//Class Matrix
class Matrix
{

public:

    ll val[20][20];

    Matrix()
    {
        MEMS(val, 0);
    }
    Matrix(bool IsUnit)
    {
        if(IsUnit)
        {
            FORi(1, nB) val[i][i] = 1;
        }
    }
    Matrix(vi & sample, bool IsB)
    {
        assert(!sample.empty());
        MEMS(val, 0);
        if (IsB)
        {
            FORi(1, nB)
            {
                val[i][1] = sample[i];
            }
        }
        else
        {
            FORi(1, nB-1)
            {
                val[i][i+1] = 1;
            }
            FORi(1, nB)
            {
                val[nB][i] = sample[i];
            }
        }

    }

    Matrix operator * (const Matrix & x)
    {
        Matrix res;
        FORi(1, nB)
        {
            FORj(1, nB)
            {
                FORk(1, nB)
                {
                    res.val[i][j] = (res.val[i][j] + val[i][k]*x.val[k][j])%MODUL;
                }
            }
        }
        return res;
    }

    void PrintDebug()
    {
        cerr << endl;
        FORi(1, nB)
        {
            FORj(1, nB)
            {
                cerr << val[i][j] << " ";
            }
            cerr << endl;
        }
        cerr << endl;
    }

};
Matrix POWER(Matrix A, ll B)
{
    if(B==1) return A;
    Matrix tmp = Matrix(true);
    tmp = POWER(A, B>>1);
    tmp = tmp * tmp;
    return (B&1) ? (tmp * A) :tmp;
}

//Process
void Multitest()
{
    b.push_back(0);
    c.push_back(0);
    scanf("%d", &nB);
    FORi(1, nB)
    {
        int x;
        scanf("%d", &x);
        b.push_back(x);
    }
    FORi(1, nB)
    {
        int x;
        scanf("%d", &x);
        c.push_back(x);
    }
    scanf("%d", &n);

    if(n<=nB) printf("%d \n", b[n]);
    else
    {
        Matrix X = Matrix(b, true);
        //X.PrintDebug();
        Matrix Y = Matrix(c, false);
        //Y.PrintDebug();
        Matrix RES = POWER(Y, n-nB+1) * X;
        RES.PrintDebug();
        int RESULT;
        FORi(1, nB) RESULT = (RESULT+RES.val[nB][i]*b[nB-i])%MODUL;
        printf("%d \n", RESULT);
    }
}

//Main Procedure
int main()
{
    scanf("%d", &TEST);
    FORi(1, TEST) Multitest();
    return 0;
}
*/
