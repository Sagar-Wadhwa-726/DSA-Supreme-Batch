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
        if (isDirected)
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

    void shortestPathBFS(T &src, T &dest)
    {
        queue<T> q;
        unordered_map<T, bool> visited;
        unordered_map<T, T> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty())
        {
            T frontNode = q.front();
            q.pop();

            // insert neighbours
            for (auto neighbour : adjList[frontNode])
            {
                if (!visited[neighbour.first])
                {
                    q.push(neighbour.first);
                    visited[neighbour.first] = true;
                    parent[neighbour.first] = frontNode;
                }
            }
        }

        vector<int> ans;
        int node = dest;

        while (node != -1)
        {
            ans.push_back(node);
            node = parent[node];
        }

        reverse(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << ", ";
    }

    void topologicalSortDFS(int src, unordered_map<int, bool> &visited, stack<int> &ans)
    {
        visited[src] = true;

        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour.first])
                topologicalSortDFS(neighbour.first, visited, ans);
        }

        ans.push(src);
    }

    void shortestPathDFS(int dest, stack<int> topologicalSortOrder, int n)
    {
        vector<int> dist(n, INT_MAX);
        int src = topologicalSortOrder.top();
        topologicalSortOrder.pop();
        dist[src] = 0;

        for (auto neighbour : adjList[src])
        {
            if (dist[src] + neighbour.second < dist[neighbour.first])
                // if this distance is smaller, update the distance
                dist[neighbour.first] = dist[src] + neighbour.second;
        }

        while (!topologicalSortOrder.empty())
        {
            int topElement = topologicalSortOrder.top();
            topologicalSortOrder.pop();

            if (dist[topElement] != INT_MAX)
            {
                for (auto neighbour : adjList[topElement])
                {
                    if (dist[topElement] + neighbour.second < dist[neighbour.first])
                        dist[neighbour.first] = dist[topElement] + neighbour.second;
                }
            }
        }

        for (auto i : dist)
            cout << i << " ";
    }

    void shortestDistanceDijkstra(int src, int n)
    {
        vector<int> dist(n, INT_MAX);
        set<pair<int, int>> st;
        dist[src] = 0;
        st.insert({0, src});

        while (!st.empty())
        {
            // fetch the first element from the set. Iterator will be returned, dereference it to get the actual value
            auto topElement = *(st.begin());
            int node = topElement.second;
            int nodeDistance = topElement.first;

            // pop from set
            st.erase(st.begin());

            for (auto neighbour : adjList[node])
            {
                if (nodeDistance + neighbour.second < dist[neighbour.first])
                {
                    // we need to update the distance, if the entry is present in the set, we need to update that entry in the set. Else we need to create a new entry in the set
                    auto result = st.find({dist[neighbour.first], neighbour.first});

                    if (result != st.end())
                        // no function to update in set, hence remove this entry and push a new entry
                        st.erase(result);

                    dist[neighbour.first] = nodeDistance + neighbour.second;
                    st.insert({dist[neighbour.first], neighbour.first});
                }
            }
        }

        for (auto i : dist)
            cout << i << " ";
    }
};
int main()
{
    system("cls");
    Graph<int> g;

    // FINDING THE SHORTEST PATH USING BFS ALGORITHM IN CASE OF UNDIRECTED GRAPH (PRINTING THE ACTUAL PATH USING THE PARENT MAP)
    // g.addEdge(0, 1, 1, 0);
    // g.addEdge(1, 2, 1, 0);
    // g.addEdge(2, 3, 1, 0);
    // g.addEdge(3, 4, 1, 0);
    // g.addEdge(0, 5, 1, 0);
    // g.addEdge(5, 4, 1, 0);
    // g.addEdge(0, 6, 1, 0);
    // g.addEdge(6, 7, 1, 0);
    // g.addEdge(7, 8, 1, 0);
    // g.addEdge(8, 4, 1, 0);
    // g.addEdge(5, 4, 1, 0);
    // g.printAdjList();
    // int src = 0;
    // int dest = 4;
    // g.shortestPathBFS(src, dest);

    // FINDING THE SHORTEST DISTANCE FROM THE SOURCE NODE TO EVERY OTHER NODE IN THE GRAPH USING DFS ALGORITHM IN CASE OF DIRECTED GRAPH USING TOPOLOGICAL SORT
    // int n = 5; // number of nodes
    // g.addEdge(0, 1, 5, 0);
    // g.addEdge(0, 2, 3, 0);
    // g.addEdge(2, 1, 2, 0);
    // g.addEdge(1, 3, 3, 0);
    // g.addEdge(2, 3, 5, 0);
    // g.addEdge(2, 4, 6, 0);
    // g.addEdge(4, 3, 1, 0);

    // stack<int> ans; // -> stack to store the topological sort in an order
    // unordered_map<int, bool> visited;
    // g.topologicalSortDFS(0, visited, ans);

    // int dest = 3;
    // here we are finding the shortest path from the source node to every other node
    // (kind of based on Dijkstra's algorithm) using topological sort. In case we don't need just
    // the distance and we want the actual path also, then here again we will require to maintain
    // a parent array
    // g.shortestPathDFS(dest, ans, n);

    // FINDING THE SHORTEST DISTANCE FROM THE SOURCE NODE TO EVERY NODE IN THE GRAPH USING DIJKSTRA'S ALGORITHM IN CASE OF DIRECTED GRAPH WITHOUT THE NEED OF TOPOLOGICAL SORT
    g.addEdge(6, 3, 2, 1);
    g.addEdge(6, 1, 14, 1);
    g.addEdge(3, 1, 9, 1);
    g.addEdge(3, 2, 10, 1);
    g.addEdge(1, 2, 7, 1);
    g.addEdge(2, 4, 15, 1);
    g.addEdge(4, 3, 11, 1);
    g.addEdge(6, 5, 9, 1);
    g.addEdge(4, 5, 6, 1);
    g.printAdjList();

    int src = 6;
    int n = 7; // -> number of nodes

    g.shortestDistanceDijkstra(src, n);

    return 0;
}