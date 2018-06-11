/*==============================================================================================================*\
**                                  _           _ _   _     _  _         _                                      **
**                                 | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   **
**                                 | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  **
**                                 | |_) | |_| | | |_| | | |__   _| | | | | | |                                 **
**                                 |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 **
\*==============================================================================================================*/
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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n, m, nCC, C1, nBridge, dfsTime, rootTree;
vi num, low, child;
vb avail;
vvi adj;
ll res;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v;
    scanf("%d%d", &n, &m);

    adj = vvi(n+1);
    avail = vb(n+1, true);
    num = low = child = vi(n+1);

    nCC = nBridge = dfsTime = C1 = 0;

    FOR(i, 1, m)
    {
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
}

//Check
void DFS(int u, int p)
{
    num[u] = low[u] = ++dfsTime;
    if(nCC == 1) ++C1;

    child[u] = 1; avail[u] = false;
    for(int v: adj[u]) if(v != p)
    {
        if(avail[v])
        {
            DFS(v, u);
            child[u] += child[v];
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }
    if(u != rootTree && low[u] == num[u]) ++nBridge;
}

//Process
void Solve()
{
    FOR(i, 1, n) if(avail[i])
    {
        rootTree = i, ++nCC;
        DFS(i, 0);
    }

    if(nCC > 2)
    {
        printf("0"); return;
    }

    if(nCC == 2)
    {
        res = (ll)(m - nBridge) * C1 * (n - C1);
    }
    else if(nCC == 1)
    {
        res = (ll)(m - nBridge) * ((ll)n * (n- 1) / 2 - m);
        FOR(i, 2, n) if(low[i] == num[i])
        {
            res += (ll)child[i] * (n - child[i]) - 1;
        }
    }

    printf("%lld", res);
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
