#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


/* the input example

2
AAABBB

 */




int main () {

    int n;
    string s;
    cin>>n;
    cin>>s;
    unordered_map<char, int> Count;

    for (char i : s) {
        Count[i]++;
    }

    priority_queue<int> queue;
    for (auto& entry : Count) {
        queue.push(entry.second);
    }

    int interval = 0;

    while (!queue.empty()) {
        int cycle = 0;
        vector<int> temp;

        for (int i = 0; i <= n; ++i) {
            if (!queue.empty()) {
                temp.push_back(queue.top());
                queue.pop();
                cycle++;
            }
        }

        for (int count : temp) {
            if (--count > 0) {
                queue.push(count);
            }
        }

        interval += queue.empty() ? cycle : n + 1;
    }

    cout<< interval;


}