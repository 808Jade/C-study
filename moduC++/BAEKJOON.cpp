#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        arr[i] = x;
    }
    
    int temp{ numeric_limits<int>::max() };

    for (int i = 0; i < n-2; ++i) {
        for (int j = i+1; j < n-1; ++j) {
            for (int k = j+1; k < n; ++k) {
                if ((m - arr[i] - arr[j] - arr[k]) <= temp && (m - arr[i] - arr[j] - arr[k]) >= 0) {
                    temp = m - arr[i] - arr[j] - arr[k];
                }
            }
        }
    }

    cout << m - temp;
}