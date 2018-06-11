//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
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
int a[maxvalueinp][maxvalueinp];
int F[maxvalueinp][maxvalueinp];
int m, n;
int res;

//=====================================
//Functions and procedures
//Input
void Input()
{
    cin >> m >> n;
    for(int i=1; i<=m; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            cin >> a[i][j];
        }
    }
    //cout << "Input done!" << endl;
}

//Check
bool Check(int x, int y)
{
    return (a[x][y] == a[x-1][y]) && (a[x][y] == a[x][y-1]) && (a[x][y] == a[x-1][y-1]);
}

//Process
void Process()
{
    res = -INFINITY;
    //MEMS(F, 0);
    FOR(i, 1, n+1) F[1][i] = 1;
    FOR(i, 1, m+1) F[i][1] = 1;
    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            if(Check(i, j)) F[i][j] = min(min(F[i-1][j], F[i][j-1]), F[i-1][j-1])+1;
            else F[i][j] = 1;
        }
    }
    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            res = max(res, F[i][j]);
        }
    }
    printf("%d", res);
}



//Main Procedure
int main()
{
    Input();
    Process();
    return 0;
}
