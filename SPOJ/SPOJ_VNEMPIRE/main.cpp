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
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int n, cnt, res;
vii x, y, z;
viii EList;
vi lab;


//=====================================
//Functions and procedures
//Enter
void Enter()
{
	scanf("%d", &n);
	lab = vi(n+1, -1);
	FOR(i, 1, n)
	{
	    int a, b, c;
	    scanf("%d%d%d", &a, &b, &c);
	    x.push_back(ii(a, i));
	    y.push_back(ii(b, i));
	    z.push_back(ii(c, i));
	}
}

///Kruskal's Algorithm
//Disjoint Sets DS
int FSet(int u)
{
    return (lab[u] < 0) ? u : lab[u] = FSet(lab[u]);
}
void Union(int r, int s)
{
    if(lab[s] < lab[r]) swap(r, s);
    lab[r] += lab[s];
    lab[s] = r;
}
//Kruskal's Algorithm
void Kruskal()
{
    sort(whole(EList));
    res = cnt = 0;

    for(iii itr: EList)
    {
        int u = FSet(itr.second.first);
        int v = FSet(itr.second.second);
        if(u!=v)
        {
            ++cnt;
            Union(u, v);
            res += itr.first;
            if(cnt == n) return;
        }
    }
}

///Process
void Solve()
{
    sort(whole(x));
    sort(whole(y));
    sort(whole(z));
    FORl(i, 0, n-1)
    {
        int ux = x[i].se, vx = x[i+1].se, cx = abs(x[i+1].fi - x[i].fi);
        int uy = y[i].se, vy = y[i+1].se, cy = abs(y[i+1].fi - y[i].fi);
        int uz = z[i].se, vz = z[i+1].se, cz = abs(z[i+1].fi - z[i].fi);
        iii xx = iii(cx, ii(ux, vx)), yy = iii(cy, ii(uy, vy)), zz = iii(cz, ii(uz, vz));
        EList.push_back(xx);
        EList.push_back(yy);
        EList.push_back(zz);
    }
    Kruskal();
    printf("%d", res);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
