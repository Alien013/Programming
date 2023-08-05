#include <bits/stdc++.h>
using namespace std;
int main() {
    pair<int , string> p1,p2;  // Initialize
    p1 = make_pair(2,"abc"); // Declare
    p2 = {3,"xyz"};

    cout << p1.first << " " << p1.second << endl;
    cout << p2.first << " " << p2.second << endl;

    // Input from user
    cin >> p1.first;
    cin >> p1.second;
    cout << p1.first << " " << p1.second << endl;

    // Array of pairs
    pair<int , int> p_array[3];
    p_array[0] = {1,2};
    p_array[1] = {2,2};
    p_array[2] = {3,2};

    for(int i=0; i<3; i++)
        cout << p_array[i].first << " " << p_array[i].second << endl;
    
    // Input from useer
    for(int i=0; i<3; i++) 
        cin >> p_array[i].first >> p_array[i].second;
    
    for(int i=0; i<3; i++)  
        cout << p_array[i].first << " " << p_array[i].second << endl;

    
    return 0;
}