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
typedef long long ll;
int n, res1, DFSCnt;
vi low, num, par;
vb avail;
vii res2;
vvi adj;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v, nLink;
    char t;

    avail = vb(n+1, true);
    num = vi(n+1, -1);
    par = vi(n+1, -1);
    low = vi(n+1, 0);
    adj = vvi(n+1);
    res2.clear();

    DFSCnt = 0;
    res1 = 0;
    n--;

    FOR(i, 0, n)
    {
        scanf("%d", &u);
        cin >> t >> nLink >> t;
        FOR(i, 1, nLink)
        {
            scanf("%d", &v);
            adj[u].pb(v);
        }
    }
}

//DFS
void DFS(int u, int p)
{
    low[u] = num[u] = DFSCnt++;
    for(int v: adj[u])
    {
        if(num[v] == -1)
        {
            DFS(v, u);

            if(low[v] > num[u])
            {
                res2.push_back(ii(min(u, v), max(u, v)));
                ++res1;
            }

            low[u] = min(low[u], low[v]);
        }
        else if(v != p)
        {
            low[u] = min(low[u], num[v]);
        }
    }
}

//Process
void Solve()
{
    if(n == 0)
    {
        printf("0 critical links\n");
        return;
    }

    FOR(_x, 0, n) if(num[_x] == -1)
    {
        DFS(_x, _x);
    }

    printf("%d critical links\n", res1);

    sort(whole(res2));

    for(ii edge: res2)
    {
        printf("%d - %d\n", edge.first, edge.second);
    }
}


//Output
void Multitest()
{
    while(scanf("%d", &n) != EOF)
    {
        Enter();
        Solve();
        puts("");
    }
}

//Main Procedure
int main()
{
    //FILEOP();
    Multitest();
    return 0;
}
