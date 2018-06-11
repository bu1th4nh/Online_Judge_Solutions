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
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


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
typedef queue<int> qi;
int n, nQuery;
vi h, F, ord;
vvi adj, P;
qi q;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v;
	scanf("%d", &n);

	P = vvi(25, vi(n+1, 0));
	F = h = vi(n+1, 0);
	adj = vvi(n+1);

	FOR(i, 1, n-1)
	{
	    scanf("%d%d", &u, &v);
	    adj[u].pb(v);
	    adj[v].pb(u);
	}

	scanf("%d", &nQuery);
}

//Check
void BFS(int u)
{
    ord.push_back(-1);
    ord.push_back(u);
    q.push(u);
    h[u] = 1;

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int v: adj[u]) if(!h[v])
        {
            h[v] = h[u] + 1;
            P[0][v] = u;
            q.push(v);
            ord.push_back(v);
        }
    }
}
void Init()
{
    FOR(k, 1, 19)
    {
        FOR(i, 1, n) if(P[k-1][i] != 0)
        {
            P[k][i] = P[k-1][P[k-1][i]];
        }
    }
}
void LCA(int u, int v)
{
    ++F[u], ++F[v];
    if(h[u] < h[v]) swap(u, v);
    if(h[u] != h[v])
    {
        FORb(k, 19, 0) if((h[u] - h[v]) & (1 << k))
        {
            u = P[k][u];
        }
    }

    if(u != v)
    {
        FORb(k, 19, 0) if(P[k][u] != P[k][v])
        {
            u = P[k][u];
            v = P[k][v];
        }
        u = P[0][u];
    }
    F[u] -= 2;
}

//Process
void Solve()
{
    int u, v;
    BFS(1);
    Init();

    while(nQuery--)
    {
        scanf("%d%d", &u, &v);
        LCA(u, v);
    }

    int res = 0;

    FORb(i, n, 2)
    {
        u = ord[i];
        for(int v: adj[u]) if(v != P[0][u])
        {
            F[u] += F[v];
        }
        if(F[u] == 0) ++res;
    }

    printf("%d", res);
}



//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
