//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
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
#define MODUL (int)(10e9+57)
#define len(x) (int)(x.length())
#define siz(x) (int)(x.size())
#define whole(x) x.begin(), x.end()
#define FORi(x, y) for(int i=x; i<=y; ++i)
#define FORj(x, y) for(int j=x; j<=y; ++j)
#define FORk(x, y) for(int k=x; k<=y; ++k)
#define FORli(x, y) for(int i=x; i<y; ++i)
#define FORbi(x, y) for(int i=x; i>=y; --i)
#define FORlbi(x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef long long ll;
ll a[1000000];
int n;


//=====================================
//Functions and procedures

ll Gen(ll x)
{
    vector<int> t;
    while(x>0)
    {
        int val = x%10;
        t.push_back(val);
        x/=10;
    }
    sort(whole(t));
    int tmp = 0;
    FORli(0, siz(t))
    {
        tmp = tmp*10 + t[i];
    }
    return tmp;
}

int main()
{
    a[1] = 1;
    FORi(2, 50) a[i] = Gen(a[i-1]*2);
    //FORi(1, 50) cerr << a[i] << endl;
    cin >> n;
    if(n<=25) cout << a[n] << endl;
    else cout << a[25 + n%6];
    return 0;
}
