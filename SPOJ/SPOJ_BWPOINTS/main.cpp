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
#define maxvalueinp (int)()
#define MODUL (int)(10e9+57)
#define whole(x) x.begin(), x.end()
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORbi(x, y) for(int i=x; i>=y; --i)
#define FORlbi(x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
struct point
{
    int val;
    bool col;
};
vector<point> vp;
int res, n;



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
bool cmp(point a, point b)
{
    return a.val < b.val;
}

//Main Procedure
int main()
{
    cin >> n;
    FORi(1, n)
    {
        point x;
        cin >> x.val;
        x.col = 0;
        vp.push_back(x);
    }
    FORi(1, n)
    {
        point x;
        cin >> x.val;
        x.col = 1;
        vp.push_back(x);
    }
    n*=2;
    res = 0;
    sort(whole(vp), cmp);
    FORli(1, n)
    {
        if (vp[i].col != vp[i-1].col)
        {
            ++res;
            ++i;
        }
    }
    cout << res;
    return 0;
}
