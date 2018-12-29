#include <iostream>

using namespace std;

int main()
{
    int m, n, a, b;
    cin >> n >> m >> a >> b;
    if(m * a > b)
    {
        cout << (n / m) * b + min((n % m) * a, b);
    }
    else cout << n * a;
    return 0;
}
