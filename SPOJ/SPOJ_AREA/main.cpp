/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
/*          Solution Briefing

                Source: https://onedrive.live.com/?cid=8056AC82E71B8954&id=8056AC82E71B8954%219727&parId=8056AC82E71B8954%2124517&o=OneUp
                Page: 4/22

*/
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
using namespace std;


//=====================================
//Macros
#define sp ' '
#define el '\n'
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


//=====================================
//Typedef
struct Line
{
    int x, y1, y2, type;

    Line() {}
    Line(int __x, int __y1, int __y2, int __type): x(__x), y1(__y1), y2(__y2), type(__type) {}

    bool operator < (const Line &other) const
    {
        return (this->x < other.x || (this->x == other.x && this->type < other.type));
    }
};
struct SegmentTree
{
    #define lc (id*2)
    #define rc (id*2+1)
    struct Node
    {
        int cnt, val;

        Node(): cnt(0), val(0) {}
        Node(int __cnt, int __val): cnt(__cnt), val(__val) {}
    };
    typedef vector<Node> vn;

    vn T;

    void update(int id, int l, int r, int ql, int qr, int type)
    {
        if(qr < l || r < ql) return;
        if(ql <= l && r <= qr)
        {
            T[id].cnt += type;

            if(type == 1) T[id].val = r - l + 1;
            else if(T[id].cnt == 0) T[id].val = T[lc].val + T[rc].val;

            return;
        }

        int mid = (l + r) / 2;
        update(lc, l, mid, ql, qr, type);
        update(rc, mid+1, r, ql, qr, type);

        if(T[id].cnt == 0) T[id].val = T[lc].val + T[rc].val;
    }
    int query() {return T[1].val;}

    SegmentTree()
    {
        T = vn(32768*4);
    }
};

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<Line> vL;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n;
vL a;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int x1, x2, y1, y2;
	scanf("%d", &n);

    FOR(i, 1, n)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        a.push_back(Line(x1, y1, y2, 1));
        a.push_back(Line(x2, y1, y2, -1));
    }

    n >>= 1;
}

//Process
void Solve()
{
    ll res = 0LL, x0 = 0LL;
    SegmentTree st;


    //puts("PRE-SORT:");
    //for(Line x: a)  cout << x.x << sp << x.y1 << sp << x.y2 << sp << x.type << el;

    sort(whole(a));

//    puts("SORTED:");
//    for(Line x: a)  cout << x.x << sp << x.y1 << sp << x.y2 << sp << x.type << el;
//    puts("============================");


    for(Line x: a)
    {
        res += 1LL * st.query() * (x.x - x0);
        x0 = x.x;
        st.update(1, 0, 30010, x.y1, x.y2-1, x.type);

        //cout << x.x << sp << x.y1 << sp << x.y2 << sp << x.type << el;
    }

    printf("%lld\n", res);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
