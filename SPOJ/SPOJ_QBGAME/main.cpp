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
#define maxinp (int)(10009)
#define MODUL (int)(2000000000)
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
int n, maxA, nBase;
ll F[256][maxinp];
ll s[256][maxinp];
int a[9][maxinp];
vi base;
ll res;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	maxA = -MODUL;
	res = -MODUL;
	scanf("%d", &n);
	FOR(i, 1, 8)
	{
	    FOR(j, 1, n)
	    {
	        scanf("%d", &a[i][j]);
	        maxA = max(maxA, a[i][j]);
	    }
	}
}

//Check
int GetBit(int k, int x)
{
    return (x >> (k))&1;
}
int ok(int x, int y)
{
    return ((x&y) == 0) ? 1 : 0;
}

//Process
void Init()
{
    FOR(i, 0, 255) if((i&(i>>1)) == 0) base.push_back(i);
    nBase = base.size() - 1;
    FOR(i, 1, n)
    {
        FOR(j, 0, nBase)
        {
            int tmp = base[j];
            FOR(k, 0, 7)
            {
                if(GetBit(k, tmp) == 1) s[base[j]][i] += (ll)a[k+1][i];
            }
        }
    }
}
void Process()
{
    FOR(i, 1, n)
    {
        FOR(j, 0, nBase)
        {
            F[base[j]][i] = -MODUL;
            FOR(k, 0, nBase)
            {
                if(k==j) continue;
                if(ok(base[k], base[j]) == 0) continue;
                F[base[j]][i] = max(F[base[j]][i], F[base[k]][i-1] + s[base[j]][i]);
            }
            res = max(res, F[base[j]][i]);
        }
    }
    printf("%lld", res);
}
void Solve()
{
    if(maxA<0) printf("%d", maxA);
    else
    {
        Init();
        Process();
    }
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
