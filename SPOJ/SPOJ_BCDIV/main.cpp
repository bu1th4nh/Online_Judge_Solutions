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
#define maxvalueinp (int)()
#define MODUL (int)(10e9+57)
#define whole(x) x.begin(), x.end()
#define FORi(x, y) for(ull i=x; i<=y; ++i)
#define FORj(x, y) for(ull j=x; j<=y; ++j)
#define FORk(x, y) for(ull k=x; k<=y; ++k)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORbi(x, y) for(int i=x; i>=y; --i)
#define FORlbi(x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef unsigned long long ull;
ull n, kk, TEST;
ull F[30][30];



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

//Process
void PreProcess()
{
    MEMS(F, 0);
    F[0][0] = 1;
    FORi(1, 25)
    {
        FORj(1, 25)
        {
            F[i][j] = F[i-1][j-1] + F[i-1][j]*j;
        }
    }
}
void MiniTest()
{
    cin >> n >> kk;
    cout << F[n][kk] << endl;
    //n = k = 0;
}


//Multi-test
void Multitest()
{
    cin >> TEST;
    FORk(1, TEST)
    {
        MiniTest();
    }
}

//Main Procedure
int main()
{
    PreProcess();
    Multitest();
    return 0;
}
