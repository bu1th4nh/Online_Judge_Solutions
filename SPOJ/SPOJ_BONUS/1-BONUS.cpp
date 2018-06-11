//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task "BONUS"
#define maxvalueinp (int)(1010)
#define MODUL (int)(10e9+57)
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
int n, k;
int a[maxvalueinp][maxvalueinp];
int res;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP(task)
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}
void IOSTROpt()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

//Main Procedure
int main()
{
    FileInit();
    res = -INFINITY;
    MEMS(a, 0);
    scanf("%d%d", &n, &k);
    FOR(i, 1, n)
    {
        FOR(j, 1, n)
        {
            scanf("%d", &a[i][j]);
            a[i][j] += a[i][j-1] + a[i-1][j] - a[i-1][j-1];
        }
    }
    FOR(i, k, n)
    {
        FOR(j, k, n)
        {
            int tmp = a[i][j] - a[i-k][j] - a[i][j-k] + a[i-k][j-k];
            res = max(res, tmp);
        }
    }
    printf("%d", res);
    return 0;
}
