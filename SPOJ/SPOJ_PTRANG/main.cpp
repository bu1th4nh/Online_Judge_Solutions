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
#define task "PTRANG"
#define maxmn (int)(6e3+10)
#define maxf (int)(10e8)
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORk(x, y) for(int k=x; k<=y; ++k)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORlj(x, y) for(int j=x; j<y; ++j)
#define FORlk(x, y) for(int k=x; k<y; ++k)

//=====================================
//Typedef
int F[maxmn];
int n, L;
int W[maxmn];
int S[maxmn];


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
    memset(F, sizeof(int), sizeof(F));
    memset(S, 0, sizeof(S));
}

//Input
void Input()
{
    W[0] = 0;
    S[0] = 0;
    cin >> n >> L;
    //FORi(1, n+1) S[i] = 0;
    FORi(1, n)
    {
        cin >> W[i];
        //S[i] = S[i-1] + W[i];
    }
    FORi(1, n+1) F[i] = sizeof(int);
}

//Process
void Process()
{
    for(int i=1;i<=n;i++)
    {
        int s=L-W[i];
        F[i]=maxf;
        for(int j=i-1;j>=0;j--)
        {
            if(s>=0)
            {
                int heso=max(F[j],s);
                F[i]=min(F[i],heso);
            }
            else break;
            s-=W[j];
        }
    }
    cout<<F[n];

}

int main()
{
    FileInit();
    //Init();
    Input();
    Process();
    FileClose();
    return 0;
}
