/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
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
#include <tuple>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define sp ' '
#define el '\n'
#define task ""
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


//=====================================
struct Data
{
    int time, pos, dir, id;

    Data(int __t, int __p, int __d, int __i): time(__t), pos(__p), dir(__d), id(__i) {}
    Data() {}
};
bool cmpID(Data __a, Data __b)
{
    return __a.id < __b.id;
}
bool cmpPos(Data __a, Data __b)
{
    return __a.pos < __b.pos;
}


//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<Data> vd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n, k, max_time = 0;
vd a;


//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP();
}
void FileDebug()
{
    FILEOP_DEBUG();
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Enter
void Enter()
{
	scanf("%d%d", &n, &k);
	int x, y;

	FORl(i, 0, n)
	{
	    scanf("%d%d", &x, &y);
	    a.push_back(Data((y == 0 ? x : k - x), x, y, i+1));
	    max_time = max(max_time, a[i].time);
	}
}

//Process
void Solve()
{
    sort(whole(a), cmpPos);


    cerr << el << "POS - DIR - TIME - ID" << el;
    for(Data x: a) cerr << x.pos << sp << x.dir << sp << x.time << sp << x.id << el;

    FORl(i, 0, n-1)
    {
        if(a[i].dir == 1 && a[i+1].dir == 0)
        {

            //if(abs(a[i+1].pos - a[i].pos))

            swap(a[i].dir, a[i+1].dir);
            swap(a[i].time, a[i+1].time);

            cerr << el;
            for(Data x: a) cerr << x.pos << sp << x.dir << sp << x.time << sp << x.id << el;
        }
    }


    FORl(i, 0, n-1)
    {
        if(a[i].dir == 1 && a[i+1].dir == 0)
        {

            //if(abs(a[i+1].pos - a[i].pos))

            swap(a[i].dir, a[i+1].dir);
            swap(a[i].time, a[i+1].time);

            cerr << el;
            for(Data x: a) cerr << x.pos << sp << x.dir << sp << x.time << sp << x.id << el;
        }
    }



    sort(whole(a), cmpID);


    cerr << el;
    for(Data x: a) cerr << x.pos << sp << x.dir << sp << x.time << sp << x.id << el;
    cerr << el;



    for(Data x: a) cout << x.time << el;

}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
