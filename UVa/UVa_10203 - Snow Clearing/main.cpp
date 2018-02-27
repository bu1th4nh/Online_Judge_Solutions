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
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task "TEST"
#define fi first
#define se second
#define pb push_back
#define maxinp (int)()
#define MODUL (int)(1e9+57)
#define siz(x) (int)(x.size())
#define len(x) (int)(x.length())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP() {freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout);}

//=====================================
//Typedef
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
typedef long long ll;
int nTest;

//=====================================
//Functions and procedures
//Main Procedure
int main()
{
    int tcc;
    cin >> tcc;
    string s;
    getline(cin, s); getline(cin, s);
    while (tcc--)
    {
        double d = 0;
        getline(cin, s); // skip hangar coords
        while (true)
        {
            getline(cin, s);
            if (s == "") break;
            stringstream ss(s);
            double x1, x2, y1, y2;
            ss >> x1 >> y1 >> x2 >> y2;
            d += pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 0.5);
        }
        int mins = round(d * 2 * 60 / 20000);
        printf("%d:%02d\n", mins / 60, mins % 60);
        if (tcc) printf("\n");
    }
    return 0;
}
