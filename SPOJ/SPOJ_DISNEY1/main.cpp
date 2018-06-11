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


const int INF = 1000000000;
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
int n, res, d[200][200], f[200][200];


//=====================================
//Functions and procedures
template<class T> void checkMin(T &a, const T &b)
{
	if(b < a) a = b;
}
//Main Procedure
int main()
{
	cin >> n;
	FORl(i, 0, n)
	{
	    FORl(j, 0, n)
	    {
			cin >> d[i][j];
	    }
	}

	memset(f, 0x3f, sizeof f);
	int res = INF;
	f[0][0] = 0;
	FORl(i, 0, n)
	{
		FORl(j, 0, n) if(f[i][j] < INF)
        {
			int next = max(i, j) + 1;
			if(next == n) checkMin(res, f[i][j] + d[i][0] + d[j][0]);
			else
			{
				checkMin(f[i][next], f[i][j] + d[j][next]);
				checkMin(f[next][j], f[i][j] + d[i][next]);
				checkMin(f[next][next], f[i][j] + d[i][next] + d[j][next]);
			}
		}
	}
	cout << res << endl;
	return 0;
}
