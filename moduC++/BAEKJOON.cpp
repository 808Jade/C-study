#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <array>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    // 행렬마냥?
    // -> 분수 문제가 생김

    for (int x = -999; x <= 999; ++x) {
        for (int y = -999; y <= 999; ++y) {
            if (a * x + b * y == c && d * x + e * y == f)
                cout << x << ' ' << y;
        }
    }
}