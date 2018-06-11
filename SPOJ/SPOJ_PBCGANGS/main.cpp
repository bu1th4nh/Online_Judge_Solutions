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
#define maxvalueinp (int)(5010)
#define MODUL (int)(10e9+57)
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
typedef pair<int, int> p2i;
int lab[maxvalueinp];
int E[maxvalueinp];
int m, n;
int cntm;
int res;


//=====================================
//Functions and procedures
//Initialization and preparation
void Init()
{
    MEMS(lab, 0);
    MEMS(lab, -1);
    res = n;
}


//Process
int FindSet(int u)
{
    return (lab[u] < 0) ? u : lab[u] = FindSet(lab[u]);
}
void UnionSet(int r, int s)
{
    if(lab[r] > lab[s]) swap(r, s);
    lab[r] += lab[s];
    lab[s] = r;
}
void Union(int u, int v)
{
    int r = FindSet(u);
    int s = FindSet(v);
    if(r!=s)
    {
        UnionSet(r, s);
        --res;
    }
}

//Output
void Query()
{
    int p, q;
    char state;
    FOR(i, 1, m)
    {
        //scanf("%c%d%d", &state, &p, &q);
        cin >> state >> p >> q;
        if(state == 'F')
        {
            Union(p, q);
        }
        else
        {
            if(E[p] == 0) E[p] = q;
            else Union(E[p], q);
            if(E[q] == 0) E[q] = p;
            else Union(E[q], p);
        }
    }
    printf("%d", res);
}


//Main Procedure
int main()
{
    cin >> n >> m;
    Init();
    Query();
    return 0;
}
