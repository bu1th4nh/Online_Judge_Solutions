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
//Typedef
struct pt
{
    int x, y;
    pt(int __x, int __y)
    {
        x = __x;
        y = __y;
    }
};

typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<pt> vpt;
typedef long long ll;
int n, nTest;
vpt vect;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    vect.clear();
	int u, v, dmy;
	scanf("%d", &n);
	FOR(i, 1, n)
	{
	    scanf("%d%d", &u, &v);
	    vect.push_back(pt(u, v));
	}
	if(nTest) scanf("%d", &dmy);
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
bool res_cmp(pt a, pt b)
{
    return (a.y < b.y || (a.y == b.y && a.x < b.x));
}

//Process
void ConvexHull(vpt & a)
{
    if(a.size() == 1)
    {
        printf("%d %d\n", a[0].x, a[0].y);
        if(nTest) printf("-1\n");
        return;
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
    FORb(i, dwn.size()-2, 1) a.push_back(dwn[i]);

}
void Solve()
{
    ConvexHull(vect);
    //sort(whole(vect), rescmp);
    printf("%d\n", vect.size());
    for(pt i: vect) printf("%d %d\n", i.x, i.y);
    if(nTest) printf("-1\n");
}

//Output
void Multitest()
{
    scanf("%d", &nTest);
    printf("%d\n", nTest);
    while(nTest--)
    {
        Enter();
        Solve();
    }
}

//Main Procedure
int main()
{

    //freopen("ffff.out", "w", stdout);

    Multitest();
    return 0;
}
