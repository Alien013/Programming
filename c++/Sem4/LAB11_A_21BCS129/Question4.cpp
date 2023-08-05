#include <bits/stdc++.h>
using namespace std;

string Pallindrone(string str, int max_changes) {
    int left=0, right=str.size()-1;
    while (left < right) {
        if (str[left] != str[right]) {
            if (max_changes > 0) {
                max_changes--;
                if (str[left] > str[right]) {
                    str[right] = str[left];
                }
                else {
                    str[left] = str[right];
                }
            }
            else {
                break;
            }
        }
        left++;
        right--;
    }
    return str;
}

int main() {

    string str1 = "3493";
    int max_changes = 1;
    cout << Pallindrone(str1, max_changes) << endl;

    string str2 = "092282";
    max_changes = 3;
    cout << Pallindrone(str2, max_changes) << endl; 
    return 0;
}
