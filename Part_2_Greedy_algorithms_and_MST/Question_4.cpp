#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cctype>

using namespace std;

//road
struct Link {
    int node1;
    int node2;
    int gold_cost;
    int silver_cost;
};

// input
int read_input() {
    int result = 0;
    int ch = getchar();

    while (!isdigit(ch)) {
        ch = getchar();
    }

    while (isdigit(ch)) {
        result = ((result << 3) + (result << 1) + (ch ^ 48)); 
        ch = getchar();
    }

    return result;
}

int num_nodes;
int num_edges;
int cost_gold;
int cost_silver;

// sorting on gold cost
bool compare_gold(const Link& l1, const Link& l2) {
    return (l1.gold_cost < l2.gold_cost);
}

//sorting on silver cost
bool compare_silver(const Link& l1, const Link& l2) {
    return (l1.silver_cost < l2.silver_cost);
}

long long min_cost = LLONG_MAX;

int parent[210];
Link links[51000];

vector<Link> edge_data;

// Initialize Union-Find data structure
void initialize_union_find() {
    for (int i = 0; i <= num_nodes; i++) {
        parent[i] = i;
    }
}

// Find the representative of a set
int find_parent(int node) {
    if(parent[node] == node) {
        return node;
    } else {
        return parent[node] = find_parent(parent[node]);
    }
    // return parent[node] == node ? node : (parent[node] = find_parent(parent[node]));
}


int main() {

    // Input the values for num_nodes, num_edges, cost_gold, cost_silver
    num_nodes = read_input();
    num_edges = read_input();
    cost_gold = read_input();
    cost_silver = read_input();

    //fill links with roads
    for (int i = 0; i < num_edges; i++) {
        links[i].node1 = read_input();
        links[i].node2 = read_input();
        links[i].gold_cost = read_input();
        links[i].silver_cost = read_input();
    }

    //sort by silver
    sort(links, links + num_edges, compare_silver);

    for (int i = 0; i < num_edges; i++) {
        edge_data.push_back(links[i]);

        //sort by gold
        sort(edge_data.begin(), edge_data.end(), compare_gold);
        
        //start unionfind
        initialize_union_find();

        int edge_count = 0;
        int max_gold_cost = 0;
        auto cycle_edge = edge_data.end();

        //MSt with Kruskal
        for (auto link = edge_data.begin(); link != edge_data.end(); link++) {
            int parent1 = find_parent(link->node1);
            int parent2 = find_parent(link->node2);

            if (parent1 != parent2) {
                parent[parent1] = parent2; 
                edge_count++;
                max_gold_cost = link->gold_cost;
            }

            else {
                cycle_edge = link;
            }
        }

        //found a cycle remove it
        if (cycle_edge != edge_data.end()) {
            edge_data.erase(cycle_edge);
        }

        // update minimums with new min road
        if (edge_count == num_nodes - 1) {
            min_cost = min(min_cost, links[i].silver_cost * (long long)cost_silver + max_gold_cost * (long long)cost_gold);
        }
    }

    //output
    if (min_cost == LLONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_cost << endl;
    }

}
