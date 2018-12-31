/*==========================================================================================*\
**                        _           _ _   _     _  _         _                            **
**                       | |__  _   _/ | |_| |__ | || |  _ __ | |__                         **
**                       | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                        **
**                       | |_) | |_| | | |_| | | |__   _| | | | | | |                       **
**                       |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                       **
\*==========================================================================================*/
//=====================================
//Brief
/*      Date/Time:  Tue 11:35PM 2018/12/3
*/
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
const int inf = 1999999000;


//=====================================
//Typedefs
//mt19937_64 GEN(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<size_t> die(1, 1LL << 60);
template<class T> class Treap
{
    typedef long long ll;
    struct Node
    {
        T val;
        ll prior, sz;

        Node* l;
        Node* r;

        Node(T value = T())
        {
            sz = 1;
            l = r = 0;
            val = value;
            prior = ((rand() % (1 << 15)) << 16) + (rand() % (1 << 15));
        }
        void update()
        {
            sz = 1;
            if(l) sz += l->sz;
            if(r) sz += r->sz;
        }
        ~Node()
        {
            delete l;
            delete r;
        }
    };
    typedef Node* pnode;
    pnode root;
    ll get_sz(pnode t)
    {
        return t ? t->sz : 0;
    }



    //Split and merge
    void split(pnode t, T val, pnode &l, pnode &r)
    {
        if(!t)
        {
            l = r = 0;
            return;
        }
        else if(t->val < val)       //Expand to right subtree
        {
            split(t->r, val, t->r, r);      //t->r = l;
            l = t;
        }
        else                        //Expand to left subtree
        {
            split(t->l, val, l, t->l);      //t->l = r;
            r = t;
        }
        t->update();
    }
    pnode merge(pnode l, pnode r)
    {
        if(!l || !r) return l ? l : r;
        else if(l->prior < r->prior)
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

    //Find
    bool find_util(pnode t, T val)
    {
        if(!t) return 0;
        if(t->val == val) return 1;
        return (val < t->val) ? find_util(t->l, val) : find_util(t->r, val);
    }
    T val_of_idx(pnode t, ll i)
    {
        ll lsz = t->l ? t->l->sz : 0;
        if(i == lsz) return t->val;
        return (i < lsz) ? val_of_idx(t->l, i) : val_of_idx(t->r, i - lsz - 1);
    }
    void show(pnode x)
    {
        if(!x) return;

        show(x->l);
        cerr << x->val << sp;
        show(x->r);
    }

public:
    void insert(T val)
    {
        if(find_util(root, val)) return;
        pnode l; pnode r;
        split(root, val, l, r);
        root = merge(merge(l, new Node(val)), r);
    }
    void erase(T val)
    {
        if(!find_util(root, val)) return;

        pnode t; pnode l; pnode r;
        split(root, val, l, t);
        split(root, val+1, t, r);

        delete t;
        root = merge(l, r);
    }
    ll order_of_key(T val)
    {
        pnode l, r;
        split(root, val, l, r);
        ll ret = get_sz(l);
        root = merge(l, r);
        return ret;
    }
    T find_by_order(ll ord)
    {
        if(ord > get_sz(root)) return -inf;
        return val_of_idx(root, ord-1);
    }
    void debug()
    {
        show(root);
    }
    ll size()
    {
        return get_sz(root);
    }


    Treap()
    {
        root = 0;
        srand(time(NULL));
    }
};




//=====================================
//Typedefs


//=====================================
//Mains
int main()
{
    Treap<int> ct;


    int Q, x;
    char t;
    scan(Q);

    while(Q--)
    {
        scanf("\n%c", &t);
        scan(x);
        if(t == 'I')
        {
            ct.insert(x);
        }
        else if(t == 'D')
        {
            ct.erase(x);
        }
        else if(t == 'K')
        {
            x = ct.find_by_order(x);
            if(x != -inf)
            {
                print(x);
                putchar(el);
            }
            else puts("invalid");
        }
        else if(t == 'C')
        {
            print(ct.order_of_key(x));
            putchar(el);
        }
//        else if(t == 'DEBUG')
//        {
//            ct.debug();
//        }
//        else if(t == 'SZ')
//        {
//            cout << ct.size() << el;
//        }
    }

    return 0;
}

//=============================================================================//
/**    CTB, you are always in my heart and in my code <3       #30yearsCTB    **/
//=============================================================================//
