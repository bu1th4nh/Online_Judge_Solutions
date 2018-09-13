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
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


//=====================================
//Convex Hull Technique
struct ConvexHullDS
{
    typedef double ld;
    typedef long long ll;
    typedef vector<ll> vll;
    typedef vector<ld> vld;

    vld x;
    vll a, b;
    int head, tail;

    ll query(ll x_query)        //Get the optimal value from constructed set of lines with x = a[i]
    {
        if(head > tail) return 0LL;
        while(head < tail && x[head + 1] <= x_query) head++;

        x[head] = x_query;
        return (1LL * a[head] * x_query + b[head]);
    }

    void update(ll new_a, ll new_b)     //Add a line to the set
    {
        ld new_x = -1e18;
        while(head <= tail)
        {
            if(new_a == a[tail]) return;
            new_x = 1.0 * (b[tail] - new_b) / (new_a - a[tail]);

            if(head == tail || new_x >= x[tail]) break;
            tail--;
        }

        a[++tail] = new_a;
        b[tail]   = new_b;
        x[tail]   = new_x;
    }

    ConvexHullDS()
    {
        head = 1, tail = 0;
        x = vld(131073, 0.0);
        a = b = vll(131073, 0LL);
    }

    ~ConvexHullDS() {}
};



//=====================================
//Typedefs
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
vll a, b, dp;
int n;


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
	scanf("%d", &n);

	a = b = dp = vll(n+1, 0LL);

	FOR(i, 1, n) scanf("%lld", &a[i]);
	FOR(i, 1, n) scanf("%lld", &b[i]);
}

//Process
void Solve()
{
    ConvexHullDS tml;

    FOR(i, 1, n)
    {
        dp[i] = tml.query(a[i]);
        tml.update(b[i], dp[i]);
    }

    printf("%I64d\n", dp[n]);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
