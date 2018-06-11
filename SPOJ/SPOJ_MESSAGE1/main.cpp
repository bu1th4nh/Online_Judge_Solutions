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
#define maxinp (int)(10069)
#define MODUL (int)(1e9+57)
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef stack<int> si;
typedef long long ll;
int a[maxinp][maxinp];
string src[maxinp];
string dst[maxinp];
int nTest, m, n;
ll res;

//=====================================
//Functions and procedures
//Initialization and preparation
void IOOpt()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

//Enter
void Enter()
{
    res = -INFINITY;
    scanf("%d%d", &m, &n);
    //cin >> m >> n;
    FOR(i, 1, m)
    {
        cin >> src[i];
        src[i] = '0' + src[i];
    }
    FOR(i, 1, m)
    {
        cin >> dst[i];
        dst[i] = '0' + dst[i];
    }
}

//Check
void Teleport(int x, int y)
{
    FOR(i, 0, m) FOR(j, 0, n) a[i][j] = 0;
    FOR(i, max(1, x+1), min(m, m+x))
    {
        FOR(j, max(1, y+1), min(n, n+y))
        {
            a[i][j] = (src[i-x][j-y] == dst[i][j]) ? 1 : 0;
        }
    }
}

//Process
ll Compute(int x, int y)
{
    vi L(maxinp, 0);
    vi R(maxinp, 0);
    vi H(maxinp, 0);
    ll tmp = -INFINITY;
    H[0] = -1;
    H[n+1] = -1;


    /*
    int hi = min(m, m+x);
    int hj = min(n, n+y);
    int li = max(0, x);
    int lj = max(0, y);
    H[hj+1] = -1;
    H[lj-1] = -1;
    FORl(i, li, hi)
    {
        si st;
        FORl(j, lj, hj)
        {
            if(a[i][j] == 1)
            {
                ++H[j];
                while(!st.empty() && H[st.top()] >= H[j]) st.pop();
                if(st.empty()) L[j] = lj - 1;
                else st.push(j);
            }
            else
            {
                while(!st.empty()) st.pop();
                st.push(j);
            }
        }
        while(!st.empty()) st.pop();
        int r;
        FORb(j, hj-1, lj)
        {
            if(H[j])
            {
                while(!st.empty() && H[st.top()] >= H[j]) st.pop();
                if(st.empty()) r = hj;
                else r = st.top();
                tmp = max(tmp, 1LL*H[j]*(r - L[j] - 1));
                st.push(j);
            }
            else
            {
                while(!st.empty()) st.pop();
                st.push(j);
            }
        }
    }
    */


    ///*
    FOR(i, 1, m)
    {
        FOR(j, 1, n)
        {
            H[j] = a[i][j]*(H[j] + 1);
        }
        FOR(j, 1, n)
        {
            L[j] = j;
            while(H[L[j]-1] >= H[j]) L[j] = L[L[j]-1];
        }
        FORb(j, n, 1)
        {
            R[j] = j;
            while(H[R[j]+1] >= H[j]) R[j] = R[R[j]+1];
        }
        FOR(j, 1, n)
        {
            tmp = max(tmp, 1LL*H[j]*(R[j] - L[j] + 1));
        }
    }
    //*/


    return tmp;
}

void Solve()
{
    FOR(i, 1-m, m-1)
    {
        FOR(j, 1-n, n-1)
        {
            Teleport(i, j);
            res = max(res, Compute(i, j));
        }
    }
    printf("%lld\n", res);
}


//Output
void Multitest()
{
    Enter();
    Solve();
}


//Main Procedure
int main()
{
    scanf("%d", &nTest);
    //IOOpt();
    while(nTest--)
    {
        Multitest();
    }
    return 0;
}
