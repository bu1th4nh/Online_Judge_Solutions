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
    template<class T> T __sqr(T __X)
    {
        return __X * __X;
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
const int inf = 1000000007;


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
int n, m, nVtx, srce, sink, timeStamp;
vi dist, Dfs, trace;
vvi cap, flow, adj;
vii res;

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
#define what_is(x) cerr << #x << " is " << x << endl;
void debugInput()
{
	what_is(srce);
	what_is(sink);
	what_is(nVtx);
    FOR(i, 0, nVtx)
	{
	    cerr << i << ": ";
	    for(int x: adj[i]) cerr << x << sp;
	    cerr << el;
	}
	cerr << el;
	FOR(i, 0, nVtx)
	{
	    for(int x: adj[i]) cerr << i << sp << x << el;
	}
	cerr << el;
	FOR(i, 0, nVtx)
	{
	    FOR(j, 0, nVtx) cerr << cap[i][j] << sp;
	    cerr << el;
	}
	cerr << el;
}


//Enter
void Enter()
{
    int u, v;
    string s;

	scan(n);
	scan(m);

	nVtx = 2*n+m+1;
	res = vii(m+1);
	adj = vvi(nVtx+10);
	Dfs = dist = trace = vi(nVtx+10, 0);
	cap = flow = vvi(nVtx+10, vi(nVtx+10, 0));
	srce = 0, sink = nVtx;



	FOR(i, 1, 2*n)
	{
	    getline(cin, s);
	    stringstream ss(s);

	    while(ss >> u)
        {
            v = i + int(i > n) * m;
            adj[v].pb(u+n);
            adj[u+n].pb(v);
            if(i > n) ++cap[u+n][v];
            else      ++cap[i][u+n];
        }
	}

	FOR(i, 1, n)
	{
	    adj[i].pb(srce); adj[i+m+n].pb(sink);
	    adj[srce].pb(i); adj[sink].pb(i+m+n);
	    ++cap[srce][i];  ++cap[i+m+n][sink];
	}
}

//Trace
void updTrace(int u, int v)
{
    trace[v] = u;
}

//Check
bool BFS(int s, int t)
{
    queue<int> q;
    dist = vi(nVtx+1, 0);
    dist[s] = 1;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        if(u == t) return 1;

        for(int v: adj[u]) if(dist[v] == 0 && flow[u][v] < cap[u][v])
        {
            q.push(v);
            dist[v] = dist[u] + 1;
        }
    }
    return 0;
}
int DFS(int u, int bottleneck)
{
    if(u == sink) return bottleneck;
    if(Dfs[u] != timeStamp) Dfs[u] = timeStamp;
    else return 0;

    for(int v: adj[u]) if(flow[u][v] < cap[u][v])
    {
        if(Dfs[v] != timeStamp && dist[v] == dist[u] + 1)
        {
            if(int x = DFS(v, min(bottleneck, cap[u][v] - flow[u][v])))
            {
                flow[u][v] += x;
                flow[v][u] -= x;

                updTrace(u, v);
                return x;
            }
        }
    }
    return 0;
}


//Process
void Dinic()
{
    //cerr << el;
    int mflow = 0;
    while(BFS(srce, sink))
    {
        while(int x = (timeStamp++, DFS(srce, inf)))
        {
            mflow += x;
        }
    }
}
void Solve()
{
    int x, y, z;
    //FOR(i, 1, n) cerr << i+m+n << sp << trace[i+m+n] << sp << trace[trace[i+m+n]] << el;

    FOR(i, 1, n)
    {
        x = i+m+n;
        y = trace[x];
        z = trace[y];

        res[y-n] = {z, i};
    }
    FOR(i, 1, m)
    {
        printf("%d %d\n", res[i].fi, res[i].se);
    }
}

//Main Procedure
int main()
{
    Enter();
    Dinic();
    Solve();
    return 0;
}

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
