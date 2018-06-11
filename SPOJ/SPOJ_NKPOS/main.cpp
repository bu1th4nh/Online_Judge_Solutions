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
#include <list>
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
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef stack<int> si;
typedef list<int> li;
typedef long long ll;
vb avail;
int n, m;
vvi adj;
vi res;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v;
    scanf("%d%d", &n, &m);

    avail = vb(n+1, true);
    adj = vvi(n+1, vi(n+1, 0));
    res.clear();

    FOR(i, 1, n) scanf("%d", &u);

    FOR(i, 1, m)
    {
        scanf("%d%d", &u, &v);
        adj[u][v]++ ,adj[v][u]++;
    }
}

//Check
void EulerTour()
{
    si s;
    s.push(1);
    while(!s.empty())
    {
        int u = s.top();
        bool f = 1;
        FOR(v, 1, n)
        {
            if(adj[u][v])
            {
                s.push(v);
                adj[u][v]-- ,adj[v][u]--;
                f = 0;
                break;
            }
        }
        if(f)
        {
            res.push_back(u);
            s.pop();
        }
    }
}


//Process
void Solve()
{
    printf("%d\n", m);
    EulerTour();
    for(int itr: res) printf("%d ", itr);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
