#include <iostream>
using namespace std;

int luckiness(int num)
{
    int largest = 0, smallest = 9;
    while (num > 0)
    {
        int digit = num % 10;
        largest = max(largest, digit);
        smallest = min(smallest, digit);
        num /= 10;
    }
    return largest - smallest;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int l, r;
        cin >> l >> r;
        int max_luck = -1, ans;
        for (int i = l; i <= r; i++)
        {
            int curr_luck = luckiness(i);
            if (curr_luck > max_luck )
            {
                max_luck = curr_luck;
                ans = i;
                if(curr_luck >= 9)
                break;  
            }
        }
        cout << ans << endl;
    }
    return 0;
}
