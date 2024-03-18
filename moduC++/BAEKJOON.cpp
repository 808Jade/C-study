#include <iostream>
#include <string>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int a1, a0, c, n;
    cin >> a1 >> a0 >> c >> n;

    bool ans{ true };
    while (n++ <= 100) {
        if (a1 * n + a0 > c * n)
            ans = false;
    }

    cout << ans;
}