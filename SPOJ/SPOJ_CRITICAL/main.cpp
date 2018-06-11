/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
//Libraries and namespaces
#include <bits/stdc++.h>
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
struct Node
{
    int low = 0, id = 0, trace = -1;
    bool used = false;
    int nChild = 0;

    vector<int> adj;

    Node() {}
};
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<Node> vn;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n, m, dfsTime;
vn adj;


//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v;
	scanf("%d%d", &n, &m);

	adj = vn(n+1);
	dfsTime = 0;

	FOR(i, 1, m)
	{
	    scanf("%d%d", &u, &v);
	    adj[u].adj.pb(v);
	    adj[v].adj.pb(u);
	}
}


//Check
void count_child(int u)
{
    adj[u].used = true;
    adj[u].nChild = 1;

    for(int v: adj[u].adj) if(!adj[v].used)
    {
        count_child(v);
        adj[u].nChild += adj[v].nChild;
    }
}
void DFS(int u, ll sz, ll &cnt)
{
    adj[u].id = adj[u].low = ++dfsTime;
    vll c;

    for(int v: adj[u].adj)
    {
        if(!adj[v].id)
        {
            adj[v].trace = u;
            DFS(v, sz, cnt);

            if(adj[v].low >= adj[u].id) c.push_back(adj[v].nChild);

            adj[u].low = min(adj[u].low, adj[v].low);
        }
        else if(v != adj[u].trace)
        {
            adj[u].low = min(adj[u].low, adj[v].id);
        }
    }


    if(!c.empty())
    {
        c.push_back(sz - 1 - accumulate(whole(c), 0));
        cnt += (sz - 1)*(sz - 1);
        for(ll cx: c) cnt -= cx*cx;
    }
}

//Process
void Solve()
{
    int id = 0;
    ll cnt = 0;

    FOR(i, 1, n) if(!adj[i].used)
    {
        dfsTime = 0;
        count_child(i);
        DFS(i, adj[i].nChild, cnt);
    }

    double res = double(cnt / 2) / double(n);

    printf("%.2lf", res);

}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
