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
using namespace std;


//=====================================
//Macros
#define task ""
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi F, phi;
int n;


//=====================================
//Functions and procedures
//Process
void Init()
{
    int N = 1000000;

    F = phi = vi(N+128, 0LL);

    FOR(i, 1, N) phi[i] = i;
    FOR(i, 2, N)
    {
        if(phi[i] == i)
        {
            for(int j = i; j <= N; j += i) phi[j] -= phi[j] / i;
        }
    }

    F[1] = 0LL;
    FOR(i, 2, N) F[i] = F[i-1] + phi[i];
}


//Output
void Solve()
{
    ll s = 0LL;
    for(int i = 1; i <= n; )
    {
        ll q = n / i;
        ll r = n / q;
        s += 1LL * (r - i + 1) * (i + r) / 2 * F[q];
        i = r + 1;
    }

    cout << s << '\n';
}


//Main Procedure
int main()
{
    Init();
    while(scanf("%d", &n) == 1 && n)
    {
        Solve();
    }
    return 0;
}
