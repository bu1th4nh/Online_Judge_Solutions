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
#define maxinp (int)(16384)
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
typedef queue<int> qi;
typedef long long ll;
bool stable[maxinp];
bool avail[maxinp];
int trace[maxinp];
int nPath[maxinp];
vi adj[maxinp];
int n, m, s;
int res;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	MEMS(stable, false);
	MEMS(avail, false);
	MEMS(trace, -1);
	MEMS(nPath, 0);

	int x, y;
	scanf("%d%d%d", &n, &m, &s);
	FOR(i, 1, m)
	{
	    scanf("%d%d", &x, &y);
	    adj[x].pb(y);
	}
}

//Process
void BFS()
{
    qi que;
    que.push(s);
    trace[s] = s;
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        for(int v: adj[u]) if(trace[v] != u)
        {
            if(trace[v] < 0)
            {
                que.push(v);
                trace[v] = u;
                nPath[v] = nPath[u] + 1;
                stable[v] = stable[u];
            }
            else if(nPath[u] + 1 == nPath[v]) stable[v] = true;
        }
    }
}
void Solve()
{
    BFS();
    res = 0;
    FOR(i, 1, n) res += stable[i];
    printf("%d", res);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
