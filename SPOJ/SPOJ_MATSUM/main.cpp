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
//Two-dimensional Fenwick Tree
struct FenwickTree2D
{
    #define k(x) x&(-x)
    vector<vector<int>> T;

    void update(int n, int x, int y, int val)
    {
        int y1 = 0;
        while(x <= n)
        {
            y1 = y;
            while(y1 <= n)
            {
                T[x][y1] += val;
                y1 += k(y1);
            }
            x += k(x);
        }
    }
    int query(int x, int y)
    {
        int ret = 0, y1 = 0;
        while(x > 0)
        {
            y1 = y;
            while(y1 > 0)
            {
                ret += T[x][y1];
                y1 -= k(y1);
            }
            x -= k(x);
        }
        return ret;
    }
    void clear()
    {
        T.clear();
        T = vector<vector<int>>(1048, vector<int>(1048, 0));
    }

    ~FenwickTree2D() {}

    FenwickTree2D() {}
};

//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int x, y, u, v, res;
char str[10];
string cmd;
int s, tc;

//=====================================
//Functions and procedures
//Fast I/O
inline int ReadInt()
{
    char b;
    for (b = getchar(); b < '0' || b > '9'; b = getchar());
    int ret = b - '0';
    for (b = getchar(); b >= '0' && b <= '9'; b = getchar())
        ret = ret * 10 + b - '0';
    return ret;
}
void WriteInt(int x)
{
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

//Process
void Solve()
{
    s = ReadInt();
    FenwickTree2D ft;
    ft.clear();

    while(scanf("%s", &str) == 1)
    {
        cmd = string(str);

        if(cmd == "END") break;

//        if(cmd == "SET")
//        {
//            x = ReadInt(), y = ReadInt(), u = ReadInt();
//            v = ft.query(x+1, y+1) - ft.query(x+1, y) - ft.query(x, y+1) + ft.query(x, y);
//            ft.update(s, x+1, y+1, u - v);
//        }
//        else if(cmd == "SUM")
//        {
//            x = ReadInt(), y = ReadInt(), u = ReadInt(), v = ReadInt();
//            res = ft.query(u+1, v+1) - ft.query(u+1, y) - ft.query(x, v+1) + ft.query(x, y);
//            WriteInt(res); puts("");
//        }

        if(cmd == "SET")
        {
            scanf("%d%d%d", &x, &y, &u);
            v = ft.query(x+1, y+1) - ft.query(x+1, y) - ft.query(x, y+1) + ft.query(x, y);
            ft.update(s, x+1, y+1, u - v);
        }
        else if(cmd == "SUM")
        {
            scanf("%d%d%d%d", &x, &y, &u, &v);
            res = ft.query(u+1, v+1) - ft.query(u+1, y) - ft.query(x, v+1) + ft.query(x, y);
            printf("%d\n", res);
        }




    }
}

//Main Procedure
int main()
{
    scanf("%d", &tc);
    while(tc--)
    {
        Solve();
        puts("");
    }
    return 0;
}
