//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp (int)(5010)
#define MODUL (int)(10e9+57)
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
int m, n;
bool avail[maxvalueinp];
bool a[maxvalueinp][maxvalueinp];
int res;


//=====================================
//Functions and procedures
//Input
void Input()
{
    scanf("%d%d", &n, &m);
    FOR(i, 1, m)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u][v] = true;
        a[v][u] = true;
    }
    MEMS(avail, true);
}

//Process
void DFS(int u)
{
    FOR(i, 1, n)
    {
        if(avail[i] && a[u][i])
        {
            avail[i] = false;
            DFS(i);
        }
    }
}


//Output





//Main Procedure
int main()
{
    int cnt = 0;
    Input();
    FOR(j, 1, n)
    {
        if(avail[j])
        {
            ++cnt;
            DFS(j);
        }
    }
    res = m - n + cnt;
    printf("%d", res);
    return 0;
}
