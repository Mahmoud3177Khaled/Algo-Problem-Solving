#include<iostream>
#include<queue>
#include<map>

using namespace std;

struct CompareSecond {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second; // min heap push, smallest first
    }
};

int main() {
    int numOfCities = 0, numOfRoads = 0;
    cin >> numOfCities >> numOfRoads;

    int goldCost = 0, silverCost = 0;
    cin >> goldCost >> silverCost;

    int goldMax = 0, silverMax = 0;

    priority_queue<pair<int, int>,vector<pair<int, int>>, CompareSecond> v;
    map<int, int> proccessedVertixs;
    map<int, int> unproccessedVertixs;

    for (int i = 1; i <= numOfCities; i++)
    {
        if(i == numOfCities) {

            pair<int, int> vertixPair = pair<int, int>(i, 0);
            v.push(vertixPair);
            unproccessedVertixs[vertixPair.first] = vertixPair.second;
            continue;
        }
        pair<int, int> vertixPair = pair<int, int>(i, 1000);
        v.push(vertixPair);
        unproccessedVertixs[vertixPair.first] = vertixPair.second;
    }

    
    

    pair<int, int> adj[numOfCities+1][numOfCities+1];

    for (int i = 1; i <= numOfCities; i++)
    {
        for (int j = 1; j <= numOfCities; j++)
        {
            adj[i][j] = pair<int, int>(1000, 1000);
        }
        
    }

    while (numOfRoads--)
    {
        int from = 0, to = 0;
        cin >> from >> to;

        int goldCoins = 0, silverCoins = 0;
        cin >> goldCoins >> silverCoins;

        pair<int, int> newRoad = pair<int, int>(goldCoins*goldCost, silverCoins*silverCost);

        if((adj[from][to].first + adj[from][to].second) > newRoad.first + newRoad.second) {
            adj[from][to] = newRoad;
            adj[to][from] = newRoad;
        }
    }

    while(!v.empty()) {
        pair<int, int> minVertix = v.top();
        v.pop();

        int sourceCity = minVertix.first;

        for (int j = 1; j <= numOfCities; j++) {
            // cout << "\n";
            if((proccessedVertixs.find(j) == proccessedVertixs.end())/* || proccessedVertixs.find(sourceCity) == proccessedVertixs.end()*/) { // destination vertix in adj not proccessed yet

                // cout << sourceCity << " " << j << endl;
                // cout << adj[sourceCity][j].first << " " << adj[sourceCity][j].second << endl;

                // cout << adj[sourceCity][j].first + adj[sourceCity][j].second << " " <<  unproccessedVertixs[j] << endl;
                // cout << adj[sourceCity][j].first + adj[sourceCity][j].second << " " <<  unproccessedVertixs[sourceCity] << endl;

                // cout << goldMax << " " << silverMax << endl;


                if((adj[sourceCity][j].first != 1000) && (adj[sourceCity][j].second != 1000)
                    && (adj[sourceCity][j].first + adj[sourceCity][j].second < unproccessedVertixs[j] || adj[sourceCity][j].first + adj[sourceCity][j].second < unproccessedVertixs[sourceCity])) {

                    if(adj[sourceCity][j].first > goldMax) {
                        goldMax = adj[sourceCity][j].first;
                    }

                    if(adj[sourceCity][j].second > silverMax) {
                        silverMax = adj[sourceCity][j].second;
                    }


                    // cout << "condition hit" << endl;
                    unproccessedVertixs[j] = adj[sourceCity][j].first + adj[sourceCity][j].second;

                }
                    // cout << "added " << minVertix.first << " to proccessed" << endl;
                    proccessedVertixs[minVertix.first] = 1;
                
            }
        }
        
    }
    
    // for (int i = 1; i <= numOfCities; i++)
    // {
    //     for (int j = 1; j <= numOfCities; j++)
    //     {
    //         // adj[i][j] = pair<int, int>(1000, 1000);

    //         cout << adj[i][j].first << "/" << adj[i][j].second << " ";
    //     }

    //     cout << endl;
        
    // }

    // while (!v.empty()) {

    //     pair<int, int> showPair = v.top();
    //     v.pop();

    //     cout << showPair.first << " " << showPair.second << endl;
        
    // }

    cout << goldMax + silverMax << endl;
}