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
template<class T> class SegmentTree
{
private:

    #define lc id*2
    #define rc id*2+1
    struct Node
    {
        T val, lazy;
        Node(): val(T()), lazy(T()) {}
        Node(T __v): val(__v), lazy(0) {}
        Node(T __v, T __l): val(__v), lazy(__l) {}
    };
    typedef vector<Node> vn;

    vn ST;
    void push_down(int id, T value)
    {
        ST[lc].lazy += value;
        ST[rc].lazy += value;
    }
    void increase(int id, int l, int r, T value)
    {
        ST[id].val += (r - l + 1) * value;
        if(l != r) push_down(id, value);
        ST[id].lazy = T();
    }


public:

    void update(int id, int l, int r, int ql, int qr, T value)
    {
        if(ST[id].lazy) increase(id, l, r, ST[id].lazy);
        if(r  <  l || qr < l || r < ql) return;
        if(ql <= l && r  <= qr)
        {
            increase(id, l, r, value);
            return;
        }

        int mid = (l + r) / 2;
        update(lc, l, mid, ql, qr, value);
        update(rc, mid+1, r, ql, qr, value);
        ST[id].val = ST[lc].val + ST[rc].val;
    }
    T query(int id, int l, int r, int ql, int qr)
    {
        if(r < l || qr < l || r < ql) return T();
        if(ST[id].lazy) increase(id, l, r, ST[id].lazy);
        if(ql <= l && r <= qr) return ST[id].val;

        int mid = (l + r) / 2;
        return query(lc, l, mid, ql, qr) + query(rc, mid+1, r, ql, qr);
    }


    SegmentTree() {}
    SegmentTree(int __n)
    {
        ST = vn(4*__n+100);
    }

};
class HeavyLightDecomp
{
    typedef long long ll;
    typedef vector<ll> vll;
    typedef vector<int> vi;
    typedef vector<vi> vvi;

    int n;
    vvi tree;
    vi path_root;
    vi parent;
    vi depth;
    vi heavy;
    vi pos;

    SegmentTree<ll> st;

    int DFS(int u)
    {
        int sz = 1, maxSubtree = 0;

        for(int v: tree[u]) if(v != parent[u])
        {
            parent[v] = u;
            depth[v] = depth[u] + 1;

            int subtree = DFS(v);
            if(subtree > maxSubtree) maxSubtree = subtree, heavy[u] = v;
            sz += subtree;
        }

        return sz;
    }
    template<class BinaryOps> void processPath(int u, int v, BinaryOps op)
    {
        for(; path_root[u] != path_root[v]; v = parent[path_root[v]])
        {
            if(depth[path_root[u]] > depth[path_root[v]]) swap(u, v);
            op(pos[path_root[v]], pos[v]);
        }

        if(u == v) return;
        if(depth[u] > depth[v]) swap(u, v);
        op(pos[u]+1, pos[v]);
    }
    void initialize()
    {
        parent[1] = -1;
        depth[1]  = 0;

        DFS(1);
        for(int i = 1, cur_pos = 1; i <= n; ++i) if(parent[i] == -1 || heavy[parent[i]] != i)
        {
            for(int j = i; j != -1; j = heavy[j]) path_root[j] = i, pos[j] = cur_pos++;
        }
    }


public:

    void addEdge(int u, int v)
    {
        tree[u].pb(v);
        tree[v].pb(u);
    }
    void update(int u, int v)
    {
        processPath(u, v, [this](int l, int r) {
            st.update(1, 1, n, l, r, 1);
        });
    }
    ll query(int u, int v)
    {
        ll ret = 0LL;
        processPath(u, v, [this, &ret](int l, int r) {
            ret += st.query(1, 1, n, l, r);
        });
        return ret;
    }
    void initHLD()
    {
        initialize();
    }


    HeavyLightDecomp() {}
    HeavyLightDecomp(int __n)
    {
        n = __n;

        tree = vvi(n+1);
        pos = vi(n+1, 0);
        depth = vi(n+1, 0);
        parent = vi(n+1, 0);
        path_root = vi(n+1, 0);
        heavy = vi(n+1, -1);

        st = SegmentTree<ll>(n);
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
int n, nQuery;

HeavyLightDecomp ctb;


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

    scan(n);
    scan(nQuery);

    ctb = HeavyLightDecomp(n);
    FORl(i, 1, n)
    {
        scan(u);
        scan(v);
        ctb.addEdge(u, v);
    }
    ctb.initHLD();
}

//Process
void Solve()
{
    char c;
    int u, v;
    while(nQuery--)
    {
        cin >> c;
        scan(u); scan(v);

        if(c == 'P') ctb.update(u, v);
        else print(ctb.query(u, v)), putchar(el);
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
