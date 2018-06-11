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
int F[128][128];
ll t[128][128];
int a[4][128];
int n, res1;
int z[128];
ll res2;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	int x;
	scanf("%d", &n);
	FOR(i, 1, n)
	{
	    scanf("%d", &x);
	    if(x != 0) a[x][i] = 1;
	}
}

//Check
bool GetBit(int __k, int __i)
{
    return ((__k >> (6 - __i)) & 1);
}
int Calc(int __x)
{
    int tmp = 0;
    FOR(i, 1, 6) {if(GetBit(__x, i)) ++tmp;}
    return tmp;
}

//Process
void Solve()
{
    int lim = (1 << 6) - 1;
    FOR(i, 1, 3) z[1] = z[1] * 2 + a[i][1];
    FOR(i, 2, n)
    {
        FOR(j, 1, 3) z[i] = z[i] * 2 + a[j][i-1];
        FOR(j, 1, 3) z[i] = z[i] * 2 + a[j][i];
    }
    t[0][0] = 1;
    F[0][0] = 0;
    FOR(j, 0, ((1<<3)-1))
    {
        if((z[1]&j) == 0)
        {
            F[1][j] = Calc(j);
            t[1][j] = 1LL;
        }
    }
    FOR(i, 2, n)
    {
        FOR(st, 0, lim)
        {
            if((z[i]&st) == 0)
                FOR(j, 0, lim)
                    if((z[i-2] & j) == 0)
                        if((t[i-2][j]) > 0)
                            if((i > 3 || (i==2 && j==0)) || (i==3&&j<(1<<3)))
                            {
                                bool ok = 1;
                                if(GetBit(st, 1))
                                {
                                    if(GetBit(st, 6)) ok = 0;
                                    if(GetBit(j, 6))  ok = 0;
                                    if(GetBit(j, 2))  ok = 0;
                                }
                                if(GetBit(st, 2))
                                {
                                    if(GetBit(j, 1)) ok = 0;
                                    if(GetBit(j, 3)) ok = 0;
                                }
                                if(GetBit(st, 3))
                                {
                                    if(GetBit(st, 4)) ok = 0;
                                    if(GetBit(j, 2)) ok = 0;
                                    if(GetBit(j, 4)) ok = 0;
                                }
                                if(GetBit(st, 4))
                                {
                                    if(GetBit(st, 3)) ok = 0;
                                    if(GetBit(j, 5)) ok = 0;
                                }
                                if(GetBit(st, 5))
                                {
                                    if(GetBit(j, 4)) ok = 0;
                                    if(GetBit(j, 6)) ok = 0;
                                }
                                if(GetBit(st, 6))
                                {
                                    if(GetBit(j, 5)) ok = 0;
                                    if(GetBit(st, 1)) ok = 0;
                                }
                                if (ok)

                                    if(F[i][st] < F[i-2][j] + Calc(st))
                                    {
                                        F[i][st] = F[i-2][j] + Calc(st);
                                        t[i][st] = t[i-2][j];
                                    }
                                    else
                                    {
                                        if(F[i][st] == F[i-2][j] + Calc(st)) t[i][st] += t[i-2][j];
                                    }

                            }
        }
    }
    FOR(st, 0, lim) res1 = max(res1, F[n][st]);
    FOR(st, 0, lim)
    if(F[n][st] == res1) res2 += t[n][st];

    cout << res1 << " " << res2;

}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
