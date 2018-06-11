//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp (int)(1010)
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
typedef long long ll;
typedef stack<int> si;
int a[maxvalueinp][maxvalueinp];
int H[maxvalueinp][maxvalueinp];
int L[maxvalueinp][maxvalueinp];
int R[maxvalueinp][maxvalueinp];
int F[maxvalueinp][maxvalueinp];
int m, n;
si stck;
ll res;

//=====================================
//Functions and procedures
//Input
void Input()
{
    scanf("%d%d", &m, &n);
    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            char x;
            cin >> x;
            a[i][j] = (x=='0') ? 0 : 1;
            H[i][j] = (a[i][j]) ? H[i-1][j]+1 : 0;
        }
    }
}

//Process
void Init()
{
    FOR(i, 1, m)
    {
        while(!stck.empty()) stck.pop();
        FOR(j, 1, n)
        {
            if(H[i][j]!=0)
            {
                if(stck.empty())
                {
                     stck.push(j);
                     L[i][j] = 1;
                }
                else
                {
                    int pers = 0;
                    bool ok = false;
                    while(!stck.empty() && H[i][j] <= H[i][stck.top()])
                    {
                        ok = true;
                        pers = stck.top();
                        stck.pop();
                    }
                    L[i][j] = (ok) ? L[i][pers] + j - pers : 1;
                    stck.push(j);
                }
            }
            else
            {
                while(!stck.empty()) stck.pop();
            }
        }
    }
}
void Process()
{
    res = 0;
    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            if(a[i][j]!=0)
            {
                int k = j - L[i][j];
                F[i][j] = F[i][k] + (L[i][j]*H[i][j]);
                res += F[i][j];
            }
        }
    }
    cout << res;
}

//Main Procedure
int main()
{
    Input();
    Init();
    Process();
    return 0;
}
