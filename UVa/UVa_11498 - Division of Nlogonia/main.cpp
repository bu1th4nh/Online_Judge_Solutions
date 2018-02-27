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
int n;

//=====================================
//Functions and procedures
int main()
{
    int x, y, u, v;
    n = 2017;

    while(n != 0)
    {
        scanf("%d", &n); if(n == 0) break;

        scanf("%d%d", &x, &y);
        FOR(i, 1, n)
        {
            scanf("%d%d", &u, &v);

            if(u == x || v == y) printf("divisa\n");
            else if(u > x && v > y) printf("NE\n");
            else if(u > x && v < y) printf("SE\n");
            else if(u < x && v > y) printf("NO\n");
            else if(u < x && v < y) printf("SO\n");

        }
    }

    return 0;
}
