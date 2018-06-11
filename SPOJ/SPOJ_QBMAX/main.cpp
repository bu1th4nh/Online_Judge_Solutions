//Libraries and namespace
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

//=====================================
//Macros
#define task "QBMAX"
#define maxmn (int)(110)
#define maxf (int)(10e8+7)
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORk(x, y) for(int k=x; k<=y; ++k)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORlj(x, y) for(int j=x; j<y; ++j)
#define FORlk(x, y) for(int k=x; k<y; ++k)

//=====================================
//Typedef
int a[maxmn][maxmn];
int F[maxmn][maxmn];
int m, n, res;

//=====================================
//Functions and procedures
//Initialization
void FileInit()
{
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}
void IOSOpt()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void Init()
{
    memset(F, 0, sizeof(F));
    FORi(1, n)
    {
        F[m+1][i] = -maxf;
        F[0][i] = -maxf;
    }
    FORi(1, m) F[i][1] = a[i][1];
    res = -maxf;
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
            F[i][j] = 0;
        }
    }
}

//Process
void Process()
{
    FORj(2, n)
    {
        FORi(1, m)
        {
            F[i][j] = max(F[i-1][j-1], max(F[i][j-1], F[i+1][j-1]))+a[i][j];
        }
    }
    FORi(1, m) res = max(res, F[i][n]);
    cout << res;
}


int main()
{
    FileInit();
    Input();
    Init();
    Process();
    FileClose();
    return 0;
}
