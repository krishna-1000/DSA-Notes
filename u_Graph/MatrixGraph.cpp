
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

class GraphImplment
{
public:
    vector<vector<int>> createGridGraph(vector<vector<int>> &edges)
    {
        vector<vector<int>> grid(4, vector<int>(5, 0));
        for (vector<int> niegh : edges)
        {
            int raw = niegh[0];
            int col = niegh[1];

            grid[raw][col] = 1;
        }
        return grid;
    }

    void printGrid(vector<vector<int>> grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << grid[i][j] << "  ";
            }
            cout << endl;
        }
    }

    void GridDFS(vector<vector<int>> &grid, vector<vector<int>> &visited, int r, int c)
    {

        int m = grid.size();
        int n = grid[0].size();

        if (r >= n || c >= m || r < 0 || c < 0)
        {
            return;
        }
        if (grid[r][c] == 0)
        {
            return;
        }
        if (visited[r][c])
        {
            return;
        }

        visited[r][c] = 1;
        GridDFS(grid, visited, r + 1, c);
        GridDFS(grid, visited, r, c - 1);
        GridDFS(grid, visited, r, c + 1);
        GridDFS(grid, visited, r - 1, c);
    }
    void numberOfIsland(vector<vector<int>> grid)
    {

        vector<vector<int>> visited(6, vector<int>(6, 0));
        int island = 0;

        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                // cout<<grid[i][j]<<" ";
                if (grid[i][j] == 1 && visited[i][j] != 1)
                {

                    GridDFS(grid, visited, i, j);
                    island++;
                }
            }
            cout << endl;
        }
        cout << "Island = " << island;
    }

    void floodDfs(vector<vector<int>> &grid, int r, int c, int originalColor, int newColor)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (r >= m || c >= n || r < 0 || c < 0)
        {
            return;
        }
        if (grid[r][c] != originalColor)
        {
            return;
        }

        grid[r][c] = newColor;
        floodDfs(grid, r + 1, c, originalColor, newColor);
        floodDfs(grid, r - 1, c, originalColor, newColor);
        floodDfs(grid, r, c + 1, originalColor, newColor);
        floodDfs(grid, r, c - 1, originalColor, newColor);
    }

    void floodFill(vector<vector<int>> &grid, int sr, int sc, int newColor)
    {
        int originalColor = grid[sr][sc];

        if (originalColor != newColor)
        {
            floodDfs(grid, sr, sc, originalColor, newColor);
        }
        return;
    }

    void pushRottenOrange(vector<vector<int>> grid, queue<pair<int, int>> &positionQueue)
    {

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    positionQueue.push({i, j});
                }
            }
        }
    }

    int rottenGrid(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> positionQueue;
        pushRottenOrange(grid, positionQueue);
        int timeTakenToMakeRot = 0;

        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, +1, -1};
        while (!positionQueue.empty())
        {
            int sizeOfQueue = positionQueue.size();
            bool flag = false;
            for (int i = 0; i < sizeOfQueue; i++)
            {
                pair<int, int> rowCol = positionQueue.front();
                positionQueue.pop();
                int r = rowCol.first;
                int c = rowCol.second;

                for (int k = 0; k < 4; k++)
                {
                    int nr = r + dr[k];
                    int nc = c - dc[k];
                    if (nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1)
                    {
                        grid[nr][nc] = 2;
                        positionQueue.push({nr, nc});
                        flag = true;
                    }
                }
            }
            if (flag)
            {

                timeTakenToMakeRot++;
            }
        }

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return timeTakenToMakeRot;
    }

    int shortestPath(vector<vector<int>> grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (grid[0][0] == 1 && grid[m - 1][n - 1] == 1)
            return -1;

        vector<vector<int>> visited(m, vector<int>(n, 0));

        queue<pair<int, int>> positionQueue;
        positionQueue.push({0, 0});
        visited[0][0] = 1;
        int steps = 1;
        vector<int> dr = {1, 0, 1, -1, -1, 1, -1, 0};
        vector<int> dc = {0, 1, 1, -1, 1, -1, 0, -1};
        while (!positionQueue.empty())
        {
            int sizeOfQueue = positionQueue.size();
            
            for (int i = 0; i < sizeOfQueue; i++)
            {
                pair<int, int> rowCol = positionQueue.front();
                positionQueue.pop();
                int r = rowCol.first;
                int c = rowCol.second;
                if (r == m - 1 && c == n - 1)
                {
                    return steps;
                }
                for (int k = 0; k < 8; k++)
                {
                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr >= 0 && nc >= 0 && nr < m && nc < n && !visited[nr][nc] && grid[nr][nc] != 1)
                    {
                        positionQueue.push({nr, nc});
                        visited[nr][nc] = 1;
                    }
                }
            }

            steps++;
        }
        return -1;
    }

    vector<pair<int, int>> shortestPath2(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int>> path;

        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
        {
            return path;
        }

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> nodeQueue;
        vector<vector<pair<int, int>>> parentGrid(n, vector<pair<int, int>>(m, {-1, -1}));
        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};
        nodeQueue.push({0, 0});
        visited[0][0] = 1;

        while (!nodeQueue.empty())
        {
            pair<int, int> currentNode = nodeQueue.front();
            nodeQueue.pop();
            int r = currentNode.first;
            int c = currentNode.second;

            if (r == n - 1 && c == m - 1)
            {
                break;
            }

            for (int i = 0; i < 4; i++)
            {
                int row = r + dr[i];
                int col = c + dc[i];

                if (row >= 0 && col >= 0 && row < n && col < m &&
                    grid[row][col] == 0 && !visited[row][col])
                {
                    nodeQueue.push({row, col});
                    visited[row][col] = 1;
                    parentGrid[row][col] = {r, c};
                }
            }
        }

        int r = n - 1;
        int c = m - 1;

        if (!visited[r][c])
            return path;

        while (r != 0 || c != 0)
        {
            path.push_back({r, c});
            pair<int, int> rowCol = parentGrid[r][c];
            r = rowCol.first;
            c = rowCol.second;
        }
        path.push_back({r, c});
        reverse(path.begin(), path.end());

        return path;
    }
};

int main()
{
    GraphImplment gimp;
    vector<vector<int>> edges = {{3, 0}, {2, 2}, {0, 4}, {2, 4},};
    vector<vector<int>> grid = gimp.createGridGraph(edges);
    // gimp.floodFill(grid, 1, 2, 2);
    // gimp.numberOfIsland(grid);
    // cout << "minute " << gimp.rottenGrid(grid) << endl;
    gimp.printGrid(grid);
    vector<pair<int, int>> path = gimp.shortestPath2(grid);
    if (path.empty())
    {
        cout << "there is path exist";
    }
    else
    {
        for (pair<int, int> it : path)
        {
            
            cout << "{ " << it.first << "," << it.second << "} ";
        }
    }
    return 0;
}