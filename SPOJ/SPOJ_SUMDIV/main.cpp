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
typedef unsigned long long ull;
typedef long long ll;
struct NumData
{
    int Basis;
    int Exponent;
};
vector<NumData> Data;
int TEST;
ull n;

//=====================================
//Functions and procedures
ull POWER(ull x, ull y)
{
    if(y==1) return x;
    ull tmp = POWER(x, y>>1LL);
    tmp = tmp*tmp;
    return (y&1LL) ? (tmp*x) : tmp;
}

//Multi-test
void Multitest()
{
    Data.clear();
    scanf("%llu", &n);
    FORi(2, (int)(sqrt(n)))
    {
        if(n%i != 0) continue;
        int exponent1 = 0;
        while(n%i==0)
        {
            ++exponent1;
            n/=i;
        }
        NumData x;
        x.Basis = i;
        x.Exponent = exponent1;
        Data.push_back(x);
    }
    if(n>1)
    {
        NumData x;
        x.Basis = n;
        x.Exponent = 1;
        Data.push_back(x);
    }
    ull res = 1;
    FORli(0, siz(Data)) res *= (POWER(Data[i].Basis, Data[i].Exponent+1) - 1)/(Data[i].Basis-1);
    printf("%llu \n", res);
}



//Main Procedure
int main()
{
    cin >> TEST;
    while(TEST--)
    {
        Multitest();
    }
    return 0;
}
