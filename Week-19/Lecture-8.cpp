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
    unordered_map<T, list<T>> adjList;
    unordered_map<int, list<int>> adjListNew;

    void addEdge(T u, T v, bool isDirected)
    {
        // directed -> 1
        // not directed -> 0
        adjList[u].push_back(v);
        if (!isDirected)
            adjList[v].push_back(u);
    }

    void printAdjList()
    {
        for (auto node : adjList)
            cout << node.first << "-> " << node.second << "\n";
    }

    // Finds the topological ordering
    void dfs(int src, stack<int> &s, unordered_map<int, bool> &visited)
    {
        visited[src] = true;
        for (auto nbr : adjList[src])
        {
            if (!visited[nbr])
                dfs(nbr, s, visited);
        }
        s.push(src);
    }

    void dfsFinal(int src, unordered_map<int, bool> &visited)
    {
        visited[src] = true;
        cout << src << ", ";
        for (auto nbr : adjListNew[src])
        {
            if (!visited[nbr])
                dfsFinal(nbr, visited);
        }
    }

    // Function to find the number of strongly connected components
    // KOSARAJU ALGORITHM
    int countNumberOfStronglyConnectedComponents(int &n)
    {
        // 1.) FINDING TOPOLOGICAL SORT ORDERING
        stack<int> s;
        unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, s, visited);
            }
        }

        // 2.) REVERSING ALL THE EDGES

        for (auto t : adjList)
        {
            for (auto nbr : t.second)
            {
                int u = t.first;
                int v = nbr;
                adjListNew[v].push_back(u);
            }
        }

        // 3.) TRAVERSE USING DFS ACCORDING TO ORDERING
        int count = 0;
        unordered_map<int, bool> visited2;
        while (!s.empty())
        {
            int node = s.top();
            s.pop();
            if (!visited2[node])
            {
                cout << "Printing " << (count + 1) << " SSC : ";
                dfsFinal(node, visited2);
                cout << "\n";
                count++;
            }
        }
        return count;
    }

    // Function to find the number of bridgest in a graph (Tarzan's algorithm)
    void findNumberOfBridges(int src, int parent, int &timer, vector<int> &timeInsertion, vector<int> &lowTime, unordered_map<int, bool> &visited)
    {
        visited[src] = true;
        timeInsertion[src] = timer;
        lowTime[src] = timer;
        timer++;

        for (auto nbr : adjList[src])
        {
            if (nbr == parent)
                continue;

            if (!visited[nbr])
            {
                // DFS CALL
                findNumberOfBridges(nbr, src, timer, timeInsertion, lowTime, visited);

                // UPDATE THE VALUE OF LOW
                lowTime[src] = min(lowTime[src], lowTime[nbr]);

                // CHECK FOR BRIDGE
                // comparing the child's lowtime with the parents "insertion" time since the insertion time of any node does not changes while the low time can update and it can give wrong answer. Insertion time remain constant hence we should compare lowTime[src] with timeInsertion[src]
                if (lowTime[nbr] > timeInsertion[src])
                    cout << nbr << " ----- " << src << " is a bridge !\n";
            }
            // node is visited and is not a parent (since parent condition checked above)
            else
                // update low
                lowTime[src] = min(lowTime[src], lowTime[nbr]);
        }
    }
};
int main()
{
    system("cls");
    Graph<int> g;
    // g.addEdge(0, 1, 1);
    // g.addEdge(1, 2, 1);
    // g.addEdge(2, 3, 1);
    // g.addEdge(3, 0, 1);
    // g.addEdge(2, 4, 1);
    // g.addEdge(4, 5, 1);
    // g.addEdge(5, 6, 1);
    // g.addEdge(6, 4, 1);
    // g.addEdge(6, 7, 1);
    // int numberOfNodes = 8;
    // cout << "Number of strongly connected components is : " << g.countNumberOfStronglyConnectedComponents(numberOfNodes);

    // n=5
    // g.addEdge(0, 1, 0);
    // g.addEdge(0, 2, 0);
    // g.addEdge(0, 1, 0);
    // g.addEdge(2, 1, 0);
    // g.addEdge(0, 3, 0);
    // g.addEdge(3, 4, 0);

    // n=5
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(3, 4, 0);

    // n=7
    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(2, 0, 0);
    // g.addEdge(1, 6, 0);
    // g.addEdge(3, 1, 0);
    // g.addEdge(1, 4, 0);
    // g.addEdge(3, 5, 0);
    // g.addEdge(4, 5, 0);

    int timer = 0;
    int numberOfNodes = 5;
    vector<int> timeInsertion(numberOfNodes);
    vector<int> lowTime(numberOfNodes);
    unordered_map<int, bool> visited;
    g.findNumberOfBridges(0, -1, timer, timeInsertion, lowTime, visited);

    // CRITICAL CONNECTIONS IN A NETWORK QUESTION ON LEETCODE
    // https://leetcode.com/problems/critical-connections-in-a-network/description/

    return 0;
}