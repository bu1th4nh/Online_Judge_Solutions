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
typedef pair<ii, int> iii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<iii> viii;
int n, v, maxi, maxj;
ll res, cur;
vii a, b;

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
    int x, y;
    scanf("%d%d", &n, &v);

    res = cur = 0LL;
    maxi = maxj = 0;

    FOR(i, 1, n)
    {
        scanf("%d%d", &x, &y);
        if(x == 1) a.push_back(ii(y, i));
        else b.push_back(ii(y, i));
    }
}

//Process
void Solve()
{
    int i = 0, j = 0;
    sort(whole(a)); reverse(whole(a));
    sort(whole(b)); reverse(whole(b));

    for(i = 0; i < (int)a.size() && v; ++i)
    {
        cur += a[i].fi;
        --v;
    }
    while(j < (int)b.size() && v > 1)
    {
        cur += b[j].fi;
        ++j; v -= 2;
    }

    res = cur;
    maxi = i;

    while(i > 0)
    {
        --i;
        cur -= a[i].fi;
        ++v;

        while(j < (int)b.size() && v > 1)
        {
            cur += b[j].fi;
            ++j; v -= 2;
        }
        if(cur > res)
        {
            maxi = i;
            res = cur;
        }
    }

    v += j * 2;

    cout << res << el;

    if(!res) return;
    FORl(i, 0, maxi) cout << a[i].se << sp;
    for(int i = 0; i < (int)b.size() && 2 * i < (v - maxi); ++i) cout << b[i].se << sp;
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
