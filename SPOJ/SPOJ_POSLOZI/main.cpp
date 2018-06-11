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


//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<int, string> ist;
typedef map<string, int> msi;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef vector<ist> vist;
typedef long long ll;
string src, dst;
vii changes;
int n, m;
msi dist;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int u, v;

    scanf("%d%d", &n, &m);

    changes = vii(m);

    FOR(i, 1, n)
    {
        scanf("%d", &u);
        src += char(u - 1 + 'A');
        dst += char(i - 1 + 'A');
    }

    FOR(i, 1, m)
    {
        scanf("%d%d", &u, &v);
        changes.push_back(ii(--u, --v));
    }
}

//Dijkstra's Algorithm
void Dijkstra()
{
    int du;
    string u, v;
    queue<ist> pq;

    pq.push(ist(0, src));
    dist[src] = 0;

    while(!pq.empty())
    {
        u = pq.front().second;
        du = pq.front().first;
        pq.pop();

        if(u == dst) return;

        if((dist.find(u) == dist.end()) || ((dist.find(u) == dist.end() && dist[u] != du))) continue;

        for(ii x: changes)
        {
            v = u;
            swap(v[x.fi], v[x.se]);

            if(dist.find(v) == dist.end())
            {
                dist[v] = du + 1;
                pq.push(ist(dist[v], v));
            }
            else
            {
                if(dist[v] > du + 1)
                {
                    dist[v] = du + 1;
                    pq.push(ist(dist[v], v));
                }
            }
        }
    }

}
void Solve()
{
    Dijkstra();
    printf("%d\n", dist[dst]);
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
