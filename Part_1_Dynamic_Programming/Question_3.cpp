#include <iostream>
#include <vector>

using namespace std;

int main() {
    // int t = 0;

    // cin >> t;
    // while(t--) {
        int capacity = 0, numOfBags = 0;
        cin >> capacity >> numOfBags;

        int bagCounter = numOfBags;

        vector<int> weights;
        vector<int> values;

       int dp[numOfBags+1][capacity+1]; 

        while(bagCounter--) {
            int value = 0, weight = 0;
            cin >> weight >> value;

            weights.push_back(weight);
            values.push_back(value);
        }

        for(int bag = 0; bag <= numOfBags; bag++) {
            dp[bag][0] = 0;
        }

        for(int cap = 0; cap <= capacity; cap++) {
            dp[0][cap] = 0;
        }

        for (int bag = 1; bag <= numOfBags; bag++)
        {
            for (int cap = 1; cap <= capacity; cap++)
            {
                if(cap - weights[bag-1] >= 0) {
                    dp[bag][cap] = max(dp[bag-1][cap], dp[bag-1][cap-weights[bag-1]] + values[bag-1]);
                } else {
                    dp[bag][cap] = dp[bag-1][cap];
                }
            }
            
        }

        cout << dp[numOfBags][capacity];
        




    // }
}