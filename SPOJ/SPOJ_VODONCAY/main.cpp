/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
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

#if __cplusplus >= 201103L
#include <unordered_map>
#include <unordered_set>
#include <random>
#endif // __cplusplus

using namespace std;


//=====================================
//Macroes
#define sp " "
#define el "\n"
#define task "DONCAY"
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
#define FILEOP_STDOUT()                         \
{                                               \
    freopen(task".inp", "r", stdin);            \
} 
#define FILEOP()                                \
{                                               \
    freopen(task".inp", "r", stdin);            \
    freopen(task".out", "w", stdout);           \
}                               
#define FILEOP_DEBUG()                          \
{                                               \
    freopen(task".inp", "r", stdin);            \
    freopen(task".out", "w", stdout);           \
    freopen(task".err", "w", stderr);           \
}                                               




//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef deque<int> dqi;
vi a, R, L, dp, res2, trace, trace_2;
int n, res1;
vvi end_at;


//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP()
}
void FileDebug()
{
    FILEOP_DEBUG()
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}
template<class T> inline void read(T &ret)
{
    bool neg = 0;
    char c = 0;
    ret = T();

    while(c != '-' && isdigit(c) == 0) c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    if(neg) ret *= -1;
}
template<class T> void write(T x)
{
    if(x < 0)
    {
        putchar('-');
        x *= -1;
    }

    if(x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

//Enter
void Enter()
{
    read(n);
    trace = trace_2 = vi(n+1, 0);
    a = L = R = vi(n+1, 0);
    end_at = vvi(n+1);
    dp = vi(n+1, n+1);

    FOR(i, 1, n) read(a[i]);
}

//Process
void Preps()
{
    stack<int> st;
    FOR(i, 1, n)
    {
        L[i] = i;
        while(!st.empty() && st.top() >= i - a[i] + 1)
        {
            L[i] = min(L[i], L[st.top()]);
            st.pop();
        }
        st.push(i);
    }
    //cerr << "L is:  ";FOR(i, 1, n) cerr << L[i] << sp; cerr << el;


    while(!st.empty()) st.pop();
    FORb(i, n, 1)
    {
        R[i] = i;
        while(!st.empty() && st.top() <= i + a[i] - 1)
        {
            R[i] = max(R[i], R[st.top()]);
            st.pop();
        }
        st.push(i);
    }
    //cerr << "R is:  ";FOR(i, 1, n) cerr << R[i] << sp; cerr << el;
}
void Solve()
{
    FOR(i, 1, n) dp[i] = i, trace[i] = -i; 
    stack<int> st;

    dp[0] = 0;
    FOR(i, 1, n)
    {
        if(dp[i] > dp[L[i] - 1] + 1) 
        {
            dp[i] = dp[L[i]-1] + 1;
            trace[i] = -L[i];
        }

        while(!st.empty() && R[st.top()] < i) st.pop();
        if(!st.empty() && dp[i] > dp[st.top()-1] + 1)
        {
            dp[i] = dp[st.top()-1] + 1;
            trace[i] = st.top();
        }
        if(st.empty() || dp[st.top()-1] > dp[i-1]) st.push(i);
    }

    //cerr << "dp is: "; FOR(i, 1, n) cerr << dp[i] << sp; cerr << el;
    
    //cerr << "trace is: "; FOR(i, 1, n) cerr << trace[i] << sp; cerr << el;
    //cerr << "trace_2 is: "; FOR(i, 1, n) cerr << trace_2[i] << sp; cerr << el;

    int i = n;
    while(i)
    {
        int x = trace[i] < 0 ? -i : trace[i];
        res2.push_back(x);
        i = abs(trace[i]) - 1;
    }
    reverse(whole(res2)); 
    

    write(dp[n]); putchar('\n');
    for(int x: res2)
    {
        write(x);
        putchar(' ');
    }
}


//Main Procedure
int main()
{
    //FILEOP_STDOUT();
    Enter();
    Preps();
    Solve();
    return 0;
}
