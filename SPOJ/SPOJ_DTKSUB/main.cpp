/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
//=====================================
//Solution Briefing - Foreword



//=====================================
//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
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

//#define DEBUG
#define OPTIONAL_FEATURE

//=====================================
//Macroes
#define sp ' '
#define el '\n'
#define task ""
#define maxinp ()
#define fi first
#define se second
#define pb push_back
#define whole(x) x.begin(),x.end()
#define whole_1(x) x.begin()+1,x.end()
#define r_whole(x) x.rbegin(),x.rend()
#define FOR(i, x, y) for(auto i=x; i<=y; ++i)
#define FORl(i, x, y) for(auto i=x; i<y; ++i)
#define FORb(i, x, y) for(auto i=x; i>=y; --i)
#define FORlb(i, x, y) for(auto i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP()                        \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
}
#define FILEOP_DEBUG()                  \
{                                       \
    freopen(task".inp", "r", stdin);    \
    freopen(task".out", "w", stdout);   \
    freopen(task".err", "w", stderr);   \
}

//Macroes - Optional
#ifdef OPTIONAL_FEATURE
    #define pc(x) putchar(x)
    #define gc() getchar()
#endif



//=====================================
//Auxilary Functions and Fast I/O
#ifdef OPTIONAL_FEATURE
    template<class T, class R> T max(T &x, R &y)
    {
        return x > y ? x : y;
    }
    template<class T, class R> T min(T &x, R &y)
    {
        return x < y ? x : y;
    }
    template<class T, class R> void maximize(T &x, R y)
    {
        x = x > y ? x : y;
    }
    template<class T, class R> void minimize(T &x, R y)
    {
        x = x < y ? x : y;
    }
    template<class T> int getBit(T &x, int i)
    {
        return ((x >> i) & 1) == 1;
    }
    template<class T> T __abs(T &x)
    {
        return (x = (x < 0) ? -x : x);
    }
#endif
//Fast I/O
template<class T> inline void read(T &ret)
{
    ret = T();
    char c = 0;
    bool neg = 0;

    while(isdigit(c) == 0 && c != '-') c = getchar();
    if(c == '-')
    {
        neg = 1;
        c = getchar();
    }

    for(; isdigit(c) != 0; c = getchar()) ret = ret * 10 + c - '0';
    ret = (neg) ? -ret : ret;

    #ifdef DEBUG
        cerr << "FastScan Diagnostic: " << ret << el;
    #endif
}
template<class T> void print(T x)
{
    if(x < 0)
    {
        putchar('-');
        x *= -1;
    }

    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

//=====================================
//Constants



//=====================================
//Typedefs
class SuffixArray
{
    typedef pair<int, int> ii;
    typedef vector<int> vi;

    int MAX_CHARACTER;

    string t;
    int n, m;

    vi RA, tempRA;                                                  //Rank array and temporary RA
    vi SA, tempSA;                                                  //Suffix array and temporary SA
    vi CntSortArr;                                                  //For radix / counting sort

    vi phi;                                                         //To remember which suffix is behind i-th suffix, to compute LCP
    vi PLCP;                                                        //Permuted LCP array
    vi LCP;                                                         //Longest Common Prefix between suffix T+SA[i-1] and current suffix T+SA[i]


    void CountingSort(int k)
    {
        int sum = 0;
        CntSortArr = vi(MAX_CHARACTER+5, 0);
        FORl(i, 0, n)
        {
            CntSortArr[ (i + k < n) ? RA[i+k] : 0 ]++;              //Count the frequency of each integer rank
        }
        FORl(i, 0, MAX_CHARACTER)
        {
            int t = CntSortArr[i];
            CntSortArr[i] = sum;
            sum += t;
        }
        FORl(i, 0, n)                                               //Shuffle the SA if necessary
        {
            tempSA[CntSortArr[(SA[i]+k < n) ? RA[SA[i]+k] : 0]++] = SA[i];
        }
        SA = tempSA;                                                //Update the SA
    }
    void initSA()
    {
        int k, r;
        FORl(i, 0, n) RA[i] = t[i];                                 //Initial Rankings array: RA[i] = t[i]
        FORl(i, 0, n) SA[i] = i;                                    //Initial SA: {0, 1, 2,..., n-1}
        for(int k = 1; k < n; k <<= 1)
        {
            CountingSort(k);                                        //Radix Sort: Sort based on the 2nd item
            CountingSort(0);                                        //then stable sort based on the 1st item
            tempRA[SA[0]] = r = 0;                                  //Re-ranking, start from 0;
            FORl(i, 1, n)
            {
                tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
                //If same pair => same rank r. Otherwise increase r
            }
            RA = tempRA;
            if(RA[SA[n-1]] == n-1) break;
        }


        #ifdef DEBUG
            FORl(i, 0, n) cerr << SA[i] << sp; cerr << el;
        #endif // DEBUG
    }
    void initLCP()
    {
        int L = 0;
        phi[SA[0]] = -1;                                            //Default value
        FORl(i, 1, n) phi[SA[i]] = SA[i-1];
        //Remember which suffix is behind this suffix

        FORl(i, 0, n)
        {
            if(phi[i] == -1)
            {
                PLCP[i] = 0;
                continue;
            }
            while(t[i+L] == t[phi[i]+L]) ++L;                       //L increased max n times
            PLCP[i] = L; L = max(L-1, 0);                           //L decreased max n times
        }

        FORl(i, 0, n) LCP[i] = PLCP[SA[i]];                         //Compute LCP in O(n)

        #ifdef DEBUG
        FORl(i, 0, n) cerr << LCP[i] << sp; cerr << el;
        #endif // DEBUG
    }

public:
    vi extractSA()
    {
        return SA;
    }
    vi extractLCP()
    {
        return LCP;
    }


    ~SuffixArray() {}

    SuffixArray() {}
    SuffixArray(string s)
    {
        t = s;
        n = s.size();
        MAX_CHARACTER = max(n, 256);

        RA = tempRA = vi(n, 0);
        SA = tempSA = vi(n, 0);
        phi = LCP = PLCP = vi(n, 0);

        initSA();
        initLCP();
    }
};



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
int n, k, res;
string s;
vi LCP;


//=====================================
//Functions and procedures
//File I/O and utilities
void FileInit()
{
    FILEOP()
}
void FileDebug()
{
    #ifdef DEBUG
        FILEOP_DEBUG()
    #else
        FILEOP()
    #endif
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}


//Enter
void Enter()
{
    char str[65536];
    scanf("%d%d", &n, &k);
	scanf("%s", &str); s = string(str) + '$';
}

//Check
bool check(int len)
{
    int run = 0, maxi = 0;
    FORl(i, 1, s.size())
    {
        if(LCP[i] < len) run = 1;
        else ++run;

        maximize(maxi, run);
    }

    return (maxi >= k);
}

//Process
void Solve()
{
    SuffixArray ctb(s);
    LCP = ctb.extractLCP();
    int l = 1, r = n, mid = 0;

    while(l <= r)
    {
        mid = (l + r) / 2;
        if(check(mid))
        {
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << res << el;
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
