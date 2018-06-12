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
#define task "CONVEXHULL"
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
typedef pair<int, int> pt;
typedef vector<int> vi;
typedef vector<pt> vpt;
typedef long long ll;
typedef set<pt> spt;
vpt vect;
spt ss;
int n;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v;

    ss.clear();
    vect.clear();

    FOR(i, 1, n)
    {
        scanf("%d %d", &u, &v);
        ss.insert(pt(u, v));
    }

    for(pt i: ss) vect.push_back(i);
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

//Process
bool ConvexHull(vpt & a)
{
    if(a.size() == 1)
    {
        printf("1 \n%d %d\n", a[0].x, a[0].y);
        return 1;
    }
    sort(whole(a), cmp);
    pt p1 = a[0];
    pt p2 = a.back();

    vpt up, dwn;
    up.push_back(p1);
    dwn.push_back(p1);

    FORl(i, 1, a.size())
    {
        if(i == a.size() - 1 || IsCW(p1, a[i], p2))
        {
            while(up.size() >= 2 && !IsCW(up[up.size() - 2], up[up.size() - 1], a[i]))
            {
                up.pop_back();
            }
            up.push_back(a[i]);
        }

        if(i == a.size() - 1 || IsCCW(p1, a[i], p2))
        {
            while(dwn.size() >= 2 && !IsCCW(dwn[dwn.size() - 2], dwn[dwn.size() - 1], a[i]))
            {
                dwn.pop_back();
            }
            dwn.push_back(a[i]);
        }

    }

    a.clear();
    FORl(i, 0, up.size()) a.push_back(up[i]);
    FORlb(i, dwn.size()-2, 0) a.push_back(dwn[i]);

    return 0;

}
void Solve()
{
    if(ConvexHull(vect)) return;
    printf("%d\n", vect.size());
    FORb(i, vect.size() - 1, 0)
    {
        printf("%d %d\n", vect[i].x, vect[i].y);
    }
}

//Output
void Multi()
{
    n = 2017;
    while(n != 0)
    {
        scanf("%d", &n);
        if(n == 0) return;
        Enter();
        Solve();
    }
}

//Main Procedure
int main()
{
    Multi();
    return 0;
}
