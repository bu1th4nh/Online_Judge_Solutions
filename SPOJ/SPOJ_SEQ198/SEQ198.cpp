/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
/*                                  Solution Brief

    Step 1: Firstly, sort the sequence

    Step 2: Dynamic Programming:

            - F[i][j]: The maximum length of SEQ198 up to position i, which have state j.
            - j: Bit state of the chosen sequence, denotes if number a[i] - k is chosen,
            the k-th bit of binary representation of j is set to 1, and 0 otherwise.


     We have the following observation:

            - Since the sequence only restrict seq[i]-1, seq[i]-8, seq[i]-9 with all of the element
            so we can simply ignore all value less than seq[i]-10. Thus we only have 2^10 corresponding
            state from seq[i]-9 to seq[i]. And there is no other way than iterate through all state.

            - An element X in order to be chosen to the sequence need to satisfy that there is no
            element already in sequence equal X-1, X-9 and X-8.

    So, we have the following formula:

            F[i][j'] = max(F[i][j'] , F[i-1][j]) if we don't choose a[i]

            F[i][j' | 1] = max(F[i][j' | 1], F[i-1][j] + 1 if we choose a[i] which satisfy

                               j' & (1 << 1 | 1 << 9 | 1 << 8) = 0.


        In this formula:
                j': The new state generated from j - Left-shift j by (a[i] - a[i-1]) bits
                Because there's no element between a[i] and a[i-1]

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
#define task "SEQ198"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin()+1, x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


const int contd = (1 << 1) | (1 << 8) | (1 << 9);
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
vi a, dp, sub_dp;
int n;

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

//Enter
void Enter()
{
    scanf("%d", &n);

    dp = sub_dp = vi(1024, -1);
    a = vi(n+1, 0);

    FOR(i, 1, n) scanf("%d", &a[i]);
    sort(whole(a));
}

//Process
void Solve()
{
    int d = 0;
    dp[0] = 0;
    dp[1] = 1;

    FOR(i, 2, n)
    {
        d = a[i] - a[i-1];

        sub_dp = vi(1024, -1);
        FOR(state, 0, 1023) if(dp[state] >= 0)
        {
            int new_state = (d >= 10) ? 0 : ((state << d) & 1023);
            sub_dp[new_state] = max(sub_dp[new_state], dp[state]);

            if((new_state & contd) == 0)            //You need to isolate this expression.
            {
                sub_dp[new_state | 1] = max(sub_dp[new_state | 1], dp[state] + 1);
            }
        }

        dp = sub_dp;
    }

    cout << n - *max_element(whole(dp));
}



//Main Procedure
int main()
{
    FileInit();
    Enter();
    Solve();
    return 0;
}
