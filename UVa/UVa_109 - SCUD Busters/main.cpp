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
#define task "109"
#define x first
#define y second
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
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pt;             ///Point data type
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<pt> vpt;
typedef vector<vpt> vvpt;

const double eps=1e-9;

vpt kingdom[64];
double res;
bool avail[64];
double area[64];
int n;


//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v;

    int c = 0;
    n = 2017;

    while(n != -1)
    {
        vpt tmp;
        scanf("%d", &n);
        if(n == -1) break;

        FOR(i, 1, n)
        {
            scanf("%d%d", &u, &v);
            tmp.push_back(pt(u, v));
        }

        kingdom[++c] = tmp;
    }

    n = c;
    MEMS(avail, true);
}

//Check
bool cmp(pt a, pt b)
{
    return (a.x < b.x || (a.x == b.x && a.y < b.y));
}
bool IsCW(pt a, pt b, pt c)
{
    return a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y) < 0;
}
bool IsCCW(pt a, pt b, pt c)
{
    return a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y) > 0;
}
bool IsInPoly(pt P, const vpt &poly)
{
    bool in=0;
    int n=poly.size();

    for(int i=0,j=n-1;i<n;j=i++){
        if((poly[i].y <= P.y && P.y < poly[j].y) || (poly[j].y <= P.y && P.y < poly[i].y)){
            if(P.x-eps < (poly[j].x-poly[i].x)*(P.y-poly[i].y)*1.0/(poly[j].y-poly[i].y)+poly[i].x) in^=1;
        }
    }

    return in;
}

//Process
double ConvexHull(vpt &a)
{
    if(a.size() == 1)
    {
        return 0;
    }

    sort(whole(a), cmp);
    pt p1 = a[0], p2 = a.back();
    int _n = a.size();
    int re = 0;

    vpt up, dwn;
    up.push_back(p1);
    dwn.push_back(p1);

    FORl(i, 1, _n)
    {
        //Up
        if(i == _n-1 || IsCW(p1, a[i], p2))
        {
            while(up.size() >= 2 && !IsCW(up[up.size()-2], up[up.size()-1], a[i]))
            {
                up.pop_back();
            }
            up.push_back(a[i]);
        }

        //Down
        if(i == _n-1 || IsCCW(p1, a[i], p2))
        {
            while(dwn.size() >= 2 && !IsCCW(dwn[dwn.size()-2], dwn[dwn.size()-1], a[i]))
            {
                dwn.pop_back();
            }
            dwn.push_back(a[i]);
        }
    }

    a.clear();
    FORl(i, 0, up.size()) a.push_back(up[i]);
    FORlb(i, dwn.size()-2, 0) a.push_back(dwn[i]);

    _n = a.size();


    FORl(i, 1, _n) re += a[i].x*(a[(i+1 < _n) ? i+1 : i+1-_n].y - a[i-1].y);
    re += a[0].x*(a[1].y - a[_n-1].y);

    return re/2.0;
}

//Output
void Solve()
{
    int u, v;

    FOR(i, 1, n)
    {
        area[i] = ConvexHull(kingdom[i]);
    }

    while(scanf("%d%d", &u, &v) == 2)
    {
        pt k = pt(u, v);
        FOR(i, 1, n)
        {
            if(!avail[i]) continue;
            if(IsInPoly(k, kingdom[i]))
            {
                avail[i] = false;
                break;
            }
        }
    }

    res = 0;
    FOR(i, 1, n) if(!avail[i]) res += fabs(area[i]);

    printf("%.2f\n", res);

}

//Main Procedure
int main()
{
    FILEOP();


    Enter();
    Solve();
    return 0;
}
