/*==============================================================================================================*\
**                                  _           _ _   _     _  _         _                                      **
**                                 | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   **
**                                 | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  **
**                                 | |_) | |_| | | |_| | | |__   _| | | | | | |                                 **
**                                 |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 **
\*==============================================================================================================*/
//=====================================
//Solution Explain
/*

Bài này là một ứng dụng kinh điển của luồng cực đại, có tên là Project selection problem.

Để giải bài này, ta tạo mạng luồng như sau:

      1.Mỗi dự án là một đỉnh của mạng, ngoài ra còn có thêm đỉnh phát s và đỉnh thu t
      2.Với mỗi dự án u có lợi nhuận dương c, ta thêm cung (s,u) với khả năng thông qua là c.
      3.Với mỗi dự án u có lợi nhuận âm c, ta thêm cung (s,u) với khả năng thông qua là -c.
      4.Với mỗi điều kiện công việc u phải thực hiện trước công việc v v, thêm cung (u, v) với khả năng thông qua = +inf

Kết quả của bài toán là max_source - MAXFLOW, max_source = tổng các cung ra từ đỉnh phát.

*/

//=====================================
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

const int inf = 1e9 + 7;
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
int n, m, src, sink, dfs_time, max_source;
vvi cap, flow, adj;
vi dist, DFS_order;

//=====================================
//Functions and procedures   ----------   PROJECT SELECTION PROBLEM
//Enter
void Enter()
{
	int u, v;
	scanf("%d", &n);

	max_source = dfs_time = 0, src = n+1, sink = n+2;

	adj = vvi(n + 6);
	cap = flow = vvi(n+6, vi(n+6, 0));
	DFS_order = dist = vi(n+6, 0);

	FOR(i, 1, n)
	{
		scanf("%d", &u);
		if(u < 0)
		{
			cap[i][sink] = -u;
			adj[i].pb(sink);
			adj[sink].pb(i);
		}
		else
		{
			cap[src][i] = u, max_source += u;
			adj[src].pb(i);
			adj[i].pb(src);
		}
	}

	scanf("%d", &m);
	FOR(i, 1, m)
	{
		scanf("%d%d", &u, &v);
		cap[u][v] = max_source + 1;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	n = n + 2;

}

//Dinitz's Algorithm
bool BFS(int s, int t)
{
	queue<int> q;
	dist = vi(n+1, 0);

	dist[s] = 1;
	q.push(s);

	while(!q.empty())
	{
		int u = q.front(); q.pop();

		if(u == t) return true;
		for(int v: adj[u])
		{
			if(!dist[v] && flow[u][v] < cap[u][v])
			{
				q.push(v);
				dist[v] = dist[u] + 1;
			}
		}
	}

	return false;
}

int DFS(int u, int Min)
{
	if(u == sink) return Min;
	if(DFS_order[u] != dfs_time) DFS_order[u] = dfs_time;
	else return 0;

	for(int v: adj[u])
	{
		if(flow[u][v] < cap[u][v])
		{
			if(DFS_order[v] != dfs_time && dist[v] == dist[u] + 1)
			{
				if(int x = DFS(v, min(Min, cap[u][v] - flow[u][v])))
				{
					flow[u][v] += x;
					flow[v][u] -= x;
					return x;
				}
			}
		}
	}

	return 0;
}


//Process
void Dinitz()
{
	int MAXFLOW = 0;
	while(BFS(src, sink))
	{
		while(int x = (dfs_time++, DFS(src, inf)))
		{
			MAXFLOW += x;
		}
	}


	printf("%d\n", max_source - MAXFLOW);
}

//Main Procedure
int main()
{
	Enter();
	Dinitz();
    return 0;
}
