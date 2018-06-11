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
//Lowest Common Ancestor
struct LowestCommonAncestor
{
    typedef vector<int> vi;
    typedef vector<vi> vvi;

    vvi P;
    vi dep;
    int n, root;


    void addEdge(int u, int v)
    {
        P[0][v] = u;
    }
    int findLvl(int u)
    {
        if(u == root) return (dep[u] = 1);
        if(dep[u] == 0) return (dep[u] = findLvl(P[0][u]) + 1);
        return dep[u];
    }
    void init()
    {
        FOR(i, 1, n) if(!P[0][i]) root = i;
        FOR(i, 1, n) findLvl(i);
        FOR(k, 1, 19)
        {
            FOR(i, 1, n)
            {
                P[k][i] = P[k-1][P[k-1][i]];
            }
        }
    }
    int LCA(int x, int y)
    {
        FORb(k, 19, 0) if(dep[P[k][x]] >= dep[y]) x = P[k][x];
        FORb(k, 19, 0) if(dep[P[k][y]] >= dep[x]) y = P[k][y];
        FORb(k, 19, 0) if(P[k][x] != P[k][y]) x = P[k][x], y = P[k][y];
        while(x != y) x = P[0][x], y = P[0][y];

        return x;
    }


    LowestCommonAncestor(int __n)
    {
        n = __n;
        dep = vi(n+2, 0);
        P = vvi(20, vi(n+2, 0));
    }
    LowestCommonAncestor() {}


    ~LowestCommonAncestor() {}
};


//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
LowestCommonAncestor lca;
int n, q;
vvii adj;
vb avail;
vi F;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP();
}
void FileDebug()
{
    FILEOP_DEBUG();
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter()
{
    int u, v, c;
	scanf("%d%d", &n, &q);

	lca = LowestCommonAncestor(n);
	avail = vb(n+1, true);
	adj = vvii(n+1);
	F = vi(n+1, 0LL);

	FOR(i, 1, n-1)
    {
        scanf("%d%d%d", &u, &v, &c);
        adj[u].pb(ii(v, c));
        adj[v].pb(ii(u, c));
    }
}

//Check
void DFS(int u, int p)
{
    avail[u] = false;
    for(ii x: adj[u])
    {
        if(avail[x.first])
        {
            lca.addEdge(u, x.first);
            F[x.first] = F[u] + x.second;
            DFS(x.first, u);
        }
    }
}

//Process
void Solve()
{
    DFS(1, 0);

    lca.init();

    while(q--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        cout << F[x] + F[y] - 2*F[lca.LCA(x, y)] << "\n";
    }

}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
