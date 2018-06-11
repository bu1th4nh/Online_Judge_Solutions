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
typedef long long ll;
typedef pair<int, int> pt;
typedef unsigned long long ull;
typedef map<pt, bool> mptb;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<pt> vpt;
typedef set<pt> spt;
int n, res;
vpt vect;
spt ss;
vb fr;
vi st;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    vect.push_back(pt(-123456666, -678900000));
    int u, v;
	scanf("%d", &n);
	FOR(i, 1, n)
	{
	    scanf("%d%d", &u, &v);
	    pt vtx = pt(u, v);
	    vect.push_back(vtx);
	}
	st = vi(n+1);
}

//Check
bool cmp(pt a, pt b)
{
    return (a.y < b.y) || ((a.y == b.y) && a.x < b.x);
}
bool IsCW(pt a, pt b, pt c)
{
    return a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y) < 0;
}
bool IsS(pt a, pt b, pt c)
{
    return a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y) != 0;
}
bool Straigh()
{
    if(n < 3) return true;
    FOR(i, 3, n)
    {
        if(IsS(vect[i-2], vect[i-1], vect[i])) return false;
    }
    return true;
}

//Process
void ConvexHull()
{
	int m = 0;
    fr = vb(n+1, true);

    FOR(i, 1, n)
    {
        while(m >= 2 && IsCW(vect[st[m - 1]], vect[st[m]], vect[i]))
        {
            fr[st[m]] = true;
            m--;
        }
        ++m, st[m] = i, fr[i] = false;
    }

    int t = m + 1;
    fr[1] = true;

    FORb(i, n, 1)
    {
        if(!fr[i]) continue;
        while(m >= t && IsCW(vect[st[m - 1]], vect[st[m]], vect[i]))
        {
            fr[st[m]] = true;
            m--;
        }
        ++m, st[m] = i, fr[i] = false;
    }

    int d = 0;
    FORl(i, 1, n) if(fr[i]) vect[++d] = vect[i];
    n = d;

}
void Solve()
{
    res = 0;
    sort(whole(vect), cmp);
    while(!Straigh())
    {
        ConvexHull();
        ++res;
    }
    printf("%d", res);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
