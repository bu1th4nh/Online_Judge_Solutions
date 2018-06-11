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
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int cost[128], val[128], f[128][2048], n, m;
vi adj[128];


//=====================================
//Functions and procedures
//Enter
void Enter()
{
	scanf("%d%d", &n, &m);
	FOR(i, 2, n) scanf("%d", &val[i]);
	FOR(i, 2, n) scanf("%d", &cost[i]);
	FORl(i, 1, n)
	{
	    int u, v;
	    scanf("%d%d", &u, &v);
	    adj[u].pb(v);
	    adj[v].pb(u);
	}
	MEMS(f, -1);
	f[0][0] = 0;
}

//Check
void DFS(int u, int p)
{
    copy(f[p], f[p]+m+1, f[u]);
    for(int v: adj[u])
    {
        if(v == p) continue;
        DFS(v, u);
    }
    for(int i = 0; i + cost[u] <= m; ++i)
    {
        if(f[u][i] != -1) {f[p][i + cost[u]] = max(f[p][i + cost[u]], f[u][i] + val[u]);}
    }
}


//Process
void Solve()
{
    DFS(1, 0);
    int res = *max_element(f[1], f[1]+m+1);
    printf("%d", res);
}



//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
