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


//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<iii> viii;
vi dp, trace;
int n, w, h;
viii a;

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
    cin>>n>>w>>h;

    trace = vi(n+1, -1);
    dp = vi(n+1, 0);
    a = viii(n+1);

    FOR(i, 1, n) cin>>a[i].fi.fi>>a[i].fi.se, a[i].se = i;
    sort(whole(a));
}

//Process
void Solve()
{
    int start_i = 0;
    FOR(i, 1, n) if(w < a[i].fi.fi && h < a[i].fi.se) dp[i] = 1;
    FOR(i, 1, n)
    {
        FOR(j, 1, i)
        {
            if(w < a[j].fi.fi && h < a[j].fi.se && a[j].fi.fi < a[i].fi.fi && a[j].fi.se < a[i].fi.se)
            {
                if(dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    trace[i] = j;
                }
            }
        }
    }

    int r = *max_element(whole(dp));
    cout << r << el;
    if(!r) return;

    int j = max_element(whole(dp)) - dp.begin();
    vi res;

    while(j > 0)
    {
        res.push_back(a[j].se);
        j = trace[j];
        if(j < 0) break;
    }
    reverse(res.begin(), res.end());
    for(int x: res) cout << x << sp;
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
