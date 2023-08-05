#include <iostream>
#include <map>
using namespace std;

int main()
{
    int q;
    cin >> q;
    map<pair<int, int>, int> fastest_times;
    while (q--)
    {
        int type, a, b, n;
        cin >> type >> a >> b;
        if (type == 1)
        {
            cin >> n;
            auto it = fastest_times.find({a, b});
            if (it == fastest_times.end() || n <= it->second)
            {
                fastest_times[{a, b}] = n;
            }
        }
        else
        {
            auto it = fastest_times.find({a, b});
            if (it == fastest_times.end())
            {
                cout << "unknown\n";
            }
            else
            {
                cout << it->second << '\n';
            }
        }
    }
    return 0;
}
