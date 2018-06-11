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
#define maxvalueinp (int)(256)
#define MODUL (int)(1000000000)
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
struct NODE
{
    int valx, valy, staff;
    NODE(int x, int y, int z)
    {
        valx = x;
        valy = y;
        staff = z;
    }
};
typedef vector<int> vi;
typedef queue<NODE> qs;
int F[maxvalueinp][maxvalueinp][2];
vi adj[maxvalueinp];
int m, n, s, t, res;
qs dir;

//=====================================
//Functions and procedures
//Input
void Input()
{
    res = MODUL;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    FOR(i, 1, m)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
    }
    //MEMS(F, MODUL);
    FOR(i, 1, n)
    {
        F[i][i][0] = MODUL;
        F[i][i][1] = MODUL;
    }
    FOR(i, 1, n-1)
    {
        FOR(j, i+1, n)
        {
            F[i][j][0] = MODUL;
            F[i][j][1] = MODUL;
            F[j][i][0] = MODUL;
            F[j][i][1] = MODUL;
        }
    }
}

//Flood Fill
void FloodFill()
{
    F[s][t][0] = 0;
    dir.push(NODE(s, t, 0));
    while(!dir.empty())
    {
        NODE cur = dir.front();
        dir.pop();
        int u = cur.valx;
        int v = cur.valy;
        int k = cur.staff;
        if(k==0)
        {
            FORl(i, 0, siz(adj[u]))
            {
                int next = adj[u][i];
                if(F[next][v][1] == MODUL)
                {
                    F[next][v][1] = F[u][v][0];
                    dir.push(NODE(next, v, 1));
                }
            }
        }
        else
        {
            FORl(i, 0, siz(adj[v]))
            {
                int next = adj[v][i];
                if(F[u][next][0] == MODUL)
                {
                    F[u][next][0] = F[u][v][1]+1;
                    if(u==next)
                    {
                        res = F[u][next][0];
                        return;
                    }
                    dir.push(NODE(u, next, 0));
                }
            }
        }
    }
}
void Output()
{
    if(res == MODUL) printf("-1");
    else printf("%d", res);
}

//Main Procedure
int main()
{
    Input();
    FloodFill();
    Output();
    return 0;
}
