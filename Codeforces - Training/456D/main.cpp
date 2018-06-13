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
//Initialization
struct Node
{
    bool win, lose, isLeaf;
    Node* child[27];
};
Node* newNode()
{
    Node* ret = new Node;

    ret->win    = false;
    ret->lose   = false;
    ret->isLeaf = true;
    FOR(i, 0, 26) ret->child[i] = NULL;

    return ret;
}
Node* root = newNode();

//Trie Operation
Node* insert(string st)
{
    Node* p = root;
    for(char c: st)
    {
        int i = c - 'a';
        p->isLeaf = false;

        if(p->child[i] == NULL) p->child[i] = newNode();
        p = p->child[i];
    }
    return p;
}
void DFS(Node* u)
{
    if(u->isLeaf)
    {
        u->lose = 1;
        u->win  = 0;
    }

    FOR(i, 0, ('z' - 'a')) if(u->child[i] != NULL)
    {
        DFS(u->child[i]);
        u->lose = u->lose || (!u->child[i]->lose);
        u->win  = u->win  || (!u->child[i]->win);
    }
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
    char str[131072];
	scanf("%d%d", &n, &k);
	FOR(i, 1, n)
	{
	    scanf("%s", &str);
	    insert(string(str));
	}
}

//Process
void Solve()
{
    DFS(root);
    if(root->win && root->lose)
    {
        puts("First");
    }
    else if(!root->win)
    {
        puts("Second");
    }
    else if(root->win && (!root->lose))
    {
        puts((k&1) ? "First" : "Second");
    }
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
