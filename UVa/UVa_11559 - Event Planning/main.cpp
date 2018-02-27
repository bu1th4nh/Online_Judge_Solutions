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
#define task ""
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
int n, b, h, w, p, nb, minCost;

//=====================================
//Functions and procedures
//Main Procedure
int main()
{
	int n, b, h, w;
	int p, nb, minCost;

	while (scanf("%d %d %d %d\n", &n, &b, &h, &w) != EOF)
    {
		minCost = 2000000000;
		while (h--)
		{
			cin >> p;
			for(int i=0;i<w;i++)
			{
				cin >> nb;
				if (nb >= n)
				{
					minCost = min(minCost,n * p);
					string s;
					getline(cin, s);
					break;
				}
			}
		}
		if (minCost != 2000000000 && minCost <= b) cout << minCost << endl;
		else cout << "stay home" << endl;
	}

	return 0;
}
