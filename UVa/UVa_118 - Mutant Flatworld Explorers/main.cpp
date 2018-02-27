//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cassert>
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
typedef map<int, char> mic;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
char str[128], t;
ii upLim, start;
string ctrl;
bool isDie;
vvb scent;
mci map1;
mic map2;
int pos;

//=====================================
//Functions and procedures
void Prep()
{
    ///Orientation
    map1['N'] = 0; map2[0] = 'N';
    map1['E'] = 1; map2[1] = 'E';
    map1['S'] = 2; map2[2] = 'S';
    map1['W'] = 3; map2[3] = 'W';
    ///Instructions
    map1['L'] = -1;
    map1['R'] = 1;
}

//Enter
void Enter()
{
    isDie = false;
    cin >> t;

    pos = map1[t];

    //cin.ignore(1);
    //scanf("%s", &str);
    //ctrl = string(str);

    cin >> ctrl;
}

//Check
bool Check(int x, int y)
{
    return x >= 0 && y >= 0 && x <= upLim.first && y <= upLim.second;
}

//Process
bool Move(ii &dir, char ch)
{
    ii cur = dir;
    assert(ch == 'F' || ch == 'R' || ch == 'L');
    if(ch == 'F')
    {
        if(pos == 0) cur.second++;
        else if(pos == 1) cur.first++;
        else if(pos == 2) cur.second--;
        else if(pos == 3) cur.first--;
    }
    else
    {
        pos += map1[ch];
        pos = (pos < 0) ? 3 : (pos%4);
    }

    if(Check(cur.first, cur.second))
    {
        dir = cur;
        return true;
    }
    else
    {
        if(!scent[dir.first][dir.second])
        {
            scent[dir.first][dir.second] = true;
            return false;
        }
    }

    return true;
}


void Solve()
{
    for(int i = 0; i < ctrl.length(); ++i)
    {
        char j = ctrl[i];
        if(!Move(start, j))
        {
            isDie = true;
            break;
        }
    }


    printf("%d %d %c", start.first, start.second, map2[pos]);
    if(isDie) printf(" LOST\n");
    else printf("\n");
}

//Output
void Multitest()
{
    int u, v;
    scanf("%d %d", &u, &v); upLim = ii(u, v);
    scent = vvb(u + 1, vb(v + 1, false));


    while(scanf("%d %d", &u, &v) == 2)
    {
        start = ii(u, v);
        Enter();
        Solve();
    }
}

//Main Procedure
int main()
{
    Prep();
    Multitest();
    return 0;
}
