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
typedef pair<double, int> di;
typedef pair<int, int> ii;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vd> vvd;
typedef vector<vii> vvii;
typedef vector<vdi> vvdi;
typedef long long ll;
const double EPS = 1e-6;
double m;
int n, w;
vvb rem;
vd dist;
vi x, y;
vvd d;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%d%d%lf", &n, &w, &m);

    int u, v;

    dist = vd(n);
    x = y = vi(n);
    d = vvd(n, vd(n));
    rem = vvb(n, vb(n));

    FORl(i, 0, n) scanf("%d%d", &x[i], &y[i]);
    FORl(i, 0, w)
    {
        scanf("%d%d", &u, &v); --u, --v;
        rem[u][v] = rem[v][u] = 1;
    }
}

//Process
double sqr(const double &x) {return x*x;}

void Solve()
{
    FORl(i, 0, n)
    {
        d[i][i] = 1000000000;
        FORl(j, i+1, n)
        {
            if(!rem[i][j])
            {
                double v = sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]));
                d[i][j] = d[j][i] = v + EPS < m ? v : 1000000000;
            }
        }
        dist[i] = 1000000000;
    }

    priority_queue<di, vdi, greater<di>> q;
    q.push(di(0, 0)); dist[0] = 0;
    while(!q.empty())
    {
        double du = q.top().first; int u = q.top().second; q.pop();
        if(du > dist[u] + EPS) continue;
        FORl(v, 0, n)
        {
            if(dist[v] > du + d[u][v] + EPS)
            {
                q.push(di(dist[v] = du + d[u][v], v));
            }
        }
    }
    printf("%d\n", dist[n-1] >= 1000000000 ? -1 : int(dist[n-1] * 1000));
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
