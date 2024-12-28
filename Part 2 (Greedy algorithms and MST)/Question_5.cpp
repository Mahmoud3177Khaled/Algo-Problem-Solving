#include <iostream>
#include <queue>
using namespace std;
#define INT_MAX 0x7fffffff

int power(int element,int exponent) {
    if (exponent == 0) {
        return 1;
    }
    if (exponent ==1) {
        return element;
    }
    int temp =element*element;
    int result = power(temp,exponent/2);
    if (exponent %2 == 1) {
        return result*element;
    }
    return result;
}

string to_binary(int number) {
    if (number == 0) {
        return "0";
    }
    string binary = "";
    while (number > 0) {
        binary = to_string(number % 2) + binary;  
        number /= 2;
    }
    return binary;
}

int minimum_unvisited_city_length(bool is_visited[] , int* shortest_paths_length,int number_of_cities){
    int city_length = INT_MAX;
    int city_index = -1;
    for (int i = 0; i < number_of_cities; i++)
    {
        if (!is_visited[i] && shortest_paths_length[i] < city_length)
        {
            city_length = shortest_paths_length[i];
            city_index = i;
        }
        
    }
    return city_index;
}

int* shortest_path_from(int **map ,int number_of_cities, int Current_city){
    bool is_visited[number_of_cities];
    int* shortest_paths_length = new int[number_of_cities];
    for (int i = 0; i < number_of_cities; i++)
    {
        shortest_paths_length[i] =INT_MAX;
    }
    shortest_paths_length[Current_city] = 0;
    for (int i = 0; i < number_of_cities; i++)
    {
        int city = minimum_unvisited_city_length(is_visited,shortest_paths_length,number_of_cities);
        is_visited[city]=true;
        for (int j = 0; j < number_of_cities; j++)
        {
            if (map[city][j] != -1 && (shortest_paths_length[city] + map[city][j]) < shortest_paths_length[j])
            {
                shortest_paths_length[j] = shortest_paths_length[city] + map[city][j];
            }
        }
        
    }
    return shortest_paths_length;
}
int main(){
    int number_of_cities , number_of_roads;
    cin>>number_of_cities>>number_of_roads;
    int city1, city2 , length;
    int **map = new int*[number_of_cities];
    for (int i = 0; i < number_of_cities; i++)
    {
        map[i]= new int[number_of_cities];
    }
    for (int i = 0; i < number_of_cities; i++) {
        for (int j = 0; j < number_of_cities; j++) {
            map[i][j] = -1; 
        }
    }
    for(int i = 0 ; i < number_of_roads ;i++){
        cin>>city1>>city2>>length;
        map[city1-1][city2-1]=power(2,length);
        map[city2-1][city1-1]=power(2,length);
    }
    // for (int i = 0; i < number_of_cities; i++) {
    //     for (int j = 0; j < number_of_cities; j++) {
    //         cout<<map[i][j]<<" "; 
    //     }
    //     cout<<"\n";
    // }
    int *shortest_path_from_city;
    int sum = 0;
    for (int i = number_of_cities; i > 1; i--)
    {
        shortest_path_from_city = shortest_path_from(map,i,i-1);
        for (int j = 0; j < i-1; j++)
        {
            // cout<<shortest_path_from_city[j]<<" ";
            sum += shortest_path_from_city[j];
        }
        // cout<<"\n";
    }
        cout<<sum;
        cout<<to_binary(sum);
    return 0 ;
}

/*

5 6
1 3 5
4 5 0
2 1 3
3 2 1
4 3 4
4 2 2

*/