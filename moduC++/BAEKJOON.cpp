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
    
    int n;
    cin >> n;

    int cnt{ 10 };
    for (int i = 1; i < n; ++i) {
        int temp{ i };
        int sum{ i };

        while (temp != 0) {
            sum += temp % 10;
            temp /= 10;
        }

        if (sum == n) {
            cout << i;
            return 0;
        }
    }

    cout << 0;
}