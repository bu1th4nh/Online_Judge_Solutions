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
#define maxinp (int)(32)
#define MODUL (int)(1e9+57)
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef queue<ii> qii;
typedef long long ll;
int a[maxinp][maxinp];
int F[65556][maxinp];
int t[maxinp];
int n, res;
qii q;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	scanf("%d", &n);
	FOR(i, 1, n)
	{
	    FOR(j, 1, n)
	    {
	        scanf("%d", &a[i][j]);
	    }
	}
}

//Bit Manipulation
int getbit(int k, int x)
{
    return (x >> (k - 1))&1;
}
int offbit(int k, int x)
{
    return x ^ (1 << (k - 1));
}

//Process
void Solve()
{
    int lim = ((1<<n) - 1);

    FOR(i, 1, lim)
    {
        int l = 0;

        FOR(j, 1, n) if(getbit(j, i) == 1) t[++l] = j;

        if(l == 1) continue;

        FOR(j, 1, l)
        {
            int x1 = offbit(t[j], i);

            F[i][t[j]] = MODUL;

            FOR(k, 1, l)
            {
                if((j != k) && F[i][t[j]] > F[x1][t[k]] + a[t[k]][t[j]])  F[i][t[j]] = F[x1][t[k]] + a[t[k]][t[j]];
            }
        }
    }

    res = MODUL;

    FOR(i, 1, n) res = min(res, F[lim][i]);

    printf("%d", res);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
