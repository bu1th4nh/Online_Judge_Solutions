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
#define maxvalueinp (int)(10010)
#define MODUL (int)(10e9+57)
#define len(x) (int)(x.length())
#define siz(x) (int)(x.size())
#define whole(x) x.begin(), x.end()
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORk(x, y) for(int k=x; k<=y; ++k)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORbi(x, y) for(int i=x; i>=y; --i)
#define FORlbi(x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
int x[maxvalueinp], y[maxvalueinp], F[maxvalueinp][maxvalueinp];
int n;

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
    scanf("%d", &n);
    FORi(1, n)
    {
        scanf("%d%d", &x[i], &y[i]);
    }
    F[0][0] = 0;
    F[1][1] = y[1];
    FORi(2, n)
    {
        F[i][0] = F[i-1][1] + x[i];
        F[i][i] = F[i-1][i-1] + y[i];
        FORj(1, i-1)
        {
            F[i][j] = min(F[i-1][j-1] + y[i], F[i-1][j+1] + x[i]);
        }
    }
    cout << F[n][0];
    return 0;
}
