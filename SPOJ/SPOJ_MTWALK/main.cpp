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
#define maxvalueinp (int)(110)
#define MODUL (int)(10e9+57)
#define len(x) (int)(x.length())
#define siz(x) (int)(x.size())
#define mp(x, y) make_pair(x, y)
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
int MoveX[4] = {-1, 0, 0, 1};
int MoveY[4] = {0, -1, 1, 0};
bool avail[maxvalueinp][maxvalueinp];
int a[maxvalueinp][maxvalueinp];
int maxh, minh, res;
bool ok;
int n;

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

//Input
void Input()
{
    minh = 111;
    maxh = 0;
    scanf("%d", &n);
    FOR(i, 1, n)
    {
        FOR(j, 1, n)
        {
            cin >> a[i][j];
            maxh = max(maxh, a[i][j]);
            minh = min(minh, a[i][j]);
        }
    }
}

//Check
bool IsValid(int x, int y, int lft, int rgt)
{
    return x > 0 && x <= n && y > 0 && y <= n && a[x][y] >= lft && a[x][y] <= rgt && avail[x][y];
}

void FloodFill(int u, int v, int left, int right)
{
    if(u==n && v==n)
    {
        ok = true;
        return;
    }
    avail[u][v] = false;
    FORl(i, 0, 4)
    {
        int x = u + MoveX[i];
        int y = v + MoveY[i];
        if(IsValid(x, y, left, right))
        {
            FloodFill(x, y, left, right);
        }
        if(ok) return;
    }
}

//Process
bool Check(int src, int dst)
{
    ok = false;
    MEMS(avail, true);
    FloodFill(1, 1, src, dst);
    return ok;
}

//Output
void Output()
{
    int l, r;
    res = maxh - minh;
    FOR(i, minh, a[1][1])
    {
        l = 0;
        r = res;
        while (l<r)
        {
            int mid = (l+r) / 2;
            if(Check(i, i+mid)) r = mid;
            else l = mid+1;
        }
        res = l;
    }
    printf("%d", res);
}

//Main Procedure
int main()
{
    Input();
    Output();
    return 0;
}
