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
typedef queue<int> qi;
bool adj[maxvalueinp][maxvalueinp];
bool avail[maxvalueinp];
int trace[maxvalueinp];
int src, dst;
int nTest;
vi prime, primeraw;
qi dir;

//=====================================
//Functions and procedures
//Input
void Input()
{
    scanf("%d%d", &src, &dst);
}

//Sieve
void Sieve()
{
    const int MaxPrime = 10000;
    static int LP[MaxPrime+1];
    FOR(i, 2, MaxPrime)
    {
        if(LP[i] == 0)
        {
            LP[i] = i;
            primeraw.push_back(i);
        }
        for(int j = 0; j<(int)(primeraw.size()) && primeraw[j]<=LP[i] && i*primeraw[j]<=MaxPrime; ++j)
        {
            LP[i*primeraw[j]] = primeraw[j];
        }
    }
    FORl(i, 0, siz(primeraw)) if(primeraw[i]>=1000 && primeraw[i]<10000) prime.push_back(primeraw[i]);
}

//Check
bool Check(int x, int y)
{
    int diff = 0;
    while(x!=0)
    {
        int tmp1 = x%10;
        int tmp2 = y%10;
        if(tmp1 != tmp2) ++diff;
        x = x/10;
        y = y/10;
    }
    if(diff==1) return true;
    else return false;
}

//Output
void PrintPath(int x, int y)
{
    if(trace[y]==-1) printf("0 \n");
    else
    {
        int cnt = 0;
        while(x!=y)
        {
            ++cnt;
            y = trace[y];
        }
        if(cnt!=0) printf("%d\n", cnt);
    }
}

void PrintFullPath(int x, int y)
{
    if(trace[y]==-1) printf(" ");
    else while(x!=y)
    {
        cout << y << "<-";
        y = trace[y];
    }
}

//Process
void BFS(int x, int y)
{
    MEMS(avail, true);
    MEMS(trace, -1);
    avail[x] = false;
    dir.push(x);
    while(!dir.empty())
    {
        int u = dir.front();
        dir.pop();
        FORl(v, 0, siz(prime))
        {
            int next = prime[v];
            if(Check(u, next) && avail[next])
            {
                avail[next] = false;
                trace[next] = u;
                dir.push(next);
            }
            //if(next == y) return;
        }
    }
    PrintPath(x, y);
}

//Multi-test
void Multitest()
{
    Input();
    BFS(src, dst);
}

//Main Procedure
int main()
{
    Sieve();
    scanf("%d", &nTest);
    while(nTest--)
    {
        Multitest();
    }
    return 0;
}
