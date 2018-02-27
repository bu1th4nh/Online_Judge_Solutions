//Libraries and namespaces
//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;


//=====================================
//Macros
#define MODUL (int)(1e9+57)
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
//Main Procedure
int main()
{
    int init, c1, c2, c3, res;
    while(scanf("%d %d %d %d", &init, &c1, &c2, &c3), init || c1 || c2 || c3)
    {
        res = 1080;
        res += (init - c1 > 0) ? (init -  c1)*9 : (init -  c1 + 40)*9;
        res += (c2 - c1 > 0) ? (c2 -  c1)*9 : (c2 -  c1 + 40)*9;
        res += (c2 - c3 > 0) ? (c2 -  c3)*9 : (c2 -  c3 + 40)*9;
        printf("%d\n", res);
    }
    return 0;
}
