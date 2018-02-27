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
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<viii> vviii;
typedef vector<vii> vvii;
typedef vector<vi> vvi;
typedef long long ll;
int nextx[4] = {-1, 0, 0, 1};
int nexty[4] = {0, -1, 1, 0};
int n, m, nTest, res;
vvi maze, dist;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%d%d", &n, &m);

    dist = vvi(n + 1, vi(m + 1, MODUL));
    maze = vvi(n + 1, vi(m + 1, 0));

    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            scanf("%d", &maze[i][j]);
        }
    }
}

//Dijkstra's Algorithm
void Dijkstra()
{
    priority_queue<iii, viii, greater<iii>> pq;
    int du, uv, ux, uy, vx, vy;

    pq.push(iii(maze[1][1], ii(1, 1)));
    dist[1][1] = maze[1][1];

    while(!pq.empty())
    {
        uy = pq.top().second.second;
        ux = pq.top().second.first;
        du = pq.top().first;
        pq.pop();

        if(du != dist[ux][uy]) continue;

        FOR(i, 0, 3)
        {
            vx = ux + nextx[i];
            vy = uy + nexty[i];

            if(vx >= 1 && vy >= 1 && vx <= n && vy <= m)
            {
                if(dist[vx][vy] > du + maze[vx][vy])
                {
                    dist[vx][vy] = du + maze[vx][vy];
                    pq.push(iii(dist[vx][vy], ii(vx, vy)));
                }
            }
        }
    }
}

//Process
void Solve()
{
    Dijkstra();
    printf("%d\n", dist[n][m]);
}

//Output
void Multitest()
{
    scanf("%d", &nTest);
    while(nTest--)
    {
        Enter();
        Solve();
    }
}

//Main Procedure
int main()
{
    Multitest();
    return 0;
}
