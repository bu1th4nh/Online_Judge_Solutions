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
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
int m, n, nTest, maxa, maxb, mina, cost, k;
vi costa, costb, lab;
viii a, b;

//=====================================
//Functions and procedures
///Enter
void Enter()
{
	scanf("%d%d", &n, &m);

	costa = costb = vi(n, 0);
	lab = vi(n+1, -1);

	FORl(i, 1, n) scanf("%d", &costa[i]);
	FORl(i, 1, n) scanf("%d", &costb[i]);
	FOR(i, 1, m)
	{
	    int u, v, t;
	    scanf("%d%d%d", &u, &v, &t);
	    if(t == 1) a.push_back(iii(i, ii(u, v)));
	    else b.push_back(iii(i, ii(u, v)));
	}
}

///Kruskal's Algorithm
//Disjoint Set DS
int FS(int u)
{
    return (lab[u] < 0) ? u : (lab[u] = FS(lab[u]));
}
void Union(int r, int s)
{
    if(lab[s] < lab[r]) swap(r, s);
    lab[r] += lab[s];
    lab[s] = r;
}
bool Join(int u, int v)
{
    int r = FS(u);
    int s = FS(v);
    if(r == s) return false;
    else
    {
        Union(r, s);
        return true;
    }
}

//Modified Kruskal's Algorithm
void Kruskal()
{
    cost = 1234567890;
    maxa = 0;
    maxb = 0;
    k = -1;
    for(iii &x: a) if(Join(x.se.fi, x.se.se)) ++maxa;
    lab = vi(n, -1);
    for(iii &x: b) if(Join(x.se.fi, x.se.se)) ++maxb;
    mina = n - 1 - maxb;
    FOR(i, mina, maxa)
    {
        if(cost > costa[i] + costb[n-1-i])
        {
            k = i;
            cost = costa[i] + costb[n-1-i];
        }
    }
}

///Process
void Solve()
{
    bitset<131072> res;
    lab = vi(n+1, -1);
    for(iii &x: b) Join(x.se.fi, x.se.se);
    for(iii &x: a) res[x.first] = Join(x.se.fi, x.se.se);

    lab = vi(n+1, -1);
    for(iii &x: a) if(res[x.first])
    {
        Join(x.se.fi, x.se.se);
        --k;
    }
    if(k > 0) for(iii &x: a) if(Join(x.se.fi, x.se.se))
    {
        res[x.first] = true;
        --k;
        if(k == 0) break;
    }
    for(iii &x: b) res[x.first] = Join(x.se.fi, x.se.se);

    FOR(i, 1, m) if(res[i]) printf("%d ", i);
    printf("\n");

}

///Multi-test processing
void Multitest()
{
    scanf("%d", &nTest);
    FOR(iQuery, 1, nTest)
    {
        Enter();
        Kruskal();
        Solve();
    }
}

//Main Procedure
int main()
{
    Multitest();
    return 0;
}
