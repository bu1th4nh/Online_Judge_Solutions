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
    struct NODE *child[27];
    bool IsEnd;
    int nWord;
};
typedef struct NODE* TRIE;
int n, res;

//=====================================
//Functions and procedures
//Trie
int CTInt(char t)
{
    return (int)(t - 'a');
}
TRIE CreateNode()
{
    NODE *N = new NODE;
    N->IsEnd = false;
    N->nWord = 0;
    FORl(i, 0, 26) N->child[i] = NULL;
    return N;
}

TRIE root = CreateNode();

void Insert(string s)
{
    TRIE p = root;
    FORl(i, 0, len(s))
    {
        int j = CTInt(s[i]);
        if (p->child[j] == NULL) p->child[j] = CreateNode();
        p = p->child[j];
    }
    p->IsEnd = true;
}

//Process
void DFS(TRIE x)
{
    if(x!=NULL)
    {
        FORl(i, 0, 26)
        {
            if(x->child[i]!=NULL)
            {
                x->child[i]->nWord = (x->child[i]->IsEnd) ? x->nWord + 1 : x->nWord;
                DFS(x->child[i]);
            }
            else
            {
                res = max(res, x->nWord);
            }
        }
    }
}
void Process()
{
    res = -1;
    DFS(root);
    printf("%d", res);
}

//Input
void Input()
{
    scanf("%d", &n);
    cin.ignore(1);
    FOR(i, 1, n)
    {
        string x;
        getline(cin, x);
        Insert(x);
    }
}

//Main Procedure
int main()
{
    Input();
    Process();
    return 0;
}
