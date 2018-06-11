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
#define maxinp (int)(1500)
#define MODUL (int)(1e9+57)
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef queue<ii> qii;
typedef long long ll;
int nextx[4] = {-1, 0, 0, 1};
int nexty[4] = {0, -1, 1, 0};
bool Free[maxinp][maxinp];
int Time[maxinp][maxinp];
char a[maxinp][maxinp];
int m, n, res, nTime;
qii mainq, subq;
ii start[3];



int nInstruction = 0;


//=====================================
//Functions and procedures
//Debug
void Debug()
{

    cout << endl;
    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            cout << Time[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;


}


//Enter
void Enter()
{
	int cnt = 1;
	MEMS(Free, true);


	scanf("%d%d", &m, &n);


	/*
    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            Time[i][j] = 1234567890;
        }
    }
    */


	FOR(i, 1, m)
	{
	    FOR(j, 1, n)
	    {

	        cin >> a[i][j];


            if(a[i][j] != 'X')
            {
                Time[i][j] = 0;

                mainq.push(ii(i, j));

                if(a[i][j] == 'L')
                {
                    start[cnt] = ii(i, j);
                    ++cnt;
                }

                Free[i][j] = false;
            }
            else Time[i][j] = 1234567890;

            ++nInstruction;


	    }
	}

}

//Check
bool IsValid(int _x, int _y)
{
    return(_x >= 1 && _y >= 1 && _x <= m && _y <= n && Free[_x][_y]);
}

void PreProcess()
{
    while(!mainq.empty())
    {
        int curx = mainq.front().first;
        int cury = mainq.front().second;

        ++nInstruction;

        //Time[curx][cury] = nTime;
        mainq.pop();

        FOR(i, 0, 3)
        {
            int x = curx + nextx[i];
            int y = cury + nexty[i];

            if(IsValid(x, y))
            {
                if(a[x][y] == 'X')
                {
                    Free[x][y] = false;
                    mainq.push(ii(x, y));
                    Time[x][y] = min(Time[x][y], Time[curx][cury] + 1);
                }
            }
        }

    }

    //Debug();



}
void FloodFill1(ii st1, ii st2)
{
    mainq.push(st1);
    Free[st1.first][st1.second] = false;
    while(!mainq.empty())
    {
        int curx = mainq.front().first;
        int cury = mainq.front().second;

        //Time[curx][cury] = nTime;
        ++nInstruction;

        mainq.pop();

        FOR(i, 0, 3)
        {
            int x = curx + nextx[i];
            int y = cury + nexty[i];
            ii dir = ii(x, y);

            if(IsValid(x, y))
            {
                Free[x][y] = false;
                if(dir == st2) return;
                if(Time[x][y] <= res) mainq.push(dir);
                else subq.push(dir);
            }
        }

        if(mainq.empty())
        {
            ++res;
            swap(mainq, subq);
        }

    }
}

//Process
void Solve()
{
    res = 0;
    PreProcess();
    MEMS(Free, true);
    FloodFill1(start[1], start[2]);
    printf("%d", res);


    cerr << endl;
    cerr << nInstruction << endl;

}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
