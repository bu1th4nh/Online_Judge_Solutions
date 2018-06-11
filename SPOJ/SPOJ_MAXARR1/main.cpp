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
#define task "MAXARR1"
#define maxmn (int)(1e5+10)
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORk(x, y) for(int k=x; k<=y; ++k)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORlj(x, y) for(int j=x; j<y; ++j)
#define FORlk(x, y) for(int k=x; k<y; ++k)

//=====================================
//Typedef
int T, MaxN;
int N[maxmn];
int A[maxmn];
int F[maxmn];

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
    memset(F, -INFINITY, sizeof(F));
    A[0] = 0;
    A[1] = 1;
    F[0] = 0;
    F[1] = A[1];
}

//Input
void Input()
{
    MaxN = -INFINITY;
    cin >> T;
    FORk(1, T)
    {
        cin >> N[k];
        MaxN = max(MaxN, N[k]);
    }
}

//Process
void SeqInit()
{
    FORi(1, (int)(MaxN/2))
    {
        A[2*i] = A[i];
        A[2*i+1] = A[i] + A[i+1];
    }
    FORi(2, MaxN)
    {
        F[i] = max(F[i-1], A[i]);
    }
}
void Process()
{
    FORi(1, T)
    {
        cout << F[N[i]] << endl;
    }
}


int main()
{
    FileInit();
    Input();
    Init();
    SeqInit();
    Process();
    FileClose();
    return 0;
}
