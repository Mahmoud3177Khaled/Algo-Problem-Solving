#include <iostream>
#include <vector>

using namespace std;

struct Treasure {
    int depth;
    int value;
};

int main() {
    int T, k, n;
    cin >> T >> k >> n;

    Treasure treasures[n]; // Fixed size since n is 3

    for (int i = 0; i < n; ++i) {
        cin >> treasures[i].depth >> treasures[i].value;
    }

    int dp[T + 1];
    for (int i = 0; i < T + 1; ++i) {
        dp[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        int time = 3 * k * treasures[i].depth;
        for (int t = T; t >= time; --t) {
            dp[t] = max(dp[t], dp[t - time] + treasures[i].value);
        }
    }


    vector<Treasure> maximum;
    int t = T;
    for (int i = n - 1; i >= 0; --i) {
        int timeRequired = 3 * k * treasures[i].depth;
        if (t >= timeRequired && dp[t] == dp[t - timeRequired] + treasures[i].value) {
            maximum.push_back(treasures[i]);
            t -= timeRequired;
        }
    }

    int max = dp[T];
    cout << max << "\n";

    cout << maximum.size() << "\n";

    for (auto treasure: maximum) {
        cout << treasure.depth << " " << treasure.value << "\n";
    }

    return 0;
}
