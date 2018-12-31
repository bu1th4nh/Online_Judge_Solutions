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

// #define DEBUG
// #define OPTIONAL_FEATURE

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
//Suffix Arrays
struct SuffixArray
{
    typedef pair<int, int> ii;
    typedef vector<int> vi;

    int MAX_CHARACTER;

    string t;
    int n, m;

    vi RA, tempRA;                                                  //Rank array and RA temporary
    vi SA, tempSA;                                                  //Suffix array and SA temporary
    vi CntSortArr;                                                  //For radix sort

    vi phi;                                                         //For computing LCP
    vi PLCP;                                                        //Permuted LCP
    vi LCP;                                                         //LCP[i]: Least Common Prefix between suffix T+SA[i-1] and current suffix T+SA[i]

    void countingSort(int k)
    {
        int sum = 0;
        CntSortArr = vi(MAX_CHARACTER+5, 0);
        FORl(i, 0, n)
        {
            CntSortArr[ (i + k < n) ? RA[i + k] : 0 ]++;            //Count the frequency of each integer rank
        }

//        FORl(i, 0, MAX_CHARACTER) if(CntSortArr[i]) cerr << i << "-" << CntSortArr[i] << sp;
//        cerr << el;

        FORl(i, 0, MAX_CHARACTER)
        {
            int t = CntSortArr[i];
            CntSortArr[i] = sum;
            sum += t;
        }
        FORl(i, 0, n)                                               //Shuffle the SA if necessary
        {
//            cerr << ((SA[i]+k < n ? RA[SA[i]+k] : 0)) << el;
            tempSA[CntSortArr[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
        }

//        FORl(i, 0, n) cerr << tempSA[i] << sp; cerr << el;


        SA = tempSA;                                                //Update the SA
    }
    void initSA()
    {
        int k, r;
        FORl(i, 0, n) RA[i] = t[i];                                 //Initial Rankings
        FORl(i, 0, n) SA[i] = i;                                    //Initial SA: {0, 1, 2,..., n-1}
        for(k = 1; k < n; k <<= 1)
        {
            countingSort(k);                                        //Radix Sort: Sort based on the 2nd item
            countingSort(0);                                        //then stable sort based on the 1st item
            tempRA[SA[0]] = r = 0;                                  //Re-ranking, start from 0.
            FORl(i, 1, n)
            {
                tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
                //If same pair => same rank r; otherwise increase r;
            }
            RA = tempRA;
            if(RA[SA[n-1]] == n-1) break;
        }
    }
    void initLCP()
    {
        int L = 0;
        phi[SA[0]] = -1;                                            //Default value
        FORl(i, 1, n) phi[SA[i]] = SA[i-1];                         //Compute phi in O(n)
        //Remember which suffix is behind this suffix

        FORl(i, 0, n)                                               //Compute Permuted LCP in O(n)
        {
            if(phi[i] == -1)                                        //Special case
            {
                PLCP[i] = 0;
                continue;
            }
            while(t[i+L] == t[phi[i]+L]) ++L;                       //L increased max n times
            PLCP[i] = L; L = max(L-1, 0);                           //L decreased max n times
        }

        FORl(i, 0, n) LCP[i] = PLCP[SA[i]];                         //Compute LCP in O(n)
        FORl(i, 0, n) cerr << LCP[i] << sp; cerr << el;

        //Put the permuted LCP to the correct position
    }
    int stringMatching(string p)
    {
        m = p.size();
        int l = 0, r = n-1, mid = l;
        while(l < r)                                                //Find lower bound
        {
            mid = (l + r) / 2;
            int res = strncmp(t.c_str() + SA[mid], p.c_str(), m);   //Try to find P in suffix 'mid'
            if(res >= 0) r = mid;
            else     l = 1 + mid;
        }
        if(strncmp(t.c_str() + SA[l], p.c_str(), m)) return 0;      //If not found


        ii ret; ret.first = l;
        l = 0, r = n-1, mid = l;
        while(l < r)                                                //If the lower bound is found, find upper bound
        {
            mid = (l + r) / 2;
            int res = strncmp(t.c_str() + SA[mid], p.c_str(), m);
            if(res > 0) r = mid;
            else    l = 1 + mid;
        }
        if(strncmp(t.c_str() + SA[r], p.c_str(), m)) --r;           //Special case
        ret.second = r;

        return ret.second - ret.first + 1;
    }
    int LRS()
    {
        int maxLCP = -1, idx = -1;
        FORl(i, 1, (int)LCP.size())
        {
            if(LCP[i] > maxLCP) idx = i, maxLCP = LCP[i];
        }
        return (maxLCP <= 0) ? -1 : idx;
    }
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
    SuffixArray(string S)
    {
        t = S;
        n = S.size();
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
int nTests;
vi SA, LCP;


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


//Process
void Solve()
{
    int idx = 0;
    string s, t;
    char str[1024];

    scanf("%s", &str); s = string(str) + '$';
    SuffixArray sa(s);
    SA = sa.extractSA();
    LCP = sa.extractLCP();

    //for(int x: LCP) cerr << x << sp; cerr << el;

    idx = sa.LRS();
    if(idx <= 0)
    {
        puts("No repetitions found!");
        return;
    }
    else
    {
        t = s.substr(SA[idx], LCP[idx]);
        printf("%s %d\n", t.c_str(), sa.stringMatching(t));
    }
}



//Output
void MULTi()
{
    read(nTests);
    while(nTests--)
    {
        Solve();
    }
}

//Main Procedure
int main()
{
    MULTi();
    return 0;
}

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
