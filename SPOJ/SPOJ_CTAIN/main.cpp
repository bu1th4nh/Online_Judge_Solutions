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
typedef vector<bool> vb;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef vector<vvi> vvvi;
typedef vector<vvvi> vvvvi;
struct Data
{
    vi water;
    int step;
    Data(): step(0), water(0){}
    Data(int st, const vi &wa): step(st), water(wa){}
};
int n, tc, res;
vi cap, rq, water;
vvvvi f;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%d", &n);

    f = vvvvi(50, vvvi(50, vvi(50, vi(50, MODUL))));
    water = rq = cap = vi(n, 0);

    FORl(i, 0, n) {scanf("%d", &cap[i]); water[i] = cap[i];}
    FORl(i, 0, n) scanf("%d", &rq[i]);
}

//Check
int GetVal(const vi& tmp)
{
    int a, b, c, d;
    a = b = c = d = 0;

    if(n == 1) a = tmp[0];
    else if(n == 2) a = tmp[0], b = tmp[1];
    else if(n == 3) a = tmp[0], b = tmp[1], c = tmp[2];
    else if(n == 4) a = tmp[0], b = tmp[1], c = tmp[2], d = tmp[3];

    return f[a][b][c][d];
}
int SetVal(const vi& tmp, int val)
{
    int a, b, c, d;
    a = b = c = d = 0;

    if(n == 1) a = tmp[0];
    else if(n == 2) a = tmp[0], b = tmp[1];
    else if(n == 3) a = tmp[0], b = tmp[1], c = tmp[2];
    else if(n == 4) a = tmp[0], b = tmp[1], c = tmp[2], d = tmp[3];

    f[a][b][c][d] = val;
}

//Process
void BFS(Data start)
{
    queue<Data> q;
    vi tmp;

    SetVal(start.water, 0);
    q.push(start);

    while(!q.empty())
    {
        Data p = q.front();
        q.pop();

        FORl(i, 0, n)
        {
            ///Pour all of them!

            int old_water = p.water[i];
            p.water[i] = 0;

            tmp = p.water;
            if(GetVal(tmp) == MODUL)
            {
                SetVal(tmp, p.step+1);
                q.push(Data(p.step+1, tmp));
            }
            tmp.clear();

            p.water[i] = old_water;

            ///Refill a tank
            if(p.water[i] < cap[i])
            {
                FORl(j, 0, n)
                {
                    if(j == i) continue;
                    if(cap[i] - p.water[i] <= p.water[j])
                    {
                        int old1 = p.water[i], old2 = p.water[j];
                        p.water[j] = p.water[j] - (cap[i] - p.water[i]), p.water[i] = cap[i];

                        tmp = p.water;
                        if(GetVal(tmp) == MODUL)
                        {
                            SetVal(tmp, p.step+1);
                            q.push(Data(p.step+1, tmp));
                        }
                        tmp.clear();

                        p.water[i] = old1;
                        p.water[j] = old2;
                    }
                }
            }

            ///Refill a tank, but empty the other tank

            FORl(j, 0, n)
            {
                if(j == i) continue;
                if(cap[j] - p.water[j] >= p.water[i])
                {
                    int old1 = p.water[i], old2 = p.water[j];
                    p.water[j] = p.water[j] + p.water[i], p.water[i] = 0;

                    tmp = p.water;
                    if(GetVal(tmp) == MODUL)
                    {
                        SetVal(tmp, p.step+1);
                        q.push(Data(p.step+1, tmp));
                    }
                    tmp.clear();

                    p.water[i] = old1;
                    p.water[j] = old2;
                }
            }
        }
    }
}
void Solve()
{
    BFS(Data(0, water));
    res = GetVal(rq);
    if(res == MODUL) printf("NO\n");
    else printf("%d\n", res);
}

//Output
void Multitest()
{
    scanf("%d", &tc);
    while(tc--)
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
