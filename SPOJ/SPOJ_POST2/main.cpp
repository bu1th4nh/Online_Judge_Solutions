/*==============================================================================================================*\
**                                  _           _ _   _     _  _         _                                      **
**                                 | |__  _   _/ | |_| |__ | || |  _ __ | |__                                   **
**                                 | '_ \| | | | | __| '_ \| || |_| '_ \| '_ \                                  **
**                                 | |_) | |_| | | |_| | | |__   _| | | | | | |                                 **
**                                 |_.__/ \__,_|_|\__|_| |_|  |_| |_| |_|_| |_|                                 **
\*==============================================================================================================*/
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
#include <tuple>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
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

const int S = 18;
const int N = 1 << S;
//=====================================
//Typedef
struct complex
{
    double r, i;
    complex(): r(0), i(0) {}
    complex(double t): r(cos(t)), i(sin(t)) {}
    complex(double r, double i): r(r), i(i) {}
    void operator/=(double d)
    {
        this->r /= d;
        this->i /= d;
    }
};
complex operator+(complex a, complex b)
{
    a.r += b.r;
    a.i += b.i;
    return a;
}
complex operator-(complex a, complex b)
{
    a.r -= b.r;
    a.i -= b.i;
    return a;
}
complex operator*(complex a, complex b)
{
    return complex(a.r*b.r - a.i*b.i, a.r*b.i + a.i*b.r);
}

//=====================================
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;

//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP()
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

//Enter
template<class T> T read()
{
    T t; cin >> t; return t;
}

//Fast Fourier Transform ( ͡° ͜ʖ ͡°)
int reverse(int n)
{
    int r = 0;
    FORl(i, 0, S) r |= ((n & (1<<i))>>i)<<(S - i - 1);
    return r;
}

complex* FFT(complex *a, bool inv = false)
{
    complex *b = new complex[N];
    FORl(i, 0, N) b[i] = a[reverse(i)];
    FORl(s, 0, S)
    {
        int len = 1 << s;
        complex w((inv ? 1 : -1) * M_PI / len);
        int i = 0, j = 0;
        for(int cnt = N >> (s + 1); cnt--;)
        {
            i = j;
            j = i + len;
            complex t(1.0, 0);
            for(int l = len; l--;)
            {
                a[i] = b[i] + t * b[j];
                a[j] = b[i] - t * b[j];
                t = t * w;
                i++, j++;
            }
        }
        swap(a, b);
    }
    delete[] a;
    if(inv) FORl(i, 0, N) b[i] /= N;
    return b;
}


//Process
void Solve()
{
    int m = read<int>();
    complex *a = new complex[N];
    complex *b = new complex[N];

    FORl(i,0,m) a[read<int>() + 50000].r += 1.0;
    FORl(i,0,m) b[read<int>() + 50000].r += 1.0;

    a = FFT(a);
    b = FFT(b);

    FORl(i,0,N) a[i] = a[i] * b[i];
    a = FFT(a, true);

    long long kq = 0;
    FORl(i,0,m) kq += round(a[read<int>() + 100000].r);
    cout << kq;

    delete[] a;
    delete[] b;
}


//Main Procedure
int main()
{
    Solve();
    return 0;
}
