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


const int inf = 1234567890;
//=====================================
//Trie
struct Node
{
    int w, min1, min2;
    Node* child[27];
    Node* parent;
};
Node* newNode()
{
    Node* ret = new Node;

    FOR(i, 0, 26) ret->child[i] = NULL;
    ret->parent = NULL;

    ret->w = -1; //Assume that there's no word ends here.
    ret->min1 = ret->min2 = inf;

    return ret;
}
Node* root = newNode();
void insert(string st, int id)
{
    Node* p = root;
    for(char c: st)
    {
        if(p->min1 == p->min2)
        {
            if(p->min1 < inf) p->min2 = id;
            else    p->min1 = p->min2 = id;
        }

        int i = c - 'a';
        if(p->child[i] == NULL) p->child[i] = newNode();

        p->child[i]->parent = p;                        //Assign parent.
        p = p->child[i];
    }
    p->w = id; //A word ends here, determined by id.

    if(p->min1 == p->min2)
    {
        if(p->min1 < inf) p->min2 = id;
        else    p->min1 = p->min2 = id;
    }

}

//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;
int n;
vs a;


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
    n = 0;
    string s;
    char str[100000];

	while(1)
    {
        getline(cin, s);
        if(s == "") break;
        a.push_back(s), ++n;
    }
    sort(whole(a));
}

//Check

int find(string st)
{
    Node* p = root;
    reverse(whole(st));
    for(char c: st)
    {
        int i = c - 'a';
        if(p->child[i] == NULL)
        {
            //cerr << "General Case: ";
            return p->min1;
        }

        p = p->child[i];
    }

    if(p->w == -1)
    {

        //cerr << "CC1: ";

        return p->min1;
    }
    else
    {
        //cerr << "CC2: ";

        int lkp = p->w;
        while(p->parent != NULL && p->min1 == p->min2)
        {
            p = p->parent;
            //cerr << " -{" << p->min1 << ", " << p->min2 << "}- ";
        }

        if(lkp != p->min1) return p->min1;
        return p->min2;
    }
}


void Query(string t)
{
    int id = find(t) - 1;
    string res = a[id];
    cout << res << el;
}


//Process
void Solve()
{
    char str[100000];
    sort(whole(a));  int ptr = 0;

    //cerr << el;
    for(string s: a)
    {
        //cerr << s << sp << ptr+1 << el;

        reverse(whole(s));
        insert(s, ++ptr);
    }
    cerr << el;

    while(scanf("%s", &str) != EOF)
    {
        Query(string(str));
    }
}

//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}
