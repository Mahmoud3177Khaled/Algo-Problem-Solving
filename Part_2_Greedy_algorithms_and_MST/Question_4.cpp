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

    //cities and roads count
    int cityCount = 0, roadCount = 0;
    cin >> cityCount >> roadCount;

    //gold cost and silver cost in olympia money
    int goldCost = 0, silverCost = 0;
    cin >> goldCost >> silverCost;

    //gold max and silver max to secure all raods with a gift containing the largest of both 
    int goldMax = 0, silverMax = 0;
    //old maximums to restore maxs to if the road whose max gold or silver got saved was removed becasue of a better one
    int oldGoldMax = 0, oldSilverMax = 0;

    //hash map to map each road to its cost
    unordered_map<pair<int, int>, pair<int, int>, HashThePair> roadMap;

    //looping on all my roads
    while (roadCount--)
    {
        //road start and finish
        int from = 0, to = 0;
        cin >> from >> to;

        //gold and silver gift cost of that road
        int goldCoins = 0, silverCoins = 0;
        cin >> goldCoins >> silverCoins;

        //create pairs to put in roads map
        pair<int, int> roadKey = pair<int, int>(from, to);
        pair<int, int> roadCost = pair<int, int>(goldCoins * goldCost, silverCoins * silverCost);

        // two cases: if the road connects two new cities -> add it
        // if it doesnt -> check if the new road has cheaper gold + silver gift cost
        //     if so -> remove the old exisiting road and add the new and update the maxs
        //     if not -> dont add that road all togther and maxs stay the same

        // road desnt exist (new road)
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

        //a road connnecting these two exists
        } else {

            // the old road
            pair<int, int> existingRoad = roadMap[roadKey];

            //is the new road "cheaper" than the esisting one?
            if((existingRoad.first + existingRoad.second) > (roadCost.first + roadCost.second)) {
                
                // if yes -> remove it and add the new
                roadMap.erase(existingRoad);
                roadMap[roadKey] = roadCost;

                // but what if the gold and silver max where based on this road?

                //if the maxs where saved from this existing road that was deleted -> reset them to what was the max before they were overwritten
                if(existingRoad.first == goldMax) {
                    goldMax = oldGoldMax;
                }
                if(existingRoad.second == silverMax) {
                    silverMax = oldSilverMax;
                }

                // save before overwriting
                oldGoldMax = goldMax;
                oldSilverMax = silverMax;

                // update the maxs if the new road was essential and more expensive...
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

    //total is the maximum gift in olypian money if gold and silver that covers at most one road between 2 cities
    cout << goldMax + silverMax << endl;

    //  ######### Thank You! :) #########


}