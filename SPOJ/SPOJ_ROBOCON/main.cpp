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
#define maxvalueinp (int)(512)
#define MODUL (int)(1000000000)
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
typedef queue<p2i> qp;
bool Obs[maxvalueinp][maxvalueinp];
int A[maxvalueinp][maxvalueinp];
int B[maxvalueinp][maxvalueinp];
int next1x[3] = {1, 0, 1};
int next1y[3] = {0, -1, -1};
int next0x[3] = {1, 0, 1};
int next0y[3] = {0, 1, 1};
int n, k, res;
qp dir;

//=====================================
//Functions and procedures
//Input
void Input()
{
    MEMS(Obs, true);
    scanf("%d%d", &n, &k);
    FOR(i, 0, n+1)
    {
        Obs[0][i] = false;
        Obs[i][0] = false;
        Obs[i][n+1] = false;
        Obs[n+1][i] = false;
    }
    FOR(i, 1, k)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        Obs[x][y] = false;
    }
}

//Process
void FloodFill()
{
    res = 0;
    int d1 = 1;
    int d2 = 1;
    dir.push(make_pair(1, 1));
    dir.push(make_pair(1, n));
    while(!dir.empty())
    {
        ++res;
        int tmp = 0;
        FOR(i, 1, d1)
        {
            p2i cur = dir.front();
            int curx = cur.first;
            int cury = cur.second;
            dir.pop();
            FORl(j, 0, 3)
            {
                int x = curx + next0x[j];
                int y = cury + next0y[j];
                if(Obs[x][y] && A[x][y]!=res)
                {
                    A[x][y] = res;
                    dir.push(make_pair(x, y));
                    ++tmp;
                }
            }
        }
        d1 = tmp;
        tmp = 0;
        FOR(i, 1, d2)
        {
            p2i cur = dir.front();
            int curx = cur.first;
            int cury = cur.second;
            dir.pop();
            FORl(j, 0, 3)
            {
                int x = curx + next1x[j];
                int y = cury + next1y[j];
                if(Obs[x][y])
                {
                    if(A[x][y] == res) return;
                    if(B[x][y] != res)
                    {
                        B[x][y] = res;
                        dir.push(make_pair(x, y));
                        ++tmp;
                    }
                }
            }
        }
        d2 = tmp;
    }
}


//Main Procedure
int main()
{
    Input();
    FloodFill();
    printf("%d", res);
    return 0;
}
