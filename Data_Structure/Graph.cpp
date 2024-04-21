#include <iostream>
using namespace std;

const int MaxVERTEX = 100;
const int INF = 99;

class MGraph
{
private:
    int vertex[MaxVERTEX];
    char vertexName[MaxVERTEX];
    int arc[MaxVERTEX][MaxVERTEX];
    int vexnum;
    int edgenum;

public:
    MGraph()
    {
        for (int i = 0; i < MaxVERTEX; i++)
        {
            for (int j = 0; j < MaxVERTEX; j++)
            {
                arc[i][j] = INF;
            }
            vexnum = 0;
            edgenum = 0;
        }
    }

    void Create()
    {

        cout << "Please input the number of vertices: ";
        cin >> vexnum;
        cout << "please input the number of edges: ";
        cin >> edgenum;
        cout << "please input the name of each vertex: ";
        for (int i = 0; i < vexnum; i++)
        {
            vertex[i] = i;
            cin >> vertexName[i];
        }
        for (int i = 0; i < edgenum; i++)
        {
            int vi, vj, weight;
            cout << "please input the start vertex and end vertex and weight of edge: ";
            cin >> vi >> vj >> weight;
            arc[vi][vj] = weight;
            arc[vj][vi] = weight;
        }
    }

    void Print()
    {
        // 输出邻接矩阵
        cout << "The Collination Matrix is:" << endl;
        for (int i = 0; i < vexnum; i++)
        {
            for (int j = 0; j < vexnum; j++)
            {
                cout << arc[i][j] << " ";
            }
            cout << endl;
        }
    }

    int getVexPos(char name)
    {
        int i;
        for (i = 0; i < vexnum; i++)
        {
            if (vertexName[i] == name)
            {
                break;
            }
        }
        if (i == vexnum)
        {
            cout << "No such vertex!" << endl;
            return -1;
        }
    }

    void addVex(char name)
    {
        vertex[vexnum] = vexnum;
        vertexName[vexnum] = name;
        vexnum++;
    }

    void delVex(char name)
    {
        int i;
        for (i = 0; i < vexnum; i++)
        {
            if (vertexName[i] == name)
            {
                break;
            }
        }
        for (int j = i; j < vexnum - 1; j++)
        {
            vertexName[j] = vertexName[j + 1];
            vexnum--;
        }
        for (int j = i; j < vexnum - 1; j++)
        {
            for (int k = 0; k < vexnum; k++)
            {
                arc[j][k] = arc[j + 1][k];
            }
        }
        for (int j = 0; j < vexnum; j++)
        {
            for (int k = vexnum - 1; k > i; k--)
            {
                arc[j][k] = arc[j][k + 1];
            }
        }
        vexnum--;
    }

    void addEdge(int vi, int vj, int weight)
    {
        arc[vi][vj] = weight;
        arc[vj][vi] = weight;
        edgenum++;
    }
};

int main()
{
    MGraph g;
    g.Create();
    g.Print();
    g.addVex('a');
    g.Print();
    g.delVex('a');
    g.Print();
    return 0;
}

// 5 6
// a b c d e
// 0 1 2 3 4
// 0 1 9
// 0 2 2
// 0 4 6
// 1 2 3
// 3 4 1