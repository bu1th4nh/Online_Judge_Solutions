//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp (int)(123456)
#define MODUL (int)(1e9+57)
#define len(x) (int)(x.length())
#define siz(x) (int)(x.size())
#define fi first
#define se second
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef pair<int, int> ii;
typedef vector<ii> vii;
int F[maxvalueinp];
int n, res;
vii vect;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    scanf("%d", &n);
    vect.push_back(make_pair(-1, -1));
    int a, b;
    FOR(i, 1, n)
    {
        scanf("%d%d", &a, &b);
        vect.push_back(make_pair(a, b));
    }
    vect.push_back(ii(1234567890, 1234567890));
}

void Debug()
{
    cout << endl;
    FOR(i, 0, n) cout << vect[i].se << " " << vect[i].fi << endl;
    cout << endl;
}


//Process
void Solve()
{
    MEMS(F, 0);

    //Debug();

    sort(whole(vect));

    FOR(i, 1, n+1)
    {
        FOR(j, 0, i-1)
        {
            if(vect[j].se <= vect[i].fi && F[i] < F[j] + vect[i].se - vect[i].fi) F[i] = F[j] + vect[i].se - vect[i].fi;
        }
    }
    printf("%d", F[n+1]);
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
