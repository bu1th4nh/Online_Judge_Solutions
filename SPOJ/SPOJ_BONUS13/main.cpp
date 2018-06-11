//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp (int)(100)
#define MODUL (int)(1e9+57)
#define len(x) (int)(x.length())
#define siz(x) (int)(x.size())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef long long ll;
struct Data
{
    int x, y, val;
};
ll res;
int cnt, k;
Data a[maxvalueinp];
Data b[maxvalueinp];
int c[maxvalueinp][maxvalueinp];
int xe[maxvalueinp][maxvalueinp];
int ma[maxvalueinp][maxvalueinp];
int hau[maxvalueinp][maxvalueinp];
int tuong[maxvalueinp][maxvalueinp];

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    cin >> k;
    cnt = 0;
    FOR(i, 1, k)
    {
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].val);
        //cin >> a[i].x >> a[i].y >> a[i].val;
        c[a[i].x][a[i].y] = 1;
    }
    FOR(i, 1, 8)
    {
        FOR(j, 1, 8)
        {
            if(!c[i][j])
            {
                ++cnt;
                b[cnt].x = i;
                b[cnt].y = j;
                b[cnt].val = 0;
            }
        }
    }
}

//Check
int Knight(int i, int j)
{
    int knx = b[i].x, kny = b[i].y;
    int tgx = a[j].x, tgy = a[j].y;
    if ((abs(knx - tgx) == 1 && abs(kny - tgy) == 2)  ||  (abs(knx - tgx) == 2 && abs(kny - tgy) == 1)) return 1;
    return 0;
}
int Rook(int i, int j)
{
    int rkx = b[i].x, rky = b[i].y;
    int tgx = a[j].x, tgy = a[j].y;
    if (tgx == rkx || tgy == rky) return 1;
    return 0;
}
int Bishop(int i, int j)
{
    int bsx = b[i].x, bsy = b[i].y;
    int tgx = a[j].x, tgy = a[j].y;
    if ((bsy - bsx == tgy - tgx) || (bsy + bsx == tgy + tgx)) return 1;
    return 0;
}
int Queen(int i, int j)
{
    int qnx = b[i].x, qny = b[i].y;
    int tgx = a[j].x, tgy = a[j].y;
    if ((qny - qnx == tgy - tgx) || (qny + qnx == tgy + tgx) || ((tgx == qnx) || (tgy == qny))) return 1;
    return 0;
}

//Process
void Solve()
{
    res = 0;
    FOR(i, 1, cnt)
    {
        FOR(j, 1, k)
        {
            ma[i][j] = Knight(i, j);
            xe[i][j] = Rook(i, j);
            hau[i][j] = Queen(i, j);
            tuong[i][j] = Bishop(i, j);
        }
    }
    FOR(MA, 1, cnt)
    {
        FOR(XE, 1, cnt) if(MA != XE)
        {
            FOR(TUONG, 1, cnt) if(TUONG != MA && TUONG != XE)
            {
                FOR(HAU, 1, cnt)
                {
                    if(HAU != XE && HAU != MA && HAU != TUONG)
                    {
                        ll tmp = 0LL;
                        FOR(i, 1, k)
                        {
                            if(ma[MA][i] || xe[XE][i] || hau[HAU][i] || tuong[TUONG][i]) tmp += a[i].val;
                        }
                        if (tmp > res) res = tmp;
                    }
                }
            }
        }
    }
    printf("%lld", res);
    //cout << res;
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
