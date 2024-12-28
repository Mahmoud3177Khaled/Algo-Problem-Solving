#include <iostream>
#include <unordered_map>

using namespace std;

struct HashThePair {

    size_t operator()(const pair<int, int> p) const {
        size_t h1 = hash<int>{}(p.first);
        size_t h2 = hash<int>{}(p.second);

        return h1 ^ (h2 << 1);
    }
};

int main() {

    int cityCount = 0, roadCount = 0;
    cin >> cityCount >> roadCount;

    int goldCost = 0, silverCost = 0;
    cin >> goldCost >> silverCost;

    int goldMax = 0, silverMax = 0;
    int oldGoldMax = 0, oldSilverMax = 0;

    unordered_map<pair<int, int>, pair<int, int>, HashThePair> roadMap;

    while (roadCount--)
    {
        int from = 0, to = 0;
        cin >> from >> to;

        int goldCoins = 0, silverCoins = 0;
        cin >> goldCoins >> silverCoins;

        pair<int, int> roadKey = pair<int, int>(from, to);
        pair<int, int> roadCost = pair<int, int>(goldCoins * goldCost, silverCoins * silverCost);

        if(roadMap.find(roadKey) == roadMap.end()) {
            roadMap[roadKey] = roadCost;

            oldGoldMax = goldMax;
            oldSilverMax = silverMax;

            if(roadCost.first > goldMax) {
                goldMax = roadCost.first;
            }
            if(roadCost.second > silverMax) {
                silverMax = roadCost.second;
            }

        } else {
            pair<int, int> existingRoad = roadMap[roadKey];

            if((existingRoad.first + existingRoad.second) > (roadCost.first + roadCost.second)) {

                roadMap.erase(existingRoad);
                roadMap[roadKey] = roadCost;

                if(existingRoad.first == goldMax) {
                    goldMax = oldGoldMax;
                }
                if(existingRoad.second == silverMax) {
                    silverMax = oldSilverMax;
                }


                oldGoldMax = goldMax;
                oldSilverMax = silverMax;

                if(roadCost.first > goldMax) {
                    goldMax = roadCost.first;
                }
                if(roadCost.second > silverMax) {
                    silverMax = roadCost.second;
                }

            }
        }



    
    }
    
    // for(auto p : roadMap) {
    //     cout << p.first.first << "->" << p.first.second << "  " << p.second.first << " " << p.second.second << endl;
    // }

    cout << goldMax + silverMax << endl;


}