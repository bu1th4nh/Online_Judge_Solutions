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

//=====================================
////Segment Tree
//struct SegmentTree
//{
    #define lc id*2
    #define rc id*2+1
    typedef vector<int> vi;
    typedef vector<vi> vvi;

    vvi ST;

    void build(int id, int l, int r, const vi &a)
    {
        if(l == r)
        {
            ST[id].pb(a[l]);
            return;
        }

        int mid = (l + r) / 2;
        build(lc, 1, mid, a);
        build(rc, mid+1, r, a);

        merge(ST[id*2].begin(), ST[id*2].end(), ST[id*2+1].begin(), ST[id*2+1].end(), ST[id].begin());
    }
    void update(int id, int l, int r, int pos, int val)
    {
        if(pos < l || r < pos) return;
        if(l == r)
        {
            ST[id].clear();
            ST[id].push_back(val);
        }

        int mid = (l + r) / 2;
        update(lc, 1, mid, pos, val);
        update(rc, mid+1, r, pos, val);

        merge(ST[id*2].begin(), ST[id*2].end(), ST[id*2+1].begin(), ST[id*2+1].end(), ST[id].begin());
    }
    int query(int id, int l, int r, int ql, int qr, int k)
    {
        if(r  <  ql || qr < l) return 0;
        if(ql <= l  && r <= qr) return ST[id].size() - (upper_bound(whole(ST[id]), k) - ST[id].begin());

        int mid = (l + r) / 2;
        return query(lc, l, mid, ql, qr, k) + query(rc, mid+1, r, ql, qr, k);
    }

//
//    ~SegmentTree() {}
//
//    SegmentTree() {}
//    SegmentTree(int __n) {ST = vvi((__n+1) * 4 + 7);}
//
//};


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
int n, nQuery;
vi a;


//=====================================
//Functions and procedures
//Main Procedure
int main()
{
    int type, u, v, k;

    scanf("%d", &n);
    a = vi(n+1);
    FOR(i, 1, n) scanf("%d", &a[i]);

//    SegmentTree st(n);
//    st.build(1, 1, n, a);

    ST = vvi((n+1)*4 + 7);
    build(1, 1, n, a);

    scanf("%d", &nQuery);
    while(nQuery--)
    {
        scanf("%d", &type);
        if(type == 0)
        {
            scanf("%d%d", &u, &k);
            update(1, 1, n, u, k);
        }
        else
        {
            scanf("%d%d%d", &u, &v, &k);
            printf("%d\n", query(1, 1, n, u, v, k));
        }
    }

    return 0;
}
