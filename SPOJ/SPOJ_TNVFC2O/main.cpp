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
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)

//=====================================
//Typedef
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vii Count;
int n, k;
vi vect;
int res;

//=====================================
//Functions and procedures
//Enter
void Enter()
{
    int x;
    scanf("%d%d", &n, &k);
    FOR(i, 1, n)
    {
        scanf("%d", &x);
        vect.push_back(x);
    }
}

//Process
void Solve()
{
    sort(whole(vect));

    int cnt = 1, val = vect[0];
    FORl(i, 1, n)
    {
        if(val != vect[i])
        {
            Count.push_back(ii(val, cnt));
            cnt = 1;
            val = vect[i];
        }
        else ++cnt;
    }
    Count.push_back(ii(val, cnt));
    FORl(i, 0, Count.size())
    {
        ii x = Count[i];
        if(x.second != k)
        {
            res = x.first;
            printf("%d", res);
            return;
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
