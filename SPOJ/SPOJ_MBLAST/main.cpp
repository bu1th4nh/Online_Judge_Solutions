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
#define maxvalueinp (int)(2048)
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
int F[maxvalueinp][maxvalueinp];
string a, b;
int m, n, k;


//=====================================
//Functions and procedures
//Enter
void Enter()
{
    cin >> a >> b >> k;
    n = a.length();
    m = b.length();
    a = '0' + a;
    b = '0' + b;
}

//Process
int ToInt(char t) {return static_cast<int> (t);}
void Solve()
{
    FOR(i, 0, n) F[i][0] = k*i;
    FOR(i, 0, m) F[0][i] = k*i;
    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            F[i][j] = min( min(F[i-1][j] + k, F[i][j-1] + k) , F[i-1][j-1] + abs( ToInt(a[i]) - ToInt(b[j]) ) );
        }
    }
    printf("%d", F[n][m]);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
