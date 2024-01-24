#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
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

    bool checkCycleBFS(int src, unordered_map<int, bool> &visited)
    {
        queue<T> q;
        unordered_map<int, int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            for (auto neighbour : adjList[frontNode])
            {
                if (!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = frontNode;
                }
                else if (parent[frontNode] != neighbour)
                    return true;
            }
        }
        return false;
    }

    bool checkCycleDFS(int src, int parent, unordered_map<int, bool> &visited)
    {
        visited[src] = true;

        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
            {
                bool futureAns = checkCycleDFS(neighbour, src, visited);
                if (futureAns)
                    return true;
            }
            else if (neighbour != parent)
                return true;
        }
        return false;
    }

    bool checkCycleDirectedGraphUsingDFS(int src, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited)
    {
        visited[src] = true;
        dfsVisited[src] = true;
        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour])
            {
                bool futureAns = checkCycleDirectedGraphUsingDFS(neighbour, visited, dfsVisited);
                if (futureAns)
                    return true;
            }
            else if (dfsVisited[neighbour])
                return true;
        }
        dfsVisited[src] = false;
        return false;
    }
};
int main()
{
    system("cls");
    Graph<int> g;

    // int n = 5;
    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(2, 3, 0);
    // g.addEdge(3, 4, 0);
    // g.addEdge(4, 0, 0);
    // g.printAdjList();
    // cout << "\n";

    // CHECKING CYCLE IN UNDIRECTED GRAPH USING BFS
    // bool ans = false;
    // unordered_map<int, bool> visited;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //     {
    //         ans = g.checkCycleBFS(i, visited);
    //         if (ans)
    //             break;
    //     }
    // }

    // if (ans)
    //     cout << "Cycle present in the graph !";
    // else
    //     cout << "Cycle not present in the graph !";

    // CHECKING CYCLE IN UNDIRECTED GRAPH USING DFS
    // bool ans = false;
    // unordered_map<int, bool> visited;
    // for (int i = 0; i < n; i++)
    // {
    //     if (!visited[i])
    //         ans = g.checkCycleDFS(i, -1, visited);
    //     if (ans)
    //         break;
    // }
    // if (ans)
    //     cout << "Cycle present !";
    // else
    //     cout << "Cycle absent !";

    // CHECKING CYCLE IN DIRECTED GRAPH USING DFS
    int n = 5;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 0, 1);

    g.printAdjList();
    bool ans = false;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            ans = g.checkCycleDirectedGraphUsingDFS(i, visited, dfsVisited);
        if (ans)
            break;
    }
    if (ans)
        cout << "Cycle present !";
    else
        cout << "Cycle absent !";
    return 0;
}
