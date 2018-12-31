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
#define task "EXAM"
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
//Expression-related Utilities
template<class T> T op(T x, char o, T y)
{
    if(o == '+') return x + y;
    if(o == '-') return x - y;
    if(o == '*') return x * y;
    throw 0;
}
template<class T, class P> string re(T x, char o, P y)
{
    stringstream ss;
    ss << "(" << x << o << y << ")";
    return string(ss.str());
}
template<class T, class P> string re2(T x, char o, P y)
{
    stringstream ss;
    ss << x << o << y;
    return string(ss.str());
}


//=====================================
//Class libraries
struct expression
{
    typedef long long ll;
    typedef vector<ll> vll;
    typedef vector<int> vi;
    typedef vector<char> vc;
    typedef vector<string> vs;
    typedef map<int, int> mii;
    typedef map<ll, int> mlli;
    typedef map<int, string> mis;


    //Level 0 Data
    string raw_input;

    //Level 1 Data
    vll operands;
    vc operators;

    //Level 2 Data
    vll raw_answer;
    vs raw_repr;

    //Level 3 Data
    vll filtered_answer;
    vs filtered_repr;

    //Level 4 Data
    mis map_vertex_id_to_representation;            //      result  --------[map]--------> vertex_id (global id)
    vi adjacent_to;                                 //        ||
                                                    //        |[-----[map using global id]------> reprentation


    void initialize(string raw) //Generate Level 1 Data
    {
        ll tmp = 0LL;
        raw_input = raw;
        for(char c: raw_input)
        {
            if(isdigit(c)) tmp = tmp * 10 + c - '0';
            else
            {
                operands.push_back(tmp);
                operators.push_back(c);
                tmp = 0LL;
            }
        }
        operands.push_back(tmp);
    }
    void init_raw_expr()        //Generate Level 2 Data
    {
        vll &d = operands;
        vc &p = operators;

        vll &e  = raw_answer;
        vs &r  = raw_repr;

        if(p.size() == 1)
        {
            e.push_back(op(d[0], p[0], d[1]));
            r.push_back(re2(d[0], p[0], d[1]));
        }
        if(p.size() == 2)
        {
            e.push_back(op(op(d[0], p[0], d[1]), p[1], d[2]));
            e.push_back(op(d[0], p[0], op(d[1], p[1], d[2])));


            r.push_back(re2(re(d[0], p[0], d[1]), p[1], d[2]));
            r.push_back(re2(d[0], p[0], re(d[1], p[1], d[2])));
        }
        if(p.size() == 3)
        {
            e.push_back(op(op(op(d[0], p[0], d[1]), p[1], d[2]), p[2], d[3]));
            e.push_back(op(op(d[0] , p[0] , op(d[1] , p[1] , d[2])) , p[2] , d[3]));
            e.push_back(op(op(d[0] , p[0] , d[1]) , p[1], op(d[2] , p[2] , d[3])));
            e.push_back(op(d[0] , p[0] , op(op(d[1] , p[1] , d[2]) , p[2], d[3])));
            e.push_back(op(d[0] , p[0] , op(d[1] , p[1] , op(d[2] , p[2], d[3]))));


            r.push_back(re2(re(re(d[0] , p[0] , d[1]) , p[1] , d[2]) , p[2] , d[3]));
            r.push_back(re2(re(d[0] , p[0] , re(d[1] , p[1] , d[2])) , p[2] , d[3]));
            r.push_back(re2(re(d[0] , p[0] , d[1]) , p[1], re(d[2] , p[2] , d[3])));
            r.push_back(re2(d[0] , p[0] , re(re(d[1] , p[1] , d[2]) , p[2], d[3])));
            r.push_back(re2(d[0] , p[0] , re(d[1] , p[1] , re(d[2] , p[2], d[3]))));
        }
    }
    void data_filter()          //Filter and generate Level 3 Data
    {
        map<ll, string> mp;
        FORl(i, 0, (int)raw_answer.size())
        {
            if(mp.find(raw_answer[i]) == mp.end())
            {
                mp[raw_answer[i]] = raw_repr[i];
            }
        }

        for(auto x: mp)
        {
            filtered_answer.push_back(x.fi);
            filtered_repr.push_back(x.se);
        }
    }
    void connect_edge(mlli &id_of_result, int &index)       //Generate Level 4 Data
    {
        for(auto x: filtered_answer) if(id_of_result[x] == 0)       //Enumerate the filtered result list.
        {
            id_of_result[x] = ++index;
        }
        FORl(i, 0, (int)filtered_answer.size())
        {
            int vertex_id       =        id_of_result[filtered_answer[i]];
            map_vertex_id_to_representation[vertex_id] = filtered_repr[i];

            adjacent_to.push_back(vertex_id);
        }
    }



