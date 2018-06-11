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
#define maxvalueinp (int)(1010)
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
int F[4][53];
int SumFuckingAll;
int n, k;
int res;
vi a;


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
    SumFuckingAll = 0;
    scanf("%d%d", &n, &k);
    a.push_back(-999999999);
    FORi(1, n)
    {
        int x;
        scanf("%d", &x);
        SumFuckingAll += x;
        x%=k;
        a.push_back(x);
    }
}

//Process
int SubMod(int x, int y)
{
    int tmp = (x-y);
    return (tmp>=0) ? tmp : (tmp+k);
}
void Process()
{
    int x=0, y=1;
    FORi(1, k-1) F[0][i] = -MODUL;
    F[0][0] = 0;
    FORi(1, n)
    {
        FORj(0, k-1)
        {
            F[y][j] = max(F[x][j], F[x][SubMod(j, a[i])] + 1);
        }
        x=1-x;
        y=1-y;
    }
    res = F[x][0];
    printf("%d", res);
}


//Output





//Main Procedure
int main()
{
    Input();
    Process();
    return 0;
}
