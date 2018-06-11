/*==============================================================================================================*\
**                                  _           _ _   _     _  _         _                                      **
**                                 | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   **
**                                 | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  **
**                                 | |_) | |_| | | |_| | | |__   _| | | | | | |                                 **
**                                 |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 **
\*==============================================================================================================*/
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
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define x first
#define y second
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


//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef long long ll;
ii pt[65536], s;
int m, n, a, b;

//=====================================
//Functions and procedures
//Check
void operator -= (ii& A, ii B) {A.x -= B.x; A.y -= B.y;}
bool CCW(ii &A, ii B, ii C) {C -= B; B -= A; return (long)B.x * C.y >= (long)B.y * C.x;}

//Main Procedure
int main()
{
    scanf("%d", &n);
    FOR(i, 1, n)
    {
        scanf("%d %d", &pt[i].x, &pt[i].y);
    }
    pt[0] = pt[n];

    scanf("%d", &m);
    while(m--)
    {
        scanf("%d%d", &a, &b), s = ii(a, b);

        bool inside = true;
        FOR(i, 1, n)
        {
            if(CCW(pt[i], pt[i-1], s))
            {
                inside = false;
                break;
            }
        }
        if(inside) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
