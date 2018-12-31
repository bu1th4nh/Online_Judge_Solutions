/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
//=====================================
//Solution Briefing - Foreword



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
#endif // __cplusplus

using namespace std;

// #define DEBUG
// #define OPTIONAL_FEATURE

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
    template<class T, class R> T max(T &x, R &y)
    {
        return x > y ? x : y;
    }
    template<class T, class R> T min(T &x, R &y)
    {
        return x < y ? x : y;
    }
    template<class T, class R> void maximize(T &x, R y)
    {
        x = x > y ? x : y;
    }
    template<class T, class R> void minimize(T &x, R y)
    {
        x = x < y ? x : y;
    }
    template<class T> int getBit(T &x, int i)
    {
        return ((x >> i) & 1) == 1;
    }
    template<class T> T __abs(T &x)
    {
        return (x = (x < 0) ? -x : x);
    }
#endif
//Fast I/O
template<class T> inline void read(T &ret)
{
    ret = T();
    char c = 0;
    bool neg = 0;

    while(isdigit(c) == 0 && c != '-') c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    ret = (neg) ? -ret : ret;

    #ifdef DEBUG
        cerr << "FastScan Diagnostic: " << ret << el;
    #endif
}
template<class T> void print(T x)
{
    if(x < 0)
    {
        putchar('-');
        x *= -1;
    }

    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

//=====================================
//Constants
const int inf = 1000000007;


//=====================================
//Typedefs
struct LowestCommonAncestor
{
    typedef set<int> si;
    typedef vector<si> vsi;
    typedef vector<int> vi;
    typedef vector<vi> vvi;

    const int MAX_LOG = 20;

    int n;
    vvi ST;
    vsi adj;
    vi level;

    void findLevel(int u)
    {
        for(int v: adj[u]) if(v != ST[0][u])
        {
            ST[0][v] = u;
            level[v] = level[u] + 1;
            findLevel(v);
        }
    }
    void InitST()
    {
        level[1] = 0;
        ST[0][1] = 1;
        findLevel(1);

        FOR(i, 1, MAX_LOG)
        {
            FOR(j, 1, n)
            {
                ST[i][j] = ST[i-1][ST[i-1][j]];
            }
        }
    }
    int LCA(int u, int v)
    {
        if(level[u] > level[v]) swap(u, v);
        int d = level[v] - level[u];
        FOR(i, 0, MAX_LOG)
        {
            if((d >> i) & 1 == 1) v = ST[i][v];
        }

        if(u == v) return u;
        FORb(i, MAX_LOG, 0) if(ST[i][u] != ST[i][v])
        {
            u = ST[i][u];
            v = ST[i][v];
        }
        return ST[0][u];
    }
    int getDist(int u, int v)
    {
        return level[u] + level[v] - 2 * level[LCA(u, v)];
    }


    ~LowestCommonAncestor() {}

    LowestCommonAncestor() {}
    LowestCommonAncestor(int __n, const vsi &G)
    {
        n = __n;
        adj = G;
        level = vi(n+1, 0);
        ST = vvi(MAX_LOG+5, vi(n+1, 0));
    }


    void operator= (const LowestCommonAncestor &x)
    {
        n = x.n;
        ST = x.ST;
        adj = x.adj;
        level = x.level;
    }
};

struct CentroidTreeDecomp
{
    typedef set<int> si;
    typedef vector<si> vsi;
    typedef vector<int> vi;
    typedef vector<vi> vvi;

    vsi adj;
    int nn, n;
    vi par, subtree;

    void findSubtree(int u, int p)
    {
        ++nn;
        subtree[u] = 1;

        for(int v: adj[u]) if(v != p)
        {
            findSubtree(v, u);
            subtree[u] += subtree[v];
        }
    }
    int findCentroid(int u, int p)
    {
        for(int v: adj[u]) if(v != p && subtree[v] * 2 > nn)
        {
            return findCentroid(v, u);
        }
        return u;
    }
    void decomp(int root, int p)
    {
        nn = 0;
        findSubtree(root, root);
        int centroid = findCentroid(root, root);

        if(p == -1) p = centroid;
        par[centroid] = p;

        for(int v: adj[centroid])
        {
            adj[v].erase(centroid);
            decomp(v, centroid);
        }
        adj[centroid].clear();
    }
    void initialize()
    {
        decomp(1, -1);
    }
    vi extract_tree()
    {
        return par;
    }


    ~CentroidTreeDecomp() {}

    CentroidTreeDecomp() {}
    CentroidTreeDecomp(int __n, const vsi &G)
    {
        n = __n;
        adj = G;
        par = subtree = vi(n+1, 0);
    }


    void operator= (const CentroidTreeDecomp &x)
    {
        n = x.n;
        adj = x.adj;
        par = x.par;
        subtree = x.subtree;
    }
};



//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef set<int> si;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<si> vsi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int nQuery, n;
vi res, par;
vsi adj;


LowestCommonAncestor lca;
CentroidTreeDecomp ctd;


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


//Enter
void Enter()
{
    int u, v;
	scanf("%d%d", &n, &nQuery);

	res = vi(n+1, inf);
	par = vi(n+1, 0);
	adj = vsi(n+1);

	FOR(i, 1, n-1)
	{
	    scanf("%d%d", &u, &v);
	    adj[u].insert(v);
	    adj[v].insert(u);
	}

	lca = LowestCommonAncestor(n, adj);
	ctd = CentroidTreeDecomp(n, adj);
}

//Check
void update(int u)
{
    int x = u;
    while(1)
    {
        //fprintf(stderr, "Distance form %d to %d is %d\n", x, u, lca.getDist(x, u));

        res[x] = min(res[x], lca.getDist(x, u));
        if(x == par[x]) break;
        x = par[x];
    }
}
int query(int u)
{
    int x = u;
    int ret = inf;
    while(1)
    {
        //fprintf(stderr, "Distance form %d to %d is %d\n", x, u, lca.getDist(x, u));

        ret = min(ret, res[x] + lca.getDist(u, x));
        if(x == par[x]) break;
        x = par[x];
    }

    return ret;
}


//Process
void Solve()
{
    int t, v;
    lca.InitST();
    ctd.initialize();
    par = ctd.extract_tree();

    //cerr << "Dist: " << lca.getDist(5, 1) << el;

    update(1);
    while(nQuery--)
    {
        scanf("%d%d", &t, &v);
        if(t == 1)
        {
            update(v);
        }
        else
        {
            printf("%d\n", query(v));
        }


        //FOR(i, 1, n) cerr << res[i] << sp; cerr << el;
    }
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
