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
//Data representation
template<class T> T opr(T x, char o, T y)
{
    if(o == '+') return x + y;
    if(o == '-') return x - y;
    if(o == '*') return x * y;
    throw 0;
}
template<class T, class P> string rep(T x, char o, P y)
{
    stringstream ss;
    ss << '(' << x << o << y << ')';
    return string(ss.str());
}
struct expression
{
    typedef long long ll;
    typedef pair<int, int> ii;
    typedef vector<string> vs;
    typedef vector<char> vc;
    typedef vector<int> vi;
    typedef vector<ll> vll;
    typedef vector<ii> vii;
    typedef vector<vi> vvi;
    typedef vector<vs> vvs;

    typedef map<ii, string> miis;
    typedef map<ll, string> mlls;
    typedef unordered_map<ll, int> mlli;
    typedef set<int> si;

    //------------------------------------
    vs representation;
    vll expr_result;
    vc operators;
    vll operand;
    miis view;

    string source;


    //------------------------------------
    expression() {}
    ~expression() {}

    //------------------------------------
    void initialize(string in)
    {
        source = in;

        ll oprd = 0LL;
        for(char c: in)
        {
            if(isdigit(c) != 0) oprd = oprd * 10 + c - '0';
            else
            {
                operand.push_back(oprd);
                operators.push_back(c);
                oprd = 0LL;
            }
        }

        operand.push_back(oprd);
        oprd = 0LL;


//        for(auto x: operand) cerr << x << sp; cerr << el;
    }
    void generate_expr()
    {
        vll &od = operand;
        vc &op = operators;

        vll &e  = expr_result;
        vs &r  = representation;

        if(op.size() == 1)
        {
            e.push_back(opr(od[0], op[0], od[1]));
            r.push_back(rep(od[0], op[0], od[1]));
        }
        if(op.size() == 2)
        {
            e.push_back(opr(opr(od[0] , op[0] , od[1]) , op[1] , od[2]));
            e.push_back(opr(od[0] , op[0] , opr(od[1] , op[1] , od[2])));

            r.push_back(rep(rep(od[0] , op[0] , od[1]) , op[1] , od[2]));
            r.push_back(rep(od[0] , op[0] , rep(od[1] , op[1] , od[2])));


//            cerr << "Really?: " << e[0] << sp << e[1] << el;
        }
        if(op.size() == 3)
        {
            e.push_back(opr(opr(opr(od[0] , op[0] , od[1]) , op[1] , od[2]) , op[2] , od[3]));
            e.push_back(opr(opr(od[0] , op[0] , opr(od[1] , op[1] , od[2])) , op[2] , od[3]));
            e.push_back(opr(opr(od[0] , op[0] , od[1]) , op[1], opr(od[2] , op[2] , od[3])));
            e.push_back(opr(od[0] , op[0] , opr(opr(od[1] , op[1] , od[2]) , op[2], od[3])));
            e.push_back(opr(od[0] , op[0] , opr(od[1] , op[1] , opr(od[2] , op[2], od[3]))));


            r.push_back(rep(rep(rep(od[0] , op[0] , od[1]) , op[1] , od[2]) , op[2] , od[3]));
            r.push_back(rep(rep(od[0] , op[0] , rep(od[1] , op[1] , od[2])) , op[2] , od[3]));
            r.push_back(rep(rep(od[0] , op[0] , od[1]) , op[1], rep(od[2] , op[2] , od[3])));
            r.push_back(rep(od[0] , op[0] , rep(rep(od[1] , op[1] , od[2]) , op[2], od[3])));
            r.push_back(rep(od[0] , op[0] , rep(od[1] , op[1] , rep(od[2] , op[2], od[3]))));
        }
    }
    void generate_edge(int &id, mlli &res_list, vii &edgeList)
    {
        int ptr = 0;
        for(auto x: expr_result)
        {
            if(!res_list.count(x)) res_list.insert({x, res_list.size()+1});
            edgeList.push_back(ii(id, res_list[x]));
            view[ii(id, res_list[x])] = representation[ptr++];
        }


//        cerr << source << el;
//        FORl(i, 0, expr_result.size()) cerr << representation[i] << " = " << expr_result[i] << ": " << res_list[expr_result[i]] << el;
    }
};
class graphMatching
{
public:

