#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
int m, n;

void DFS(int node)
{
    visited[node] = 1;
    cout << node << " ";

    for (int i = 0; i < graph[node].size(); i++)
    {
        int nb = graph[node][i];
        if (visited[nb] == 0)
        {
            DFS(nb);
        }
    }
}

void BFS(int start)
{
    queue<int> q;
    visited[start] = 1;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int nb : graph[node])
        {
            if (visited[nb] == 0)
            {
                visited[nb] = 1;
                q.push(nb);
            }
        }
    }
}

int main()
{
    string filename;
    cout << "Enter input file name: ";
    cin >> filename;

    ifstream infile(filename);
    if (!infile.is_open())
    {
        cout << "Error " << filename << endl;
        return 1;
    }

    infile >> n >> m;

    graph.resize(n);
    visited.resize(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        infile >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    infile.close();

    for (int i = 0; i < n; i++)
        visited[i] = 0;
    cout << "DFS Traversal: ";
    DFS(0);

    int conn = 1;
    for (int i = 0; i < n; i++)
        if (visited[i] == 0)
            conn = 0;

    if (conn)
        cout << "\nDFS Result: Network is fully connected\n";
    else
        cout << "\nDFS Result: Network is NOT fully connected\n";

    for (int i = 0; i < n; i++)
        visited[i] = 0;
    cout << "BFS Traversal: ";
    BFS(0);
    cout << "\nBFS Result: Network reachability checked using shortest paths\n";

    return 0;
}