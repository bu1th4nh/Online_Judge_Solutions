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
    int nStr, nEnd;
    struct NODE *child[2];
};
typedef struct NODE* TRIE;
int m, n, res;
TRIE root;

//=====================================
//Functions and procedures
//Trie Tree
TRIE AddNode()
{
    TRIE N = new NODE;
    N->nEnd = 0;
    N->nStr = 0;
    N->child[0] = NULL;
    N->child[1] = NULL;
    return N;
}
void Insert()
{
    int nChr;
    TRIE p = root;
    scanf("%d", &nChr);
    FOR(i, 1, nChr)
    {
        int x;
        scanf("%d", &x);
        ++p->nStr;
        if(p->child[x] == NULL) p->child[x] = AddNode();
        p = p->child[x];
    }
    ++p->nEnd;
}
void Query()
{
    int k;
    scanf("%d", &k);
    res = 0;
    TRIE p = root;
    int i;
    for(i=1; i<=k; ++i)
    {
        int x;
        scanf("%d", &x);
        p = p->child[x];
        if(p == NULL) break;
        res += p->nEnd;
    }
    if(p!=NULL) res += p->nStr;
    FOR(j, i+1, k) scanf("%d", &i);
    printf("%d\n", res);
}

//Main Procedure
int main()
{
    root = AddNode();
    cin >> m >> n;
    FOR(i1, 1, m)
    {
        Insert();
    }
    FOR(i2, 1, n)
    {
        Query();
    }
    return 0;
}
