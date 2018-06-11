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
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef long long ll;
ll a[128][128], SumCol, Rest, tmp;
int n;

//=====================================
//Main Procedure
int main()
{
	MEMS(a, 0);

	SumCol = Rest = tmp = 0LL;

	cin >> n;
	FOR(i, 1, n)
	{
	    FOR(j, 1, n)
	    {
	        scanf("%lld", &a[i][j]);
	        Rest += a[i][j];
	    }
	}

	SumCol = Rest / (n-1);
	FOR(i, 1, n)
	{
	    tmp = 0LL;
	    FOR(j, 1, n)
	    {
	        tmp += a[i][j];
	    }
	    a[i][i] = SumCol - tmp;
	}

	FOR(i, 1, n)
	{
	    FOR(j, 1, n)
	    {
	        printf("%lld ", a[i][j]);
	    }
	    puts("");
	}

    return 0;
}
