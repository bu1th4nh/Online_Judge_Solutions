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
#define maxvalueinp (int)(10e3+10)
#define MODUL (int)(10e9+57)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORbi(x, y) for(int i=x; i>=y; --i)
#define FORlbi(x, y) for(int i=x; i>y; --i)
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef

typedef stack<int> si;
typedef vector<int> vi;
int a[maxvalueinp][maxvalueinp];
int Heigh[maxvalueinp], Left[maxvalueinp] , Right[maxvalueinp];
int m, n;
int res;
si stck;


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
    cin >> m >> n;
    FORi(1, m)
    {
        FORj(1, n)
        {
            cin >> a[i][j];
        }
    }
}


//Process
void Process()
{
    res = -INFINITY;
    Heigh[0] = -1;
    Heigh[n+1] = -1;
    FORj(1, m)
    {
        FORi(1, n)
        {
            Heigh[i] = a[j][i]*(Heigh[i]+1);
        }
        FORi(1, n)
        {
            Left[i] = i;
            while(Heigh[Left[i]-1]>=Heigh[i]) Left[i] = Left[Left[i]-1];
        }
        FORbi(n, 1)
        {
            Right[i] = i;
            while(Heigh[Right[i]+1]>=Heigh[i]) Right[i] = Right[Right[i]+1];
        }
        FORi(1, n) res = max(res, Heigh[i]*(Right[i] - Left[i] + 1));
    }
    cout << res;
}

//Main Procedure
int main()
{
    Input();
    Process();
    return 0;
}
