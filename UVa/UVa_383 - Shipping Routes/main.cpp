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
#define task "IFF"
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
typedef map<string, int> mstr;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef queue<int> qi;
typedef long long ll;
int m, n, p, nTest;
vi trace;
vb avail;
vvi adj;
mstr mp;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    mp.clear();
    char s1[2], s2[2];
    string s11, s12;
    int u, v;

    scanf("%d%d%d", &n, &m, &p);

    adj = vvi(n+1);

    FOR(i, 1, n)
    {
        //scanf("%s", &s1);
        //mp[string(s1)] = i;

        cin >> s11;
        mp[s11] = i;
    }
    FOR(i, 1, m)
    {
        //scanf("%s %s", &s1, &s2);
        //u = mp[string(s1)], v = mp[string(s2)];

        cin >> s11 >> s12;
        u = mp[s11], v = mp[s12];

        adj[u].pb(v);
        adj[v].pb(u);
    }
}

//Check
void Query(int src, int dst, int cost)
{
    avail = vb(n+1, true);
    trace = vi(n+1, -1);
    qi que;

    que.push(src);
    avail[src] = false;

    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        FORl(i, 0, adj[u].size())
        {
            int v = adj[u][i];
            if(avail[v])
            {
                que.push(v);
                avail[v] = false;
                trace[v] = u;
            }
        }
    }

    if(trace[dst] == -1) printf("NO SHIPMENT POSSIBLE\n");
    else
    {
        int res = 0;
        while(src != dst)
        {
            ++res;
            dst = trace[dst];
        }
        res *= 100 * cost;
        printf("$%d\n", res);
    }
}


//Process
void Solve()
{
    int load, u, v;
    string sr1, ds1;
    char sr[2], ds[2];
    FOR(iQuery, 1, p)
    {

        //scanf("%d %s %s", &load, &sr, &ds);
        //u = mp[string(sr)], v = mp[string(ds)];

        cin >> load >> sr1 >> ds1;
        u = mp[sr1], v = mp[ds1];
        Query(u, v, load);
    }
}

//Output
void Multitest()
{
    scanf("%d", &nTest);
    printf("SHIPPING ROUTES OUTPUT\n\n");
    FOR(IFF, 1, nTest)
    {
        printf("DATA SET  %d\n", IFF);
        puts("");
        Enter();
        Solve();
        puts("");
    }
    printf("END OF OUTPUT\n");
}

//Main Procedure
int main()
{
    FILEOP();
    Multitest();
    return 0;
}
