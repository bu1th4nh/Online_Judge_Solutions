//Libraries and namespace
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

//=====================================
//Macros
#define task "QBSTR"
#define maxmn (int)(11000)
#define maxf (int)(10e8+7)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORk(x, y) for(int k=x; k<=y; ++k)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORlj(x, y) for(int j=x; j<y; ++j)
#define FORlk(x, y) for(int k=x; k<y; ++k)

//=====================================
//Typedef
string s1, s2;
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
    MEMS(F, 0);
}

//Input
void Input()
{
    getline(cin, s1);
    getline(cin, s2);
    n = s1.length();
    m = s2.length();
}

//Process
void Process()
{
    FORli(0, m)
    {
        FORlj(0, n)
        {
            F[i][j] = (s1[i] == s2[j]) ? F[i-1][j-1]+1 : max(F[i-1][j], F[i][j-1]);
        }
    }
    cout << F[m-1][n-1];
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
