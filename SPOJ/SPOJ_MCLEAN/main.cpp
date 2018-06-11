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
#define MODUL (int)(123456789)
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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vc> vvc;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<ii> vii;
typedef queue<ii> qii;
int nextx[4] = {-1, 0, 0, 1};
int nexty[4] = {0, -1, 1, 0};
int w, h, nDust, res, sum;
bool valid = true;
vvi d, step;
ii vaccum;
vvc vect;
vii dust;
vi path;
vb fre3;

//=====================================
//Functions and procedures
//Debug
void Debug(vvi x, int m, int n)
{
    cout << endl;
    cout << "===============DEBUG===============\n";
    FOR(i, 0, m)
    {
        FOR(j, 0, n) cout << x[i][j] << " ";
        cout << endl;
    }
    cout << "=============END-DEBUG=============\n";
    cout << endl;
}
void Debug2(vvb x, int m, int n)
{
    cout << endl;
    cout << "===============DEBUG===============\n";
    FOR(i, 0, m)
    {
        FOR(j, 0, n) cout << x[i][j] << " ";
        cout << endl;
    }
    cout << "=============END-DEBUG=============\n";
    cout << endl;
}


//Enter
void Enter()
{
	sum = 0;
	nDust = 0;
	res = MODUL;
	valid = true;
	dust.clear();
	dust.push_back(ii(0, 0));
	step = vvi(h+3, vi(w+3, 0));
	vect = vvc(h+3, vc(w+3, '?'));

	FOR(i, 1, h)
	{
	    FOR(j, 1, w)
	    {
	        cin >> vect[i][j];


			step[i][j] = MODUL;
	        if(vect[i][j] == '*')
            {
                ++nDust;
                dust.push_back(ii(i, j));
            }
            else if(vect[i][j] == 'o')
            {
                dust[0] = ii(i, j);
            }
            else if(vect[i][j] == 'x')
            {
                step[i][j] = -1;
            }
	    }
	}

	d = vvi(nDust + 9, vi(nDust + 9, MODUL));
	fre3 = vb(nDust + 2, true);
	path = vi(nDust + 2, 0);


}

//Check
bool Check(int __x, int __y)
{
    return (__x >= 1 && __x <= h && __y >= 1 && __y <= w && vect[__x][__y] != 'x');
}


//Breadth-First Search
void FloodFill(ii start, int index)
{
    vvb avail = vvb(h+3, vb(w+3, true));
    int curx, cury, x, y;
    vvi time = step;
    qii que;


    que.push(start);
    time[start.first][start.second]  = 0;
    avail[start.first][start.second] = false;

    while(!que.empty())
    {
        cury = que.front().second;
        curx = que.front().first;
        que.pop();

        FOR(i, 0, 3)
        {
            x = curx + nextx[i];
            y = cury + nexty[i];
            ii n3xt = ii(x, y);

            if(Check(x, y))
            {
                if(avail[x][y])
                {
                    que.push(n3xt);
                    avail[x][y] = false;
                }
                time[x][y] = min(time[x][y], time[curx][cury] + 1);
            }
        }
    }


    FOR(i, 0, nDust)
    {


        d[index][i] = time[dust[i].fi][dust[i].se];
        if(d[index][i] == MODUL)
        {
            valid = false;
            return;
        }
    }

}

//Hamiltonian Cycle, solved by Branch And Bound method
void BranchBound(int pos)
{
    if(sum >= res) return;
    FOR(i, 1, nDust)
    {
        if(fre3[i])
        {
            path[pos] = i;
            fre3[i] = false;
            sum += d[path[pos - 1]][i];
            if(pos == nDust)
            {
                if(sum < res) res = sum;
            }
            else BranchBound(pos + 1);
            sum -= d[path[pos - 1]][i];
            fre3[i] = true;
        }
    }
}

//Process
void Solve()
{
    path[0] = 0;
    FOR(i, 0, nDust)
    {
        FloodFill(dust[i] ,i);
        if(!valid) break;
    }


    if(valid)
    {
        BranchBound(1);
        printf("%d\n", res);
        return;
    }
    else
    {
        printf("-1\n");
    }
}

//Multi-test
void Multitest()
{
    Enter();
    Solve();
}

//Main Procedure
int main()
{
    w = h = 1000;
    while(w != 0 && h != 0)
    {
        scanf("%d%d", &w, &h);
        if(w*h == 0) break;
        else Multitest();
    }
    return 0;
}