    typedef long long ll;
    typedef unsigned long long ull;
    typedef pair<int, int> ii;
    typedef vector<string> vs;
    typedef vector<bool> vb;
    typedef vector<int> vi;
    typedef vector<ll> vll;
    typedef vector<ii> vii;
    typedef vector<vi> vvi;
    typedef vector<vs> vvs;
    typedef vector<vb> vvb;
    typedef vector<vll> vvll;
    typedef vector<vii> vvii;
    typedef queue<int> qi;

    const int inf = 1000000007;

    int m, n, nMatch;
    vi d, matx, maty;
    vvi adj;

private:

    bool BFS()
    {
        /** \brief Find the length of shortest augmenting path from source vertex and partition the graph into layers
         * \return Return true if found an aug. path, false otherwise
         */

        qi q;
        int u;

        while(!q.empty()) q.pop();
        FOR(i, 1, m)
        {
            if(matx[i] == 0)
            {
                d[i] = 0;
                q.push(i);
            }
            else d[i] = inf;
        }

        d[0] = inf;
        while(!q.empty())
        {
            u = q.front(); q.pop();
            if(d[u] < d[0]) for(int v: adj[u]) if(d[maty[v]] >= inf)
            {
                d[maty[v]] = d[u] + 1;
                q.push(maty[v]);
            }
        }

        return (d[0] < inf);
    }
    bool DFS(const int &u)
    {
        /** \brief Flip the edge status along the augmenting path
         */

        if(u == 0) return true;
        for(int v: adj[u]) if(d[maty[v]] == d[u] + 1)
        {
            if(DFS(maty[v]))
            {
                matx[u] = v;
                maty[v] = u;
                return true;
            }
        }
        d[u] = inf;
        return false;
    }

public:
    void addEdge(int u, int v)
    {
        /** \brief Add an edge to the bipartite graph
        *   \param u: ID of left-vertex
        *   \param v: ID of right-vertex
        */

        adj[u].pb(v);

        //cerr << "Edge " << u << " - " << v << " is added!\n";
    }
    void initMatch()
    {
        /** \brief Start the algorithm
         */
        nMatch = 0;
        while(BFS())
        {
            FOR(i, 1, m) if(matx[i] == 0)
            {
                if(DFS(i)) ++nMatch;

                //cerr << nMatch << "\n";
            }
        }
    }
    vi extract_match_from_x()
    {
        /** \brief Extarct the result (left-side ====> right-side)
        */
        return matx;
    }
    int extract_match_qty()
    {
        /** \brief Extarct the number of maximum match
        */
        return nMatch;
    }


    graphMatching(int __m, int __n)
    {
        m = __m, n = __n;
        matx = d = vi(m+1, 0);
        maty = vi(n+1, 0);
        adj = vvi(m+1);
    }
    graphMatching() {}

    ~graphMatching() {}


};

//=====================================
//Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef unordered_map<ll, int> mlli;
typedef map<int, ll> mill;
typedef vector<expression> ve;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vs> vvs;
typedef vector<vb> vvb;
typedef vector<vll> vvll;
typedef vector<vii> vvii;
int nExpressions, nResult;
ve expressionList;
mlli result_map;
vii edgeList;

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
    char str[1010101];
    expressionList = ve(1);
    scanf("%d", &nExpressions);

    //cerr << nExpressions << sp << nResult << el;

    FOR(i, 1, nExpressions)
    {
        expression e;
        scanf("%s", &str);
        e.initialize(string(str));
        e.generate_expr();
        e.generate_edge(i, result_map, edgeList);

        expressionList.push_back(e);
    }
    nResult = (int)result_map.size();

    cerr << nExpressions << sp << nResult << el;
}


//Process
void FUCKING_SOLVE()
{
    if(nExpressions > nResult)
    {
        puts("NO SOLUTION");
        return;
    }



    //---------------------------------------------
    graphMatching planaxis(nExpressions, nResult);
    for(ii ed: edgeList) planaxis.addEdge(ed.fi, ed.se);
    planaxis.initMatch();


    //---------------------------------------------
    if(planaxis.extract_match_qty() < nExpressions)
    {
        puts("NO SOLUTION");
        return;
    }
    else
    {
        FOR(i, 1, nExpressions) printf("%s\n", expressionList[i].view[ii(i, planaxis.matx[i])].c_str());
    }


}

//Main Procedure
int main()
{
    FileInit();
    Enter();
    FUCKING_SOLVE();
    return 0;
}

/*
3
2*3-4
2*3-4
3*2-4
*/
