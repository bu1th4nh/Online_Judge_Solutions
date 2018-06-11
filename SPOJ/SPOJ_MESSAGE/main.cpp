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
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef stack<int> sti;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef long long ll;
vi num, low, scc, deg_in;
int m, n, nTime, nSCC;
vvi adj;
sti s;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v;

    scanf("%d%d", &n, &m);

    adj = vvi(n);
    nSCC = nTime = 0;
    num = low = scc = vi(n, -1);

    FOR(i, 1, m)
    {
        scanf("%d%d", &u, &v);
        adj[--u].pb(--v);
    }
}

//Check
void DFS(int u)
{
    s.push(u); num[u] = low[u] = nTime++;

    for(int v: adj[u]) if(num[v] == -1)
    {
        DFS(v), low[u] = min(low[u], low[v]);
    }
    else
    {
        low[u] = min(low[u], num[v]);
    }

    if(low[u] == num[u])
    {
        int v;
        do
        {
            v = s.top(); s.pop();
            scc[v] = nSCC;
        }
        while(u != v);
        ++nSCC;
    }
    num[u] = 1000000007;
}

//Process
void Solve()
{
    FORl(u, 0, n) if(num[u] == -1) DFS(u);

    deg_in = vi(nSCC);

    FORl(u, 0, n)
    {
        for(int v: adj[u])
        {
            if(scc[u] != scc[v]) ++deg_in[scc[v]];
        }
    }

    printf("%d",  count(whole(deg_in), 0)  );
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
