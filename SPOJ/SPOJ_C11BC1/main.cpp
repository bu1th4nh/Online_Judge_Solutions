/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
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
#include <tuple>
#include <vector>
#include <utility>

#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#include <random>
#endif // __cplusplus

using namespace std;


//=====================================
//Macroes
#define sp " "
#define el "\n"
#define task ""
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin()+1, x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


const long long mod = 790972;
//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n, k, exc, res;
vii a;
vvi F;


//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP()
}
void FileDebug()
{
    FILEOP_DEBUG()
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter()
{
	scanf("%d%d", &n, &k);

	a = vii(n+1);
	F = vvi(n+100, vi(k+100, 0ll));

	FOR(i, 1, n)
	{
	    F[i][0] = 1;
	    scanf("%lld%lld" ,&a[i].fi, &a[i].se);
	}
}

//Check
bool cmp(ii __a, ii __b)
{
    return __a.second < __b.second;
}
int Calc(int u, int v)
{
    if(v - u + 1 < k) return 0;
    int d = u - 1, l = v - u + 1;

    F[0][0] = 1;
    FOR(j, 1, k)
    {
        FOR(i, j, l) F[i][j] = (F[i-1][j-1] * a[i+d].fi % mod + F[i-1][j]) % mod;
    }
    return F[l][k];
}

//Process
void Solve()
{
    res = Calc(1, n);
	sort(whole(a), cmp);
	a.push_back(ii(0, 2000000002));

	int d = 1;
	FOR(i, 2, n+1) if(a[i].se != a[i-1].se)
	{
	    exc = (exc + Calc(d, i-1)) % mod;
	    d = i;
	}

	res = (res - exc + mod) % mod;
	cout << res;
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
