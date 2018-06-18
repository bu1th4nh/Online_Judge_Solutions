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
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi fact, inp, res;
ll n, pos;
vb avail;


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
    inp.push_back(-1);
	while(scanf("%lld", &n) != EOF)
    {
        inp.push_back(n);
    }
    pos = inp.back();
    inp.pop_back();

    n = inp.size() - 1;
    fact = vi(14, 1LL);
}

//Process
void Solve()
{
    fact[0] = 1LL;
    FOR(i, 1, 12) fact[i] = 1LL * fact[i-1] * i;

    avail = vb(n+1, 1);    ll res1 = 1LL;
    FOR(i, 1, n)
    {
        FORl(j, 1, inp[i])
        {
            if(avail[j]) res1 += fact[n - i];
        }
        avail[inp[i]] = 0;
    }
    cout << res1 << el;



    avail = vb(n+1, 1);
    FOR(i, 1, n)
    {
        FOR(j, 1, n) if(avail[j])
        {
            if(pos > fact[n-i]) pos -= fact[n-i];
            else
            {
                res.push_back(j);
                avail[j] = 0;
                break;
            }
        }
    }
    for(auto x: res) cout << x << sp;
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
