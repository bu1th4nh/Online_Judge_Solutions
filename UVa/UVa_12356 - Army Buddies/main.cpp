/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/

/*      --Solution Briefing: Doubly Linked List  /Doubly Linked List Deletion.

          For each (l, r),   Node[Node[l].left].right = Node[r].right
                             Node[Node[r].right].left = Node[l].left
*/


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
//DLL
struct NODE
{
    int l, r;
    NODE(): l(0), r(0) {}
    NODE(int __l, int __r): l(__l), r(__r) {}
};


//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<NODE> vn;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n, b, x, y;

//=====================================
//Functions and procedures
//Main Procedure
int main()
{
    while(scanf("%d%d", &n, &b), (n || b))
    {
        vn mylist(n+2);

        FOR(i, 1, n) mylist[i] = NODE(i-1, (i+1)%(n+1));

        //FOR(i, 1, n) cout << i << ": " << mylist[i].l << " - " << mylist[i].r << el;

        FOR(i, 1, b)
        {
            scanf("%d%d", &x, &y);

            if(mylist[x].l) cout << mylist[x].l << sp;
            else cout << "* ";

            if(mylist[y].r) cout << mylist[y].r << el;
            else cout << "*\n";

            mylist[mylist[x].l].r = mylist[y].r;
            mylist[mylist[y].r].l = mylist[x].l;
        }

        puts("-");
    }
    return 0;
}
