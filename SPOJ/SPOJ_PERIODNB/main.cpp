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


const long long inf = 12345678998764321;
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
typedef deque<ll> dll;
typedef vector<vii> vvii;
ll m, n, p, q, res, delta;
dll dq;
vll a;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%lld%lld%lld%lld%lld", &n, &delta, &p, &q, &m);
    a = vll(2*n + 1, 0LL);
}

//Process

void Solve()
{
    /*
        Solution:
            a[i] = (p * i) % m + q + i * delta
            a[i+n] = a[i] + n * delta

            res = min{a[i] - (i - 1) * delta}, 1 <= i <= n
            -- Using Deque to find
    */

    res = inf;

    //Sequence Preparation
    FOR(i, 1, n)
    {
        a[i] = (p * i) % m + q + i * delta;
        a[i+n] = a[i] + n * delta;
    }


    //Find min{ max{a[i], l <= i <= l + n} }
    FORl(i, 1, n)
    {
        while(!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
        dq.push_back(i);
    }
    FORl(i, n, 2*n)
    {
        if(i - dq.front() == n) dq.pop_front();
        while(!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
        dq.push_back(i);
        res = min(res, a[dq.front()] - (i - n) * delta);
    }


    cout << res << el;
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
