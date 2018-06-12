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
//Trie Tree
struct Node
{
    bool w;
    Node *child[27];
};
Node* newNode()
{
    Node* N = new Node;
    FOR(i, 0, 26) N->child[i] = NULL;
    N->w = 0;

    return N;
}

Node* root = newNode();
void insert(string st)
{
    Node* p = root;
    FORb(j, st.size() - 1, 0)
    {
        int i = st[j] - 'a';
        if(p->child[i] == NULL) p->child[i] = newNode();
        p = p->child[i];
    }
    p->w = 1;
}


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
int n, nWrd;
string src;
vi F;

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
    cin >> src >> nWrd;
    n = src.length();
	src = '.' + src;

	FOR(i, 1, nWrd)
	{
	    string s;
	    cin >> s;
	    insert(s);
	}

	F = vi(n+1, 0);
}

//Process
void Solve()
{
    Node* p;
    F[0] = 1;
    FOR(i, 1, n)
    {
        int j = i; p = root;
        while(j > 0 && p->child[src[j] - 'a'] != NULL)
        {
            p = p->child[src[j] - 'a'];
            --j;
            if(p->w) F[i] += F[j];
        }
        F[i] %= 1337377;
    }
    cout << F[n];
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
