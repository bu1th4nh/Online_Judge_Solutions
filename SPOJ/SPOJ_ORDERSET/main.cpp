/*==============================================================================================================*\
**                                  _           _ _   _     _  _         _                                      **
**                                 | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   **
**                                 | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  **
**                                 | |_) | |_| | | |_| | | |__   _| | | | | | |                                 **
**                                 |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 **
\*==============================================================================================================*/
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

const int INVALID = -1234567890;
//=====================================
//Segment Tree
class SegmentTree
{
    #define lc id*2
    #define rc id*2+1
    typedef vector<int> vi;

    vi ST, pos;
    int n;

    int query(int id, int l, int r, int ql, int qr)
    {
        if(qr <  l || r <  ql) return 0;
        if(ql <= l && r <= qr) return ST[id];

        int mid = (l + r) / 2;

        return query(lc, l, mid, ql, qr) + query(rc, mid+1, r, ql, qr);
    }

public:

    void build(int id, int l, int r)
    {
        if(l == r)
        {
            pos[l] = id;
            ST[id] = 0;
            return;
        }

        int mid = (l + r) / 2;

        build(lc, l, mid);
        build(rc, mid+1, r);

        ST[id] = ST[lc] + ST[rc];
        ST[id] = 0;
    }
    void insert(int x)
    {
        int id = pos[x];
        ST[id] = 1;
        while(id / 2 > 0)
        {
            id /= 2;
            ST[id] = ST[lc] + ST[rc];
        }
    }
    void erase(int x)
    {
        int id = pos[x];
        ST[id] = 0;
        while(id / 2 > 0)
        {
            id /= 2;
            ST[id] = ST[lc] + ST[rc];
        }
    }
    int getK_th(int x)
    {
        if(x > query(1, 1, n, 1, n))
        {
            return INVALID;
        }

        int l = 0, h = n;
        while(h - l > 1)
        {
            int mid = (l + h)/2;
            if(x <= query(1, 1, n, 1, mid)) h = mid;
            else l = mid;
        }
        return h;
    }
    int countVal(int x)
    {
        return query(1, 1, n, 1, x - 1);
    }

    ~SegmentTree() {ST.clear(); pos.clear();}

    SegmentTree() {}
    SegmentTree(int __n)
    {
        n = __n;
        ST = vi(4*(n+1) + 16);
        pos = vi(n+16);
    }

};

//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
char order[262144];
vi a, sorted, cpr;
int q, res;


//=====================================
//Functions and procedures
//Main Procedure
int main()
{
    scanf("%d", &q);

    a = cpr = vi(q + 1);

    FOR(i, 1, q) cin >> order[i] >> a[i];
    sorted = a; sorted[0] = INVALID;

    sort(whole(sorted));

    FOR(i, 1, q) cpr[i] = lower_bound(whole(sorted), a[i]) - sorted.begin();
    SegmentTree st(q);
    st.build(1, 1, q);

    FOR(i, 1, q)
    {
        if(order[i] == 'I') st.insert(cpr[i]);
        else if(order[i] == 'D') st.erase(cpr[i]);
        else if(order[i] == 'K')
        {
            res = st.getK_th(a[i]);
            if(res == INVALID) printf("invalid\n");
            else printf("%d\n", sorted[res]);
        }
        else printf("%d\n", st.countVal(cpr[i]));
    }

    return 0;
}
