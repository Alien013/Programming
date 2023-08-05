#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int max = (n - 1) * 3;
        int runner_up = (n - 2) - ((n - 2) / 2);
        cout << max - runner_up * 3 << endl;
    }
    return 0;
}
