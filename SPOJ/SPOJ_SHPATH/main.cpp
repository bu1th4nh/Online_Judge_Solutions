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
typedef long long ll;
typedef unsigned long long ull;
typedef map<string, int> msi;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
int n, nQuery, nTest;
msi MapVertex;
vvii adj;
vi dist;


//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%d%d", &n);
    MapVertex = msi();
    adj = vvii(n+1, vii());
    char s[16];
    int nEdges;
    string t;

    FOR(i, 1, n)
    {
        //cin >> t;
        scanf("%s", &s);
        scanf("%d", &nEdges);

        t = string(s);
        MapVertex[t] = i;

        FOR(j, 1, nEdges)
        {
            int v, c;
            scanf("%d%d", &v, &c);
            adj[i].pb(ii(c, v));
        }
    }

    scanf("%d", &nQuery);
}

//Dijkstra's Algorithm
void Dijkstra(int start, int finish)
{
    priority_queue<ii, vii, greater<ii>> pq;
    int u, v, du, uv;

    dist = vi(n+1, MODUL);
    pq.push(ii(0, start));
    dist[start] = 0;

    while(!pq.empty())
    {
        u = pq.top().second;
        du = pq.top().first;
        pq.pop();

        if(du != dist[u]) continue;

        for(ii x: adj[u])
        {
            v = x.second;
            uv = x.first;
            if(dist[v] > dist[u] + uv)
            {
                dist[v] = dist[u] + uv;
                pq.push(ii(dist[v], v));
            }
        }
    }

    printf("%d\n", dist[finish]);

}


//Process
void Solve()
{
    char s1[16], s2[16];
    string t1, t2;
    int s, t;
    FOR(kkkkkk, 1, nQuery)
    {
        scanf("%s %s", &s1, &s2);
        t1 = string(s1), t2 = string(s2);
        //cin >> s1 >> s2;
        s = MapVertex[s1], t = MapVertex[s2];
        Dijkstra(s, t);
    }
}

//Multi-test
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
