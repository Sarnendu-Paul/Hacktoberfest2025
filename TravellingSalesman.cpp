#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int tsp(int pos, int mask, const vector<vector<int>> &graph, vector<vector<int>> &dp, int n) {
    // If all cities have been visited, return to starting city
    if (mask == (1 << n) - 1) {
        return graph[pos][0];
    }

    // Return already computed state
    if (dp[pos][mask] != -1) return dp[pos][mask];

    int ans = INT_MAX;

    // Try to go to any unvisited city
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = graph[pos][city] + tsp(city, mask | (1 << city), graph, dp, n);
            ans = min(ans, newAns);
        }
    }

    return dp[pos][mask] = ans;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the distance matrix:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    vector<vector<int>> dp(n, vector<int>(1 << n, -1));

    int minCost = tsp(0, 1, graph, dp, n); // Start from city 0

    cout << "Minimum cost of travelling salesman path: " << minCost << endl;

    return 0;
}
