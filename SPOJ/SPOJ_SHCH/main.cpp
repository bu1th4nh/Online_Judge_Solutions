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
    typedef long long ll;
    typedef vector<int> vi;

    const int BASE = 10000;
    const int MAX_D  =  45;
    const int LOG_BASE = 4;

    vi d;
    int n;


    //I-O and comparison
    void operator = (const ll &x)
    {
        d = vi(MAX_D, 0); n = 0;
        for(ll t = x; t != 0; t /= BASE) d[n++] = t % BASE;
    }
    void operator = (const BigInt &x)
    {
        this->d = x.d;
        this->n = x.n;
    }
    bool operator < (const BigInt &other) const
    {
        if(this->n != other.n) return (this->n < other.n);

        FORb(i, n-1, 0)
        {
            if(this->d[i] < other.d[i]) return 1;
            else if(this->d[i] > other.d[i]) return 0;
        }
        return 0;
    }
    void scan()
    {
        char str[1010101]; scanf("%s", &str); string s(str);
        int l = s.size();

        reverse(whole(s));
        this->d = vi(MAX_D, 0);


        for(this->n = 0; LOG_BASE * this->n < l; ++this->n)
        {
            FORb(j , min(LOG_BASE*(this->n+1) , l)-1 , LOG_BASE*this->n)
            {
                this->d[this->n] = this->d[this->n] * 10 + s[j] - '0';
            }
        }
    }
    void print()
    {
        printf("%d", this->d[n-1]);
        FORb(i, n-2, 0) printf("%0*d", LOG_BASE, this->d[i]);
    }


    //BigInt operations
    BigInt operator * (const int &other) const
    {
        BigInt ret;
        int rem = 0, p = 0;

        ret = 0;
        ret.n = this->n;
        ret.d = vi(MAX_D, 0);

        FORl(i, 0, this->n)
        {
            p = this->d[i] * other + rem;
            ret.d[i] = p % BASE;
            rem = p / BASE;
        }
        for(; rem != 0; rem /= BASE) ret.d[ret.n++] = rem % BASE;

        return ret;
    }
    void operator += (const BigInt &other)
    {
        int rem = 0, p = 0;
        this->n = max(this->n, other.n);

        FORl(i, 0, this->n)
        {
            p = this->d[i] + other.d[i] + rem;
            if(p >= BASE) this->d[i] = p - BASE, rem = 1;
            else this->d[i] = p, rem = 0;
        }
        if(rem) this->d[this->n++] = rem;
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


    BigInt() {n = 0; d = vi(MAX_D, 0);}
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
BigInt pos, res2, A[128][128];
vi sample, res1;
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
	sample = vi(k+1, 0);
	FOR(i, 1, k) scanf("%d", &sample[i]);
}



//Process
void Preps()
{
    A[0][0] = 1;
    FOR(i, 1, n)
    {
        A[i][0] = 1;
        FOR(j, 1, min(k, i)) A[i][j] = A[i][j-1] * (i - j + 1);
    }
}
void Solve()
{
    //For the 1st query: POS ---> STATE
	avail = vb(n+1, 1);
    FOR(i, 1, k)
    {
        FOR(j, 1, n) if(avail[j])
        {
            if(A[n-i][k-i] < pos) pos -= A[n-i][k-i];
            else
            {
                res1.push_back(j);
                avail[j] = 0;
                break;
            }
        }
    }
    for(int x: res1) printf("%d ", x); puts("");



    //For the 2nd query: STATE ---> POS
	avail = vb(n+1, 1); res2 = 1;
    FOR(i, 1, k)
    {
        FORl(j, 1, sample[i])
        {
            if(avail[j]) res2 += A[n-i][k-i];
        }
        avail[sample[i]] = 0;
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
