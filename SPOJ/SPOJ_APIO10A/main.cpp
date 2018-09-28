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


#define NGUYEN_RR
//=====================================
//CHT Library Implementation

#ifndef NGUYEN_RR
/*  This is the implementation of CHT by KTH Royal Institute of Technology, Sweden */

/*
 * Author: Simon Lindholm
 * Date: 2017-04-20
 * License: CC0
 * Source: own work
 * Description: Container where you can add lines of the form kx+m, and query maximum values at points x.
 *  Useful for dynamic programming.
 * Time: O(\log N)
 * Status: tested
 */


bool Q;
struct Line
{
    typedef long long ll;
    mutable ll k, m, p;
    bool operator< (const Line &other) const
    {
        return Q ? p < other.p : k < other.k;
    }
};
struct ConvexHullDP : multiset<Line>
{
    typedef long long ll;
    const ll inf = 12345678987654;

    ll div(ll a, ll b)
    {
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y)
    {
        if(y == end())
        {
            x->p = inf;
            return false;
        }

        if(x->k == y->k) x->p = (x->m > y->m) ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);

        return (x->p >= y->p);
    }
    void update(ll k, ll m)
    {
        auto z = insert({k, m, 0}), y = z++, x = y;

        while(isect(y, z)) z = erase(z);
        if(x != begin() && isect(--x, y)) isect(x, y = erase(y));

        while((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
    }
    ll query(ll x)
    {
        //assert(!empty());
        Q = 1; auto l = *lower_bound({0, 0, x}); Q = 0;
        return l.k * x + l.m;
    }
};


#else
/*    And this is the implementation for CHT by Thanh Trung Nguyen, aka RR,
      team RRWatameda @ NUS' notebook and this is also my preferred implementation.   */

struct ConvexHullDP
{
    typedef double ld;
    typedef long long ll;
    typedef vector<ld> vld;
    typedef vector<ll> vll;

    vld x;
    vll a, b;
    int head, tail;

    ll query(ll x_query)                //Get optimal value from constructed set of lines with query x
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


    ConvexHullDP()
    {
        a = b = vll(1048576, 0LL);
        x = vld(1048576, 0.00000);
        head = 1, tail = 0;
    }
};

#endif

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
int nTest, n, A, B, C;
vll ps, dp;

//=====================================
//Functions and procedures
//Utilities
inline ll sqr(ll x)
{
    return 1LL * x * x;
}
inline ll F(ll m)
{
    return 1LL * A * sqr(m) + 1LL * B * m + C;
}
inline ll G(int i)
{
    return 1LL * A * sqr(ps[i]) - 1LL * B * ps[i];
}
inline int readInt()
{
    char c = 0;
    int ret = 0;
    bool neg = 0;

    while(c != '-' && isdigit(c) == 0) c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + int(c - '0');
    return (neg) ? -ret : ret;
}

//Enter
void Enter()
{
	n = readInt();
	A = readInt();
	B = readInt();
	C = readInt();
	ps = dp = vll(n+10, 0LL);

	FOR(i, 1, n) ps[i] = ps[i-1] + readInt();
}

//Process
void Solve()
{
    ConvexHullDP Planaxis;
    FOR(i, 1, n+1)
    {
        #ifndef NGUYEN_RR
            Planaxis.update((-2LL * A * ps[i-1]) , (dp[i-1] + G(i-1)));
            dp[i] = Planaxis.query(ps[i]) + F(ps[i]);        #else
            Planaxis.update(-(-2LL * A * ps[i-1]) , -(dp[i-1] + G(i-1)));
            dp[i] = -Planaxis.query(ps[i]) + F(ps[i]);
        #endif
    }
    //FOR(i, 1, n) cerr << dp[i] << sp; cerr << el;       //Print dp array.
    printf("%lld\n", dp[n]);
}


//Main Procedure
int main()
{
    nTest = readInt();
    FOR(iTest, 1, nTest)
    {
        Enter();
        Solve();
    }
    return 0;
}


/*
3
4
-1 10 -20
2 2 3 4
5
-1 10 -20
1 2 3 4 5
8
-2 4 3
100 12 3 4 5 2 4 2
*/
