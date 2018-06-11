/*==============================================================================================================*\
**                                  _           _ _   _     _  _         _                                      **
**                                 | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   **
**                                 | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  **
**                                 | |_) | |_| | | |_| | | |__   _| | | | | | |                                 **
**                                 |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 **
\*==============================================================================================================*/
//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
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
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}

const int maxc = 16777216;
//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vi fx, fy, bx, by, x, y;
vvi a;
int n;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%d", &n);
    a = vvi(n+1, vi(n+1, maxc));
    fx = fy = bx = by = x = y = vi(n+1, 0);
    int u, v, c = maxc;

    while(true)
    {
        c = maxc;
        scanf("%d%d%d", &u, &v, &c);
        if(c == maxc) break;
        a[u][v] = c;
    }
}

///Hungarian Algorithm
void Update(int v)      //Update the augmenting path
{
    int u, k;
    while(v > 0)
    {
        u = by[v];
        k = x[u];
        x[u] = v;
        y[v] = u;
        v = k;
    }
}
bool BFS(int i)         //Find the augmenting path
{
    queue<int> q;

    bx.assign(n+1, 0);
    by.assign(n+1, 0);
    q.push(i);
    bx[i] = 1;

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        FOR(v, 1, n) if(by[v] == 0 && fx[u] + a[u][v] - fy[v] == 0)
        {
            by[v] = u;
            if(y[v] == 0)
            {
                Update(v);
                return true;                //Augmenting Path Found!
            }
            q.push(y[v]);
            bx[y[v]] = 1;
        }
    }

    return false;                           //Can't find Augmenting Path!
}
void Modify()           //Modify the graph - Kuhn-Munkres Method
{
    int delta = maxc;
    FOR(i, 1, n) if(bx[i] == 1)
    {
        FOR(j, 1, n) if(by[j] == 0)
        {
            if(delta > fx[i] + a[i][j] - fy[j])
            {
                delta = fx[i] + a[i][j] - fy[j];
            }
        }
    }
    FOR(i, 1, n) if(!bx[i]) fx[i] += delta;
    FOR(i, 1, n) if(!by[i]) fy[i] += delta;
}
void HUNGARIAN()       //Core algorithm
{
    FOR(i, 1, n)
    {
        while(!BFS(i)) Modify();
    }
}

//Process
void Solve()
{
    int res = 0;
    HUNGARIAN();
    FOR(i, 1, n) res += a[i][x[i]];
    printf("%d\n", res);
    FOR(i, 1, n) printf("%d %d\n", i, x[i]);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
