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
#define sp ' '
#define el '\n'
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
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;

//=====================================
//Functions and procedures
//Process
class Solve
{
private:

    ll n;
    const long long MOD = 29*1LL;


    ll Power(ll a, ll b)
    {
        if(b == 0) return 1LL;
        if(b == 1) return (a % MOD);

        ll ret = Power(a, b/2);
        return (b % 2 == 1) ? (1LL * ret * ret * a) % MOD : (1LL * ret * ret) % MOD;
    }

public:

    Solve() {}
    void solve(ll a)
    {
        ll res = 1LL * ((Power(2, 2*a+1LL) - 1LL) * ((Power(3, a+1LL) - 1LL) * Power(2, MOD-2)) * ((Power(167, a+1LL) - 1LL) * Power(166, MOD-2))) % MOD;
        printf("%lld\n", res);
    }

};


//Main Procedure
int main()
{
    ll a = 0;
    while(scanf("%lld", &a) == 1 && a)
    {
        Solve sv;
        sv.solve(a);
    }
    return 0;
}
