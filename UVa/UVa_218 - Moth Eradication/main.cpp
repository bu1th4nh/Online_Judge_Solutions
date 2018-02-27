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
typedef unsigned long long ull;
typedef pair<double, double> pt;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<pt> vpt;
typedef vector<ii> vii;
typedef long long ll;
const double eps = 1e-9;
int n, nRegion;
double res;
vpt vect;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    vect.clear();
    double u, v;
    FOR(i, 1, n)
    {
        scanf("%lf %lf", &u, &v);
        vect.push_back(pt(u, v));
    }
    if(nRegion) puts("");
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
double dist(pt a, pt b)
{
    return (double)(hypot(a.x - b.x, a.y - b.y));
}

//Process
bool ConvexHull()
{
    if(vect.size() <= 2)
    {
        return false;
    }

    sort(whole(vect), cmp);
    pt p1 = vect[0], p2 = vect.back();

    vpt up, dwn;
    up.push_back(p1);
    dwn.push_back(p1);

    FORl(i, 1, n)
    {
        //Up
        if(i == n-1 || IsCW(p1, vect[i], p2))
        {
            while(up.size() >= 2 && !IsCW(up[up.size()-2], up[up.size()-1], vect[i]))
            {
                up.pop_back();
            }
            up.push_back(vect[i]);
        }

        //Down
        if(i == n-1 || IsCCW(p1, vect[i], p2))
        {
            while(up.size() >= 2 && !IsCCW(dwn[dwn.size()-2], dwn[dwn.size()-1], vect[i]))
            {
                dwn.pop_back();
            }
            dwn.push_back(vect[i]);
        }
    }

    vect.clear();

    FORl(i, 0, up.size()) vect.push_back(up[i]);
    FORlb(i, dwn.size() - 2, 0) vect.push_back(dwn[i]);

    n = vect.size();
    FOR(i, 1, n-1)
    {
        res += sqrt((vect[i].x-vect[i-1].x)*(vect[i].x-vect[i-1].x) + (vect[i].y-vect[i-1].y)*(vect[i].y-vect[i-1].y));
    }
    res += sqrt((vect[n-1].x-vect[0].x)*(vect[n-1].x-vect[0].x) + (vect[n-1].y-vect[0].y)*(vect[n-1].y-vect[0].y));
    return true;
}
void Solve()
{
    res = 0;
    ConvexHull();

    printf("Region #%d:\n", ++nRegion);
    FORl(i, 0, n) printf("(%.1lf,%.1lf)-", vect[i].x, vect[i].y);
    printf("(%.1lf,%.1lf)\n", vect[0].x, vect[0].y);
    printf("Perimeter length = %.2lf\n\n", res);

}

//Output
void Multitest()
{
    while(scanf("%d", &n) == 1 && n)
    {
        Enter();
        Solve();
    }
}

//Main Procedure
int main()
{
    Multitest();
    return 0;
}
