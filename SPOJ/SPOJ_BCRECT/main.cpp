//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp (int)()
#define MODUL (int)(1e9+57)
#define len(x) (int)(x.length())
#define siz(x) (int)(x.size())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef long long ll;
typedef vector<int> vi;
typedef stack<int> si;
vi vect, L, R;
int m, n;
si stck;
ll res;

//=====================================
//Functions and procedures
//Input
void Input()
{
    vect.push_back(-999);
    scanf("%d%d", &m, &n);
    FOR(i, 1, n)
    {
        int x;
        scanf("%d", &x);
        vect.push_back(x);
    }
    vect.push_back(0);
    vect.push_back(0);
    L.resize(n+5);
    R.resize(n+5);
}


//Check
void PrepLR()
{
    L.assign(L.size(), 0);
    R.assign(R.size(), 0);

    L[1] = 0;
    stck.push(0);
    stck.push(1);
    FOR(i, 2, n)
    {
        while(stck.size()>1 && vect[stck.top()]>=vect[i]) stck.pop();
        L[i] = stck.top();
        stck.push(i);
    }

    while(!stck.empty()) stck.pop();

    R[n+1] = 0;
    R[n] = n+1;
    stck.push(n+1);
    stck.push(n);
    FORb(i, n-1, 1)
    {
        while(stck.size()>1 && vect[stck.top()]>=vect[i]) stck.pop();
        R[i] = stck.top();
        stck.push(i);
    }

    while(!stck.empty()) stck.pop();
}



//Process
void Process()
{
    PrepLR();

    res = -1;

    FOR(i, 1, n) res = max(res, 1LL*vect[i]*(R[i] - L[i] - 1));

    FOR(i, 1, n) vect[i] = m - vect[i];

    PrepLR();

    FOR(i, 2, n) res = max(res, 1ll*vect[i]*(R[i] - L[i] - 1));

    printf("%lld", res);
}


//Output





//Main Procedure
int main()
{
    Input();
    Process();
    return 0;
}
