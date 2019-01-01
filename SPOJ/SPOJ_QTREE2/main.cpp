/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
//=====================================
/*Solution Briefing - Foreword

    Use LCA. #lca #tree

      * The first query: DIST u v = dist[u] + dist[v] - 2 * dist[LCA(u, v)]
      * The second query: KTH u v k: Use binary lifting to find p-th parent
                        node of u or v depends on k. If k-1 is greater than
                        distance from node u to LCA(u, v) --> the needed
                        parent will lies on the path from v to LCA(u, v) and
                        vice versa.
*/
//=====================================
//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
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

#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <chrono>
#endif // __cplusplus

using namespace std;

//#define DEBUG
#define OPTIONAL_FEATURE

//=====================================
//Macroes
#define sp ' '
#define el '\n'
#define task ""
#define maxinp ()
#define fi first
#define se second
#define pb push_back
#define whole(x) x.begin(),x.end()
#define whole_1(x) x.begin()+1,x.end()
#define r_whole(x) x.rbegin(),x.rend()
#define FOR(i, x, y) for(auto i=x; i<=y; ++i)
#define FORl(i, x, y) for(auto i=x; i<y; ++i)
#define FORb(i, x, y) for(auto i=x; i>=y; --i)
#define FORlb(i, x, y) for(auto i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define what_is(x) cerr << #x << " is " << x << endl;
#define FILEOP()                        \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
}
#define FILEOP_DEBUG()                  \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
    freopen(task".err", "w", stderr);   \
}

//Macroes - Optional
#ifdef OPTIONAL_FEATURE
    #define pc(x) putchar(x)
    #define gc() getchar()
#endif



//=====================================
//Auxilary Functions and Fast I/O
#ifdef OPTIONAL_FEATURE
    template<class T, class R> T max(const T &__X, const R &__Y)
    {
        return __X > __Y ? __X : __Y;
    }
    template<class T, class R> T min(const T &__X, const R &__Y)
    {
        return __X < __Y ? __X : __Y;
    }
    template<class T, class R> void maximize(T &__X, R __Y)
    {
        __X = __X > __Y ? __X : __Y;
    }
    template<class T, class R> void minimize(T &__X, R __Y)
    {
        __X = __X < __Y ? __X : __Y;
    }
    template<class T> int getBit(T &__X, int __i)
    {
        return ((__X >> __i) & 1) == 1;
    }
    template<class T> bool inRange(T __L, T __R, T __X)
    {
        return __L <= __X && __X <= __R;
    }
    template<class T> T __abs(T __X)
    {
        return (__X < 0) ? -__X : __X;
    }
#endif
//Fast I/O
template<class T> inline void scan(T &__ret)
{
    __ret = T();
    char c = 0;
    bool neg = 0;

    while(isdigit(c) == 0 && c != '-') c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) __ret = __ret * 10 + c - '0';
    __ret = (neg) ? -__ret : __ret;
}
template<class T> void print(T __X)
{
    if(__X < 0)
    {
        putchar('-');
        __X *= -1;
    }

    if(__X > 9) print(__X / 10);
    putchar(__X % 10 + '0');
}

//=====================================
//Constants



//=====================================
//Typedefs
class LowestCommonAncestor
{
    typedef long long ll;
    typedef pair<int, int> ii;
    typedef vector<ii> vii;
    typedef vector<ll> vll;
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    typedef vector<vii> vvii;

    int n;
    vvi par;
    vi depth;
    vll dist;
    vvii adj;


    void findLevel(int u, int p)
    {
        for(ii x: adj[u]) if(x.se != p)
        {
            int v = x.se;

            par[v][0] = u;
            depth[v] = depth[u] + 1;
            dist[v] = dist[u] + x.fi;

            findLevel(v, u);
        }
    }
    int LCA(int u, int v)
    {
        FORb(k, 19, 0) if(depth[par[u][k]] >= depth[v]) u = par[u][k];
        FORb(k, 19, 0) if(depth[par[v][k]] >= depth[u]) v = par[v][k];
        FORb(k, 19, 0) if(par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
        while(u != v) u = par[u][0], v = par[v][0];

        return u;
    }


public:
    void addEdge(int u, int v, int w)
    {
        adj[u].pb(ii(w, v));
    }
    void initTable()
    {
        findLevel(1, 0);
        FOR(kth, 1, 19)
        {
            FOR(u, 1, n) par[u][kth] = par[par[u][kth-1]][kth-1];
        }
    }
    ll getDistance(int u, int v)
    {
        return dist[u] + dist[v] - 2 * dist[LCA(u, v)];
    }
    int getKth_node(int u, int v, int kth)
    {
        int lca = LCA(u, v); --kth;
        int target_node = (depth[u] - depth[lca] >= kth) ? u : v;
        int target_pare = (depth[u] - depth[lca] >= kth) ? kth : depth[u] + depth[v] - 2 * depth[lca] - kth;

        //cerr << target_node << sp << target_pare << el;

        FORb(i, 19, 0) if((1 << i) <= target_pare)
        {
            target_node = par[target_node][i];
            target_pare -= 1 << i;
        }
        return target_node;
    }


    LowestCommonAncestor() {}
    LowestCommonAncestor(int __n)
    {
        n = __n;
        adj = vvii(n+1);
        depth = vi(n+1, 0);
        dist = vll(n+1, 0LL);
        par = vvi(n+1, vi(22, 0));
    }
};



//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int nTest, nQuery, n;

//=====================================
//Functions and procedures
//File I/O and utilities
void FileInit()
{
    FILEOP()
}
void FileDebug()
{
    #ifdef DEBUG
        FILEOP_DEBUG()
    #else
        FILEOP()
    #endif
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}


//Check
void Solve()
{
    int u, v, w;
    string t = "FUCK";

    scan(n);
    LowestCommonAncestor ctb(n);

    FORl(i, 1, n)
    {
        scan(u);
        scan(v);
        scan(w);

        ctb.addEdge(u, v, w);
    }
    ctb.initTable();
    while(cin >> t && t != "DONE")
    {
        if(t == "DIST")
        {
            scan(u);
            scan(v);
            print(ctb.getDistance(u, v));
        }
        else
        {
            scan(u);
            scan(v);
            scan(w);
            print(ctb.getKth_node(u, v, w));
        }
        putchar(el);
    }
    putchar(el);
}


//Output
void MULTi()
{
    scan(nTest);
    while(nTest--)
    {
        Solve();
    }
}



//Main Procedure
int main()
{
    MULTi();
    return 0;
}

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
