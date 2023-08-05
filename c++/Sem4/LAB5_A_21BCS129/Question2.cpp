#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string mostFrequentWord(string arr[], int n)
    {
        unordered_map<string, int> freq;
        unordered_map<string, int> occurrence;
        int max = 0;
        string result;
        int k = 1;

        for (int i = 0; i < n; i++)
        {
            if (occurrence.count(arr[i]) > 0)
            {
                continue;
            }

            occurrence[arr[i]] = k++;
        }

        for (int i = 0; i < n; i++)
        {

            freq[arr[i]]++;

            if (max <= freq[arr[i]])
            {

                if (max < freq[arr[i]])
                {
                    max = freq[arr[i]];
                    result = arr[i];
                }
                else
                {
                    if (occurrence[result] < occurrence[arr[i]])
                    {
                        max = freq[arr[i]];
                        result = arr[i];
                    }
                }
            }
        }

        return result;
    }
};

int main()
{

    string arr[] = {"the", "day", "is",
                    "sunny", "the", "the",
                    "the", "sunny", "is",
                    "is"};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution obj;

    cout << obj.mostFrequentWord(arr, n) << endl;    

    return 0;
}
