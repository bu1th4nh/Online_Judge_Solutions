//Libraries and namespaces
//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <iostream>
#include <fstream>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp (int)(10e4+10)
#define MODUL (int)(10e9+57)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORbi(x, y) for(int i=x; i>=y; --i)
#define FORlbi(x, y) for(int i=x; i>y; --i)
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
int lab[maxvalueinp];
int query;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP(task)
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}
void IOSTROpt()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void Init()
{
    MEMS(lab, -1);
}

//Input
void Input()
{
    cin >> query;
}

//Process
int FindSet(int u)
{
    return (lab[u]<0) ? u : lab[u] = FindSet(lab[u]);
}

void Union(int r, int s)
{
    if (lab[r] > lab[s]) swap(r, s);
    lab[r] += lab[s];
    lab[s] = r;
}
void CheckSet(int u, int v)
{
    int r = FindSet(u);
    int s = FindSet(v);
    int res = (r == s) ? 1 : 0;
    cout << res << endl;
}
void UnionSet(int u, int v)
{
    int r = FindSet(u);
    int s = FindSet(v);
    if (r!=s)
    {
        Union(r, s);
    }
}

//Output
void Output()
{
    FORi(1, query)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (z==1) UnionSet(x, y);
        else CheckSet(x, y);
    }
}

//Main Procedure
int main()
{
    Input();
    Init();
    Output();
    return 0;
}
