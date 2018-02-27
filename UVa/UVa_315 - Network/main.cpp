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
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
int n, res, Time;
vi num, low;
vi CrNode;
vvi adj;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    string s = "FUCK";

    adj.clear();
    CrNode = vi(n+1, 0);
    num = vi(n+1, -1);
    low = vi(n+1, 0);
    adj = vvi(n+1);
    Time = 0;
    res = 0;

    while(getline(cin, s), s.compare("0") != 0)
    {
        stringstream ss(s);
        int u; ss >> u;
        int v;
        while(ss >> v)
        {
            adj[u].pb(v);
            adj[v].pb(u);
        }
    }
}

//DFS
void DFS(int u, int p)
{
    int numChild = 0;
    low[u] = num[u] = Time++;
    for(int v : adj[u])
    {
        if (num[v] == -1)
        {
            DFS(v, u);
            numChild++;

            if (low[v] >= num[u])
                CrNode[u] = (u == p) ? (numChild > 1) : 1;

            low[u] = min(low[u], low[v]);
        }
        else if (v != p)
            low[u] = min(low[u], num[v]);
    }
}

//Process
void Solve()
{
    FOR(i, 1, n) if(num[i] == -1) DFS(i, i);
    FOR(i, 1, n) res += CrNode[i];
    printf("%d\n", res);
}

//Output
void Multitest()
{
    while(cin >> n, n)
    {
        cin.ignore(1);
        if(n == 0) break;
        Enter();
        Solve();
    }
}

//Main Procedure
int main()
{
    //FILEOP();
    Multitest();
    return 0;
}
