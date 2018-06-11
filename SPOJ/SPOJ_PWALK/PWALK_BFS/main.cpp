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
#define maxvalueinp (int)(1010)
#define MODUL (int)(10e9+57)
#define len0(x) (int)(x.length())
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
int len[maxvalueinp][maxvalueinp];
bool avail[maxvalueinp];
int trace[maxvalueinp];
vi adj[maxvalueinp];
int n, query;


//=====================================
//Functions and procedures
//Input
void Input()
{
    MEMS(len, 0);
    MEMS(trace, 0);
    MEMS(avail, true);
    scanf("%d%d", &n, &query);
    FORl(i, 1, n)
    {
        int a, b, l;
        scanf("%d%d%d", &a, &b, &l);
        adj[a].push_back(b);
        adj[b].push_back(a);
        len[a][b] = len[b][a] = l;
    }
}

//Breath-first search
void BFS(int st, int fi)
{
    queue<int> vertex;
    vertex.push(st);
    while(!vertex.empty())
    {
        int u = vertex.front();
        vertex.pop();
        FORl(i, 0, siz(adj[u]))
        {
            int v = adj[u][i];
            if(avail[v])
            {
                vertex.push(v);
                avail[v] = false;
                trace[v] = u;
            }
            if(v==fi) return;
        }
    }

}

//Process
void Multitest()
{
    MEMS(trace, 0);
    MEMS(avail, true);
    int src, dst, res;
    res = 0;
    scanf("%d%d", &src, &dst);
    BFS(src, dst);
    while(src!=dst)
    {
        res += len[dst][trace[dst]];
        dst = trace[dst];
    }
    printf("%d\n", res);
}


//Main Procedure
int main()
{
    Input();
    while(query--)
    {
        Multitest();
    }
    return 0;
}
