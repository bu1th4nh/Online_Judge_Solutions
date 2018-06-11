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
int m, n, nQuery;
ll a[1024][1024];

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	scanf("%d%d%d", &m, &n, &nQuery);
	FOR(i, 1, m)
	{
	    FOR(j, 1, n)
	    {
	        scanf("%lld", &a[i][j]);
	        a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
	    }
	}
}

//Check
ll GetVal(int __x, int __y, int __u, int __v)
{
    return a[__u][__v] - a[__u][__y-1] - a[__x-1][__v] + a[__x-1][__y-1];
}

void Query(int x, int y, int u, int v)
{
    ll localres = 1000000000000;
    ll tmp = GetVal(x, y, u, v);
    FOR(t, 0, 1)
    {
        int mid;
        int l = (t == 0) ? (x) : (y);
        int r = (t == 0) ? (u-1) : (v-1);
        while(l <= r)
        {
            mid  = (l + r) / 2;
            ll s = ( (t == 0) ? (GetVal(x, y, mid, v)) : (GetVal(x, y, u, mid)) )*2 - tmp;
            if(s >= 0)
            {
                localres = (s < localres) ? (s) : (localres);
                r = mid - 1;
            }
            else
            {
                localres = (-s < localres) ? (-s) : (localres);
                l = mid + 1;
            }
        }
    }
    printf("%lld\n", localres);
}


//Process
void Solve()
{
    FOR(QUERY, 1, nQuery)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        Query(a, b, c, d);
    }
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
