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
#define maxinp (int)()
#define MODUL (int)(1e9+7)
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
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef long long ll;
vi deg, res, f;
int m, n, d;
vvb adj;
vvi a;


//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%d%d", &n, &m);

    int u, v, c;
    adj = vvb(n+1, vb(n+1, false));
    f = res = vi((n+1)*(n+1));
    a = vvi(n+1, vi(n+1));
    deg = vi(n+1);

    FORl(i, 0, m)
    {
        scanf("%d%d%d", &u, &v, &c);
        adj[u][v] = adj[v][u] = true;
        a[u][v] = a[v][u] = c, ++deg[u], ++deg[v];
    }
}

//Check
bool IsValid(int pos)
{
    int sum = 0;

    if(d != m+1) return false;
    FOR(i, 1, n)
    {
        if(deg[i]&1) return false;
    }
    FORl(i, pos, d)
    {
        sum += a[res[i]][res[i+1]];
        if(sum < 0) return false;
    }
    FORl(i, 1, pos)
    {
        sum += a[res[i]][res[i+1]];
        if(sum < 0) return false;
    }
    return true;
}

//Process
void Solve()
{
    stack<int> s;
    s.push(1);
    while(!s.empty())
    {
        int u = s.top();
        FOR(v, 1, n)
        {
            if(adj[u][v])
            {
                adj[u][v] = adj[v][u] = false;
                s.push(v); break;
            }
        }
        if(u == s.top())
        {
            res[++d] = u, s.pop();
        }
    }

    int low = MODUL; int start;
    f[1] = 0;
    FOR(i, 2, d)
    {
        f[i] = f[i-1] + a[res[i]][res[i-1]];
        if(f[i] < low) low = f[i], start = i;
    }
    if(!IsValid(start)) printf("-1");
    else
    {
        FOR(i, start, d) printf("%d ", res[i]);
        FOR(i, 2, start) printf("%d ", res[i]);
    }
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
