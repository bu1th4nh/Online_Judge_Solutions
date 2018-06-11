//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp (int)()
#define MODUL (int)(1e9+57)
#define len(x) (int)(x.length())
#define siz(x) (int)(x.size())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
struct conv
{
    int z1, z2, m1, m2, s1, s2;
    conv(int aa, int bb, int cc, int dd, int ee, int ff)
    {
        z1 = aa;
        s1 = bb;
        m1 = cc;
        z2 = dd;
        s2 = ee;
        m2 = ff;
    }
};
struct sta
{
    int z, s, m, k;
    sta(int aa, int bb, int cc, int dd)
    {
        z = aa;
        s = bb;
        m = cc;
        k = dd;
    }
};
int k, z, s, m, z0, s0, m0, n;
int f[10][10][10];
bool avail[10][10][10];
vector<conv> vect;
vector<sta> res;
queue<sta> tt;



//=====================================
//Functions and procedures
//Input
void Input()
{
    int a1, a2, a3, a4, a5, a6;
    //MEMS(f, 0);
    MEMS(avail, true);
    scanf("%d", &k);
    scanf("%d%d%d%d%d%d", &z, &s, &m, &z0, &s0, &m0);

    /*
    while(scanf("%d%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5, &a6) != EOF)
    {
        //scanf("%d%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5, &a6);
        //cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
        vect.push_back(conv(a1, a2, a3, a4, a5, a6));
    }
    */

    while (scanf("%d",&a1) != EOF)
    {
        scanf("%d%d%d%d%d", &a2, &a3, &a4, &a5, &a6);
        vect.push_back(conv(a1, a2, a3, a4, a5, a6));
    }

}

//Check
bool cmp(const sta u, const sta v)
{
    if(u.z < v.z) return true;
    if(u.z == v.z && u.s < v.s) return true;
    if(u.z == v.z && u.s == v.s && u.m < v.m) return true;
    return false;
}


//Process
void Process()
{
    tt.push(sta(z, s, m, 0));
    while(!tt.empty())
    {
        sta fro = tt.front();
        tt.pop();
        int z = fro.z;
        int s = fro.s;
        int m = fro.m;
        if(z > z0 && s > s0 && m > m0 && f[z][s][m] <= k) res.push_back(sta(z, s, m, f[z][s][m]));
        else
        {
            if(f[z][s][m] > k) break;
            FORl(i, 0, siz(vect))
            {
                int z3 = z - vect[i].z1 + vect[i].z2;
                int s3 = s - vect[i].s1 + vect[i].s2;
                int m3 = m - vect[i].m1 + vect[i].m2;
                if(z >= vect[i].z1 && z3 <= 4 && s >= vect[i].s1 && s3 <= 4 && m >= vect[i].m1 && m3 <= 4 && (avail[z3][s3][m3]))
                {
                    tt.push(sta(z3, s3, m3, 0));
                    f[z3][s3][m3] = f[z][s][m] + 1;
                    avail[z3][s3][m3] = false;
                }
            }
        }
    }
}


//Output
void Output()
{
    if(res.empty()) cout << -1;
    else
    {
        printf("%d\n", res.size());
        sort(whole(res), cmp);
        FORl(i, 0, siz(res))
        {
            printf("%d %d %d %d\n", res[i].z, res[i].s, res[i].m, res[i].k);
        }
    }
}



//Main Procedure
int main()
{
    Input();
    Process();
    Output();
    return 0;
}
