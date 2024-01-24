#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

// We can now create a graph of any generic type
// int, char, double etc.
template <typename T>
class Graph
{
public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool isDirected)
    {
        adjList[u].push_back(v);
        if (isDirected)
            adjList[v].push_back(u);
    }

    void printAdjList()
    {
        for (auto node : adjList)
        {
            cout << node.first << "-> ";
            for (auto neighbour : node.second)
                cout << neighbour << ", ";
            cout << "\n";
        }
    }

    void bfs(T src, unordered_map<T, bool> &visited)
    {
        queue<T> q;

        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            T frontNode = q.front();
            q.pop();
            cout << frontNode << ", ";
            visited[frontNode] = true;

            // insert neighbours
            for (auto neighbour : adjList[frontNode])
            {
                if (!visited[neighbour])
                    q.push(neighbour);
            }
        }
    }

    void dfs(T src, unordered_map<T, bool> &visited)
    {
        cout << src << ", ";
        visited[src] = true;

        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
                dfs(neighbour, visited);
        }
    }
};
int main()
{
    system("cls");

    // // UNDIRECTED INPUT
    // Graph g;
    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(0, 2, 0);
    // g.printAdjList();

    // DIRECTED INPUT
    // Graph g;
    // g.addEdge(0, 1, 1);
    // g.addEdge(1, 2, 1);
    // g.addEdge(0, 2, 1);
    // g.printAdjList();

    // Graph<char> g;
    // g.addEdge('a', 'b', 0);
    // g.addEdge('b', 'c', 0);
    // g.addEdge('a', 'c', 0);
    // g.printAdjList();

    Graph<int> g;
    int n = 4;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(0, 2, 0);
    g.addEdge(2, 4, 0);
    g.printAdjList();
    cout << endl;

    unordered_map<int, bool> visited;
    cout << "Printing BFS Traversal :\n";
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.bfs(i, visited);
            cout << "\n";
        }
    }

    cout << "\n";
    unordered_map<int, bool> visited2;
    cout << "Printing DFS Traversal :\n";
    for (int i = 0; i < n; i++)
    {
        if (!visited2[i])
        {
            g.dfs(i, visited2);
            cout << "\n";
        }
    }
    return 0;
}
