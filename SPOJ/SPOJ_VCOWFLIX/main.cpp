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
#define maxvalueinp (int)(10000)
#define MODUL (int)(10e9+57)
#define len(x) (int)(x.length())
#define siz(x) (int)(x.size())
#define whole(x) x.begin(), x.end()
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORk(x, y) for(int k=x; k<=y; ++k)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORbi(x, y) for(int i=x; i>=y; --i)
#define FORbj(x, y) for(int j=x; j>=y; --j)
#define FORlbi(x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
bool F[maxvalueinp];
vector<int> Weigh;
int n, c;

//=====================================
//Functions and procedures

int main()
{
    scanf("%d%d", &c, &n);
    Weigh.push_back(0);
    FORi(1, n)
    {
        int x;
        scanf("%d", &x);
        Weigh.push_back(x);
    }
    F[0] = true;
    FORi(1, n)
    {
        FORbj(c, Weigh[i])
        {
            F[j] = F[j] || F[j-Weigh[i]];
        }
    }
    FORbi(c, 0)
    {
        if(F[i])
        {
            printf("%d", i);
            return 0;
        }
    }
    return 0;
}
