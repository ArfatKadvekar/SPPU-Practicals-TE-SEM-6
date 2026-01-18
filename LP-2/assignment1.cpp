#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

vector<vector<int>> graph;
vector<int> visited;
int m, n;

void DFS(int node)
{
    visited[node] = 1;
    cout << "\033[44m" << node << " " << "\033[0m";

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
        cout << "\033[44m" << node << " " << "\033[0m";
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

void removeRandomEdge()
{
    srand(time(0));
    int u;
    do
    {
        u = rand() % n;
    } while (graph[u].empty());

    int v = graph[u][rand() % graph[u].size()];

    for (int i = 0; i < graph[u].size(); i++)
        if (graph[u][i] == v)
        {
            graph[u].erase(graph[u].begin() + i);
            break;
        }

    for (int i = 0; i < graph[v].size(); i++)
        if (graph[v][i] == u)
        {
            graph[v].erase(graph[v].begin() + i);
            break;
        }

    cout << "\nRandom edge removed: " << u << " - " << v << endl;
}

int countComponents()
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int components = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFS(i);
            components++;
            cout << endl;
        }
    }
    return components;
}

int main()
{
    string filename;
    cout << "Enter input file name: ";
    cin >> filename;

    ifstream infile(filename);
    if (!infile)
    {
        cout << "File error\n";
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

    cout << "\n\033[44mDFS before partition:\033[0m\n";
    int conn = countComponents();
    if (conn == 1)
        cout << "\n\033[42mDFS Result: Network is fully connected\033[0m\n";
    else
        cout << "\n\033[41mDFS Result: Network is NOT fully connected\033[0m\n";

    for (int i = 0; i < n; i++)
        visited[i] = 0;
    cout << "\n\033[44mBFS before partition:\033[0m ";
    BFS(0);
    cout << "\n\033[47mBFS Result: Network reachability checked using shortest paths\033[0m\n";

    removeRandomEdge();

    cout << "\n\033[44mDFS after partition:\033[0m\n";
    int conn1 = countComponents();
    if (conn1 == 1)
        cout << "\n\033[42mDFS Result: Network is fully connected\033[0m\n";
    else
        cout << "\n\033[41mDFS Result: Network is NOT fully connected \033[0m\n";

    for (int i = 0; i < n; i++)
        visited[i] = 0;
    cout << "\n\033[44mBFS after partition:\033[0m ";
    BFS(0);
    cout << "\n\033[47mBFS Result: Network reachability checked using shortest paths\033[0m\n";
    cout << endl;

    return 0;
}
