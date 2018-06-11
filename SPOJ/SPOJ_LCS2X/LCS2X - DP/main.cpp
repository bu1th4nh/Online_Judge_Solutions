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
int tc;
vi a, b, X, Y;  //X[j]: F[i][j] - Y[j]: F[i-1][j]

//=====================================
//Functions and procedures
//Process
void Solve()
{
	int m, n, res;
	int prev_max = 0, cur_max = 0;

	scanf("%d%d", &m, &n);

	vi x(n, 0);     //x[i] : the length of LCS2X ends at b[i];
	a = vi(m+1);
    b = vi(n+1);

	FORl(i, 0, m) scanf("%d", &a[i]);
	FORl(i, 0, n) scanf("%d", &b[i]);

	res = 0;

	FORl(i, 0, m)
	{
		cur_max = 0;
		FORl(j, 0, n)
		{
			prev_max = cur_max;
			if(b[j] * 2 <= a[i]) cur_max = max(cur_max, x[j]);
			if(a[i] == b[j]) x[j] = max(x[j], prev_max + 1);
		}
	}

	FORl(i, 0, n) res = max(res, x[i]);

	printf("%d\n", res);
}

void Solve_2()
{
    int m, n, res;
	int prev_max = 0, cur_max = 0;

	scanf("%d%d", &m, &n);

    X = Y = vi(n+1, 0);
    a = vi(m+1);
    b = vi(n+1);
	FOR(i, 1, m) scanf("%d", &a[i]);
	FOR(i, 1, n) scanf("%d", &b[i]);

	res = 0;

    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            if(a[i] != b[j]) X[j] = Y[j];
            else
            {
                X[j] = 1;
                FOR(v, 1, j-1)
                {
                    if(b[v]*2 <= b[j]) X[j] = max(X[j], Y[v] + 1);
                }
            }
        }
        Y = X;
    }

//    puts("");
//    for(vi x: F)
//    {
//        for(int i: x) cout << i << " ";
//        puts("");
//    }
//    puts("");

    printf("%d\n", *max_element(whole(X)));
}

//Main Procedure
int main()
{
	scanf("%d", &tc);
	while(tc--)
	{
		Solve_2();
	}
    return 0;
}
