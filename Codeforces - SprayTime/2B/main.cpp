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


const int inf = 123456789;
//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef vector<vii> vvii;
bool isZero;
int n, x, k;
vvi F[2];
vvc G[2];

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
    x = 0;

	scanf("%d", &n);
	F[0] = F[1] = vvi(n+1, vi(n+1, 0));
	G[0] = G[1] = vvc(n+1, vc(n+1, 0));

	FOR(j, 0, 1) FOR(i, 2, n) F[j][0][i] = F[j][i][0] = inf;
	FOR(i, 1, n)
	{
	    FOR(j, 1, n)
	    {
            scanf("%d", &k);
            if(!k) x = i;
            else
            {
                while(k % 2 == 0) ++F[0][i][j], k /= 2;
                while(k % 5 == 0) ++F[1][i][j], k /= 5;
            }

            FOR(p, 0, 1)
            {
                if(G[p][i][j] = F[p][i-1][j] < F[p][i][j-1])
                {
                    F[p][i][j] += F[p][i-1][j];
                }
                else
                {
                    F[p][i][j] += F[p][i][j-1];
                }
            }
	    }
	}
}

//Process
void Print(int x, int y)
{
    if(x == 1 && y == 1) return;
    if(G[k][x][y])
    {
        Print(x-1, y);
        putchar('D');
    }
    else
    {
        Print(x, y-1);
        putchar('R');
    }
}
void Solve()
{
    k = F[1][n][n] < F[0][n][n];
    if(x != 0 && F[k][n][n] > 1)
    {
        puts("1");
        FOR(i, 2, x) putchar('D');
        FOR(i, 2, n) putchar('R');
        FOR(i, x+1, n) putchar('D');
        puts("");
    }
    else
    {
        printf("%d\n", F[k][n][n]);
        Print(n, n);
        puts("");
    }
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
