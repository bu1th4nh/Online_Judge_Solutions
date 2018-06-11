/*==============================================================================================================*\
**                                  _           _ _   _     _  _         _                                      **
**                                 | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   **
**                                 | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  **
**                                 | |_) | |_| | | |_| | | |__   _| | | | | | |                                 **
**                                 |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 **
\*==============================================================================================================*/
//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
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
#include <tuple>
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
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int nx, ny, m;
vi used, my;
vvi adj;


//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v;
	scanf("%d%d%d", &nx, &ny, &m);

	adj = vvi(nx);
	my = vi(ny, -1);
	used = vi(ny, 0);


	FORl(i, 0, m)
	{
	    scanf("%d%d", &u, &v);
	    adj[--u].pb(--v);
	}
}

//Check
bool DFS(int u)
{
	for(int v: adj[u]) if(!used[v])
	{
		used[v] = true;
		if(my[v] == -1 || DFS(my[v])) return my[v] = u, true;
	}
	return false;
}

//Process
void Solve()
{
    int res = 0;
    for(int i = 0; used.assign(1001, 0), i < nx; ++i) if(DFS(i)) ++res;
    printf("%d", res);
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
