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


//=====================================
//Typedef
struct coin
{
    int a, b, id;
    bool operator < (const coin &other) const
    {
        return this->a < other.a;
    }
};
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<coin> vc;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
vb take;
vc vect;
ll res;
int n;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
	scanf("%d", &n);

	take = vb(n, false);
	vect = vc(n);

	FORl(i, 0, n) vect[i].id = i + 1;
	FORl(i, 0, n) scanf("%d", &vect[i].a);
	FORl(i, 0, n) scanf("%d", &vect[i].b);
}

//Process
void Solve()
{
    sort(whole(vect));
    priority_queue<ii> pq;

    FORl(i, 0, n)
    {
        pq.push(ii(vect[i].b, i));
        if(i % 2 == 0)
        {
            ii x = pq.top(); pq.pop();
            res += (ll)x.first;
            take[x.second] = true;
        }
    }

    printf("%lld\n", res);
    stack<int> st;

    FORl(i, 0, n)
    {
        if(take[i]) st.push(vect[i].id);
        else
        {
            printf("%d %d\n", vect[i].id, st.top());
            st.pop();
        }
    }
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
