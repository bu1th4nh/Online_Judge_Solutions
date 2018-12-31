/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
//=====================================
//Solution Briefing - Foreword

//Heavy Light Decomposition X Lazy ST

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
#define task "QTREEX"
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

    #ifdef __DEBUG
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
struct edge
{
    int u, v, c;

    edge(): u(0), v(0), c(0) {}
    edge(int __u, int __v, int __c): u(__u), v(__v), c(__c) {}

    void scan()
    {
        read(u);
        read(v);
        read(c);
    }
};
struct LazySegmentTree
{
    #define lc id*2
    #define rc id*2+1

    typedef vector<int> vi;

    struct Node
    {
        int max_val, min_val, state, lazy;
        Node(int a, int b, int c): max_val(a), min_val(b), state(c), lazy(0) {}
        Node(int a): max_val(a), min_val(a), state(0), lazy(0) {}
        Node(): max_val(0), min_val(0), state(0), lazy(0) {}

        Node operator+ (const Node &other)
        {
            int max1, max2, min1, min2;

            max1 = (this->state == 0) ? this->max_val : -(this->min_val);
            min1 = (this->state == 0) ? this->min_val : -(this->max_val);

            max2 = (other.state == 0) ? other.max_val : -(other.min_val);
            min2 = (other.state == 0) ? other.min_val : -(other.max_val);

            return Node(max(max1, max2) , min(min1, min2) , 0);
        }
        void flip()
        {
            state ^= 1;
            lazy = (lazy + 1) & 1;
        }
    };

    vector<Node> ST;

    void push_down(int id)
    {
        int &tmp = ST[id].lazy;

        ST[lc].lazy += tmp;
        ST[rc].lazy += tmp;

        if(tmp & 1)
        {
            ST[lc].state ^= 1;      // x ^= 1 equivalent to x = 1 - x.
            ST[rc].state ^= 1;
        }

        tmp = 0;                    // This will affect ST[id].lazy as well.
    }
    void build(int id, int l, int r, const vi &a)
    {
        if(l > r) return;
        if(l == r)
        {
            ST[id] = Node(a[l]);
            return;
        }

        int mid = (l + r) / 2;
        build(lc, l,   mid, a);
        build(rc, mid+1, r, a);
        ST[id] = ST[lc] + ST[rc];
    }
    void update(int id, int l, int r, int pos, int val)
    {
        if(pos < l || r < pos) return;
        if(pos == l && l == r)
        {
            ST[id] = Node(val);
            return;
        }

        push_down(id);
        int mid = (l + r) / 2;
        update(lc, l,   mid, pos, val);
        update(rc, mid+1, r, pos, val);
        ST[id] = ST[lc] + ST[rc];
    }
    void change(int id, int l, int r, int ql, int qr)
    {
        #ifdef DEBUG
        fprintf(stderr, "Change in node #%d range %d to %d, from %d to %d\n", id, l, r, ql, qr);
        #endif // DEBUG

        if(qr <  l || r <  ql) return;
        if(ql <= l && r <= qr)
        {
            ST[id].flip();
            return;
        }

        push_down(id);
        int mid = (l + r) / 2;
        change(lc, l,   mid, ql, qr);
        change(rc, mid+1, r, ql, qr);
        ST[id] = ST[lc] + ST[rc];
    }
    int query(int id, int l, int r, int ql, int qr)
    {
        if(qr <  l || r <  ql) return -inf;
        if(ql <= l && r <= qr) return (ST[id].state == 0) ? ST[id].max_val : -ST[id].min_val;

        push_down(id);
        int mid = (l + r) / 2;

        int rt1 = query(lc, l,   mid, ql, qr);
        int rt2 = query(rc, mid+1, r, ql, qr);
        ST[id] = ST[lc] + ST[rc];
        return max(rt1, rt2);
    }


    ~LazySegmentTree() {ST.clear();}

    LazySegmentTree() {}
    LazySegmentTree(int __n)
    {
        ST = vector<Node> (__n * 4 + 128, 0);
    }
};
class HeavyLightDecomp
{
    typedef pair<int, int> ii;
    typedef vector<int> vi;
    typedef vector<ii> vii;
    typedef vector<vii> vvii;

    int n;
    vvii tree;
    vi baseArray;
    vi path_root;
    vi parent;
    vi heavy;
    vi depth;
    vi pos;

    LazySegmentTree st;

