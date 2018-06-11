//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define fi first
#define se second
#define maxinp (int)(2020)
#define MODUL (int)(1e9+57)
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef queue<ii> qii;
typedef long long ll;
const int base = 1010;
bool InQueue[maxinp][maxinp];
bool FreeR[maxinp];
bool FreeC[maxinp];
int minR[maxinp];
int minC[maxinp];
int maxR[maxinp];
int maxC[maxinp];
int n, res;
qii dir;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v;
	MEMS(InQueue, true);
    MEMS(FreeC, true);
    MEMS(FreeR, true);
	scanf("%d", &n);
	FOR(i, 1, n)
	{
	    scanf("%d%d", &u, &v);
	    u+=base;
	    v+=base;
	    if(InQueue[u][v])
        {
            InQueue[u][v] = false;
            dir.push(ii(u, v));
        }
	}
}

//Process
void Solve()
{
    res = 0;
    while(!dir.empty())
    {
        ++res;
        int u = dir.front().fi;
        int v = dir.front().se;
        dir.pop();
        if(FreeR[u])
        {
            FreeR[u] = false;
            minR[u] = v;
            maxR[u] = v;
        }
        else
        {
            if(v<minR[u])
            {
                FOR(i, v+1, minR[u]-1)
                {
                    if(InQueue[u][i])
                    {
                        InQueue[u][i] = false;
                        dir.push(ii(u, i));
                    }
                }
                minR[u] = v;
            }
            if(v>maxR[u])
            {
                FOR(i, maxR[u]+1, v-1)
                {
                    if(InQueue[u][i])
                    {
                        InQueue[u][i] = false;
                        dir.push(ii(u, i));
                    }
                }
                maxR[u] = v;
            }
        }
        if(FreeC[v])
        {
            FreeC[v] = false;
            minC[v] = u;
            maxC[v] = u;
        }
        else
        {
            if(u<minC[v])
            {
                FOR(i, u+1, minC[v]-1)
                {
                    if(InQueue[i][v])
                    {
                        InQueue[i][v] = false;
                        dir.push(ii(i, v));
                    }
                }
                minC[v] = u;
            }
            if(u>maxC[v])
            {
                FOR(i, maxC[v]+1, u-1)
                {
                    if(InQueue[i][v])
                    {
                        InQueue[i][v] = false;
                        dir.push(ii(i, v));
                    }
                }
                maxC[v] = u;
            }
        }
    }
    printf("%d", res);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
