//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
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
#define MODUL (int)(1e9+57)
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}

//=====================================
//Segment Tree
struct SegmentTree
{
    struct Node
    {
        int val, lazy;          //Lazy: For the child node of the current node, NOT for the current node
        Node(): val(0), lazy(0) {}
        Node(int __v): val(__v), lazy(0) {}
        Node(int __v, int __l): val(__v), lazy(__l) {}
    };


    vector<Node> ST;



    void push_down(int id)      //Lazy Propagation - Push the "lazy" value of a node down to its child nodes
    {
        int t = ST[id].lazy;

        ST[2*id].lazy += t;     //Left child
        ST[2*id].val += t;

        ST[2*id+1].lazy += t;   //Right child
        ST[2*id+1].val += t;

        ST[id].lazy = 0;
    }
    void update(int id, int l, int r, int up_l, int up_r, int v)
    {
        if(up_r <  l || r <  up_l) return;
        if(up_l <= l && r <= up_r)
        {
            ST[id].val += v;
            ST[id].lazy += v;
            return;
        }

        int mid = (l + r) / 2;
        push_down(id);                                      //Lazy Propagation

        update(id*2  , l    , mid, up_l, up_r, v);          //Update its child
        update(id*2+1, mid+1, r  , up_l, up_r, v);

        ST[id].val = max(ST[id*2].val, ST[id*2+1].val);     //Update the child's ancestor
    }
    int query(int id, int l, int r, int ql, int qr)
    {
        if(qr <  l || r <  ql) return -INFINITY;
        if(ql <= l && r <= qr) return ST[id].val;

        int mid = (l + r) / 2;
        push_down(id);                                      //Lazy Propagation

        return max( query(id*2, l, mid, ql, qr)  ,  query(id*2+1, mid+1, r, ql, qr) );
    }


    SegmentTree() {}
    SegmentTree(int __n) {ST = vector<Node>(4*__n+16);}

    ~SegmentTree() {ST.clear();}

};

//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int x, y, res, val, value, type;
int n, m;

//=====================================
//Functions and procedures
//Main Procedure
int main()
{
    scanf("%d%d", &n, &m);
    SegmentTree st(n);

    while(m--)
    {
        scanf("%d", &type);
        if(type == 0)
        {
            scanf("%d%d%d", &x, &y, &val);
            st.update(1, 1, n, x, y, val);
        }
        else
        {
            scanf("%d%d", &x, &y);
            res = st.query(1, 1, n, x, y);
            printf("%d\n", res);
        }
    }

    return 0;
}