    int dfs(int u)
    {
        int sz = 1;
        int maxSubtree = 0;

        for(auto x: tree[u]) if(x.se != parent[u])
        {
            int v = x.se;

            parent[v] = u;
            depth[v]  = depth[u] + 1;

            int subtree = dfs(v);
            if(maxSubtree < subtree)
            {
                maxSubtree = subtree;
                heavy[u] = v;
            }

            sz += subtree;
        }

        return sz;
    }
    template<class BinaryOperation> void processPath(int u, int v, BinaryOperation op)
    {
        for(; path_root[u] != path_root[v]; v = parent[path_root[v]])
        {
            if(depth[path_root[u]] > depth[path_root[v]]) swap(u, v);
            op(pos[path_root[v]], pos[v]);

            #ifdef DEBUG

                cerr << "1. " << pos[path_root[v]] << sp << pos[v] << el;

            #endif // DEBUG

        }

        if(u == v) return;
        if(depth[u] > depth[v]) swap(u, v);
        op(pos[u]+1, pos[v]);


        #ifdef DEBUG

            cerr << "2. " << pos[u]+1 << sp << pos[v] << el;

        #endif // DEBUG
    }

public:
    void initialize()
    {
        parent[1] = -1;
        depth[1] = 0;

        dfs(1);
        for(int i = 1, cur_pos = 1; i <= n; ++i)
        {
            if(parent[i] == -1 || heavy[parent[i]] != i)
            {
                for(int j = i; j != -1; j = heavy[j])
                {
                    path_root[j] = i;
                    pos[j] = cur_pos++;
                }
            }
        }
    }
    void initBaseArray()
    {
        FOR(i, 1, n) for(auto x: tree[i])
        {
            if(x.se != parent[i])
            {
                baseArray[pos[x.se]] = x.fi;
            }
        }
        st.build(1, 1, n, baseArray);
    }
    void addEdge(edge e)
    {
        tree[e.u].pb(ii(e.c, e.v));
        tree[e.v].pb(ii(e.c, e.u));
    }
    void set(int u, int v, int value)
    {
        if(parent[v] == u) swap(u, v);
        st.update(1, 1, n, pos[u], value);
    }
    void flipp_path(int u, int v)
    {
        processPath(u, v, [this](int l, int r) {

            st.change(1, 1, n, l, r);

            #ifdef DEBUG
                cerr << "Flipped: " << l << sp << r << el;
            #endif // DEBUG
        });
    }
    int query_path(int u, int v)
    {
        int ret = -inf;
        processPath(u, v, [this, &ret](int l, int r) {ret = max(ret, st.query(1, 1, n, l, r));}  );
        return ret;
    }

    void debugBaseArray()
    {
        cerr << "baseArray is:         "; FOR(i, 1, n) cerr << st.query(1, 1, n, pos[i], pos[i]) << sp; cerr << el;
    }
    void debug()
    {
        cerr << "id is:                "; FOR(i, 1, n) cerr << i << sp; cerr << el;
        cerr << "pos is:               "; FOR(i, 1, n) cerr << pos[i] << sp; cerr << el;
        cerr << "heavy is:             "; FOR(i, 1, n) cerr << heavy[i] << sp; cerr << el;
        cerr << "depth is:             "; FOR(i, 1, n) cerr << depth[i] << sp; cerr << el;
        cerr << "parent is:            "; FOR(i, 1, n) cerr << parent[i] << sp; cerr << el;
        cerr << "path_root is:          "; FOR(i, 1, n) cerr << path_root[i] << sp; cerr << el;
        // cerr << "counter_pos is:       "; FOR(i, 1, n) cerr << counter_pos[i] << sp; cerr << el;
        cerr << "Initial baseArray is: "; FOR(i, 1, n) cerr << baseArray[i] << sp; cerr << el;
        cerr << "id is:                "; FOR(i, 1, n) cerr << i << sp; cerr << el;


        // FOR(i, 1, n)
        // {
        //     cerr << i << ": ";
        //     for(auto x: tree[i]) if(parent[i] != x.se) cerr << x.se << "-" << x.fi << sp;
        //     cerr << el;
        // }
    }


    ~HeavyLightDecomp() {}

    HeavyLightDecomp() {}
    HeavyLightDecomp(int __n)
    {
        n = __n;
        tree = vvii(n+1);
        baseArray = vi(n+1, 0);

        pos = vi(n+1, 0);
        depth = vi(n+1, 0);
        parent = vi(n+1, 0);
        path_root = vi(n+1, 0);
        heavy = vi(n+1, -1);

        st = LazySegmentTree(n);
    }
};


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<edge> ve;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
HeavyLightDecomp ctb;
int n, nTest;
ve edgeList;


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
	read(n);
	ctb = HeavyLightDecomp(n);
	edgeList = ve(n);

	FORl(i, 1, n)
	{
	    edgeList[i].scan();
	    ctb.addEdge(edgeList[i]);
	}
}

//Check
void Solve()
{
    int u, v, res;
    ctb.initialize();
    ctb.initBaseArray();

    #ifdef DEBUG
        ctb.debug();
        ctb.debugBaseArray();

        cerr << "====================================================\n";

        int nQuery = 0;
        int nChange = 0;
    #endif //DEBUG

    char str[1024];
    string q = "TML x CTB";
    while(q != "DONE")
    {
        scanf("%s", &str);
        q = string(str);
        if(q == "DONE") break;

        if(q == "CHANGE")
        {
            read(u), read(v);
            ctb.set(edgeList[u].u, edgeList[u].v, v);

            #ifdef DEBUG
                ctb.debugBaseArray();
                cerr << "====================================================\n";
            #endif // DEBUG
        }
        else if(q == "NEGATE")
        {
            read(u), read(v);
            ctb.flipp_path(u, v);

            #ifdef DEBUG
                ctb.debugBaseArray();
                cerr << "====================================================\n";
            #endif // DEBUG
        }
        else if(q == "QUERY")
        {
            read(u), read(v);

            if(u == v)
            {
                puts("0");
                continue;
            }

            res = ctb.query_path(u, v);
            print(res); putchar(el);
        }
    }
}


//Process
void MULTi()
{
    read(nTest);
    while(nTest--)
    {
        Enter();
        Solve();
    }
}


//Main Procedure
int main()
{
    //FileInit();
    MULTi();
    return 0;
}

/*
1

3
1 2 1
2 3 2
QUERY 1 2
CHANGE 1 3
QUERY 1 2
DONE
*/


//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
