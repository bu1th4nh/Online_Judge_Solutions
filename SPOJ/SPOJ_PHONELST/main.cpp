//Libraries and namespaces
//#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;


//=====================================
//Macros
#define task ""
#define maxvalueinp (int)()
#define MODUL (int)(1e9+57)
#define len(x) (int)(x.length())
#define siz(x) (int)(x.size())
#define whole(x) x.begin(), x.end()
#define FOR(i, x, y) for(int i=x; i<=y; ++i)
#define FORl(i, x, y) for(int i=x; i<y; ++i)
#define FORb(i, x, y) for(int i=x; i>=y; --i)
#define FORlb(i, x, y) for(int i=x; i>y; --i)
#define MEMS(x, val) memset(x, val, sizeof(x))
#define FILEOP(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);

//=====================================
//Typedef
struct NODE
{
    int nNum;
    bool IsEnd;
    struct NODE *child[10];
};
typedef struct NODE* TRIE;
TRIE root;
int nTest;
string s;
bool ok;
int n;

//=====================================
//Functions and procedures
// Trie Tree
TRIE AddNode()
{
    TRIE N = new NODE;
    N->IsEnd = false;
    N->nNum = 0;
    FOR(i, 0, 9) N->child[i] = NULL;
    return N;
}
void Insert(string t)
{
    TRIE p = root;
    FORl(i, 0, len(s))
    {
        int x = s[i] - '0';
        if(p->child[x] == NULL) p->child[x] = AddNode();
        p = p->child[x];
    }
    p->IsEnd = true;
}
void DFS(TRIE N)
{
    FOR(i, 0, 9)
    {
        if(N->child[i] != NULL)
        {
            if(N->IsEnd) ok = false;
            DFS(N->child[i]);
        }
    }
}


//Initialization
void Init()
{
    root = AddNode();
    ok = true;
    scanf("%d", &n);
    FOR(i, 1, n)
    {
        cin >> s;
        Insert(s);
    }
}

//Process
void Process()
{
    DFS(root);
    if(ok) printf("YES\n");
    else printf("NO\n");
}

//Main Procedure
int main()
{
    scanf("%d", &nTest);
    while(nTest--)
    {
        Init();
        Process();
    }
    return 0;
}
