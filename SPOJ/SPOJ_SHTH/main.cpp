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
#define task ""
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
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


//=====================================
//Big Integers
struct BigInt
{
    //Constants, typedefs and variables
    typedef vector<int> vi;
    typedef long long ll;

    const int MAX_DIGIT = 100;
    const int LOG_BASE  = 4;
    const int BASE      = 10000;

    int n;
    vi d;

    //Constructor and destructor
    ~BigInt() {}
    BigInt()
    {
        d = vi(MAX_DIGIT, 0);
        n = 0;
    }


    //Operators
    void operator= (const BigInt &other)
    {
        this->n = other.n;
        this->d = other.d;
    }
    void operator= (const ll &a)
    {
        BigInt ret;
        for(ll t = a; t != 0LL; t /= BASE) ret.d[ret.n++] = t % BASE;
        *this = ret;
    }
    bool operator< (const BigInt &other) const
    {
        BigInt a = *this;
        BigInt b = other;

        if(a.n != b.n) return (a.n < b.n);
        FORb(i, a.n - 1, 0)
        {
            if(a.d[i] < b.d[i]) return 1;
            else if(a.d[i] > b.d[i]) return 0;
        }
        return 0;
    }
    BigInt operator+ (const BigInt &other)
    {
        BigInt a = *this;
        BigInt b = other;

        BigInt ret;
        int rem = 0, p = 0;
        ret.n = max(a.n, b.n);

        FORl(i, 0, ret.n)
        {
            p = a.d[i] + b.d[i] + rem;
            if(p > BASE) ret.d[i] = p - BASE, rem = 1;
            else ret.d[i] = p, rem = 0;
        }
        if(rem) ret.d[ret.n++] = rem;

        return ret;
    }
    void operator += (const BigInt &other)
    {
        *this = *this + other;
    }
    void operator -= (const BigInt &other)
    {
        int rem = 0, p = 0;

        FORl(i, 0, this->n)
        {
            p = this->d[i] - other.d[i] - rem;
            if(p < 0) this->d[i] = p + BASE, rem = 1;
            else this->d[i] = p, rem = 0;
        }
        while(this->n > 0 && this->d[n-1] == 0) --n;
    }

    //Input - Output operators
    void scan()
    {
        BigInt c;
        char str[10000]; scanf("%s", &str);
        string s(str);

        reverse(whole(s));
        int l = s.length();

        for(c.n = 0; c.n * LOG_BASE < l; ++c.n)
        {
            FORb(j, min(LOG_BASE*(c.n + 1) , l)-1 , LOG_BASE*c.n)
            {
                c.d[c.n] = c.d[c.n] * 10 + s[j] - '0';
            }
        }

        *this = c;
    }
    void print()
    {
        BigInt a = *this;
        printf("%d", a.d[a.n-1]);
        FORb(i, a.n-2, 0) printf("%0*d", LOG_BASE, a.d[i]);
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
BigInt pos, res2, C[512][512];
vi a, res1;
vb avail;
int n, k;

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
	scanf("%d%d", &n, &k);
	pos.scan();
	a = res1 = vi(k+1, 0);
	FOR(i, 1, k) scanf("%d", &a[i]);
}

//Preparation
void Preps()
{
    FOR(i, 1, n) C[k][i] = 1;
    FORb(i, k-1, 0)
    {
        FORb(j, n, 1) C[i][j] = C[i+1][j+1] + C[i][j+1]; // nCk = (n-1)C(k-1) + (n-1)C(k)
    }

//    putchar('\n');
//    FOR(i, 0, n)
//    {
//        FOR(j, 0, i)
//        {
//            C[i][j].print();
//            putchar(' ');
//        }
//        putchar('\n');
//    }
//    putchar('\n');
}

//Process
void Solve()
{
    //First operation: POS ----> STATE
    FOR(i, 1, k)
    {
        FOR(j, res1[i - 1] + 1, n)
        if (C[i][j] < pos) pos -= C[i][j];
        else
        {
            res1[i] = j;
            break;
        }
    }
    FOR(i, 1, k) printf("%d ", res1[i]); puts("");

    //Second operation: STATE ----> POS
    res2 = 1;
    FOR(i, 1, k)
    {
        FORl(j, a[i-1] + 1, a[i])
        {
            res2 += C[i][j];
        }
    }
    res2.print();
}

//Main Procedure
int main()
{
    Enter();
    Preps();
    Solve();
    return 0;
}
