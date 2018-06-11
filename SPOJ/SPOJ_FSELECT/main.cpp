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
int n, k, root, maxDepth;
vvi adj, meet, par;
vi dep;



//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v;
	scanf("%d%d", &n, &k);

	dep = vi(n+1);
	adj = meet = vvi(n+1);
	par = vvi(20, vi(n+1, 0));

	FOR(i, 1, n)
	{
	    scanf("%d%d", &u, &v);
	    adj[(par[0][i] = v)].pb(i);
	    meet[u].pb(i);
	    if(v == 0) root = v;
	}
}

//Check
void DFS(int u)
{
    if(dep[u] > maxDepth) maxDepth = dep[u];
    for(int v: adj[u])
    {
        dep[v] = dep[u] + 1;
        DFS(v);
    }
}
void InitLCA()
{
    FOR(k, 1, 19)
    {
        FOR(i, 1, n) par[k][i] = par[k-1][par[k-1][i]];
    }
}
int LCA(int x, int y)
{
    int lg;
    if(dep[x] < dep[y]) swap(x, y);
    for(lg = 0; 1 << lg <= dep[x]; ++lg);

    FORb(i, lg, 0)
    {
        if(dep[x] - (1 << i) >= dep[y]) x = par[i][x];
    }

    if(x == y) return x;
    FORb(i, lg, 0)
    {
        if(par[i][x] && par[i][x] != par[i][y]) x = par[i][x], y = par[i][y];
    }

    return par[0][x];
}

void Query(vi meeting)
{
    int x = meeting[0], y = 0, maxDist = 0, res = 0;
    for(int j: meeting)
    {
        int dist = dep[x] + dep[j] - 2*dep[LCA(x, j)];
        if(dist > maxDist) maxDist = dist, y = j;
    }
    for(int j: meeting)
    {
        int dist = dep[y] + dep[j] - 2*dep[LCA(y, j)];
        if(dist > res) res = dist;
    }
    cout << res << "\n";
}

//Process
void Solve()
{
    DFS(root);
    InitLCA();
    FOR(i, 1, k) Query(meet[i]);
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
