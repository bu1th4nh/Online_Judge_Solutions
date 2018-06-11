//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
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
#define x first
#define y second
#define pb push_back
#define maxinp (int)()
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
//Typedef
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
ii a[6];



//=====================================
//Functions and procedures
ll GCD(ll a, ll b)
{
    if(b == 0) return a;
    else return (b, a % b);
}
ll LatPts(ii a, ii b)
{
    ll x = abs(b.second - a.second), y = abs(b.first - a.first);

    if(x == 0) return y+1;
    if(y == 0) return x+1;

    return GCD(x, y) + 1;
}


//Main Procedure
int main()
{
    FOR(i, 1, 4) scanf("%d%d", &a[i].x, &a[i].y);
    ll s = 0;
    a[5] = a[1];


    s = (a[1].x - a[2].x)*(a[1].x - a[2].x) + (a[1].y - a[2].y)*(a[1].y - a[2].y);

    ll bound = (LatPts(a[1], a[2]) - 1)*2;

    ll res = s + 1 - bound;


    printf("%lld", res);

    return 0;
}
