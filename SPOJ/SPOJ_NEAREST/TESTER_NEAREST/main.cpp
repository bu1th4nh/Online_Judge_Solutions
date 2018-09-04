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
#include <chrono>
#include <random>
#endif // __cplusplus

using namespace std;


#include "test_lib.h"


//=====================================
//Macroes
#define sp " "
#define el "\n"
#define task "NEAREST"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define whole1(x) x.begin()+1, x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}
#define FILEOP_DEBUG() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); freopen(task".err", "w", stderr);}


#define sqr(x) (x*x)

//=====================================
//Typedefs
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ld, ld> dd;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<dd> vdd;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;

auto timeStart = chrono::steady_clock::now();
auto timeEnd   = chrono::steady_clock::now();

//==================================================
//Input generate
void Generate_input()
{
    unordered_map<string, int> mp, mp2;
    ofstream test_inp(task".inp");

    int n = rand_int(100000, 100000);

    test_inp << n << el;
    FOR(i, 1, n)
    {
        string a = rand_double(7, 3);
        while(mp[a] != 0) a = rand_double(7, 3);
        mp[a] = 1; test_inp << a << sp;

        string b = rand_double(7, 3);
        while(mp2[b] != 0) b = rand_double(7, 3);
        mp2[b] = 1; test_inp << b << el;
    }
}
void Generate_answer()
{
    system(task"___AC.exe");
}


//==================================================
//Checker
void Checker()
{
    int T;
    cout << "How many test do ya want to generate? "; cin >> T;

    FOR(iTest, 1, T)
    {
        cout << "Test #" << iTest << ":\n";


        Generate_input();
        cout << "Input generating completed\n";


        timeStart = chrono::steady_clock::now();
        Generate_answer();
        timeEnd   = chrono::steady_clock::now();
        cout << "Answer generating completed with elapsed time: " << chrono::duration<double>(timeEnd - timeStart).count() << " second(s)" << el;


        timeStart = chrono::steady_clock::now();
        system(task);
        timeEnd   = chrono::steady_clock::now();
        double T = chrono::duration<double>(timeEnd - timeStart).count();
        cout << "Sample program completed with elapsed time: " << T << " second(s)";
        puts(T > 1.00 ? " (Time limit exceeded)" : "");

        system("fc "task".out "task".ans");
    }

}

//Main Procedure
int main()
{
    Checker();
    return 0;
}
