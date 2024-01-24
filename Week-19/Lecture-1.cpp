#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
using namespace std;
class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEdge(int u, int v, int weight, bool isDirected)
    {
        adjList[u].push_back({v, weight});
        if (isDirected)
            adjList[v].push_back({u, weight});
    }

    void printAdjList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "-> ";
            for (auto neighbour : node.second)
                cout << "(" << neighbour.first << "," << neighbour.second << "), ";
            cout << "\n";
        }
    }
};
int main()
{
    system("cls");

    // Representation of a graph using adjacency matrix
    /*int n;
    cout << "Enter the number of nodes in the graph : ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n, 0));

    int e;
    cout << "Enter the number of edges in the graph : ";
    cin >> e;

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }*/

    // // UNDIRECTED INPUT
    // Graph g;
    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(0, 2, 0);
    // g.printAdjList();

    // DIRECTED INPUT
    Graph g;
    g.addEdge(0, 1, 5, 1);
    g.addEdge(1, 2, 8, 1);
    g.addEdge(0, 2, 6, 1);
    g.printAdjList();

    return 0;
}
