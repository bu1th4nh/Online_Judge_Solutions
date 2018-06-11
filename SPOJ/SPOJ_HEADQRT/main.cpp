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
#include <cassert>
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
//Geometr
struct Point
{
    int x, y;

    Point(int __x, int __y): x(__x), y(__y) {}
    Point() {}

    ~Point() {}

    bool operator < (const Point &other) const
    {
        if(this->x != other.x) return this->x < other.x;
        return this->y < other.y;
    }
};
bool cross(Point _a, Point _b, Point _c)
{
    return 1ll * (_a.x - _b.x) * (_c.y - _b.y) - 1ll * (_a.y - _b.y) * (_c.x - _b.x) >= 0;
}
struct ConvexHull
{
    Point CH[100007], in[100007];
    int n, sz;


    void push(const Point &p)
    {
        ++n;
        in[n] = p;
    }
    void convex()
    {
        sz = 0;

        sort(in+1, in+n+1);

        for(int i = 1; i <= n; ++i)
        {
            while(sz >= 2 && cross(CH[sz - 1], CH[sz], in[i])) --sz;
            CH[++sz] = in[i];
        }

        for(int i = n - 1, t = sz; i >= 1; --i)
        {
            while(sz > t && cross(CH[sz - 1], CH[sz], in[i])) --sz;
            if(i > 1) CH[++sz] = in[i];
        }
    }


    ConvexHull()
    {
        n = 0;
    }
    ~ConvexHull() {}
};


//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<Point> vp;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int tc;

//=====================================
//Functions and procedures
//Utilities
inline int next(int __x, int __n)
{
    return (__x < __n) ? __x + 1 : 1;
}
inline int prev(int __x, int __n)
{
    return (__x > 1) ? __x - 1 : __n;
}
inline ll sqr(int x)
{
    return 1LL * x * x;
}
inline ll dist(Point _a, Point _b)
{
    return sqr(_a.x - _b.x) + sqr(_a.y - _b.y);
}


//Process
void Solve()
{
    int n, na, nb, x, y, c;
    ConvexHull A, B;
    ll best = 0;

    scanf("%d", &n);
    FOR(i, 1, n)
    {
        scanf("%d%d%d", &x, &y, &c);
        if(c == 0) A.push(Point(x, y));
        else B.push(Point(x, y));
    }

    A.convex(); B.convex();
    na = A.sz, nb = B.sz;

    for(int i = 1, j = 1; i <= na; ++i)
    {
        while(dist(A.CH[i], B.CH[j]) < dist(A.CH[i], B.CH[next(j, nb)])) j = next(j, nb);
        while(dist(A.CH[i], B.CH[j]) < dist(A.CH[i], B.CH[prev(j, nb)])) j = prev(j, nb);

        ll d = dist(A.CH[i], B.CH[j]);
        if(d > best) best = d;
    }

    ll res = sqrt(best);
    assert(sqr(res) <= best);
    while(sqr(res + 1) <= best) ++res;
    printf("%lld\n", res);
}


//Main Procedure
int main()
{
    scanf("%d", &tc);
    while(tc--)
    {
        Solve();
    }
    return 0;
}
