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
typedef vector<vii> vvii;
ull a, b, x, y, m, F[512][512], fib[512];
short tc;


//=====================================
//Functions and procedures
inline ull fmul(ull a, ull b)
{
	if(!b) return 0;
	if(!(b-1)) return a;
	if(b%2)
	{
		return (fmul(a, (b / 2)) * 2 + a) % m;
	}
	else
	{
		return (fmul(a, (b / 2)) * 2) % m;
	}
}

inline ull gcd(ull a, ull b)
{
	return (a ? gcd(b % a, a) : b);
}

//Main Procedure
int main()
{
	int i, j;
	scanf("%d", &tc);
	while(tc--)
	{
		cin >> x >> y >> a >> b >> m;
		fib[1] = 1; fib[2] = 1;

		for (i=3; i < 501; i++) fib[i] = (fib[i-1]+fib[i-2])%m;
   	    for (i=0; i <= x; i++) F[i][0] = i%m;
    	for (i=0; i <= y; i++) F[0][i] = i%m;
    	for (i=1; i <= x; i++)
    	{
	        for (j=1; j <= y; j++)
            {
				F[i][j] = (fmul(a, F[i-1][j])+fmul(b, F[i][j-1])+fib[gcd(i, j)])%m;
            }
    	}

		cout << F[x][y] << endl;
	}
    return 0;
}
