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
#include <tuple>
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

const int INF = 2000000000;
//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef map<int, int> mii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int tc, coin[34];
mii m1, m2;


//=====================================
//Functions and procedures
//Check
void Backtrack(int first, int last, int sum, int c, mii &m)
{
    if(sum > INF) return;
    if(first == last) m[sum] = max(m[sum], c);
    else
    {
        Backtrack(first+1, last, sum, c, m);
        Backtrack(first+1, last, sum+coin[first], c+1, m);
    }
}

//Process
void Solve()
{
    coin[0] = 2, coin[1] = 3, coin[2] = 5;
    FORl(i, 3, 34) coin[i] = coin[i-1] + coin[i-2] + coin[i-3];

    Backtrack(0, 17, 0, 0, m1);
    Backtrack(17, 34, 0, 0, m2);

    scanf("%d", &tc);
    FOR(t, 1, tc)
    {
        int x, res = -1;
        scanf("%d", &x);
        for(auto i: m2)
        {
            if(i.fi <= x)
            {
                if(m1.count(x - i.fi)) res = max(res, i.se + m1[x - i.fi]);
            }
            else break;
        }
        printf("Case #%d: %d\n", t, res);
    }

}


//Main Procedure
int main()
{
    Solve();
    return 0;
}
