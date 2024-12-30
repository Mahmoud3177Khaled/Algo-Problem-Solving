#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Treasure {
    int depth;
    int gold;
};

int main() {
    int t, w;
    bool Case1 = true;
    while (cin >> t >> w) {
        int n;
        cin >> n;
        vector<Treasure> treasures(n);
        for (int i = 0; i < n; ++i) {
            cin >> treasures[i].depth >> treasures[i].gold;
        }

        vector<vector<int>> dp(n + 1, vector<int>(t + 1, 0));

        for (int i = 1; i <= n; ++i) {
            int timeRequired = 3 * w * treasures[i - 1].depth;
            for (int j = 0; j <= t; ++j) {
                dp[i][j] = dp[i - 1][j]; // Not taking the treasure
                if (j >= timeRequired) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - timeRequired] + treasures[i - 1].gold);
                }
            }
        }

        int maxGold = dp[n][t];
        vector<Treasure> selected;
        int remainingTime = t;

        for (int i = n; i > 0; --i) {
            int timeRequired = 3 * w * treasures[i - 1].depth;
            if (remainingTime >= timeRequired && dp[i][remainingTime] == dp[i - 1][remainingTime - timeRequired] + treasures[i - 1].gold) {
                selected.push_back(treasures[i - 1]);
                remainingTime -= timeRequired;
            }
        }

        if (!Case1) {
            cout << '\n';
        }
        Case1 = false;

        cout << maxGold << '\n';
        cout << selected.size() << '\n';
        for (auto it = selected.rbegin(); it != selected.rend(); ++it) {
            cout << it->depth << " " << it->gold << '\n';
        }
    }
    return 0;
}