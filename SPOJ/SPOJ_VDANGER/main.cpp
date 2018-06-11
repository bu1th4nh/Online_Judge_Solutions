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
#define maxvalueinp (int)(192)
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
int c[maxvalueinp][maxvalueinp];
vector<int> dst;
int m, n;
int res;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int x;
    dst.push_back(-1);
    scanf("%d%d", &n, &m);
    FOR(i, 1, m)
    {
        scanf("%d", &x);
        dst.push_back(x);
    }
    FOR(i, 1, n)
    {
        FOR(j, 1, n)
        {
            scanf("%d", &c[i][j]);
        }
    }
}

//Floyd - Warshall's Algorithm
void Floyd()
{
    FOR(k, 1, n)
    {
        FOR(i, 1, n)
        {
            FOR(j, 1, n)
            {
                if(c[i][j] > c[i][k] + c[k][j]) c[i][j] = c[i][k] + c[k][j];
            }
        }
    }
}

//Process
void Solve()
{
    res = c[1][dst[1]] + c[dst[m]][n];
    FOR(i, 2, m) res += c[dst[i-1]][dst[i]];
    printf("%d", res);
}

//Main Procedure
int main()
{
    Enter();
    Floyd();
    Solve();
    return 0;
}
