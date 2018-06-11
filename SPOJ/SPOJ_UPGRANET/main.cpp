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
#define maxinp (int)(131072)
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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<iii> viii;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<ll> vi;
ii par[maxinp][20];
vii adj[maxinp];
ll m, n, res;
vi root, h;
viii EList;
vb avail;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	scanf("%lld%lld", &n, &m);

	EList.push_back(iii(999999999, ii(-1, -1)));

	avail = vb(m+1, true);
	root = h = vi(n+1);

	FOR(i, 1, m)
	{
	    int u, v, c;
	    scanf("%lld%lld%lld", &u, &v, &c);
	    EList.push_back(iii(c, ii(u, v)));
	}
}

//Kruskal's Algorithm
ll GetRoot(ll u)
{
    return (root[u] == 0) ? u : (root[u] = GetRoot(root[u]));
}
bool cmp(iii a, iii b)
{
    return (a.first > b.first);
}
void Kruskal()
{
    res = 0;
    sort(whole(EList), cmp);
    FOR(i, 1, m)
    {
        iii edge = EList[i];
        int u = edge.second.first, v = edge.second.second, w = edge.first;
        int p = GetRoot(u), q = GetRoot(v);
        if(p != q)
        {
            root[p] = q;
            avail[i] = false;
            adj[u].pb(ii(v, w));
            adj[v].pb(ii(u, w));
        }
    }
}

//Process
void DFS(ll u, ll tr)
{
    for(ii vertex: adj[u])
    {
        ll v = vertex.first;
        if(v == tr) continue;
        h[v] = h[u] + 1;
        par[v][0] = ii(u, vertex.second);
        FOR(i, 1, 18)
        {
            par[v][i].first = par[par[v][i-1].first][i-1].first;
            par[v][i].second = min(par[par[v][i-1].first][i-1].second, par[v][i-1].second);
        }
        DFS(v, u);
    }
}
ii LCA(ll u, ll v)
{
    ii p;
    p.second = ll(1e18);
    if(h[u] > h[v]) swap(u, v);
    ll diff = h[v] - h[u];
    FORb(i, 18, 0) if((diff >> i)&1)
    {
        p.second = min(p.second, par[v][i].second);
        v = par[v][i].first;
    }
    if(v == u) return ii(u, p.second);
    FORb(i, 18, 0) if(par[u][i].first != par[v][i].first)
    {
        p.second = min(p.second, min(par[u][i].second, par[v][i].second));
        v = par[v][i].first;
        u = par[u][i].first;
    }
    return ii(par[u][0].first, min(p.second, min(par[u][0].second, par[v][0].second)));
}
void Solve()
{
    Kruskal();
    h[1] = 1;
    DFS(1, 0);
    FOR(i, 1, m) if(avail[i])
    {
        ii l = LCA(EList[i].second.first, EList[i].second.second);
        res += max(0LL, l.second - EList[i].first);
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
