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
int n, dir = 0;
string t;

/*
    0: +x 1: -x
    2: +y 3: -y
    4: +z 5: -z
*/

//=====================================
//Functions and procedures
//Main Procedure
int main()
{
    while(scanf("%d", &n) && n)
    {
        dir = 0;
        FORl(i, 1, n)
        {
            cin >> t;
            if(t == "No") continue;
            else if(t == "+y")
            {
                if(dir == 0)      dir = 2;
                else if(dir == 1) dir = 3;
                else if(dir == 2) dir = 1;
                else if(dir == 3) dir = 0;
            }
            else if(t == "-y")
            {
                if(dir == 0)      dir = 3;
                else if(dir == 1) dir = 2;
                else if(dir == 2) dir = 0;
                else if(dir == 3) dir = 1;
            }
            else if(t == "+z")
            {
                if(dir == 0)      dir = 4;
                else if(dir == 1) dir = 5;
                else if(dir == 4) dir = 1;
                else if(dir == 5) dir = 0;
            }
            else if(t == "-z")
            {
                if(dir == 0)      dir = 5;
                else if(dir == 1) dir = 4;
                else if(dir == 4) dir = 0;
                else if(dir == 5) dir = 1;
            }
        }

        switch(dir)
        {
            case 0: puts("+x"); break;
            case 1: puts("-x"); break;
            case 2: puts("+y"); break;
            case 3: puts("-y"); break;
            case 4: puts("+z"); break;
            case 5: puts("-z"); break;
        }
    }
    return 0;
}
