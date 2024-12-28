#include <iostream>
#include <queue>
using namespace std;

bool is_there_a_path(bool **graph,int number_of_vertices, int source , int destination){
    bool is_connected[number_of_vertices] = {};
    bool is_visited[number_of_vertices] = {};
    queue<int> q;
    is_connected[source] = true;
    q.push(source);
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        is_visited[vertex] = true;
        for (int i = 0; i < number_of_vertices; i++)
        {
            if (graph[vertex][i] == true) 
            {
                is_connected[i] = true;
                if (is_visited[i] == false)
                {
                    q.push(i);
                }
                
            }
            
        }
        
    }
    
    return is_connected[destination];
}

int main(){
    int number_of_vertices;
    cin>>number_of_vertices;
    bool **graph = new bool*[number_of_vertices];
    for (int i = 0; i < number_of_vertices; i++)
    {
        graph[i]= new bool[number_of_vertices];
    }
    for (int i = 0; i < number_of_vertices; i++) {
        for (int j = 0; j < number_of_vertices; j++) {
            graph[i][j] = false; 
        }
    }
    string edges_string,number_string1  = "",number_string2 = "";
    cin>>edges_string;
    bool is_first_number;
    for (int i = 1; i < edges_string.size()-1; i++)
    {
        if(edges_string[i] == '['){
            is_first_number = true;
        }
        else if(edges_string[i] == ','){
            is_first_number = false;
        }
        else if(edges_string[i] == ']'){
            graph[stoi(number_string1)][stoi(number_string2)] = true;
            graph[stoi(number_string2)][stoi(number_string1)] = true;
            number_string1 = "";
            number_string2 = "";
        }
        else if(edges_string[i] >= '0' && edges_string[i] <= '9'){
            if(is_first_number){
                number_string1 += edges_string[i];
            }
            else{
                number_string2 += edges_string[i];
            }
        } 
    }
    // for (int i = 0; i < number_of_vertices; i++)
    // {
    //     for (int j = 0; j < number_of_vertices; j++)
    //     {
    //         cout<<graph[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    int source , destination;
    cin>>source >> destination;
    bool path = is_there_a_path(graph,number_of_vertices,source,destination);
    cout<<path;
    for (int i = 0; i < number_of_vertices; i++)
    {
        delete graph[i];
    }
    delete graph;
    return 0;
}
/*

3
[[0,1],[1,2],[2,0]]
0 2



6
[[0,1],[0,2],[3,5],[5,4],[4,3]]
0 5

*/