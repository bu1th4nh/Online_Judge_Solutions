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
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;
int nextx[] = {0, 0, 1, 1, -1, -1};
int nexty[] = {1, -1, 1, 0, 0, -1};
ll F[15][40][40];
int nTest, x;

//=====================================
//Functions and procedures
int main()
{
    F[0][20][20] = 1;
    FOR(i, 1, 14)
    {
        FOR(j, 1, 38)
        {
            FOR(k, 1, 38)
            {
                FOR(m, 0, 5) F[i][j][k] += F[i-1][j + nextx[m]][k + nexty[m]];
            }
        }
    }
    scanf("%d", &nTest);
    while(nTest--)
    {
        scanf("%d", &x);
        printf("%I64d\n", F[x][20][20]);
    }
    return 0;
}
