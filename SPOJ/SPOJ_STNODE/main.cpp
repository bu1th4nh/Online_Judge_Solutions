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
typedef vector<vi> vvi;
typedef queue<int> qi;
typedef long long ll;
bool avail[maxinp];
int trace[maxinp];
int pos[maxinp];
vi adj[maxinp];
int m, n, s, t;
int res;
vi path;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    MEMS(avail, true);
    MEMS(trace, -1);
    MEMS(pos, -1);

    int x, y;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    FOR(i, 1, m)
    {
        scanf("%d%d", &x, &y);
        adj[x].pb(y);
    }
}

//Check
void FindPath(int st, int fi)
{
    path.push_back(-1);
    qi que;
    que.push(st);
    trace[st] = st;
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        for(int v: adj[u])
        {
            if(trace[v] < 0)
            {
                que.push(v);
                trace[v] = u;
            }
        }
    }

    int u = fi;
    while(u != st)
    {
        path.push_back(u);
        u = trace[u];
    }
    path.push_back(st);
    for(int i = 1, j = (path.size()-1); i<j; ++i, --j) swap(path[i], path[j]);
}
int BFS(int st)
{
    qi que;
    int r = -1;
    que.push(st);
    avail[st] = false;
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        for(int v: adj[u])
        {
            if(avail[v] && pos[v]<0)
            {
                que.push(v);
                avail[v] = false;
            }
            else
            {
                r = max(r, pos[v]);
            }
        }
    }
    return r;
}


//Process
void Solve()
{
    res = 0;
    int r = -1;
    FindPath(s, t);
    FOR(i, 1, (path.size()-1)) pos[path[i]] = i;
    FOR(i, 1, (path.size()-1))
    {
        int u = path[i];
        if(u != s && u != t && r <= pos[u]) ++res;
        r = max(r, BFS(u));
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
