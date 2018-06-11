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

const long long inf = 1e15;
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

//=====================================
//Segment Tree
struct Node
{
    ll lsum, rsum, sum, res;

    Node(ll __x)
    {
        lsum = rsum = sum = res = __x;
    }
    Node()
    {
        lsum = rsum = sum = res = -inf;
    }
    ~Node() {}

    bool IsNull() const
    {
        return (this->sum <= -inf);
    }
    Node operator + (const Node & other) const
    {
        Node ret;
        if(this->IsNull()) return other;
        if(other.IsNull()) return *this;

        ret.sum = this->sum + other.sum;
        ret.lsum = max(this->lsum, this->sum + other.lsum);
        ret.rsum = max(other.rsum, other.sum + this->rsum);

        ret.res = max(max(this->res, other.res), this->rsum + other.lsum);

        return ret;
    }

};
struct SegmentTree
{
    vector<Node> ST;
    int n;

    void build(int id, int l, int r, const vi &a)
    {
        if(l > r) return;

        if(l == r) ST[id] = Node(a[l]);
        else
        {
            int mid = (l + r) / 2;
            build(id*2, l, mid, a);
            build(id*2 + 1, mid+1, r, a);
            ST[id] = ST[id*2] + ST[id*2+1];
        }

    }

    Node query(int id, int l, int r, int l_query, int r_query)
    {
        if(l_query > r || r_query < l || l > r || l_query > r_query) return Node();
        if(l_query <= l && r <= r_query) return ST[id];

        int mid = (l + r) / 2;

        return query(id*2, l, mid, l_query, r_query) + query(id*2 + 1, mid+1, r, l_query, r_query);
    }


    SegmentTree(int __n)
    {
        ST = vector<Node> (4 * __n + 8, Node());
    }
    SegmentTree() {}
    ~SegmentTree() {}
};

//=====================================
//Variable declaration
int n, u, v, q;
vi vect;

//=====================================
//Functions and procedures
int main()
{
    scanf("%d", &n);

    vect = vi(n+1);

    FOR(i, 1, n) scanf("%d", &vect[i]);
    scanf("%d", &q);

    SegmentTree st(n);
    st.build(1, 1, n, vect);

    FOR(qq, 1, q)
    {
        scanf("%d%d", &u, &v);
        printf("%lld\n", st.query(1, 1, n, u, v).res);
    }

    return 0;
}
