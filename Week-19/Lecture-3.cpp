#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <stack>
#include <queue>
using namespace std;
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

    void topologicalSortDFS(T src, unordered_map<T, bool> &visited, stack<T> &ans)
    {
        visited[src] = true;

        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
                topologicalSortDFS(neighbour, visited, ans);
        }
        // while returning store the node in stack
        ans.push(src);
    }

    void topologicalSortBFS(int n, vector<int> &ans)
    {
        queue<T> q;
        unordered_map<int, int> inDegree;

        // Populating the indegree map using adjList
        for (auto i : adjList)
        {
            int src = i.first;
            for (auto nbr : adjList[src])
                inDegree[nbr]++;
        }

        // Push all the nodes curently having indegree as 0
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        // BFS logic to be applied
        while (!q.empty())
        {
            T fNode = q.front();
            q.pop();

            cout << fNode << " ";
            ans.push_back(fNode);

            for (auto nbr : adjList[fNode])
            {
                inDegree[nbr]--;
                if (inDegree[nbr] == 0)
                    q.push(nbr);
            }
        }
    }
};
int main()
{
    system("cls");
    Graph<int> g;
    int n = 8;
    g.addEdge(2, 4, 1);
    g.addEdge(2, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 3, 1);
    g.addEdge(3, 7, 1);
    g.addEdge(6, 7, 1);
    g.addEdge(7, 0, 1);
    g.addEdge(7, 1, 1);
    g.printAdjList();

    unordered_map<int, bool> visited;
    stack<int> ans;
    cout << "Printing topological sort using DFS:\n";
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            g.topologicalSortDFS(i, visited, ans);
    }
    while (!ans.empty())
    {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << "\n";

    // works for both connected or disconnected
    vector<int> ans2;
    cout << "Printing topological sort using BFS:\n";
    g.topologicalSortBFS(n, ans2);

    cout << "\n";
    if (ans2.size() == n)
        cout << "It is a valid topological sort";
    else
        cout << "It is not a valid topological sort";
    return 0;
}
