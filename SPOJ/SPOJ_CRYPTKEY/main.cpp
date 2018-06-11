/*==============================================================================================================*\
**                                  _           _ _   _     _  _         _                                      **
**                                 | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   **
**                                 | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  **
**                                 | |_) | |_| | | |_| | | |__   _| | | | | | |                                 **
**                                 |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 **
\*==============================================================================================================*/
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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vll a, p, b;
int tc, n;
ll k;

//=====================================
//Functions and procedures
//Math Utilities
ll GCD(ll _a, ll _b)
{
    while(_b > 0)
    {
        _a %= _b;
        swap(_a, _b);
    }
    return _a;
}
vll Factorization(ll x)
{
    vll ret;
    ll d = 2;
    while(d * d <= x)
    {
        if(x % d == 0)
        {
            ll tmp = 1;
            while(x % d == 0) x /= d, tmp *= d;
            ret.push_back(tmp);
        }
        ++d;
    }
    if(ret.empty() || x > 1) ret.push_back(x);
    return ret;
}


//Process
void Solve()
{
    scanf("%d", &n);
    a = vll(n, 0LL);
    for(ll &x: a) scanf("%lld", &x);
    scanf("%lld", &k);

    p = Factorization(k);
    b = vll(p.size(), 0);

    for(ll x: a)
    {
        FORl(i, 0, b.size())
        {
            if(x % p[i] == 0)               //Check if a[i] % prime_factor[j]
            {
                b[i] = GCD(x, b[i]);        //Get the GCD value of all a[i] | a[i] % prime_factor[j] == 0.
            }
        }
    }
    bool ok = true;

    for(ll x: b) ok &= (x > 0 && k % x == 0);
    printf("%s\n", ok? "YES" : "NO");
}



//Main Procedure
int main()
{
    scanf("%d", &tc);
    while(tc--)
    {
        Solve();
    }
    return 0;
}
