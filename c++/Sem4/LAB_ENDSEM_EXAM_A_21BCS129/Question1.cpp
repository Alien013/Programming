#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A = 0, B = 7, C = 4;
    while (B != 2 && C != 2)
    { 
        if (B == 7)
        { 
            if (C == 4)
            {
                B -= (4 - C);
                C = 0;
            }
            else
            {
                B -= (10 - A);
                A = 0;
            }
        }
        else if (C == 4)
        { 
            if (B == 0)
            {
                B += A;
                A = 0;
            }
            else
            {
                C -= (7 - B);
                B = 7;
            }
        }
        else
        { 
            if (B < C)
            {
                C -= (7 - B);
                B = 7;
            }
            else
            {
                B -= (4 - C);
                C = 4;
            }
        }
    }

    if (B == 2)
        cout << "2 litres of water is left in Container B\n";
    else
        cout << "2 litres of water is left in Container C\n";

    return 0;
}
