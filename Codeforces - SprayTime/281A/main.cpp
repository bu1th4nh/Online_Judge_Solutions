#include <bits/stdc++.h>

using namespace std;


int main()
{
    string s;
    cin >> s;
    s[0] = isupper(s[0]) ? s[0] : s[0]-('a'-'A');
    cout << s;
    return 0;
}
