#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <stack>
#include <limits.h>
#include <set>
using namespace std;
template <typename T>
class Graph
{
public:
    unordered_map<T, list<pair<T, T>>> adjList;

    void addEdge(T u, T v, T weight, bool isDirected)
    {
        adjList[u].push_back({v, weight});
        if (!isDirected)
            adjList[v].push_back({u, weight});
    }

    void printAdjList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "-> ";
            for (auto j : node.second)
                cout << "(" << j.first << ", " << j.second << "), ";
            cout << "\n";
        }
    }

    vector<int> bellmanFordAlgo(int n, int src)
    {
        // assuming directed and weighted graph
        vector<int> dist(n, INT_MAX);

        dist[src] = 0;

        // relaxation needs to be done n-1 times
        for (int i = 0; i < n - 1; i++)
        {
            // run the loop for all edges
            for (auto t : adjList)
            {
                for (auto nbr : t.second)
                {
                    int u = t.first;
                    int v = nbr.first;
                    int wt = nbr.second;
                    if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
                        dist[v] = dist[u] + wt;
                }
            }
        }
        return dist;
    }

    bool checkForNegativeCycleUsingBellmanFordAlgorithm(int n, int src)
    {
        // run algo n-1 times
        vector<int> dist = bellmanFordAlgo(n, src);

        // run algo 1 more time
        bool flag = false;
        for (auto t : adjList)
        {
            for (auto nbr : t.second)
            {
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;
                if (dist[u] != INT_MAX && dist[u] + wt < dist[v])
                {
                    flag = true;
                    break;
                }
            }
        }
        return flag;
    }

    void flloydWarshallAlgo(int n)
    {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (auto t : adjList)
        {
            for (auto nbr : t.second)
            {
                int u = t.first;
                int v = nbr.first;
                int wt = nbr.second;

                dist[u][v] = wt;
            }
        }

        for (int helper = 0; helper < n; helper++)
        {
            for (int src = 0; src < n; src++)
            {
                for (int dest = 0; dest < n; dest++)
                    dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
            }
        }

        cout << "\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << dist[i][j] << " ";
            cout << "\n";
        }
    }
};
int main()
{
    system("cls");

    // HELPER CODE FOR BELLMAN FORD ALGORITHM
    // Graph<int> g;
    // g.addEdge(0, 1, -1, 1);
    // g.addEdge(0, 2, 4, 1);
    // g.addEdge(1, 2, 3, 1);
    // g.addEdge(1, 3, 2, 1);
    // g.addEdge(1, 4, 2, 1);
    // g.addEdge(3, 1, 1, 1);
    // g.addEdge(3, 2, 5, 1);
    // g.addEdge(4, 3, -3, 1);
    // g.printAdjList();

    // vector<int> ans = g.bellmanFordAlgo(5, 0);
    // for (int i : ans)
    //     cout << i << " ";

    // cout << "\n";
    // if (g.checkForNegativeCycleUsingBellmanFordAlgorithm(5, 0))
    //     cout << "-VE EDGE CYCLE PRESENT";
    // else
    //     cout << "-VE EDGE CYCLE NOT PRESENT";

    // HELPER CODE FOR FLYOD WARSHALL ALGORITHM
    Graph<int> g;
    g.addEdge(0, 1, 3, 1);
    g.addEdge(0, 3, 5, 1);
    g.addEdge(1, 0, 2, 1);
    g.addEdge(1, 3, 4, 1);
    g.addEdge(2, 1, 1, 1);
    g.addEdge(3, 2, 2, 1);
    g.printAdjList();

    g.flloydWarshallAlgo(4);
    return 0;
}