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
#include <tuple>
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


const int nextx[4] = {1, 0, -1, 0};
const int nexty[4] = {0, 1, 0, -1};
//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vc> vvc;
typedef vector<vii> vvii;
typedef stack<ii> sii;
vi TopoOrder, IdOrder, F, sumComponent;
int n, m, nSCC, nTime, TopoTime;
vvi num, low, adj, idComponent;
vb avail;
vvc a;
sii s;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	scanf("%d%d", &m, &n);

	num = low = idComponent = vvi(m+1, vi(n+1, 0));
	a = vvc(m+2, vc(n+2, '?'));

	nTime = nSCC = 0;

	FOR(i, 1, m)
	{
	    FOR(j, 1, n)
	    {
	        cin >> a[i][j];
	    }
	}
}

//Check
void GetSCC(ii cur)
{
    ii r;

    s.push(cur);
    num[cur.first][cur.second] = low[cur.first][cur.second] = ++nTime;

    FOR(i, 0, 3)
    {

        if(i > 1)
        {
            if(a[cur.first][cur.second] != 'W' && a[cur.first][cur.second] != 'N') break;
            if(a[cur.first][cur.second] == 'W' && i == 2) continue;
            if(a[cur.first][cur.second] == 'N' && i == 3) continue;
        }


        int x = (cur.first + nextx[i]);
        int y = (cur.second + nexty[i]);


        if(a[x][y] != '?' && a[x][y] != '#' && idComponent[x][y] == 0)
        {
            if(num[x][y] != 0) low[cur.first][cur.second] = min(num[x][y], low[cur.first][cur.second]);
            else
            {
                GetSCC(ii(x, y));
                low[cur.first][cur.second] = min(low[x][y], low[cur.first][cur.second]);
            }
        }

    }

    if(num[cur.first][cur.second] == low[cur.first][cur.second])
    {
        ++nSCC;
        int sum = 0;
        do
        {
            r = s.top(); s.pop();
            idComponent[r.first][r.second] = nSCC;
            if(a[r.first][r.second] >= '0' && a[r.first][r.second] <= '9') sum += (a[r.first][r.second] - '0');
        }
        while(r != cur);
        sumComponent.push_back(sum);
    }
}
void GetGraph()
{
    sumComponent.push_back(-1);

    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            if(num[i][j] == 0 && a[i][j] != '#') GetSCC(ii(i, j));
        }
    }

    TopoOrder = IdOrder = F = vi(nSCC+1);
    avail = vb(nSCC+1, true);
    adj = vvi(nSCC+1);

    TopoTime = nSCC;

    FOR(i, 1, m) FOR(j, 1, n)
    {
        if(a[i][j] != '#')
        {
            FOR(k, 0, 3)
            {

                if(k > 1)
                {
                    if(a[i][j] != 'W' && a[i][j] != 'N') break;
                    if(a[i][j] == 'W' && k == 2) continue;
                    if(a[i][j] == 'N' && k == 3) continue;
                }

                int x = i + nextx[k];
                int y = j + nexty[k];

                if(a[x][y] != '?' && a[x][y] != '#')
                {
                    if(idComponent[i][j] != idComponent[x][y])
                    {
                        adj[idComponent[i][j]].pb(idComponent[x][y]);
                    }
                }
            }
        }
    }
}

//Process
void Topological_DFS(int u)
{
    avail[u] = false;
    for(int v: adj[u])
    {
        if(avail[v]) Topological_DFS(v);
    }

    TopoOrder[u] = TopoTime;
    IdOrder[TopoTime--] = u;
}
void LongestPath()
{
    //FOR(i, 1, nSCC) unique(whole(adj[i]));
    FOR(i, 1, nSCC) if(avail[i]) Topological_DFS(i);

    int x = idComponent[1][1];
    F = vi(nSCC+1, -1);

    F[IdOrder[nSCC]] = sumComponent[IdOrder[nSCC]];

    FORb(i, nSCC-1, 1)
    {
        int u = IdOrder[i];
        for(int v: adj[u])
        {
            if(F[v] > -1) if(F[v] + sumComponent[u] > F[u]) F[u] = F[v] + sumComponent[u];
        }
        if(F[u] == -1) F[u] = sumComponent[u];
        if(u == x) return;
    }
}

//Output
void Solve()
{
    GetGraph();
    LongestPath();
    printf("%d", F[idComponent[1][1]]);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
