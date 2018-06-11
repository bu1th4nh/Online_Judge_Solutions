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
typedef vector<int> vi;
typedef stack<int> si;
typedef stack<ll> sll;
si stck;
sll val;
ll cnt;
int n;

//=====================================
//Functions and procedures
//Main Procedure
int main()
{
    cin >> n;
    cnt = 0;
    FORi(1, n)
    {
        int x;
        cin >> x;
        int k = 1;
        while (!stck.empty() && x>=stck.top())
        {
            cnt+=val.top();
            if(x==stck.top()) k+=val.top();
            stck.pop();
            val.pop();
        }
        if(!stck.empty()) ++cnt;
        stck.push(x);
        val.push(k);
    }
    cout << cnt;
    return 0;
}
