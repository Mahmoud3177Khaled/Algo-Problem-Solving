#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int childrenCount = 0, cookiesCount = 0;
    cin >> childrenCount >> cookiesCount;

    vector<int> childrenGreed;
    vector<int> cookiesSizes;

    while(childrenCount--) {
        int x = 0;
        cin >> x;
        childrenGreed.push_back(x);
    }

    while(cookiesCount--) {
        int x = 0;
        cin >> x;
        cookiesSizes.push_back(x);
    }

    sort(childrenGreed.begin(), childrenGreed.end());
    sort(cookiesSizes.begin(), cookiesSizes.end());

    int i = 0;
    int j = 0;
    int counter = 0;

    while((i != childrenGreed.size()) && (j != cookiesSizes.size())) {

        if(childrenGreed[i] <= cookiesSizes[j]) {
            counter++;
            i++;
            j++;

        } else {
            j++;
            
        }
    }

    cout << counter;

}