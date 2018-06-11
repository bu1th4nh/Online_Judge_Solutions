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
#define maxvalueinp (int)(256)
#define MODUL (int)(1e9+57)
#define mp make_pair
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
int f[maxvalueinp][maxvalueinp];
int n, nTest;
bool ok;
qp num;

//=====================================
//Functions and procedures
//Output
void Output(int x, int y)
{
    FOR(i, 1, x) printf("8");
    FOR(i, 1, y) printf("6");
    printf("\n");
}



//Process
int m10(int x)
{
    int t = 1;
    FOR(i, 1, x) t = (t*10) % n;
    return t;
}
void Process()
{
    while(!num.empty()) num.pop();
    scanf("%d", &n);
    MEMS(f, 0);
    f[0][0] = 0;
    num.push(mp(0, 0));
    while(!num.empty())
    {
        int x = num.front().first;
        int y = num.front().second;
        num.pop();
        if(x+y > 203)
        {
            printf("-1\n");
            return;
        }
        if(f[x][y+1] == 0) num.push(mp(x, y+1));
        if(f[x+1][y] == 0) num.push(mp(x+1, y));
        f[x+1][y] = (f[x][y] + m10(x+y) * 8)%n;
        f[x][y+1] = (f[x][y]*10 + 6)%n;
        if(f[x][y+1] == 0)
        {
            Output(x, y+1);
            return;
        }
        if(f[x+1][y] == 0)
        {
            Output(x+1, y);
            return;
        }
    }
}

//Main Procedure
int main()
{
    scanf("%d", &nTest);
    while(nTest--)
    {
        Process();
    }
    return 0;
}
