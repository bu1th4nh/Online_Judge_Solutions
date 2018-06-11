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
#define pb push_back
#define maxinp (int)(16384)
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
typedef queue<int> qi;
typedef long long ll;
bool avail[maxinp];
int CComp[maxinp];
vi adj[maxinp];
int n, m, cnt;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	 int x, y;
	 MEMS(CComp, 0);
	 MEMS(avail, true);
	 scanf("%d%d", &n, &m);
	 FOR(i, 2, n)
	 {
	     scanf("%d%d", &x, &y);
	     if(y == 1)
         {
             adj[i].pb(x);
             adj[x].pb(i);
         }
	 }
}

//BFS
void BFS(int start)
{
    qi que;
    que.push(start);
    avail[start] = false;
    CComp[start] = cnt;

    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        for(int v: adj[u])
        {
            if(avail[v])
            {
                que.push(v);
                avail[v] = false;
                CComp[v] = cnt;
            }
        }
    }
}


//Process
void Solve()
{
    cnt = 0;
    FOR(i, 1, n)
    {
        if(avail[i])
        {
            ++cnt;
            BFS(i);
        }
    }
    FOR(i, 1, m)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if(CComp[x] == CComp[y]) printf("NO\n");
        else printf("YES\n");
    }
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
