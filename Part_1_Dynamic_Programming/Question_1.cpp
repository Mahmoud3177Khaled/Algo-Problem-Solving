#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    while (n--) {
        cin >> m;
        vector<int> coins(m);
        int total = 0;
        for (int i = 0; i < m; ++i) {
            cin >> coins[i];
            total += coins[i];
        }

        int half = total / 2;
        vector<int> dp(half + 1, 0);

        for (int i = 0; i < m; ++i) {
            for (int j = half; j >= coins[i]; --j) {
                dp[j] = max(dp[j], dp[j - coins[i]] + coins[i]);
            }
        }

        int Sum = dp[half];
        cout << total - 2 * Sum << '\n';
    }
    return 0;
}