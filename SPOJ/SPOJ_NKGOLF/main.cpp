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
#define maxvalueinp (int)(1010)
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
typedef stack<int> si;
bool b[maxvalueinp][maxvalueinp];
long long a[maxvalueinp][maxvalueinp];
int h[maxvalueinp];
int l[maxvalueinp];
int r[maxvalueinp];
int m, n, res;
si stck;

//=====================================
//Functions and procedures
//Input
void Input()
{
    scanf("%d%d", &m, &n);
    FOR(i, 1, m)
    {
        FOR(j,1, n)
        {
            scanf("%lld", &a[i][j]);
        }
    }


    /*
    FOR(i, 1, n+1)
    {
        a[m+1][i] = MODUL;
        a[0][i] = MODUL;
    }
    FOR(i, 0, m+1) a[i][n+1] = MODUL;
    */

    /*                                 //Debug
    cout << endl;
    FOR(i, 0, m+1)
    {
        FOR(j, 0, n+1)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    */


}


//Process
void PreProcess()
{
    int dir;
    res = 1;
    FOR(i, 1, m-1)
    {
        FOR(j, 1, n-1)
        {
            b[i][j]=((a[i][j]<=a[i+1][j]) && (a[i][j]<=a[i][j+1]) && (a[i+1][j]<=a[i+1][j+1]) && (a[i][j+1]<=a[i+1][j+1]));
        }
    }

    /*                                 //Debug
    cout << endl;
    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    */

    //Search rows
    FOR(i, 1, m)
    {
        dir = 1;
        FOR(j, 2, n)
        {
            if(a[i][j] >= a[i][j-1])
            {
                ++dir;
                res = max(res, dir);
            }
            else dir = 1;
        }
    }

    //Search columns
    FOR(i, 1, n)
    {
        dir = 1;
        FOR(j, 2, m)
        {
            if(a[i][j] >= a[i-1][j])
            {
                ++dir;
                res = max(res, dir);
            }
            else dir = 1;
        }
    }
    MEMS(h, 0);
    MEMS(l, 0);
    MEMS(r, 0);

}
void Process()
{
    stck.push(0);
    FOR(i, 1, m-1)
    {
        FOR(j, 1, n-1)
        {
            if(b[i][j]) ++h[j];
            else h[j] = 0;
        }
        FOR(j, 1, n-1)
        {
            while(stck.size()>1 && h[j]<=h[stck.top()])
            {
                r[stck.top()] = j-1;
                stck.pop();
            }
            l[j] = stck.top()+1;
            stck.push(j);
        }
        while(stck.size()>1)
        {
            r[stck.top()] = n-1;
            stck.pop();
        }

        FOR(j, 1, n-1)
        {
            if (h[j] > 0) res = max(res, (h[j]+1)*(r[j]-l[j]+2));
        }
    }
    printf("%d", res);
}

//Main Procedure
int main()
{
    Input();
    PreProcess();
    Process();
    return 0;
}
