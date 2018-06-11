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
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi trace, res, F, G;
int m, n, nTest;
vii a;

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
	scanf("%d%d", &n, &m);
	trace = vi(m+11, -1);
	F = G = vi(m+11, 0);
	a = vii(n+1);
	res.clear();

    FOR(i, 1, n) scanf("%d", &a[i].fi);
    FOR(i, 1, n) scanf("%d", &a[i].se);
}

//Check
void DP()
{
    FOR(i, 1, n)
    {
        FOR(j, 0, a[i].fi - 1) F[j] = G[j];
        FOR(j, a[i].fi, m)
        {
            if(G[j] < G[j - a[i].fi] + a[i].se)
            {
                F[j] = G[j - a[i].fi] + a[i].se;
                trace[j] = i;
            }
        }
        G = F;
    }

    int mval = 0, ptr = 0;
    FORb(i, m, 1) if(F[i] > mval) mval = F[i], ptr = i;

    while(trace[ptr] != -1)
    {
        res.push_back(trace[ptr]);
        ptr -= a[trace[ptr]].fi;
    }

    printf("%d %d\n", mval, res.size());
    FORb(i, res.size()-1, 0) printf("%d ", res[i]);
    putchar('\n');
}


//Main Procedure
int main()
{
    scanf("%d", &nTest);
    while(nTest--)
    {
        Enter();
        DP();
    }
    return 0;
}
