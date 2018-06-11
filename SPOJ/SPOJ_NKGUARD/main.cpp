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
#define maxvalueinp (int)(707)
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
typedef pair<int, int> p2i;
typedef queue<p2i> qp;
bool avail[maxvalueinp][maxvalueinp];
int a[maxvalueinp][maxvalueinp];
int movex[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int movey[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int m, n, res;
qp dir;

//=====================================
//Functions and procedures
//Input
void Input()
{
    MEMS(avail, true);
    scanf("%d%d", &n, &m);
    FOR(i, 0, m+1)
    {
        a[0][i] = -1;
        a[n+1][i] = -1;
    }
    FOR(i, 0, n+1)
    {
        a[i][0] = -1;
        a[i][n+1] = -1;
    }
    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            scanf("%d", &a[i][j]);
            //cin >> a[i][j];
        }
    }
}

//Process
void FloodFill(int u, int v)
{
    dir.push(make_pair(u, v));
    bool ok = true;
    avail[u][v] = false;
    while(!dir.empty())
    {
        p2i x = dir.front();
        dir.pop();
        int curx = x.first;
        int cury = x.second;
        FORl(i, 0, 8)
        {
            int nextx = curx + movex[i];
            int nexty = cury + movey[i];
            if (a[nextx][nexty] > a[curx][cury]) ok = false;
            if (a[nextx][nexty] == a[curx][cury] && avail[nextx][nexty])
            {
                dir.push(make_pair(nextx, nexty));
                avail[nextx][nexty] = false;
            }
        }
    }
    if(ok)
    {
        res = res + 1;
    }
}
void Process()
{
    res = 0;
    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            if(avail[i][j])
            {
                FloodFill(i, j);
            }
        }
    }
    printf("%d", res);
}



//Main Procedure
int main()
{
    Input();
    Process();
    return 0;
}
