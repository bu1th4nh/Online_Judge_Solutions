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
#define maxinp (int)()
#define MODUL (int)(1e9+57)
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
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef long long ll;
vvi col, row, f;
int n, nTest;


//=====================================
//Functions and procedures
//Process
vvi MakeArr(int _n)
{
    return vvi(_n+1, vi(_n+1, 0));
}

void Solve()
{
	scanf("%d", &n);
	col = MakeArr(n);
	row = MakeArr(n);
	f = MakeArr(n);
	FOR(i, 1, n)
	{
	    FOR(j, 1, n)
	    {
	        int x;
	        scanf("%d", &x);
	        row[i][j] = row[i][j-1] + x;
	        col[i][j] = col[i-1][j] + x;
	        if(~row[i][j] & 1) f[i][j] |= ~f[i-1][j];
	        if(~col[i][j] & 1) f[i][j] |= ~f[i][j-1];
	    }
	}
	if(f[n][n]) printf("YES\n");
	else printf("NO\n");
}

//Multitest
void Multitest()
{
    scanf("%d", &nTest);
    FOR(iiiiii, 1, nTest)
    {
        Solve();
    }
}

//Main Procedure
int main()
{
    Multitest();
    return 0;
}
