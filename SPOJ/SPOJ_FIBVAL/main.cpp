//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp (int)()
#define MODUL (int)(1e9+57)
#define len(x) (int)(x.length())
#define siz(x) (int)(x.size())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
const int f[] = {1, 2, 3, 5, 1, 6, 0, 6, 6, 5, 4, 2, 6, 1, 0, 1};
int nTest;
int u, v;
int res;


//=====================================
//Process
int Solve(int u, int v)
{
    int k = (v - u + 1)/16;
    if(k>=2) return (k*16);
    int lm = min(u+17, v);
    FOR(i, u+1, lm) if(f[i%16] == f[(i+15)%16]) return 2;
    return -1;
}


//Main Procedure
int main()
{
    scanf("%d", &nTest);
    while(nTest--)
    {
        scanf("%d%d", &u, &v);
        printf("%d\n", Solve(u - 1, v - 1));
    }
    return 0;
}
