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
#define maxinp (int)(512)
#define MODUL (int)(1e9+57)
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int t[maxinp][maxinp];
int c[maxinp][maxinp];
int a[maxinp];
int n, m;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	scanf("%d", &n);
	FOR(i, 1, n) scanf("%d", &a[i]);
	scanf("%d", &m);
	FOR(i, 1, m)
	{
	    int u, v;
	    scanf("%d%d", &u, &v);
	    scanf("%d%d", &t[u][v], &c[u][v]);
	    t[v][u] = t[u][v];
	    c[v][u] = c[u][v];
	}
}

//Check
int Check(int w)
{
    vi d(n+2, 1000000000), e(n+2, 0);
    vector<bool> b(n, true);
    d[1] = 0;
    e[1] = w;
    FOR(i, 1, n)
    {
        int u = -1;
        FOR(v, 1, n) if(b[v])
        {
            if(u < 0 || d[u] > d[v]) u = v;
        }
        if(u<0) break;
        if(u==n) return d[u];
        b[u] = false;

        FOR(v, 1, n) if(t[u][v] && e[u] - c[u][v] >= 0)
        {
            if(d[v] > d[u] + t[u][v])
            {
                d[v] = d[u] + t[u][v];
                e[v] = a[v] ? w : e[u] - c[u][v];
            }
            else if(d[v] == d[u] + t[u][v])
            {
                e[v] = max(e[v], e[u] - c[u][v]);
            }
        }
    }
    return -1;
}

//Process
void Solve()
{
    int tmin = Check(1000000000);
    int l = 0, r = 1000000000;
    while(l <= r)
    {
        int k = (l + r) / 2;
        if(Check(k) == tmin) r = k - 1;
        else l = k + 1;
    }
    printf("%d", l);
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
