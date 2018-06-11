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
#define MODUL (ll)(1e18)
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
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
int n, m, k;
vvi adj, d;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	scanf("%d%d%d", &n, &m, &k);
	adj = vvi(n+2, vi(n+2, MODUL));
	d = vvi(n+2, vi(n+2, MODUL));
	FOR(i, 1, n) adj[i][i] = d[i][i] = 0;
	FOR(i, 1, m)
	{
	    int u, v, c;
	    scanf("%d%d%d", &u, &v, &c);
	    adj[u][v] = c;
	    d[u][v] = c;
	}
}

//Process
void Solve()
{
    FOR(lxlxlx, 1, k)
    {
        int type;
        scanf("%d", &type);
        if(type == 1)
        {
            int node;
            scanf("%d", &node);
            FOR(i, 1, n)
            {
                FOR(j, 1, n)
                {
                    d[i][j] = min(d[i][j], d[i][node] + d[node][j]);
                }
            }
        }
        if(type == 2)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if(d[u][v] == MODUL) printf("-1\n");
            else printf("%lld\n", d[u][v]);
        }
    }
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
