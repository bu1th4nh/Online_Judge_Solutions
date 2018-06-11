//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
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
#define MODUL (int)(1e9+57)
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}

//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
vi color, par;
vvi adj, F;
int n;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%d", &n);

    par = vi(n+4);
    adj = vvi(n+4);
    color = vi(n+4);
    F = vvi(n+4, vi(4));

    FORl(i, 1, n)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

//DFS + DP
void DFS(int u)
{
    FOR(i, 1, 3) F[u][i] = i;
    for(int v: adj[u]) if(par[u] != v)
    {
        par[v] = u;
        DFS(v);
        F[u][1] += min(F[v][2], F[v][3]);
        F[u][2] += min(F[v][1], F[v][3]);
        F[u][3] += min(F[v][1], F[v][2]);
    }
}

//Trace
void Trace(int u, int col)
{
    color[u] = col;
    for(int v: adj[u]) if(par[u] != v)
    {
        if(col == 1)
        {
            if(F[v][2] < F[v][3]) Trace(v, 2);
            else Trace(v, 3);
        }
        else if(col == 2)
        {
            if(F[v][1] < F[v][3]) Trace(v, 1);
            else Trace(v, 3);
        }
        else if(col == 3)
        {
            if(F[v][1] < F[v][2]) Trace(v, 1);
            else Trace(v, 2);
        }
    }
}

//Process
void Solve()
{
    int root = 1, res = INFINITY, cres = -1;
    DFS(root);
    FOR(i, 1, 3)
    {
        if(res > F[root][i])
        {
            res = F[root][i];
            cres = i;
        }
    }
    Trace(root, cres);
    printf("%d\n", res);
    FOR(i, 1, n) printf("%d\n", color[i]);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
