#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

class Creation
{
public:
    vector<vector<int>> buildAdj(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n + 1);
        for (vector<int> eg : edges)
        {

            int u = eg[0];
            int v = eg[1];

            adj[u].push_back(v);
            // adj[v].push_back(u);
        }

        return adj;
    }
    void GraphCreation(vector<vector<int>> &adj)
    {
        adj[1].push_back(2);
        adj[1].push_back(3);
        adj[2].push_back(1);
        adj[2].push_back(4);
        adj[3].push_back(1);
        adj[3].push_back(4);
        adj[4].push_back(2);
        adj[4].push_back(3);
    }
    void DisconnectedGraph(vector<vector<int>> &adj)
    {
        adj[1].push_back(2);
        adj[1].push_back(3);
        adj[2].push_back(1);
        adj[2].push_back(3);
        adj[3].push_back(1);
        adj[3].push_back(2);
        adj[4].push_back(5);
        adj[4].push_back(6);
        adj[5].push_back(4);
        adj[6].push_back(4);
        adj[6].push_back(7);
        adj[7].push_back(6);
        adj[8].push_back(9);
        adj[9].push_back(8);
    }
};
class Traversal
{
public:
    bool isCycleInUndirected(vector<vector<int>> &adj, int start_node)
    {
        queue<int> nodeQueue;
        vector<int> visited(adj.size(), 0);
        vector<int> parent(adj.size(), -1);

        nodeQueue.push(start_node);
        visited[start_node] = 1;

        while (!nodeQueue.empty())
        {
            int size = nodeQueue.size();

            for (int i = 0; i < size; i++)
            {
                int currentNode = nodeQueue.front();

                nodeQueue.pop();
                for (int niegh : adj[currentNode])
                {

                    if (!visited[niegh])
                    {
                        nodeQueue.push(niegh);
                        visited[niegh] = 1;
                        parent[niegh] = currentNode;
                    }
                    else
                    {

                        if (niegh != parent[currentNode])
                        {
                            cout << "CYCLE" << endl;
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }

    bool isCycleInDirected(vector<vector<int>> &adj, vector<int> &visited, vector<int> &pathVisited, int node)
    {
        visited[node] = 1;
        pathVisited[node] = 1;

        for (int neigh : adj[node])
        {

            if (!visited[neigh])
            {

                if (isCycleInDirected(adj, visited, pathVisited, neigh))
                    return true;
            }

            else if (pathVisited[neigh] == 1)
            {
                return false;
            }
        }

        pathVisited[node] = 0;
        return false;
    }

    bool DisconnectBSF(vector<vector<int>> &adj, int startPoint)
    {

        vector<int> visited(adj.size(), 0);
        vector<int> pathVisited(adj.size(), 0);
        bool isCycle = false;
        for (int i = 1; i < adj.size(); i++)
        {
            if (!visited[i])
            {
                isCycle = isCycleInDirected(adj, visited, pathVisited, i);
            }
        }
        return isCycle;
    }
    int CountComponent(vector<vector<int>> &adj)
    {

        vector<int> visited(adj.size(), 0);

        int count = 0;

        for (int i = 1; i < visited.size(); i++)
        {
            if (!visited[i])
            {
                count++;
                // BFS(adj, i, visited);
                cout << endl;
            }
        }
        return count;
    }
    bool DFS(vector<vector<int>> &adj, vector<int> &visitd, int currentNode, int dest, vector<int> &path)
    {
        if (currentNode == dest)
        {
            path.push_back(currentNode);
            return true;
        }
        visitd[currentNode] = 1;

        for (int niegh : adj[currentNode])
        {
            if (!visitd[niegh])
            {
                if (DFS(adj, visitd, niegh, dest, path))
                {
                    path.push_back(currentNode);
                    return true;
                }
            }
        }
        return false;
    }
    vector<int> isPathExist(vector<vector<int>> &adj, int src, int dest)
    {

        vector<int> visited(adj.size(), 0);
        vector<int> path;
        DFS(adj, visited, src, dest, path);

        reverseVector(path);
        return path;
    }
    vector<int> reverseVector(vector<int> &arr)
    {

        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i; j < arr.size(); j++)
            {
                if (arr[i] > arr[j])
                {
                    swap(arr[i], arr[j]);
                }
            }
        }
        return arr;
    }
    vector<int> reconstructPath(int n, vector<int> &parent, int src, int dest)
    {
        vector<int> path;

        while (dest != -1)
        {
            path.push_back(dest);
            dest = parent[dest];
        }

        reverseVector(path);

        if (path[0] == src)
        {
            return path;
        }

        return {};
    }

    bool biPartite(vector<vector<int>> &adj)
    {
        int n = adj.size();

        vector<int> visited(n, 0);
        vector<int> color(n, -1);

        queue<int> nodeQueue;

        for (int k = 1; k <= visited.size(); k++)
        {
            if (!visited[k])
            {

                nodeQueue.push(k);
                visited[k] = 1;
                color[k] = 0;

                while (!nodeQueue.empty())
                {
                    int sizeOfQueue = nodeQueue.size();

                    for (int i = 0; i < sizeOfQueue; i++)
                    {
                        int currentNode = nodeQueue.front();
                        nodeQueue.pop();

                        for (int neigh : adj[currentNode])
                        {

                            if (!visited[neigh])
                            {
                                nodeQueue.push(neigh);
                                visited[neigh] = 1;
                                int parentColor = color[currentNode];
                                color[neigh] = (parentColor == 1) ? 0 : 1;
                            }
                            else if (color[neigh] == color[currentNode])
                            {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }

    bool biPartiteDfs(int node, vector<vector<int>> &adj, vector<int> &color)
    {

        for (int neigh : adj[node])
        {

            if (color[neigh] == -1)
            {
                color[neigh] = 1 - color[node];
                if (!biPartiteDfs(neigh, adj, color))
                    return false;
            }
            else if (color[neigh] == color[node])
            {
                return false;
            }
        }
        return true;
    }

    bool biPartiteDfsLaunchpad(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> color(n, -1);
        for (int i = 0; i < adj.size(); i++)
        {
            if (color[i] == -1)
            {
                color[i] = 0;

                if (!biPartiteDfs(i, adj, color))
                    return false;
            }
        }
        return true;
    }

    void topoDfs(int node, vector<vector<int>> &adj, vector<int> &visited, stack<int> &st)
    {

        visited[node] = 1;
        for (int neigh : adj[node])
        {

            if (!visited[neigh])
            {

                topoDfs(neigh, adj, visited, st);
            }
        }

        st.push(node);
    }
    void topoLogicalSort(vector<vector<int>> &adj)
    {
        int n = adj.size();
        vector<int> visited(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {

                topoDfs(i, adj, visited, st);
            }
        }

        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
    }

    void topoLogicalSortUsingBFS(vector<vector<int>> &adj)
    {
        int n = adj.size();
        queue<int> nodeQueue;
        vector<int> indegree(n, 0);

        for (vector<int> neigh : adj)
        {
            for (int it : neigh)
            {
                indegree[it]++;
            }
        }

        cout << "indegree -> ";
        for (int i = 0; i < indegree.size(); i++)
        {
            cout << indegree[i] << " ";
            if (indegree[i] == 0)
            {
                nodeQueue.push(i);
            }
        }
        cout << endl<<"topo_sort -> ";

        while (!nodeQueue.empty())
        {
            int currentNode = nodeQueue.front();
            nodeQueue.pop();
            cout << currentNode << " ";

            for (int neigh : adj[currentNode])
            {
                indegree[neigh]--;

                if (indegree[neigh] == 0)
                {
                    nodeQueue.push(neigh);
                }
            }
        }
    }
};
int main()
{
    Traversal tv;
    Creation cr;
    vector<vector<int>> edges = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<vector<int>> adj = cr.buildAdj(3, edges);
    int n = adj.size();

    // cout << tv.biPartiteDfsLaunchpad(adj);
    tv.topoLogicalSortUsingBFS(adj);
    return 0;
}