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
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int n, C, S, B, c, s, b;
vii v1, v2, v3;
int sum = 0;

//=====================================
//Functions and procedures
bool cmp(ii x, ii y)
{
    return x.first <= y.first;
}

//Main Procedure
int main()
{
    cin >> n;
    FOR(i, 0, n-1)
    {
        scanf("%d%d%d", &c, &s, &b);
        sum += c + s + b;
        v1.push_back(ii(c, i));
        v2.push_back(ii(s, i));
        v3.push_back(ii(b, i));
    }
    sort(whole(v1), cmp); reverse(whole(v1));
    sort(whole(v2), cmp); reverse(whole(v2));
    sort(whole(v3), cmp); reverse(whole(v3));
    int mve = 1234567890;
    FORl(i, 0, 3)
    {
        FORl(j, 0, 3)
        {
            FORl(k, 0, 3)
            {
                if(v1[i].se == v2[j].se || v1[i].se == v3[k].se || v3[k].se == v2[j].se)
                {
                    continue;
                }
                if(mve > sum - v1[i].fi - v2[j].fi - v3[k].fi)
                {
                    mve = sum - v1[i].fi - v2[j].fi - v3[k].fi;
                    C = v1[i].se;
                    S = v2[j].se;
                    B = v3[k].se;
                }
            }
        }
    }
    printf("%d\n%d\n%d\n", C, S, B);
    return 0;
}
