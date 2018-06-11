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

const int inf = 2000000007;
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
int T1[300007] = {0}, T2[300007] = {0};
int a, b, n, res;
vii vect;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	int u, v;
	scanf("%d%d%d", &n, &a, &b);

	vect.pb(ii(-999, -999));

	FOR(i, 1, n)
	{
		scanf("%d%d", &u, &v);
		vect.pb(ii(u, v));
	}
}

//Process
void Solve()
{
	sort(whole(vect));

	//for(ii x: vect) printf("%d %d\n", x.fi, x.se);
	res = inf;

	FOR(i, 1, n)
	{
		T1[i] = T1[i-1] + (vect[i].se == 1);
        T2[i] = T2[i-1] + (vect[i].se == 2);
	}

	// FOR(i, 1, n) printf("%d ", T1[i]); puts("");
	// FOR(i, 1, n) printf("%d ", T2[i]); puts("");

	int j = 1;
	FOR(i, 1, n)
	{
		while(T1[i] - T1[j-1] >= a && T2[i] - T2[j-1] >= b)
		{
			res = min(res, vect[i].fi - vect[j].fi);
			++j;
		}
	}

	if(res == inf) res = -1;

	printf("%d\n", res);
}

//Main Procedure
int main()
{
	Enter();
	Solve();
    return 0;
}

/*
7 2 2
20 2
30 1
25 1
35 1
60 2
65 2
10 1*/
