#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

class Graph
{
private:
    int numVertices;
    vector<vector<int>> adjList;
    vector<vector<int>> adjMatrix;

public:
    Graph(int n) : numVertices(n), adjList(n), adjMatrix(n, vector<int>(n, 0)) {}

    void addEdge(int v1, int v2)
    {
        adjList[v1].push_back(v2);
        adjMatrix[v1][v2] = 1;
    }

    void printAdjList()
    {
        for (int i = 0; i < numVertices; i++)
        {
            cout << "顶点 " << i << " 的邻接顶点：";
            for (auto v: adjList[i])
            {
                cout << "-> " << v << " ";
            }
            cout << endl;
        }
    }

    void printAdjMatrix()
    {
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl; 
        }
    }

    // 基于邻接矩阵的深度优先遍历
    void DFS1(int startVertex)
    {
        vector<bool> visited(numVertices, false);
        dfsUtil(startVertex, visited);
        cout << endl;
    }

    void dfsUtil(int vertex, vector<bool> &visited)
    {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int i = 0; i < numVertices; i++)
        {
            if (adjMatrix[vertex][i] == 1 && !visited[i])
            {
                dfsUtil(i, visited);
            }
        }
    }

    // 基于邻接表的深度优先遍历
    void DFS2(int startVertex)
    {
        vector<bool> visited(numVertices, false);
        stack<int> s;
        s.push(startVertex);
        visited[startVertex] = true;

        while (!s.empty())
        {
            int vertex = s.top();
            s.pop();
            cout << vertex << " ";

            for (auto i : adjList[vertex])
            {
                if (!visited[i])
                {
                    s.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }

    // 基于邻接矩阵的广度优先遍历
    void BFS1(int startVertex)
    {
        vector<bool> visited(numVertices, false);
        queue<int> q;
        q.push(startVertex);
        visited[startVertex] = true;

        while (!q.empty())
        {
            int vertex = q.front();
            cout << vertex << " ";
            q.pop();

            for (int i = 0; i < numVertices; i++)
            {
                if (adjMatrix[vertex][i] == 1 && !visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }

    // 基于邻接表的广度优先遍历
    void BFS2(int startVertex)
    {
        vector<bool> visited(numVertices, false);
        queue<int> q;
        q.push(startVertex);
        visited[startVertex] = true;

        while (!q.empty())
        {
            int vertex = q.front();
            cout << vertex << " ";
            q.pop();

            for (auto i : adjList[vertex])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }

    void inOutDegree()
    {
        vector<int> inDegree(numVertices, 0);
        vector<int> outDegree(numVertices, 0);
        for (int i = 0; i < numVertices; i++)
        {
            outDegree[i] = adjList[i].size();
            for (auto j : adjList[i])
            {
                inDegree[j]++;
            }
        }

        for (int i = 0; i < numVertices; i++)
        {
            cout << "顶点 " << i << " 的入度为 " << inDegree[i] << ", 出度为 " << outDegree[i] << endl;
        }
    }

    void topologicalSort()
    {
        vector<int> inDegree(numVertices, 0);
        for (auto i : adjList)
        {
            for (auto j : i)
            {
                inDegree[j]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numVertices; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> topoOrder;
        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();
            topoOrder.push_back(vertex);

            for (auto i : adjList[vertex])
            {
                inDegree[i]--;
                if (inDegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }

        if (topoOrder.size() == numVertices)
        {
            cout << "拓扑排序成功！" << endl;
            for (auto i : topoOrder)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "拓扑排序失败！" << endl;
        }
    }

    void Menu()
    {
        int choice;
        do
        {
            cout << "1. 添加边" << endl;
            cout << "2. 输出邻接表" << endl;
            cout << "3. 输出邻接矩阵" << endl;
            cout << "4. 深度优先遍历（基于邻接矩阵）" << endl;
            cout << "5. 广度优先遍历（基于邻接矩阵）" << endl;
            cout << "6. 深度优先遍历（基于邻接表）" << endl;
            cout << "7. 广度优先遍历（基于邻接表）" << endl;
            cout << "8. 计算每个顶点的入度和出度" << endl;
            cout << "9. 拓扑排序" << endl;
            cout << "0. 退出" << endl;
            cout << "请输入选项：";
            cin >> choice;

            switch (choice)
            {
            case 1:
            {
                int v1, v2;
                cout << "请输入两个顶点：" << endl;
                cin >> v1 >> v2;
                addEdge(v1, v2);
                break;
            }
            case 2:
                printAdjList();
                break;
            case 3:
                printAdjMatrix();
                break;
            case 4:
            {
                int startVertex;
                cout << "请输入起始顶点：" << endl;
                cin >> startVertex;
                DFS1(startVertex);
                break;
            }
            case 5:
            {
                int startVertex;
                cout << "请输入起始顶点：" << endl;
                cin >> startVertex;
                BFS1(startVertex);
                break;
            }
            case 6:
            {
                int startVertex;
                cout << "请输入起始顶点：" << endl;
                cin >> startVertex;
                DFS2(startVertex);
                break;
            }
            case 7:
            {
                int startVertex;
                cout << "请输入起始顶点：" << endl;
                cin >> startVertex;
                BFS2(startVertex);
                break;
            }
            case 8:
                inOutDegree();
                break;
            case 9:
                topologicalSort();
                break;
            case 0:
                break;
            default:
                cout << "输入错误，请重新输入！" << endl;
                break;
            }
        } while (choice != 0);
    }
};

int main()
{
    int n;
    cout << "请输入顶点数：" << endl;
    cin >> n;
    Graph g(n);
    g.Menu();
    return 0;
}
