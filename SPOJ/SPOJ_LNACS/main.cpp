//Libraries and namespaces
//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <iostream>
#include <fstream>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp (int)(10000+10)
#define MODUL (int)(10e9+57)
#define whole(x) x.begin(), x.end()
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORbi(x, y) for(int i=x; i>=y; --i)
#define FORlbi(x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef vector<int> vi;
int F[maxvalueinp][maxvalueinp];
int res;
int a[maxvalueinp], b[maxvalueinp];
int m, n;

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

//Input
void Input()
{
    scanf("%d%d", &m, &n);
    FORi(1, m)
    {
        scanf("%d", &a[i]);
    }
    FORi(1, n)
    {
        scanf("%d", &b[i]);
    }
}

//Preparation
void Prep()
{
    MEMS(F, 0);
    FORi(1, n) F[1][i] = (a[1]==b[i]) ? 1 : F[1][i-1];
    FORi(1, m) F[i][1] = (a[i]==b[1]) ? 1 : F[i-1][1];
}

//Process
void Process()
{
    FORi(2, m)
    {
        FORj(2, n)
        {
            F[i][j] = (a[i]==b[j]) ? F[i-2][j-2] + 1 : max(max(F[i-1][j], F[i][j-1]), F[i-1][j-1]);
        }
    }
    cout << F[m][n];
}

//Main Procedure
int main()
{
    Input();
    Process();
    return 0;
}
