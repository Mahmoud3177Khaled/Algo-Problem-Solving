/*
Given a list of numbers A, find the length of the longest increasing subsequence in it.
A subsequence is a sequence that can be derived from the given sequence by
deleting zero or more elements without changing the order of the remaining
elements. An increasing subsequence is a subsequence in which each element is
greater than all previous elements.
For example, in the list {33 , 11 , 22 , 44}:
The subsequences {33 , 44} and {11} are increasing subsequences 
while {11 , 22 ,44} is the longest increasing subsequence.
-------
Input
-------
First line contains a single integer N (1 <= N <= 10) the length of the list A.
The second line contains N numbers (1 <= each number <= 20), the numbers in the
list A separated by spaces.
--------
Output
--------
One line containing the length of the longest increasing subsequence in A.
--------
Sample
-------
Input                   Output
5                         3
1 4 2 4 3                   
*/
#include <iostream>
using namespace std;
//like longest common subsequence
int get_longest_increasing_subsequence_length(int array[] , int array_size){
    int length_array[array_size+1][array_size];
    for (int i = 0; i < array_size; i++)
    {
        length_array[0][i] = 0;
    }
    
    for (int i = 1; i < array_size + 1; i++)
    {
        for (int j = i-1; j < array_size; j++)
        {
            if(array[j] > array[i-1] || i-1 == j){
                length_array[i][j] = length_array [i-1][j] + 1;
            }
            else{
                length_array[i][j] = length_array [i-1][j];
            }
            // cout<<length_array[i][j]<<" ";
        }
        // cout<<"\n";
    }
    int longest_increasing_subsequence_length = 0;
    for (int i = 0; i < array_size; i++)
    {
        if(length_array[i+1][i] > longest_increasing_subsequence_length){
            longest_increasing_subsequence_length = length_array[i+1][i];
        }
    }
    
    

    return longest_increasing_subsequence_length;
}

int main(){
    int array_size;
    cin>>array_size;
    int array[array_size];
    for (int i = 0; i < array_size; i++)
    {
        cin>>array[i];
    }
    int longest_increasing_subsequence_length = get_longest_increasing_subsequence_length(array,array_size);
    cout<<longest_increasing_subsequence_length;
    return 0;
}