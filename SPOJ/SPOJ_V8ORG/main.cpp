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
#define maxvalueinp (int)(10010)
#define MODUL (int)(10e9+57)
#define len(x) (int)(x.length())
#define siz(x) (int)(x.size())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
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
bool avail[maxvalueinp];
vi adj[maxvalueinp];
int F[maxvalueinp];
int n, k, res;


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
    scanf("%d%d", &k, &n);
    FORl(i, 1, n)
    {
        int x;
        scanf("%d", &x);
        adj[x].pb(i+1);
        adj[i+1].pb(x);
    }
    MEMS(avail, true);
    MEMS(F, 1);
}

//DFS
int DFS(int u)
{
    int tmp = 1;
    avail[u] = false;
    FORl(i, 0, siz(adj[u]))
    {
        int t = adj[u][i];
        if(avail[t])
        {
            tmp += DFS(t);
        }
    }
    if(tmp>=k)
    {
        ++res;
        tmp = 0;
    }
    return tmp;
}

//Process
void Process()
{
    res = 0;
    DFS(1);
    printf("%d", res);
}


//Main Procedure
int main()
{
    Input();
    Process();
    return 0;
}
