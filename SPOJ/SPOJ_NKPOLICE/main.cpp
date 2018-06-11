/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define siz(x) (int)(x.size())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}

const int LOG_N = 16;
const int MAX_N = 131072;
//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n, m, dfsTime, nQuery;
vi num, low, dep, comp, F;
vvi adj, p;
vb IsCut;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v;
    scanf("%d%d", &n, &m);

    dfsTime = 0;

    adj = vvi(n);
    num = vi(n, -1);
    low = dep = comp = F = vi(n);
    p = vvi(MAX_N, vi(LOG_N + 1, -1));

    IsCut = vb(n, false);

    FOR(i, 1, m)
    {
        scanf("%d%d", &u, &v);
        adj[--u].pb(--v);
        adj[v].pb(u);
    }
    scanf("%d", &nQuery);

}


//DFS
void DFS(int u, int c)
{
    int nChild = 0;

    comp[u] = c;
    num[u] = low[u] = dfsTime++;

    for(int v: adj[u]) if(num[v] == -1)
    {
        dep[v] = dep[u] + 1;

        p[v][0] = u;

        ++nChild;


        DFS(v, c);

        low[u] = min(low[u], low[v]);

        if(low[v] >= num[u] || (p[u][0] == -1 && nChild == 2)) IsCut[u] = true;
    }
    else if(v != p[u][0]) low[u] = min(low[u], num[v]);
    F[u] =  dfsTime++;
}


//Utilities
bool IsDescendant(int u, int v)
{
    return num[u] >= num[v] && F[u] <= F[v];
}
void InitST()
{
    for(int i = 1; 1 << i < n; ++i)
    {
        FORl(u, 0, n) if(p[u][i-1] != -1) p[u][i] = p[p[u][i-1]][i-1];
    }
}
int jump(int u, int x)
{
    FOR(i, 0, LOG_N) if(x & (1 << i)) u = p[u][i];
    return u;
}


//Check
bool canGo(int x, int y, int z)
{
    if(comp[x] != comp[y]) return false;
    if(comp[x] != comp[z]) return true;
    if(!IsCut[z]) return true;
    if(!IsDescendant(x, z) && !IsDescendant(y, z)) return true;
    if(!IsDescendant(x, z)) return canGo(y, x, z);

    int px = jump(x, dep[x] - dep[z] - 1);
    if(IsDescendant(y, z))
    {
        int py = jump(y, dep[y] - dep[z] - 1);
        return px == py || (low[px] < num[z] && low[py] < num[z]);
    }

    return low[px] < num[z];
}
bool canGo(int x, int y, int u, int v)
{
    if(comp[x] != comp[y]) return false;
    if(comp[x] != comp[u]) return true;

    if(!IsDescendant(v, u)) return canGo(x, y, v, u);

    if(low[v] < num[v]) return true;

    return !(IsDescendant(x, v) ^ IsDescendant(y, v));
}
void out(bool x) {puts(x ? "yes" : "no");}



//Process
void Query()
{
    int x, y, u, v, t;
    FOR(i, 1, nQuery)
    {
        scanf("%d", &t);
        if(t == 1)
        {
            scanf("%d%d%d%d", &x, &y, &u, &v);
            out(canGo(--x, --y, --u, --v));
        }
        else
        {
            scanf("%d%d%d", &x, &y, &u);
            out(canGo(--x, --y, --u));
        }
    }
}


//Output
void Solve()
{
    for(int u = 0, c = 0; u < n; ++u) if(num[u] == -1) DFS(u, c++);
    InitST();
    Query();
}



//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
