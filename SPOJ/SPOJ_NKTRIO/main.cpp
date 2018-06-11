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
#define fi first
#define se second
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
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef long long ll;
int a[1024][1024];
int n;
vii d;

//=====================================
//Functions and procedures
bool cmp(ii x, ii y)
{
    return x.first < y.first;
}
//Main Procedure
int main()
{
    scanf("%d", &n);

    d = vii(n, ii(0, 0));

    FORl(i, 0, n)
    {
        d[i].se = i;
        d[i].fi = 0;
    }

    FORl(i, 0, n)
    {
        FORl(j, 0, n)
        {
            scanf("%d", &a[i][j]);
            if(a[i][j] == 1) d[i].fi++;
        }
    }

    sort(whole(d), cmp);
    FORl(i, 0, n-1)
    {
        if(d[i].fi == d[i+1].fi)
        {
            int x = d[i].se, y = d[i+1].se;
            FORb(j, n-1, 0)
            {
                if(a[y][x] == 1)
                {
                    if(a[x][j] == 1 && a[j][y] == 1)
                    {
                        printf("%d %d %d", x+1, j+1, y+1);
                        return 0;
                    }
                }
                else
                {
                    if(a[y][j] == 1 && a[j][x] == 1)
                    {
                        printf("%d %d %d", y+1, j+1, x+1);
                        return 0;
                    }
                }
            }
        }
    }

    printf("-1 -1 -1");

    return 0;
}
