#include <iostream>
#include <climits>

using namespace std;
const int N = 12; // number of vertices
const int K = 5;  // number of stages

int c[N + 1][N + 1]; // cost matrix
int Cost[N + 1];     // minimum cost array
int p[N + 1];        // path array

int multistage_graph()
{
    // initialization
    Cost[N] = 0;
    p[1] = 1;
    p[K] = N;

    // dynamic programming
    for (int i = N - 1; i >= 1; i--)
    {
        int min_cost = INT_MAX;
        int min_vertex = -1;
        for (int j = i + 1; j <= N; j++)
        {
            if (c[i][j] != -1 && c[i][j] + Cost[j] < min_cost)
            {
                min_cost = c[i][j] + Cost[j];
                min_vertex = j;
            }
        }
        Cost[i] = min_cost;
        p[i] = min_vertex;
    }

    // trace the path
    cout << "Minimum cost path: ";
    int vertex = 1;
    cout << vertex << " - ";
    for (int i = 2; i < K; i++)
    {
        vertex = p[vertex];
        cout << vertex << " - ";
    }
    cout << p[vertex] << endl;
    // return the cost
    return Cost[1];
}

int main()
{
    // initialize cost matrix
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            c[i][j] = -1; // set all values to -1 (not connected)
        }
    }
    c[1][2] = 9;
    c[1][3] = 7;
    c[1][4] = 3;
    c[1][5] = 2;
    c[2][6] = 4;
    c[2][7] = 2;
    c[2][8] = 1;
    c[3][6] = 2;
    c[3][7] = 7;
    c[4][8] = 11;
    c[5][7] = 11;
    c[5][8] = 8;
    c[6][9] = 6;
    c[6][10] = 5;
    c[7][9] = 4;
    c[7][10] = 3;
    c[8][10] = 5;
    c[8][11] = 6;
    c[9][12] = 4;
    c[10][12] = 2;
    c[11][12] = 5;

    int cost = multistage_graph();
    cout << "Cost of the path: " << cost << endl;

    return 0;
}
