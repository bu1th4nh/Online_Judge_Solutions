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
typedef stack<int> si;
typedef vector<vii> vvii;
int num[16384], low[16384], tp[16384];
int n, m, res, nComp, cnt, t;
vb avail, mark, visiting;
vvi adj;
si st;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP()
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter()
{
	scanf("%d%d%d", &n, &m, &t);

	int u, v;

	nComp = cnt = 0;
	adj = vvi(n+1);
	avail = vb(n+1, true);
	visiting = mark = vb(n+1, false);

	FOR(i, 1, m)
	{
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
	}

}

//Check
void DFS(int u)
{
	visiting[u] = true;
	avail[u] = false;
	st.push(u);

	low[u] = num[u] = ++cnt;

	for(int v: adj[u])
	{
		if(avail[v])
		{
			DFS(v);
			low[u] = min(low[u], low[v]);
		}
		else if(visiting[v]) low[u] = min(low[u], num[v]);
	}

	if(low[u] == num[u])
	{
		++nComp;
		while(true)
		{
			int v = st.top();
			tp[v] = nComp;
			st.pop();

			if(v == u) break;
		}
	}

	visiting[u] = false;
}

//Process
void Solve()
{
	res = 0;
	FOR(i, 1, n) if(avail[i]) DFS(i);
	FOR(i, 1, n)
	{
		for(int j: adj[i])
		{
			if(tp[i] != tp[j]) mark[tp[i]] = true;
		}
	}
	FOR(i, 1, nComp) if(!mark[i] && i != tp[t]) ++res;

	cout << res;
}


//Main Procedure
int main()
{
	Enter();
	Solve();
    return 0;
}
