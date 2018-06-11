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

const int N = 2048;
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
int low[N], num[N], in[N], out[N], lab[N];
int n, m, cnt, nSCC, src, sink, s, t;
stack<int> st;
vvi adj;
vb done;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	int u, v;
	scanf("%d%d", &n, &m);

	done = vb(n+1, false);
	adj = vvi(n+1);
	cnt = nSCC = 0;

	FOR(i, 1, m)
	{
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
	}
}

//Check
void DFS(int u)
{
	low[u] = num[u] = ++cnt;
	st.push(u);

	for(int v: adj[u])
	{
		if(done[v]) continue;
		if(num[v] != 0)
		{
			low[u] = min(low[u], num[v]);
		}
		else
		{
			DFS(v);
			low[u] = min(low[u], low[v]);
		}
	}

	if(low[u] == num[u])
	{
		++nSCC;
		while(1)
		{
			int v = st.top(); st.pop();
			lab[v] = nSCC;
			done[v] = true;
			if(v == u) break;
		}
	}
}

//Process
void Solve()
{
	FOR(i, 1, n) if(!num[i]) DFS(i);
	FOR(u, 1, n)
	{
		for(int v: adj[u])
		{
			if(lab[u] != lab[v])
			{
				in[lab[v]]++, out[lab[u]]++;
			}
		}
	}
	FOR(i, 1, nSCC)
	{
		if(in[i] == 0) src++, s = i;
		if(out[i] == 0) sink++, t = i;
	}
	if(src != 1 || sink != 1) printf("NO");
	else
	{
		printf("YES\n");
		FOR(i, 1, n) if(lab[i] == s) {s = i; break;}
		FOR(i, 1, n) if(lab[i] == t) {t = i; break;}
		printf("%d %d", t, s);
	}
}

//Main Procedure
int main()
{
	Enter();
	Solve();
    return 0;
}
