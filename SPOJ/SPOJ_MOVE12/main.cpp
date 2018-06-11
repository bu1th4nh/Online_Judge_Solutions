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
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef long long ll;
int c[16384], t[16384], n;
vi l, r;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d%d", &c[i], &t[i]);
}

//Process
bool Possible(int val)
{
    l = r = vi(n+1, 0);

    FOR(i, 1, n) l[ max(1, c[i] - val/t[i]) ]++, r[ min(n, c[i] + val/t[i]) ]++;

    FOR(i, 1, n)
    {
        l[i] += l[i-1], r[i] += r[i-1];

        if(l[i] < i || r[i] > i) return false;
    }
    return true;
}
void Solve()
{
    int lo = 0, hi = 100000000, res = hi;
    while(lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        if(Possible(mid)) res = mid, hi = mid - 1;
        else lo = mid + 1;
    }

    printf("%d", res);
}



//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
