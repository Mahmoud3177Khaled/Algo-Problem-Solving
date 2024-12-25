/*
Our friends at TXT have a bug-ridden message sender.
Specifically, this sender can send a string s to TXT or others, but if the character “w”
is entered, it will send “uu” instead of “w”, and if the character “m” is entered, it will
send “nn” instead of “m”.
That day TXT received a message from his friend, and he knew the message was
wrong.
Now please can you help TXT calculate the number of the possibilities of the original
string s
  //------
    Input
  //------
    The input consists of a line containing a string s contains only lowercase Latin
    letters. (1 ≤ | s | ≤ 10^5)
  //------
    Output
  //------
    Print an integer - the original string s number of possibilities, modulo 10^9+7.


ouuoharinn  4  --> “ouuoharinn”,“ouuoharim”, “owoharim”, and “owoharinn”
banana      1  
nnn         3  --> “nm”, “mn” and “nnn”
amanda      0  --> the message sender will not send “m”

*/

#include <iostream>
using namespace std;

long long combination(int n, int r) {
    if (r > n)
    { 
        return 0;
    }
    if (r > n - r) {
        r = n - r;
    }
    long long result = 1;
    for (int i = 1; i <= r; i++) {
        result *= (n - (r - i)); 
        result /= i;              
    }
    return result;
}

int get_original_string_possibilities_number(string message){
    int possibilities_array[message.size()];
    possibilities_array[0] = 1;
    int n = 0, u = 0;
    if(message[0] == 'n'){
        n++;
    }
    else if(message[0] == 'u'){
        u++;
    }
    for (int i = 1; i < message.size(); i++)
    {
        if(message[i] == 'n'){
            n++;
            if(n == 0){
            possibilities_array[i] = possibilities_array[i-1];
            }else{
            possibilities_array[i] = possibilities_array[i-n] *combination(n,2)  ;
            }
        }
        else if (message[i] == 'u'){
            u++;
            if(u == 0){
            possibilities_array[i] = possibilities_array[i-1];
            }else{
            possibilities_array[i] = possibilities_array[i-u] *combination(u,2)  ;
            }
        }
        else{
            n = 0;
            u = 0;
            possibilities_array[i] = possibilities_array[i-1];
        }

    }
    

    return possibilities_array[message.size()-1];
}

int main(){
    cout<<"Enter the message: ";
    string message;
    cin>>message;
    int original_string_possibilities_number = get_original_string_possibilities_number(message);
    cout<<"the number of the possibilities of the original message is: "<<original_string_possibilities_number;


}