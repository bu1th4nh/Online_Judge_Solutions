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
#define task "test"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define MODUL (int)(1e9+57)
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}

//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef queue<int> qi;
typedef long long ll;
int n, nQuery, res1, res2;
vi d, boom;
vb avail;
vvi adj;


//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int m, v;
    scanf("%d", &n);

    adj = vvi(n+1);

    FORl(i, 0, n)
    {
        scanf("%d", &m);
        FOR(j, 1, m)
        {
            scanf("%d", &v);
            adj[i].pb(v);
        }
    }

    scanf("%d", &nQuery);
}

//BFS
void BFS(int start)
{
    int u;
    qi que;

    avail = vb(n+1, true);
    boom = vi(2560, 0);
    d = vi(n+1, 0);
    res1 = 0;
    res2 = 0;

    avail[start] = false;
    d[start] = 1;
    que.push(start);

    while(!que.empty())
    {
        u = que.front();
        que.pop();
        for(int v: adj[u])
        {
            if(avail[v])
            {
                que.push(v);
                avail[v] = false;
                d[v] = d[u] + 1;
                boom[d[u]]++;
            }
        }
        if(boom[d[u]] > res1)
        {
            res1 = boom[d[u]];
            res2 = d[u];
        }
    }
}


//Process
void Solve()
{
    while(nQuery--)
    {
        int st;
        scanf("%d", &st);
        BFS(st);
        if(res1 == 0)
        {
            printf("0\n");
        }
        else
        {
            printf("%d %d\n", res1, res2);
        }
    }
}

//Main Procedure
int main()
{
    //FILEOP();

    Enter();
    Solve();
    return 0;
}
