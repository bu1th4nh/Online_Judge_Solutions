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
int n, m, cnt, res;
vvii adj;
vi num;


//=====================================
//Functions and procedures
//Enter
void Enter()
{
	int u, v;
	scanf("%d%d", &n, &m);

	adj = vvii(n+1);
	num = vi(n+1);
	cnt = 0;

	FOR(i, 1, m)
	{
	    scanf("%d%d", &u, &v);
	    adj[u].pb(ii(v, i));
	    adj[v].pb(ii(u, i));
	}
}

//Check
void DFS(int u, int id)
{
    num[u] = id;
    ++cnt;

    for(ii x: adj[u])
    {
        int v = x.first;
        if(num[v] == id || x.second == id) continue;
        DFS(v, id);
    }
}

//Process
void Solve()
{
    res = 0;
    FOR(i, 1, m)
    {
        cnt = 0;
        DFS(1, i);
        res += cnt*(n - cnt);
    }
    printf("%d", res);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
