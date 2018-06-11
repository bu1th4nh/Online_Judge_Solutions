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


const int inf    = 123456789;
const int m10[5] = {1, 10, 100, 1000, 10000};
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
typedef stack<int> si;
int m, n, mn, res;
vvi a, b;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP();
}
void FileDebug()
{
    FILEOP_DEBUG();
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter()
{
	scanf("%d%d", &m, &n);
	a = b = vvi(m, vi(n, 0));
	FORl(i, 0, m)
	{
	    FORl(j, 0, n) scanf("%d", &a[i][j]);
	}
	mn = m*n;
}

//Check
int getBit(int i, int k)
{
    return((i >> k) & 1);
}
bool Check(int x, int y)
{
    return(x < m && y < n && b[x][y] != -1);
}
int GetSum(int state)
{
    si stck;
    int j2, i2, tmp, ret = 0;

    FORl(i, 0, m)
    {
        FORl(j, 0, n)
        {
            b[i][j] = getBit(state, i*n+j);
        }
    }

    //Calculate
    //1 -- Horizontal, 0 -- Vertical.
    FORl(i, 0, m) FORl(j, 0, n) if(b[i][j] != -1)
    {
        if(b[i][j] == 0)
        {
            i2 = i, tmp = 0;
            vi vect;
            while(Check(i2, j) && b[i2][j] == 0)
            {
                b[i2][j] = -1;
                tmp = tmp * 10 + a[i2++][j];
            }

            ret += tmp;
        }
        else
        {
            j2 = j, tmp = 0;
            vi vect;
            while(Check(i, j2) && b[i][j2] == 1)
            {
                b[i][j2] = -1;
                tmp = tmp * 10 + a[i][j2++];
            }

            ret += tmp;
        }
    }

    return ret;

}


//Process
void Solve()
{
    res = -inf;
    FORl(states, 0, (1 << mn)) res = max(res, GetSum(states));
    printf("%d\n", res);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
