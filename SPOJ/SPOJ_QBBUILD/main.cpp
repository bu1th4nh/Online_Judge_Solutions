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
#define maxinp (int)(100)
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
typedef long long ll;
int a[maxinp][maxinp];
int x[5];
int res;
int n;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	scanf("%d", &n);
    res = MODUL;
	int u, v, c;
	FOR(i, 1, n)
	{
	    FOR(j, 1, n)
	    {
	        a[i][j] = (i == j) ? 0 : MODUL;
	    }
	}
	FOR(i, 1, 4) scanf("%d", &x[i]);
	while(scanf("%d%d%d", &u, &v, &c) == 3)
    {
        a[u][v] = c;
        a[v][u] = c;
    }
}

//Floyd's Algorithm
void Floyd()
{
    FOR(k, 1, n)
    {
        FOR(u, 1, n)
        {
            FOR(v, 1, n)
            {
                a[u][v] = min(a[u][k] + a[k][v], a[u][v]);
            }
        }
    }
}

//Process
void Solve()
{
    FOR(u, 1, n)
    {
        FOR(v, u, n)
        {
            FOR(i, 1, 3)
            {
                FOR(j, (i+1), 4)
                {
                    int tmp = a[x[i]][u] + a[x[j]][u] + a[u][v];
                    FOR(k, 1, 4) if(k!=i && k!=j) tmp += a[x[k]][v];
                    res = min(res, tmp);
                }
            }
        }
    }
    printf("%d", res);
}

//Main Procedure
int main()
{
    Enter();
    Floyd();
    Solve();
    return 0;
}
