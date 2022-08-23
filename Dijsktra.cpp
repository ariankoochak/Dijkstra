#include <iostream>
#include <string.h>

using namespace std;
///////////////////////////////////////Graph Data
const int Vertex_num = 6;
const int Edge_num = 9;
int Graph[Edge_num][3] = {
    {0, 1, 7},
    {0, 2, 9},
    {0, 5, 14},
    {1, 2, 10},
    {1, 3, 15},
    {2, 3, 11},
    {2, 5, 2},
    {3, 4, 6},
    {4, 5, 9},
};
/////////////////////////////////////////////////

//////////////////////////////////Array & Variable
int Neighbors[Vertex_num][Vertex_num];
int Dist[Vertex_num];
int Prev[Vertex_num];
int q[Vertex_num];
int origin, dest;
//////////////////////////////////////////////////

/////////////////////////////////////////Functions
void SetNeighbors()
{
    int counter[Vertex_num] = {0};
    for (int i = 0; i < Vertex_num; i++)
    {
        for (int j = 0; j < Vertex_num; j++)
        {
            Neighbors[i][j] = -1;
        }
    }
    for (int i = 0; i < Edge_num; i++)
    {
        Neighbors[Graph[i][0]][counter[Graph[i][0]]] = Graph[i][1];
        counter[Graph[i][0]]++;
        Neighbors[Graph[i][1]][counter[Graph[i][1]]] = Graph[i][0];
        counter[Graph[i][1]]++;
    }
}

void PreSet()
{
    for (int i = 0; i < Vertex_num; i++)
    {
        Dist[i] = 1000000000;
        Prev[i] = -2;
        q[i] = -1;
    }
    Dist[origin] = 0;
    Prev[origin] = -1;
}

int FindEdge(int m, int d)
{
    for (int i = 0; i < Edge_num; i++)
    {
        if (Graph[i][0] == m || Graph[i][1] == m)
        {
            if (Graph[i][1] == d || Graph[i][0] == d)
                return Graph[i][2];
        }
    }
    return -1;
}

void CheckNeighbors()
{
    for (int i = 0; Neighbors[origin][i] != -1; i++)
    {
        int n = Neighbors[origin][i];
        if (Dist[n] > Dist[origin] + FindEdge(origin, n))
        {
            Dist[n] = Dist[origin] + FindEdge(origin, n);
            Prev[n] = origin;
        }
    }
    q[origin] = 1;
}
int NextVertexSelector()
{
    int min = 1000000000;
    int res = -1;
    for (int i = 0; i < Vertex_num; i++)
    {
        if (Dist[i] < min && q[i] == -1)
        {
            min = Dist[i];
            res = i;
        }
    }
    return res;
}

bool CheckNull()
{
    for (int i = 0; i < Vertex_num; i++)
    {
        if (q[i] == -1)
            return true;
    }
    return false;
}

void MakeRoad()
{
    int ReRoad[Vertex_num];
    int pointer = dest;
    int i = 0;
    for (i = 0; pointer != -1; i++)
    {
        ReRoad[i] = pointer;
        pointer = Prev[pointer];
    }
    for (i--; i >= 0; i--)
    {
        if (i != 0)
            cout << ReRoad[i] << " => ";
        else
            cout << ReRoad[i];
    }
}
bool Validation(){
    for(int i = 0;i < Edge_num;i++){
        if(Graph[i][0] == Graph[i][1] || Graph[i][2] <= 0)
            return false;
    }
    return true;
}
////////////////////////////////////////////////////

////////////////////////////////////////////////Main
int main()
{
    if(Validation()){
        cout << "Enter Your Starter Point : ";
        cin >> origin;
        cout << "Enter Your final Point : ";
        cin >> dest;
        SetNeighbors();
        PreSet();
        while (CheckNull())
        {
            CheckNeighbors();
            origin = NextVertexSelector();
        }
        MakeRoad();
    }
    else
        cout<<"Your Graph its wrong";
}