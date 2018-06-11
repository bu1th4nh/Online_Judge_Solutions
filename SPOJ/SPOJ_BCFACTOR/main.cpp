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
unsigned long long n;
struct Data
{
    int Basis;
    int Exponent;
};
vector<Data> RES;

//=====================================
//Functions and procedures
int main()
{
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
        Data x;
        x.Basis = i;
        x.Exponent = exponent1;
        RES.push_back(x);
    }
    if(n>1)
    {
        Data x;
        x.Basis = n;
        x.Exponent = 1;
        RES.push_back(x);
    }
    //FORli(0, siz(RES)) printf("%d %d\n", RES[i].Basis, RES[i].Exponent);


    FORli(0, siz(RES)-1) printf("%d^%d * ", RES[i].Basis, RES[i].Exponent);
    printf("%d^%d\n", RES[siz(RES)-1].Basis, RES[siz(RES)-1].Exponent);

    return 0;
}
