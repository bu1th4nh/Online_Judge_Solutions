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

const int max_v = 10000 + 10;
const int max_val = 10000;
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
static int LP[max_v];
vvii fact(max_v);
vi freq(max_v);
ll res1, res2;
vi a, c;
int n;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	scanf("%d", &n); a = c = vi(n+1);
	FOR(i, 1, n) scanf("%d", &a[i]);
	FOR(i, 1, n) ++freq[a[i]];
}

//Check
void Factorization()
{
    vi prime;
    FOR(i, 2, max_val)
    {
        if(!LP[i])
        {
            LP[i] = i;
            prime.push_back(i);
        }
        for(int j = 0; j < prime.size() && prime[j] <= LP[i] && i * prime[j] <= max_val; ++j)
        {
            LP[i*prime[j]] = prime[j];
        }
    }

    FOR(i, 1, 10000)
    {
        if(!freq[i]) continue;
        for(int pr: prime)
        {
            int cnt = 0, v = i;
            while(v % pr == 0) ++cnt, v /= pr;
            fact[pr].pb(ii(cnt, freq[i]));
        }
    }
}
ll Power(int x, int k)
{
    ll r = 1;
    FOR(i, 1, k) r *= x;
    return r;
}

//Process
void Solve()
{
    Factorization();

    int mid, l;
    ll g, s;

    res1 = 0LL, res2 = 1LL;

    FOR(i, 1, max_val)
    {
        if(fact[i].size() > 0)
        {
            l = 0;
            g = s = 0LL;
            c = vi(51, 0);
            mid = (n + 1) / 2;

            for(ii x: fact[i]) c[x.first] += x.second;

            FOR(j, 0, 50) g += (ll)(j) * c[j];
            FOR(j, 0, 50)
            {
                s += (ll)(j) * c[j];
                l += c[j];

                if(l >= mid)
                {
                    res1 += 1LL * j * l - s + (g - s) - 1LL * j * (n - l);
                    res2 *= Power(i, j);
                    break;
                }
            }
        }
    }

    printf("%lld %lld", res1, res2);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
