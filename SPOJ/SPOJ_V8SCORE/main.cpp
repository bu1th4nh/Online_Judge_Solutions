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
#define wholef1(x) x.begin()+1, x.end()
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
int s, k, n, tmp;
bool ok = 0;
vi res;
vvi a;

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
    scanf("%d%d%d", &s, &k, &n);
    a = vvi(k+1, vi(n+1, 0));
    res = vi(n+1, 0);
    res[0] = -1;

    FOR(i, 1, n)
    {
        FOR(j, 1, k) scanf("%d", &a[j][i]);
    }
}

//Check
bool cmp(int a, int b)
{
    return (a > b);
}
void PreSort()
{
    FOR(i, 1, k) sort(wholef1(a[i]), cmp);
}
void PrintRes()
{
    if(tmp != s) return;
    else
    {
        ok = 1;
        puts("YES");
        FOR(i, 1, k) printf("%d ", res[i]);
        puts("");
    }
}
void Backtrack(int i)           //Problem #i, Judge #j
{
//    puts("========================="); cerr << "Attempt #" << i << ": ";
//    FOR(i, 1, k) cerr << res[i] << sp; puts("");
//    puts("=========================");

    FOR(j, 1, n)
    {
//        cerr << j << sp << i << sp << a[i][j] << sp << tmp << el;

        if(a[i][j] < res[i-1]) { /*cerr << "Because " << a[i][j] << " < " << res[i-1]   << " ===> Terminated!\n"  */; break;}

//        cerr << "Try " << a[i][j] << ": \n";

        res[i] = a[i][j];
        tmp += res[i];

//        cerr << i << sp << j << sp << tmp << el;


        if(s - tmp >= res[i] * (k - i))
        {
            if(i == k) PrintRes();
            else if(!ok) Backtrack(i+1);
        }

        tmp -= res[i];
    }

}


//Process
void Solve()
{
    res.clear();

//    for(auto x: a)
//    {
//        for(auto y: x) cerr << y << sp;
//        cerr << el;
//    }

    tmp = 0;
    PreSort();

//    for(auto x: a)
//    {
//        for(auto y: x) cerr << y << sp;
//        cerr << el;
//    }

    Backtrack(1);

    if(!ok) puts("NO");
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
