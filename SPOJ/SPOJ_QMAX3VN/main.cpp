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
#include <chrono>
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
template<class T> inline void scan(T &ret)
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
mt19937_64 PRNG(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> die(1, 100000007);
template<class T> class ImplicitTreap
{
private:

    //Node implementation
    struct Node
    {
        Node *l, *r;
        T val, tagret;
        int sz, priority;

        Node(T __val = T())
        {
            sz = 1;
            l = r = 0;
            val = tagret = __val;
            priority = die(PRNG);
        }
        ~Node()
        {
            delete l;
            delete r;
        }

        void update()
        {
            sz = 1;
            tagret = val;
            if(l != NULL)
            {
                sz += l->sz;
                tagret = max(tagret, l->tagret);
            }
            if(r != NULL)
            {
                sz += r->sz;
                tagret = max(tagret, r->tagret);
            }
        }
    };
    typedef Node* pnode; pnode root; //Root initialization
    int get_sz(pnode t) {return t ? t->sz : 0;}

    //Split and merge
    void split(pnode t, pnode &l, pnode &r, int pos, int add = 0)
    {
        if(!t) return void(l = r = NULL);
        int cur_pos = add + get_sz(t->l);
        if(cur_pos <= pos)
        {
            split(t->r, t->r, r, pos, cur_pos+1),
            l = t;
        }
        else
        {
            split(t->l, l, t->l, pos, add),
            r = t;
        }
        t->update();
    }
    pnode merge(pnode l, pnode r)
    {
        if((!l) || (!r)) return l != NULL ? l : r;
        else if(l->priority > r->priority)
        {
            l->r = merge(l->r, r);
            l->update();
            return l;
        }
        else
        {
            r->l = merge(l, r->l);
            r->update();
            return r;
        }
    }
    void dfs(pnode n)
    {
        if(!n) return;
        if(n->l) dfs(n->l);
        cerr << n->val << sp << n->tagret << el;
        if(n->r) dfs(n->r);
    }

public:
    void insert(T x, int i)
    {
        Node *l, *r;
        split(root, l, r, i-2);
        root = merge(merge(l, new Node(x)), r);
    }
    T query(int ql, int qr)
    {
        Node *L1, *R1, *L2, *R2;

        split(root, L1, R1, ql - 2);
        split(R1, L2, R2, qr - ql);


//        fprintf(stderr, "Size of L1 = %d, Size of L2 = %d, Size of R2 = %d\n", get_sz(L1), get_sz(L2), get_sz(R2));
//        fprintf(stderr, "Query from %d to %d, with key from %d to %d: ", ql, qr, ql-2, qr-1);


        T ret = L2->tagret;
        root = merge(L1, merge(L2, R2));
        root->update();
        return ret;
    }
    void show()
    {
        dfs(root);
    }

    ImplicitTreap()
    {
        root = 0;
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
int nQuery, val, x, y;
char t;

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

//Main Procedure
int main()
{
    ImplicitTreap<int> ict;
    scan(nQuery);
    while(nQuery--)
    {
        scanf("\n%c", &t);
        if(t == 'A' || t == 'Q')
        {
            scan(x);
            scan(y);
        }

        if(t == 'A') ict.insert(x, y);
        else if(t == 'Q') print(ict.query(x, y)), putchar(el);
        else if(t == 'D')
        {
            cerr << "----------------\n";
            ict.show();
            cerr << "----------------\n";
        }
    }
    return 0;
}

/*
8
A 3 1
A -7 2
A 1 1
A 3 2
A 6 5
Q 1 6
Q 1 4
Q 4 4
*/

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
