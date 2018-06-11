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
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;
int F[((1<<20)-1)];
ll g[((1<<20)-1)];
int a[21][21];
int n, k, cur;
int lim;

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

//Check
int OffBit(int __k, int __x)
{
    return (__x^(1 << (__k - 1)));
}


//Process
void Try(int i, int m)
{
    int fmax, t;
    ll gmax;
    if(i == n+1)
    {
        fmax = -INFINITY;
        gmax = 0LL;
        FOR(i, 1, n)
        {
            if((k & (1 << (i-1))) != 0)
            {
                t = F[OffBit(i, k)] + a[m][i];
                if (fmax<t)
                {
                    fmax = t;
                    gmax = g[OffBit(i, k)];
                }
                else if(fmax == t) gmax += g[OffBit(i, k)];
            }
        }
        if(F[k] < fmax)
        {
            F[k] = fmax;
            g[k] = gmax;
        }
        else if (F[k] == fmax)
        {
            g[k] += gmax;
        }
        return;
    }

    if(cur == m)
    {
        Try(i+1, m);
        return;
    }

    if(m - cur == n - i + 1)
    {
        ++cur;
        k += (1 << (i-1));
        Try(i+1, m);
        k -= (1 << (i-1));
        --cur;
        return;
    }

    Try(i+1, m);
    ++cur;
    k += (1 << (i-1));
    Try(i+1, m);
    k -= (1 << (i-1));
    --cur;

}


//Output
void Solve()
{
    lim = (1 << n) - 1;
    FOR(i, 0, lim)
    {
        F[i] = -MODUL;
        g[i] = 0;
    }
    F[0] = 0;
    cur  = 0;
    k    = 0;
    g[0] = 1;
    FOR(i, 1, n) Try(1, i);


    printf("%d %lld", F[lim], g[lim]);


}



//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
