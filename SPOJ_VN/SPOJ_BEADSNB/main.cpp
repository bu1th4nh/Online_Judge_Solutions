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
#define whole(x) x.begin()+1, x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}



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

//=====================================
//Typedef
class FenwickTree
{
public:

    #define _(x) x&(-x)

    vi T;
    int n;

    void update1(int pos, int value)
    {
        while(pos <= n)
        {
            T[pos] = max(T[pos], value);
            pos += _(pos);
        }
    }
    int query1(int pos)
    {
        int ret = 0;
        while(pos > 0)
        {
            ret = max(ret, T[pos]);
            pos -= _(pos);
        }
        return ret;
    }


    void update2(int pos, int value)
    {
        while(pos > 0)
        {
            T[pos] = max(T[pos], value);
            pos -= _(pos);
        }
    }
    int query2(int pos)
    {
        int ret = 0;
        while(pos <= n)
        {
            ret = max(T[pos], ret);
            pos += _(pos);
        }
        return ret;
    }

    void assign(int __n, int StartValue = 0)
    {
        n = __n;
        T = vi(n+20, StartValue);
    }


    FenwickTree(int __n, int StartValue = 0)
    {
        n = __n;
        T = vi(n+20, StartValue);
    }
    FenwickTree() {}

    ~FenwickTree() {T.clear();}

};


//=====================================
//Variable decl.
FenwickTree ft1, ft2;
vi vect, srt, comp;
int n, res;


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
	scanf("%d", &n);
	vect = comp = vi(n+1, 0);

	ft1.assign(n);
	ft2.assign(n);
	FOR(i, 1, n)
	{
	    scanf("%d", &vect[i]);
	}

}

//Process
void Solve()
{
    reverse(whole(vect));
    srt = vect;
    sort(whole(srt));
    FOR(i, 1, n) comp[i] = lower_bound(whole(srt), vect[i]) - srt.begin();



    //FOR(i, 1, n) cout << comp[i] << sp;


    FOR(i, 1, n)
    {
        int x = ft1.query1(comp[i] - 1) + 1;
        ft1.update1(comp[i], x);
        int y = ft2.query2(comp[i] + 1) + 1;
        ft2.update2(comp[i], y);

        res = max(res, x + y - 1);

    }

    cout << res;

}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
