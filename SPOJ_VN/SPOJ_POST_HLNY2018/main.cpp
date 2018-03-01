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
using namespace std;


//=====================================
//Macros
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
//Typedef
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vb> vvb;
typedef vector<vii> vvii;




//=====================================
//Functions and procedures
//Initialization and preparation
void FileInit()
{
    FILEOP();
}
void FileDebug()
{
    FILEOP_DEBUG();
}
void FileClose()
{
    fclose(stdin);
    fclose(stdout);
}

/*
___.         ____  __  .__        _____        .__
\_ |__  __ _/_   |/  |_|  |__    /  |  |  ____ |  |__   /\
 | __ \|  |  \   \   __\  |  \  /   |  |_/    \|  |  \  \/
 | \_\ \  |  /   ||  | |   Y  \/    ^   /   |  \   Y  \ /\
 |___  /____/|___||__| |___|  /\____   ||___|  /___|  / \/
     \/                     \/      |__|     \/     \/
  ___ ___
 /   |   \_____  ______ ______ ___.__.
/    ~    \__  \ \____ \\____ <   |  |
\    Y    // __ \|  |_> >  |_> >___  |
 \___|_  /(____  /   __/|   __// ____|
       \/      \/|__|   |__|   \/
.____                                 _______                  _____.___.                   ._.
|    |    __ __  ____ _____ _______   \      \   ______  _  __ \__  |   | ____ _____ _______| |
|    |   |  |  \/    \\__  \\_  __ \  /   |   \_/ __ \ \/ \/ /  /   |   |/ __ \\__  \\_  __ \ |
|    |___|  |  /   |  \/ __ \|  | \/ /    |    \  ___/\     /   \____   \  ___/ / __ \|  | \/\|
|_______ \____/|___|  (____  /__|    \____|__  /\___  >\/\_/    / ______|\___  >____  /__|   __
        \/          \/     \/                \/     \/          \/           \/     \/       \/
*/

//Main Procedure
int main()
{
    ll a, b;
    cin >> a >> b;
    cout << a + b;
    return 0;
}