    expression() {}
    ~expression()
    {
        raw_repr.clear();
        raw_answer.clear();
        adjacent_to.clear();
        filtered_repr.clear();
        filtered_answer.clear();
        map_vertex_id_to_representation.clear();
    }
};
class graphMatching
{
    const int inf = 1000000007;

    typedef vector<int> vi;
    typedef vector<vi> vvi;

    int n, m, nMatch;
    vi d, matx, maty;
    vvi adj;

    bool BFS()
    {
       /*
        *Find if there's existing augmenting path, or the path from unmatched L-vertex to unmatched R-vertex.
        *If so find the shortest one and return true. Oherwise, return false
        */

        queue<int> que;
        int u;

        FOR(i, 1, m)
        {
            if(!matx[i])        //Vertex i is unmatched
            {
                d[i] = 0;
                que.push(i);
            }
            else d[i] = inf;
        }

        d[0] = inf;
        while(!que.empty())
        {
            u = que.front(); que.pop();
            if(d[u] < d[0]) for(int v: adj[u]) if(d[maty[v]] >= inf)
            {
                d[maty[v]] = d[u] + 1;
                que.push(maty[v]);
            }
        }

        return (d[0] < inf);
    }
    bool DFS(const int &u)
    {
        /*
         *  Flip the edge type from unmatched to matched and vice versa along the augmenting path
         */

        if(!u) return 1;
        for(int v: adj[u]) if(d[maty[v]] == d[u] + 1)
        {
            if(DFS(maty[v]))
            {
                matx[u] = v;
                matx[v] = u;
                return 1;
            }
        }
        d[u] = inf;
        return 0;
    }

public:
    void initialize(int __m, int __n)
    {
        m = __m, n = __n;
        matx = d = vi(m+1, 0);
        maty = vi(n+1, 0);
        adj = vvi(m+1);
    }
    void add_edge(int u, const vi &adjacent_to)
    {
        adj[u] = adjacent_to;
    }
    void init_match()
    {
        nMatch = 0;
        while(BFS())
        {
            FOR(i, 1, m) if(!matx[i])
            {
                if(DFS(i)) ++nMatch;
            }
        }
    }
    int extract_match_qty()   {  return nMatch;  }
    vi extract_match_fr_x()   {  return matx;    }
    vi extract_match_fr_y()   {  return maty;    }


    graphMatching() {}
    ~graphMatching() {}
};


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

typedef vector<expression> ve;
typedef map<ll, int> mlli;

graphMatching exp_match;
mlli id_of_result;
int n, m;
ve vect;

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
    char str[1024];
    scanf("%d", &n);
    vect = ve(n+1);
    m = 0;

    FOR(i, 1, n)
    {
        scanf("%s", &str);
        vect[i].initialize(string(str));
    }
}

//Data-generating
void generate_id()
{
    FOR(i, 1, n)
    {
        vect[i].init_raw_expr();
        vect[i].data_filter();
        vect[i].connect_edge(id_of_result, m);
    }
}
void generate_bipartite_graph()
{
    exp_match.initialize(n, m);
    FOR(i, 1, n) exp_match.add_edge(i, vect[i].adjacent_to);
}

//Process
void Solve()
{
    generate_id();

    if(n > m)
    {
        cout << "NO SOLUTION" << el;
        return;
    }

    generate_bipartite_graph();
    exp_match.init_match();

    if(exp_match.extract_match_qty() < n)
    {
        cout << "NO SOLUTION" << el;
        return;
    }
    vi res = exp_match.extract_match_fr_x();

    FOR(i, 1, n)
    {
        printf("%s\n", vect[i].map_vertex_id_to_representation[res[i]].c_str());
    }
}


//Main Procedure
int main()
{
    Enter();
    Solve();
    return 0;
}

/*
3
2*3-4
2*3-4
3*2-4

4
2*3-4
2*3-4
3*2-4
3*2-4
*/
