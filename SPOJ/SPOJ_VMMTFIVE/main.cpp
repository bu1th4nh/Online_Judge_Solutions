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
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
bool mark[26];
int row[6];
int col[6];
vi res;

//=====================================
//Sample I/O
/**
Input:
60 86 59 38 82
61 59 57 89 59

Output:
15 5 9 25 6
17 10 23 20 16
12 19 3 18 7
13 14 1 2 8
4 11 21 24 22

 */

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	FOR(i, 1, 5) scanf("%d", &row[i]);
	FOR(i, 1, 5) scanf("%d", &col[i]);
}

//Check
bool Check(vi & sample)
{

    FOR(i, 0, 4)
    {
        int tmp1 = 0;
        int tmp2 = 0;
        FOR(j, 0, 4)
        {
            tmp1 += sample[i*5 + j];
            tmp2 += sample[j*5 + i];
        }
        if(tmp1 != row[i]) return false;
        if(tmp2 != col[i]) return false;
    }


    return true;
}
void Solve()
{

}



//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
