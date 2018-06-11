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
typedef pair<ll, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int a, b, c;
ll d[131072];
ll h;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    cin >> h >> a >> b >> c;
}

//Dijkstra's Algorithm
void Dijkstra()
{
    MEMS(d, 0x3f);
	d[0] = 0;

	priority_queue<pair<long long, int> > q;
	q.push(make_pair(0, 0));

    while(!q.empty())
    {
		long long du = -q.top().first;
		int u = q.top().second; q.pop();
		if(d[(u + a) % c] > du + a)
		{
			d[(u + a) % c] = du + a;
			q.push(make_pair(-d[(u + a) % c], (u + a) % c));
		}
		if(d[(u + b) % c] > du + b)
		{
			d[(u + b) % c] = du + b;
			q.push(make_pair(-d[(u + b) % c], (u + b) % c));
		}
	}
}

//Process
void Solve()
{
    Dijkstra();
    ll res = 0;
    FORl(u, 0, c)
    {
        if(d[u] >= h) continue;
        res += (h - d[u] - 1) / c + 1;
    }
    printf("%lld\n", res);
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
