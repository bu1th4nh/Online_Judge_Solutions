/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
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
#define task "BIC"
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
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef stack<int> si;
typedef queue<int> qi;
int m, n, dfsTime, topoTime;
vi num, low, idOrder, comp;
vll F, res;
bool ok;
vvi adj;
vb Free;
si st;
qi q;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	int u, v;
	scanf("%d%d", &n, &m);

	num = low = idOrder = vi(n+1, 0);
	adj = vvi(n+1);

	F = res = vll(n+1, 0LL);
	Free = vb(n+1, true);

	dfsTime = topoTime = 0;

	FOR(i, 1, m)
	{
	    scanf("%d%d", &u, &v);
	    adj[u].pb(v);
	}
}

//Check
void GetSCC(int u)
{
    st.push(u);
    num[u] = low[u] = ++dfsTime;

    for(int v: adj[u])
    {
        if(Free[v])
        {
            if(num[v] == 0)
            {
                GetSCC(v);
                low[u] = min(low[u], low[v]);
            }
            else low[u] = min(low[u], num[v]);
        }
    }

    if(num[u] == low[u])
    {
        int cnt = 0, x = 0;
        do
        {
            x = st.top(); st.pop();
            Free[x] = false;
            ++cnt;
        }
        while(x != u);

        if(cnt > 1)
        {
            comp.push_back(u);
        }
    }
}

void BFS()
{
    for(int start: comp) q.push(start), Free[start] = false;

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int v: adj[u])
        {
            if(Free[v])
            {
                Free[v] = false;
                q.push(v);
            }
        }
    }

    ok = Free[2];
}

void Topological_DFS(int u)
{
    Free[u] = false;
    for(int v: adj[u]) if(Free[v]) Topological_DFS(v);

    idOrder[topoTime--] = u;
}

//Process
void InitBFS()
{
    Free = vb(n+1, true);
    BFS();
}
void InitTopoSort()
{
    Free = vb(n+1, true);
    topoTime = dfsTime;
    Topological_DFS(1);
}
void DP()
{
    F[1] = 1LL;
    FOR(i, 1, dfsTime)
    {
        int u = idOrder[i];
        for(int v: adj[u])
        {
            F[v] = (F[v]*1LL + F[u]*1LL) % 1000000000;
            res[v] = max(res[v], max(res[u], (ll)(F[u] + F[v] >= 1000000000)));
        }
    }
}
void Solve()
{
    GetSCC(1);
    if(!comp.empty())
    {
        InitBFS();
        if(!ok)
        {
            printf("inf");
            return;
        }
    }
    InitTopoSort();
    DP();

    if(res[2] == 0) printf("%lld", F[2]);
    else
    {
        string RESULT;
        while(F[2] > 0)
        {
            RESULT = (char)('0' + F[2] % 10) + RESULT;
            F[2] /= 10;
        }
        while(RESULT.length() < 9) RESULT = '0' + RESULT;
        printf("%s\n", RESULT.c_str());
    }

}

//Main Procedure
int main()
{
    FILEOP();
    Enter();
    Solve();
    return 0;
}
