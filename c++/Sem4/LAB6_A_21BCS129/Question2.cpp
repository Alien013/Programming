#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int maximumUnits(vector<vector<int>> &box, int truckSize)
{
    sort(box.begin(), box.end(), [](const vector<int> &a, const vector<int> &b)
         { 
            return a[1] > b[1]; });
    int maxUnits = 0;
    int i = 0;
    while (truckSize > 0 && i < box.size())
    {
        if (box[i][0] <= truckSize)
        {
            maxUnits += box[i][0] * box[i][1];
            truckSize -= box[i][0]; 
        }
        else
        {
            maxUnits += truckSize * box[i][1];
            break;
        }
        i++;
    }
    return maxUnits;
}
int main()
{
    vector<vector<int>> box{{1, 3}, {2, 2}, {3, 1}};
    cout << maximumUnits(box, 4) << endl;
    box = {{5, 10}, {2, 5}, {4, 7}, {3, 9}};
    cout << maximumUnits(box, 10) << endl;
}