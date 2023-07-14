#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Graph
{
private:
    int m_VertexCnt = 0;
    vector<vector<int>> m_Edges;
    vector<bool> visited;

public:
    Graph(int vertexCnt) : m_VertexCnt(vertexCnt)
    {
        m_Edges.resize(m_VertexCnt);
        visited.resize(m_VertexCnt);
    }

    void AddEdge(int vertex1, int vertex2)
    {
        m_Edges[vertex1].push_back(vertex2);
        m_Edges[vertex2].push_back(vertex1);

        sort(m_Edges[vertex1].begin(), m_Edges[vertex1].end());
        sort(m_Edges[vertex2].begin(), m_Edges[vertex2].end());
    }

    void DFS(int startVertex)
    {
        stack<int> dfs;

        dfs.push(startVertex);
        int curVertex;

        while (!dfs.empty())
        {
            curVertex = dfs.top();
            //dfs.pop();
            if (visited[curVertex] == false)
            {
                cout << curVertex << " ";
            }
            visited[curVertex] = true;


            bool ck = false;

            for (size_t i = 0; i < m_Edges[curVertex].size(); i++)
            {
                if (!visited[m_Edges[curVertex][i]])
                {
                    ck = true;
                    dfs.push(m_Edges[curVertex][i]);
                    break;
                }
            }

            if (!ck)
                dfs.pop();
        }
        cout << '\n';
    }

    void BFS(int startVertex)
    {
        queue<int> bfs;

        visited[startVertex] = true;
        bfs.push(startVertex);

        while (!bfs.empty()) {
            int vertex = bfs.front();
            cout << vertex << " ";
            bfs.pop();

            for (int v : m_Edges[vertex]) {
                if (!visited[v]) {
                    visited[v] = true;
                    bfs.push(v);
                }
            }
        }
    }

    void Init()
    {
        for (size_t i = 0; i < visited.size(); i++)
        {
            visited[i] = false;
        }
    }
};

int main()
{
    int N, M, V;
    cin >> N >> M >> V;

    Graph graph(N + 1);
    for (size_t i = 0; i < M; i++)
    {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;
        graph.AddEdge(vertex1, vertex2);
    }

    graph.DFS(V);
    graph.Init();
    graph.BFS(V);
}