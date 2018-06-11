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
struct LowestCommonAncestor
{
    typedef vector<int> vi;
    typedef vector<vi> vvi;

    vvi P;                  //P[i][j]: The 2^i-th ancestor of node j
    vi dist;                //dist[i]: the depth of i-th node
    int n, root;

    void addEdge(int u, int v)
    {
        P[0][v] = u;
    }
    int findLevel(int u)
    {
        if(u == root) return dist[u] = 1;
        if(dist[u] == 0) dist[u] = findLevel(P[0][u]) + 1;
        return dist[u];
    }
    void initSparseTable()
    {
        FOR(i, 1, n) if(P[0][i] == 0) root = i;
        FOR(i, 1, n) findLevel(i);
        FOR(k, 1, 19)
        {
            FOR(i, 1, n)
            {
                P[k][i] = P[k-1][P[k-1][i]];        //Dynamic Programming
            }
        }
    }
    int LCA(int x, int y)
    {
        FORb(k, 19, 0) if(dist[P[k][x]] >= dist[y]) x = P[k][x];     //Jump!
        FORb(k, 19, 0) if(dist[P[k][y]] >= dist[x]) y = P[k][y];
        FORb(k, 19, 0) if(P[k][x] != P[k][y]) x = P[k][x], y = P[k][y];
        while(x != y) x = P[0][x], y = P[0][y];

        return x;
    }



    LowestCommonAncestor(int __n)
    {
        n = __n;
        dist = vi(n+2, 0);
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
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;

//=====================================
//Functions and procedures
void Solve()
{
	int tc, m, n, u, v;

	scanf("%d", &tc);
	FOR(iTest, 1, tc)
    {
        scanf("%d", &n);

        LowestCommonAncestor lca(n);

        FOR(i, 1, n)
        {
            scanf("%d", &m);
            while(m-- > 0)
            {
                scanf("%d", &u);
                lca.addEdge(i, u);      //P[0][v] = u; - (u, v)
            }
        }

        lca.initSparseTable();

        scanf("%d", &m);
        printf("Case %d:\n", iTest);
        while(m-- > 0)
        {
            scanf("%d%d", &u, &v);
            printf("%d\n", lca.LCA(u, v));
        }
    }
}

//Main Procedure
int main()
{
    Solve();
    return 0;
}
