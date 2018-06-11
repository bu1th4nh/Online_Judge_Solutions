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
struct Edge
{
	int u, v;
	int cost;
	int LCA;
	Edge(int __u, int __v, int __c)
	{
		u = __u, v = __v, cost = __c;
	}
};
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi discover, finish, depth, deg, col;
int n, m, cost_sum, traversal_time;
vector<Edge> E;
vvi tree, F;
vii par;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	int u, v, c;
	cost_sum = 0;
	scanf("%d%d", &n, &m);

	discover = finish = depth = deg = col = vi(n+2, 0);
	F = vvi(n+1, vi(1069, 0));
	par = vii(n+2);
	tree = vvi(n);

	par[0] = ii(-1, -1);

	FOR(i, 1, m)
	{
		scanf("%d%d%d", &u, &v, &c);
		E.pb(Edge(--u, --v, c));

		cost_sum += c;
		if(c == 0)
		{
			tree[u].pb(v);
			tree[v].pb(u);
		}
	}
}

//Check
bool Check(const Edge __a, const Edge __b)
{
	return finish[__a.LCA] < finish[__b.LCA];
}


//Process
void DFS(int a)
{
	discover[a] = ++traversal_time;
	for(int x: tree[a])
	{
		if(x == par[a].fi) continue;
		col[x] = col[a] ^ 1;
		depth[x] = depth[a] + 1;

		par[x] = ii(a, 1 << deg[a]++);

		DFS(x);
	}
	finish[a] = ++traversal_time;
}
void CalcLCA()
{
	FORl(i, 0, m)
	{
		int u = E[i].u;
		int v = E[i].v;
		while(depth[u] > depth[v]) u = par[u].fi;
		while(depth[v] > depth[u]) v = par[v].fi;
		while(u != v)
		{
			u = par[u].fi;
			v = par[v].fi;
		}
		E[i].LCA = u;
	}
}
void Solve()
{
	DFS(0);
	CalcLCA();
	sort(whole(E), Check);

	ii u, v;
	FORl(i, 0, m)
	{
		if(E[i].cost != 0 && col[E[i].u] != col[E[i].v]) continue;

		int L = E[i].LCA;
		int sum = E[i].cost;

		for(u = ii(E[i].u, 0); u.fi != L; u = par[u.fi]) sum += F[u.fi][u.se];
		for(v = ii(E[i].v, 0); v.fi != L; v = par[v.fi]) sum += F[v.fi][v.se];

		for(int mask = (1 << deg[L]) - 1; mask >= 0; --mask)
		{
			if(!(mask & u.se || mask & v.se))
			{
				F[L][mask] = max(sum + F[L][mask | u.se | v.se], F[L][mask]);
			}
		}
	}

	cout << cost_sum - F[0][0];
}

//Main Procedure
int main()
{
	Enter();
	Solve();
    return 0;
}
