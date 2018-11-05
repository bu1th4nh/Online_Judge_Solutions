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

#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#include <random>
#endif // __cplusplus

using namespace std;


//=====================================
//Macroes
#define sp " "
#define el "\n"
#define task "QTREE"
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



//#define ENABLE_DEBUG


//=====================================
//Fast I/O and min/max utilities
template<class T> inline void _scan(T &ret)
{
    ret = T();
    char c = 0;
    bool neg = 0;

    while(c != '-' && isdigit(c) == 0) c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    ret *= neg ? -1 : 1;
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
template<class P, class Q> P _max(P a, Q b)
{
    return (a > b) ? a : b;
}

//=====================================
//Typedefs
template<class T> struct SegmentTree
{
    #define lc id*2
    #define rc id*2+1
    typedef vector<T> vt;

    int n;
    vt ST;

    void build(int id, int l, int r, const vt &a)
    {
        if(l > r) return;

        ST[id] = _max(ST[id], a[l]);

        if(l == r)
        {
            return;
        }

        int mid = (l + r) / 2;
        build(lc, l, mid, a);
        build(rc, mid+1, r, a);
        ST[id] = _max(ST[lc], ST[rc]);
    }
    void update(int id, int l, int r, int pos, T value)
    {
        if(pos < l || r < pos) return;
        if(l == r && l == pos)
        {
            ST[id] = value;
            return;
        }

        ST[id] = _max(ST[id], value);
        int mid = (l + r) / 2;

        update(lc,     l, mid, pos, value);
        update(rc, mid+1,   r, pos, value);
        ST[id] = _max(ST[lc], ST[rc]);
    }
    T query(int id, int l, int r, int ql, int qr)
    {
        if(qr <  l || r <  ql || l > r || ql > qr) return 0;
        if(ql <= l && r <= qr) return ST[id];

        int mid = (l + r) / 2;
        return _max(query(lc, l, mid, ql, qr), query(rc, mid+1, r, ql, qr));
    }

    SegmentTree(int __n)
    {
        n = __n;
        ST = vt(4 * __n, T());
    }
    SegmentTree() {}

    ~SegmentTree() {}
};
template<class T> struct edge
{
    int u, v;
    T c;

    edge(): u(0), v(0), c(T()) {}
    edge(int __u, int __v, T __c): u(__u), v(__v), c(__c) {}

    void scan()
    {
        _scan(u);
        _scan(v);
        _scan(c);
    }
};
template<class T_w, bool VALUE_ON_VERTICES> class HeavyLightDecomp
{
private:

    typedef pair<T_w, int> ti;
    typedef vector<int> vi;
    typedef vector<T_w> vt;
    typedef vector<ti> vti;
    typedef vector<vti> vvti;

    int n;
    vvti tree;
    vt baseArray;
    vi counter_pos;
    vi pathRoot;
    vi parent;
    vi heavy;
    vi depth;
    vi pos;

    SegmentTree<T_w> st;

    int dfs(int u)
    {
        int sz = 1;
        int maxSubtree = 0;

        for(auto x: tree[u]) if(x.se != parent[u])
        {
            int v = x.se;

            parent[v] = u;
            depth[v] = depth[u] + 1;

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


        for(; pathRoot[u] != pathRoot[v]; v = parent[pathRoot[v]])
        {
            if(depth[pathRoot[u]] > depth[pathRoot[v]]) swap(u, v);
            op(pos[pathRoot[v]], pos[v]);


            #ifdef ENABLE_DEBUG
                fprintf(stderr, "Query %d %d or %d %d\n" , u, v, pos[pathRoot[v]], pos[v] + 1);
            #endif //ENABLE_DEBUG


        }

        #ifdef ENABLE_DEBUG
            cerr << "Query: " << u << sp << v << el;
        #endif //ENABLE_DEBUG

        if(u == v) return;
        if(depth[u] > depth[v]) swap(u, v);
        op(pos[u]+1, pos[v]);
    }


public:
    void initialize()
    {
        parent[1] = -1, depth[1] = 0;
        dfs(1);
        // debug();

        for(int i = 1, cur_pos = 1; i <= n; ++i)
        {
            if(parent[i] == -1 || heavy[parent[i]] != i)
            {
                for(int j = i; j != -1; j = heavy[j])
                {
                    //cerr << j << el;

                    pathRoot[j] = i;
                    pos[j] = cur_pos++;
                    counter_pos[pos[j]] = j;
                }
            }
        }
    }
    void initBaseArray()
    {
        FOR(i, 1, n)
        {
            for(auto x: tree[i])
            {
                if(x.se != parent[i])
                {
                    baseArray[pos[x.se]] = x.fi;
                }
            }
        }

        st.build(1, 1, n, baseArray);

//        debug();
//        FOR(i, 1, n) st.update(1, 1, n, i, baseArray[i]), cerr << baseArray[i] << sp; cerr << el;
//        debug();
    }
    void addEdge(edge<T_w> e)
    {
        tree[e.u].push_back(ti(e.c, e.v));
        tree[e.v].push_back(ti(e.c, e.u));
    }
    void set(int u, int v, T_w value)
    {
        if(parent[v] == u) swap(u, v);
        st.update(1, 1, n, pos[u], value);
    }
    T_w queryPath(int u, int v)
    {
        T_w ret = 0LL;
        processPath(u, v, [this, &ret](int l, int r) {ret = max(ret,  st.query(1, 1, n, l, r)); 
        
            #ifdef ENABLE_DEBUG

                cerr << "ST query from - to: " << l << sp << r << sp << " w/ ret = " << ret << el;

            #endif //ENABLE_DEBUG
        
        
         } );


        #ifdef ENABLE_DEBUG
            // cerr << el;
        #endif //ENABLE_DEBUG


        return ret;
    }


    void debugBaseArray()
    {
        cerr << "baseArray is:         "; FOR(i, 1, n) cerr << st.query(1, 1, n, pos[i], pos[i]) << sp; cerr << el;
    }
    void debug()
    {
        cerr << "pos is:               "; FOR(i, 1, n) cerr << pos[i] << sp; cerr << el;
        cerr << "heavy is:             "; FOR(i, 1, n) cerr << heavy[i] << sp; cerr << el;
        cerr << "depth is:             "; FOR(i, 1, n) cerr << depth[i] << sp; cerr << el;
        cerr << "parent is:            "; FOR(i, 1, n) cerr << parent[i] << sp; cerr << el;
        cerr << "pathRoot is:          "; FOR(i, 1, n) cerr << pathRoot[i] << sp; cerr << el;
        cerr << "counter_pos is:       "; FOR(i, 1, n) cerr << counter_pos[i] << sp; cerr << el;
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
        tree = vvti(n+1);
        baseArray = vt(n+1, T_w());

        pos = vi(n+1, 0);
        depth = vi(n+1, 0);
        parent = vi(n+1, 0);
        pathRoot = vi(n+1, 0);
        counter_pos = vi(n+1, 0);
        heavy = vi(n+1, -1);

        st = SegmentTree<T_w>(n);
    }
};


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef edge<ll> edg;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<edg> ve;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
HeavyLightDecomp<ll, true> hld;
int n, nTest;
ve edgeList;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP()
}
void FileDebug()
{
    FILEOP_DEBUG()
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter()
{
    _scan(n);
    hld = HeavyLightDecomp<ll, true> (n);
    edgeList = ve(n);
    FOR(i, 1, n-1)
    {
        edgeList[i].scan();
        hld.addEdge(edgeList[i]);
    }
}

//Check
void Solve()
{
    hld.initialize();
    hld.initBaseArray();

    ll ti;
    int i, u, v;
    char t[20];

    #ifdef ENABLE_DEBUG
        hld.debug();
        int nQuery = 0;
        int nChange = 0;
    #endif //ENABLE_DEBUG

    while(scanf("%s", &t) == 1)
    {
        if(t[0] == 'C')
        {
            _scan(i);
            _scan(ti);


            #ifdef ENABLE_DEBUG
                fprintf(stderr, "Operation #%d: Change edge #%d or (%d - %d) by %lld \n", ++nChange, i, edgeList[i].u, edgeList[i].v, ti);
            #endif //ENABLE_DEBUG


            hld.set(edgeList[i].u, edgeList[i].v, ti);
            
            
            #ifdef ENABLE_DEBUG
                hld.debugBaseArray();
            #endif //ENABLE_DEBUG
        }
        else if(t[0] == 'Q')
        {
            _scan(u);
            _scan(v);

            #ifdef ENABLE_DEBUG
                fprintf(stderr, "Operation #%d: Query path from %d to %d: \n", ++nQuery, u, v);
            #endif //ENABLE_DEBUG
            
            ll res = hld.queryPath(u, v);

            print(res); putchar('\n');


            #ifdef ENABLE_DEBUG
                hld.debugBaseArray();
                cerr << "Result: " << res << el;
                //hld.debug();
            #endif //ENABLE_DEBUG
        }
        else return;

        #ifdef ENABLE_DEBUG
            cerr << "-----------------------------------\n";
        #endif //ENABLE_DEBUG

    }
}



//Process
void MultiTest()
{
    _scan(nTest);
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
    //FILEOP_DEBUG();

    MultiTest();
    return 0;
}

/*    Afterthough: Maybe I need to re-write my Segtree implementation now. And Al.Cash's code is NOT a problem with me anymore from now on.    */

