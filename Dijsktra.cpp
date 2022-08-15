#include <iostream>
#include <algorithm>
using namespace std;

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

int Neighbors[Vertex_num][Vertex_num];
int Dist[Vertex_num] = {10000};
int Prev[Vertex_num] = {-1};
int q[Vertex_num];
int origin;
void SetNeighbors(){
    int counter[Vertex_num] = {0};
    for (int i = 0; i < Vertex_num; i++)
    {
        for (int j = 0; j < Vertex_num; j++)
        {
            Neighbors[i][j] = -1;
        }
    }
    for(int i = 0; i < Edge_num;i++){
        Neighbors[Graph[i][0]][counter[Graph[i][0]]] = Graph[i][1];
        counter[Graph[i][0]]++;
        Neighbors[Graph[i][1]][counter[Graph[i][1]]] = Graph[i][0];
        counter[Graph[i][1]]++;
    }
}
int main()
{
    SetNeighbors();
    for(int i = 0;i< Vertex_num;i++){
        for (int j = 0; j < Vertex_num; j++)
        {
            cout<<"{"<<Neighbors[i][j]<<" , ";
        }
        cout<<"}"<<endl;
    }
    cin>>origin;
    q[origin] = -1;
    Dist[origin] = 0;
}