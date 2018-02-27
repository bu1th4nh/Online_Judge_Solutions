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
typedef map<char, int> mci;
typedef pair<int, int> ii;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vc> vvc;
typedef vector<ii> vii;
typedef long long ll;
int nextx[4] = {0, -1, 0, 1};
int nexty[4] = {1, 0, -1, 0};
int m, n, nCtrl, dir, res;
string order;
ii coor;
mci mp;
vvc a;

//=====================================
//Functions and procedures
//Preparation
void Prep()
{
    mp['N'] = 0;
    mp['L'] = 1;
    mp['S'] = 2;
    mp['O'] = 3;

    mp['D'] = 1;
    mp['E'] = -1;
}

//Enter
void Enter()
{
    a = vvc(n + 1, vc(m + 1));

    FOR(i, 1, n)
    {
        FOR(j, 1, m)
        {
            //scanf("%c", &a[i][j]);
            cin >> a[i][j];

            if(a[i][j] == 'N' || a[i][j] == 'S' || a[i][j] == 'L' || a[i][j] == 'O')
            {
                dir = mp[a[i][j]];
                coor = ii(i, j);
            }
        }
    }

    //char str[65536]; scanf("%s", &str); order = string(str);
    cin >> order;
    order = '?' + order;
}

//Check
bool Check(int x, int y)
{
    return (x >= 1 && y >= 1 && x <= n && y <= m && a[x][y] != '#');
}

//Process
void Solve()
{
    res = 0;
    FOR(i, 1, nCtrl)
    {
        if(order[i] == 'F')
        {
            int new_x = coor.first, new_y = coor.second;

            if(dir == 0) new_x--;
            else if(dir == 1) new_y++;
            else if(dir == 2) new_x++;
            else if(dir == 3) new_y--;

            if(Check(new_x, new_y))
            {
                a[coor.first][coor.second] = '.';
                if(a[new_x][new_y] == '*')
                {
                    ++res;
                    a[new_x][new_y] = '.';
                }
                coor = ii(new_x, new_y);
            }
        }
        else
        {
            if(order[i] == 'D') ++dir;
            else --dir;
            dir = (dir < 0) ? 3 : (dir % 4);
        }
    }

    printf("%d\n", res);
}


//Output
void Multitest()
{
    Prep();
    m = n = nCtrl = 2017;
    while(true)
    {
        scanf("%d%d%d", &n, &m, &nCtrl);
        if(n == 0 && m == 0 && nCtrl == 0) break;
        Enter();
        Solve();
    }
}


//Main Procedure
int main()
{
    Multitest();
    return 0;
}
