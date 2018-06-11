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
#define maxinp (int)(128)
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
int c[maxinp];
int n, res;

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
	        if(!a[i][j] && i!=j) a[i][j] = MODUL;
	    }
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
                a[u][v] = min(a[u][v], a[u][k] + a[v][k]);
            }
        }
    }
}

//Process
void Solve()
{
    res = 0;
    int cur = 1;
    c[1] = c[n] = 1;
    while(true)
    {
        int m = MODUL, t = 0;
        FORl(i, 1, n) if(i!=cur && a[i][cur]<m && !c[i])
        {
            m = a[i][cur];
            t = i;
        }
        if(!t) break;
        res += a[t][cur];
        c[t] = 1, cur = t;
    }
    res += a[cur][n];
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
