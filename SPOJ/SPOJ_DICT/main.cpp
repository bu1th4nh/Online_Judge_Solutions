#include <bits/stdc++.h>

using namespace std;

int n, k;
string rest;
string pref;

struct NODE
{
    bool w;
    struct NODE *child[27];
};

typedef struct NODE* TRIE;

TRIE AddNode()
{
    TRIE N = new NODE;
    N->w = false;
    for (int i=0; i<26; i++) N->child[i] = NULL;
    return N;
}

TRIE root = AddNode();

int CVINT(char c)
{
    return static_cast<int> (c) - static_cast<int> ('a');
}

char CVCHR(int i)
{
    return char(i + static_cast<int> ('a'));
}

void Insert(string s)
{
    TRIE p = root;
    for (unsigned int i=0; i<s.length(); i++)
    {
        int j = CVINT(s[i]);
        if (p->child[j]==NULL) p->child[j]=AddNode();
        p = p->child[j];
    }
    p->w = true;
}

void DFS(TRIE N)
{
    if (N->w && (rest.length()!=0)) cout << pref + rest << "\n";
    for (int i=0; i<26; i++)
    {
        if(N->child[i]!=NULL)
        {
            rest.push_back(CVCHR(i));
            DFS(N->child[i]);
            rest.pop_back();
        }
    }
}

void Process(string s)
{
    TRIE p = root;
    for(int i=0; i<s.length(); i++)
    {
        int j = CVINT(s[i]);
        if (p->child[j]==NULL)
        {
            cout << "No match. \n";
            return;
        }
        p = p->child[j];
    }
    rest.clear();
    DFS(p);
}

void IO1()
{
    cin >> n;
    cin.ignore(1);
    for (int i=1; i<=n; i++)
    {
        string x;
        getline(cin, x);
        Insert(x);
    }
}

void IO2()
{
    cin >> k;
    cin.ignore(1);
    for (int i=1; i<=k; i++)
    {
        getline(cin, pref);
        cout << "Case #" << i << ":\n";
        Process(pref);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    IO1();
    IO2();
    return 0;
}
