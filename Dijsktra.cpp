#include <iostream>
#include <algorithm>
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
int origin;
//////////////////////////////////////////////////


/////////////////////////////////////////Functions
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

void PrevAndDistSet(){
    for(int i = 0;i < Vertex_num;i++){
        Dist[i] = 1000000;
    }
    Dist[origin] = 0;
    Prev[origin] = -1;
    q[origin] = -1;
}
////////////////////////////////////////////////////


////////////////////////////////////////////////Main
int main()
{
    cin >> origin;
    SetNeighbors();
    PrevAndDistSet();

}