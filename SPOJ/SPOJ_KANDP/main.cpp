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
typedef vector<int> vi;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef queue<ii> qii;
typedef long long ll;
const int nextx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int nexty[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int base  = 2048;
int Left, Right, Top;
int MX, MY, TX, TY;
int state, res;
vvb avail;
vvi Time;

//=====================================
//Functions and procedures
//Enter
int V(int __x)
{
    return __x + base;
}
void Enter()
{
	scanf("%d%d%d%d%d", &MX, &MY, &TX, &TY, &state);
	MX = V(MX);
	MY = V(MY);
	TX = V(TX);
	TY = V(TY);
	Time = vvi(4096, vi(4096, 1234567890));
	avail = vvb(4096, vb(4096, true));
    Right = max(MY, TY) + 2;
	Left = min(MY, TY) - 2;
    Top = max(MX, TX) + 2;
    res = 2147483609;
}

//Check
bool Check(int __x, int __y)
{
    return (__y >= Left && __y <= Right && __x <= Top && __x >= 0);
}
void FloodFill(ii start)
{
    qii que;
    que.push(start);
    Time[start.first][start.second] = state;
    avail[start.first][start.second] = false;
    while(!que.empty())
    {
        int curx = que.front().first;
        int cury = que.front().second;
        que.pop();

        FOR(i, 0, 7)
        {
            int x = curx + nextx[i];
            int y = cury + nexty[i];
            if(Check(x, y))
            {
                if(avail[x][y])
                {
                    que.push(ii(x, y));
                    avail[x][y] = false;
                }
                Time[x][y] = min(Time[x][y], Time[curx][cury] + 1);
            }
        }
    }
}



//Process
void Debug()
{
    cout << "\n";
    FOR(i, 2030, Top)
    {
        FORl(j, Left, Right)
        {
            if(Time[i][j]==1234567890) cout << "- ";
            else cout << Time[i][j]  << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void GetTime()
{
    //Debug();
    //
    FORb(i, TY, 0)
    {
        if(Time[TX][i] == TY - i + 1)
        {
            res = min(res, Time[TX][i]);
        }
    }
    printf("%d", res);
}
void Solve()
{
    if((state == 1 && (abs(MX-TX)+abs(MY-TY)) % 2 == 0)||(state == 0 && (abs(MX-TX)+abs(MY-TY)) % 2 == 1))
    {
        printf("YES\n");
        FloodFill(ii(MX, MY));
        GetTime();
    }
    else
    {
        printf("NO\n");
        return;
    }
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
