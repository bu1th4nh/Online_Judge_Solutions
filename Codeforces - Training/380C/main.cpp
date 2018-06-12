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


//=====================================
//Segment Tree
struct SegmentTree
{
    struct Node
    {
        int optimal, open, close;

        ~Node() {}

        Node(): optimal(0), open(0), close(0) {}
        Node(int __opt, int __o, int __c): optimal(__opt), open(__o), close(__c) {}

        Node operator + (const Node & other)
        {
            Node ret;
            int tmp = min(this->open, other.close);

            ret.optimal = this->optimal + other.optimal - tmp;

            ret.open = this->open + other.open - tmp;
            ret.close = this->close + other.close - tmp;

            return ret;
        }
    };

    vector<Node> ST;

    void build(int id, int l, int r, const string &s)
    {
        if(l == r)
        {
            ST[id] = (s[l] == '(') ? Node(0, 1, 0) : Node(0, 0, 1);
            return;
        }

        int mid = (l + r) / 2;

        build(id*2, l, mid, s);
        build(id*2+1, mid+1, r, s);

        ST[id] = ST[id*2] + ST[id*2+1];
    }
    Node query(int id, int l, int r, int ql, int qr)
    {
        if(qr < l || r < ql) return Node();
        if(ql <= l && r <= qr) return ST[id];

        int mid = (l + r) / 2;

        return query(id*2, l, mid, ql, qr) + query(id*2+1, mid+1, r, ql, qr);
    }

    ~SegmentTree() {ST.clear();}


    SegmentTree() {}
    SegmentTree(int n): ST(vector<Node> (n*4 + 16)) {}

};




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
int nQuery, u, v, n;
string t;


//=====================================
//Functions and procedures
//Main Procedure
int main()
{
    char str[1048576]; scanf("%s", &str); t = '?' + string(str);
    scanf("%d", &nQuery);
    n = t.length();

    SegmentTree st(n);
    st.build(1, 1, n, t);

    while(nQuery--)
    {
        scanf("%d%d", &u, &v);
        int res = abs(st.query(1, 1, n, u, v).optimal)*2;
        printf("%d\n", res);
    }

    return 0;
}
