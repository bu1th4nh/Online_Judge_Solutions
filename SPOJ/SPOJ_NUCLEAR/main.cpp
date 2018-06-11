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
#define fi first
#define se second
#define maxvalueinp (int)()
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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
int ax, ay, bx, by;
int res = 0;
int q, n;
vii vect;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%d", &n);
    FOR(i, 1, n)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        vect.push_back(ii(x, y));
    }
    scanf("%d%d%d%d%d", &ax, &ay, &bx, &by, &q);
}

//Check
int Query(int r1, int r2)
{
    int cnt = 0;
    FORl(i, 0, n)
    {
        ll tmp1 = (1LL*vect[i].fi - 1LL*ax) * (1LL*vect[i].fi - 1LL*ax) + (1LL*vect[i].se - 1LL*ay) * (1LL*vect[i].se - 1LL*ay);
        ll tmp2 = (1LL*vect[i].fi - 1LL*bx) * (1LL*vect[i].fi - 1LL*bx) + (1LL*vect[i].se - 1LL*by) * (1LL*vect[i].se - 1LL*by);
        if((tmp1 <= 1LL*r1*r1) || (tmp2 <= 1LL*r2*r2)) ++cnt;
    }
    return cnt;
}


//Process
void Solve()
{
    FOR(kk, 1, q)
    {
        int R1, R2;
        scanf("%d%d", &R1, &R2);
        res = Query(R1, R2);
        printf("%d\n", res);
    }
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
