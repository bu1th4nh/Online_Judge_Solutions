//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp (int)(5e5+20)
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
typedef vector<int> vi;
int F[maxvalueinp];
int G[maxvalueinp];
int T[maxvalueinp];
int res1, res2;
int n, h;
vi A, B;

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
    scanf("%d%d", &n, &h);
    FOR(i, 1, n)
    {
        if(i&1)
        {
            int x;
            scanf("%d", &x);
            A.push_back(x);
        }
        else
        {
            int x;
            scanf("%d", &x);
            B.push_back(x);
        }
    }
}

//Process
void Process()
{
    MEMS(F, 0);
    MEMS(G, 0);


    FORl(i, 0, siz(A)) ++F[A[i]];
    FORl(i, 0, siz(B)) ++G[B[i]];



    FORb(i, h-1, 1) F[i] += F[i+1];
    FORb(i, h-1, 1) G[i] += G[i+1];


    res2 = 1;
    res1 = F[1]+G[h-1+1];
    FOR(i, 2, h)
    {
        int tmp = F[i]+G[h-i+1];
        if(tmp==res1) ++res2;
        else if(tmp<res1)
        {
            res1 = tmp;
            res2 = 1;
        }
    }

    printf("%d %d", res1, res2);
}
//Main Procedure
int main()
{
    Input();
    Process();
    return 0;
}
