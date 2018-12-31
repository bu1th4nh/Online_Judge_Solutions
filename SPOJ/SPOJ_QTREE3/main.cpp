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


const int inf = 1000000007;
//=====================================
//Typedefs
struct SegmentTree
{
    #define lc id*2
    #define rc id*2+1
    typedef vector<int> vi;


    vi nodeId;
    vi ST;
    int n;


    //Update and queries
    void update(int id, int l, int r, int pos)
    {
        if(pos < l || pos > r) return;
        if(l == r && l == pos)
        {
            ST[id] = (ST[id] == inf) ? pos : inf;
            return;
        }

        int mid = (l + r) / 2;
        update(lc, l    , mid, pos);
        update(rc, mid+1, r  , pos);
        ST[id] = min(ST[lc], ST[rc]);
    }
    int query(int id, int l, int r, int ql, int qr)
    {
        if(ql > r || qr < l || l > r || ql > qr) return inf;  //or -INFINITY
        if(ql <= l && r <= qr) return ST[id];

        int mid = (l + r) / 2;

        return min(query(lc, l, mid, ql, qr), query(rc, mid+1, r, ql, qr));
    }


    //Constructors and destructor
    SegmentTree(int __n)
    {
        ST = vi(4*__n+8, inf);
    }
    SegmentTree() {}
    ~SegmentTree() {}
};
class HeavyLight
{
private:
    typedef vector<int> vi;
    typedef vector<vi> vvi;


    int n;
    vvi tree;
    vi pathRoot;
    vi parent;
    vi heavy;
    vi depth;
    vi pos;
    SegmentTree st;


    int dfs(int u)
    {
        int sz = 1;
        int maxSubtree = 0;

        for(int v: tree[u]) if(v != parent[u])
        {
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
        }

        if(u == v) return;
        if(depth[u] > depth[v]) swap(u, v);
        op(pos[u], pos[v]);               //We may change it for research.
    }

public:
    void initialize()
    {
        parent[1] = -1, depth[1] = 0;
        dfs(1);

        for(int i = 1, cur_pos = 1; i <= n; ++i)
        {
            if(parent[i] == -1 || heavy[parent[i]] != i)
            {
                for(int j = i; j != -1; j = heavy[j])
                {
                    pathRoot[j] = i;
                    pos[j] = cur_pos++;
                }
            }
        }
    }
    void addEdge(int u, int v)
    {
        tree[u].pb(v);
    }
    void set(int u)
    {
        st.update(1, 1, n, u);
    }
    int query(int u)
    {
        int ret = inf;
        processPath(1, u, [this, &ret](int l, int r) { ret = min(ret, st.query(1, 1, n, l, r)); cerr << ret<< sp; });
        return ret;
    }

    ~HeavyLight() {}

    HeavyLight() {}
    HeavyLight(int __n)
    {
        n = __n;
        tree = vvi(n+1);
        pos = vi(n+1, 0);
        depth = vi(n+1, 0);
        parent = vi(n+1, 0);
        pathRoot = vi(n+1, 0);
        heavy = vi(n+1, -1);

        st = SegmentTree(n);
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
int timeStamp, nQuery, n;
vi topoOrder, idOrder;
vb avail;
vvi adj;

HeavyLight hld;

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
    int u, v;
	scanf("%d%d", &n, &nQuery);

	timeStamp = n;
	adj = vvi(n+1);
	avail = vb(n+1, 1);
	topoOrder = idOrder = vi(n+1, 0);

	hld = HeavyLight(n);

	FOR(i, 1, n-1)
	{
	    scanf("%d%d", &u, &v);
	    adj[u].pb(v);
	    adj[v].pb(u);
	}
}

//Check
void topoDFS(int u)
{
    avail[u] = 0;

    for(int v: adj[u]) if(avail[v]) topoDFS(v);

    topoOrder[u] = timeStamp;
    idOrder[timeStamp--] = u;
}
void Preps()
{
    FOR(i, 1, n) if(avail[i]) topoDFS(i);
    FOR(i, 1, n)
    {
        for(int x: adj[i]) hld.addEdge(topoOrder[i], topoOrder[x]);
    }

//    FOR(i, 1, n)
//    {
//        cerr << i << ": ";
//        for(int x: adj[i]) cerr << x << sp;
//        cerr << el;
//    }

    hld.initialize();
}

//Process
void Solve()
{
    int t, u, res;
    while(nQuery--)
    {
        scanf("%d%d", &t, &u);
        if(t == 0) hld.set(topoOrder[u]);
        else
        {
            res = hld.query(topoOrder[u]);
            if(res >= inf) puts("-1");
            else printf("%d\n", idOrder[res]);
        }
    }
}


//Main Procedure
int main()
{
    Enter();
    Preps();
    Solve();
    return 0;
}


/*
9 8
1 2
1 3
2 4
2 9
5 9
7 9
8 9
6 8
1 3
0 8
1 6
1 7
0 2
1 9
0 2
1 9
*/
