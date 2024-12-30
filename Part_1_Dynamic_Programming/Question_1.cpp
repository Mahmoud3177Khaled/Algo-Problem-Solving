#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;



string createKey(int index, int currentSum) {
    return to_string(index) + "," + to_string(currentSum);
}

int recurse(const vector<int>& coins, int index, int currentSum, int total) {
    unordered_map<string, int> memo;

    if (index == coins.size()) {
        return abs((2 * currentSum) - total);
    }

    string key = createKey(index, currentSum);

    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    int include = recurse(coins, index + 1, currentSum + coins[index], total);

    int exclude = recurse(coins, index + 1, currentSum, total);

    memo[key] = min(include, exclude);
    return memo[key];
}


int main() {

    int n,m;
    cin>>n;
    vector<int>coins;
    while(n--){
        cin>>m;
        coins.clear();
        int coin,total = 0;
        for (int i = 0; i < m; ++i) {
            cin>>coin;
            total+=coin;
            coins.emplace_back(coin);
        }

        cout<<recurse(coins, 0, 0, total)<<'\n';

    }
    return 0;
}
