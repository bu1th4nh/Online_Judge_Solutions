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
#define maxvalueinp (int)(128)
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

   //-------DFS-------

//=====================================
//Typedef
typedef pair<int, int> p2i;
typedef queue <p2i> qp;
int a[maxvalueinp][maxvalueinp];
//int a[maxvalueinp][maxvalueinp];
int nextx[4] = {-1, 0, 0, 1};
int nexty[4] = {0, -1, 1, 0};
int m, n, maxh, minh, res;
qp dir;

//=====================================
//Functions and procedures
//Input
void Input()
{
    MEMS(a, 12345);
    maxh = -1;
    //minh = 1000000;
    scanf("%d%d", &m, &n);
    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            scanf("%d", &a[i][j]);
            maxh = max(maxh, a[i][j]);
            //minh = min(minh, a[i][j]);
        }
    }
}

//Check
bool Check(int xx, int yy)
{
    return (xx > 0 && xx <= m && yy > 0 && yy <= n);
}

//Process
void FloodFill(int u, int v, int h)
{
    if(a[u][v] != h) return;
    a[u][v] = h+1;
    FORl(i, 0, 4)
    {
        int x = u + nextx[i];
        int y = v + nexty[i];
        if(true)
        {
            //++a[x][y];
            FloodFill(x, y, h);
        }
    }
}
void Process()
{
    res = 0;
    FORl(k, 0, maxh)
    {
        FOR(i, 1, n)
        {
            FloodFill(1, i, k);
            FloodFill(m, i, k);
        }
        FOR(i, 1, m)
        {
            FloodFill(i, 1, k);
            FloodFill(i, n, k);
        }
        FORl(i, 2, m)
        {
            FORl(j, 2, n)
            {
                if(a[i][j] == k)
                {
                    ++res;
                    a[i][j] = k+1;
                }
            }
        }
    }
    printf("%d", res);
}

//Output





//Main Procedure
int main()
{
    Input();
    Process();
    return 0;
}


/* //-------BFS-------

//=====================================
//Typedef
typedef pair<int, int> p2i;
typedef queue <p2i> qp;
int a[maxvalueinp][maxvalueinp];
int F[maxvalueinp][maxvalueinp];
int nextx[4] = {-1, 0, 0, 1};
int nexty[4] = {0, -1, 1, 0};
int m, n, maxh, minh, res;
qp dir;

//=====================================
//Functions and procedures
//Input
void Input()
{
    MEMS(a, 0);
    maxh = -1;
    minh = 1000000;
    scanf("%d%d", &m, &n);
    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            scanf("%d", &a[i][j]);
            maxh = max(maxh, a[i][j]);
            minh = min(minh, a[i][j]);
        }
    }
}

//Check
bool Check(int xx, int yy)
{
    return (xx > 0 && xx <= m && yy > 0 && yy <= n);
}

//Process
void FloodFill(int u, int v, int h)
{
    if(a[u][v]!=h) return;
    F[u][v] = h+1;
    dir.push(make_pair(u, v));
    while(!dir.empty())
    {
        p2i cur = dir.front();
        dir.pop();
        int curx = cur.first;
        int cury = cur.second;
        FORl(i, 0, 4)
        {
            int x = curx + nextx[i];
            int y = cury + nexty[i];
            if(Check(x, y) && a[x][y] == h)
            {
                F[x][y] = h+1;
                dir.push(make_pair(x, y));
            }
        }
    }
}
void Process()
{
    MEMS(F, -1);
    res = 0;
    FORl(k, 0, maxh)
    {
        FOR(i, 1, n)
        {
            FloodFill(1, i, k);
            FloodFill(m, i, k);
        }
        FOR(i, 1, m)
        {
            FloodFill(i, 1, k);
            FloodFill(i, n, k);
        }
        FORl(i, 2, m)
        {
            FORl(j, 2, n)
            {
                if(a[i][j] == k)
                {
                    ++res;
                    F[i][j] = k+1;
                }
            }
        }
    }
    printf("%d", res);
}

//Output





//Main Procedure
int main()
{
    Input();
    Process();
    return 0;
}

*/
