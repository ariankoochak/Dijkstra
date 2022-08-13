#include <iostream>
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

int Neighbors[Vertex_num][Vertex_num] = {
    {1,2,5},
    {0,2,3},
    {0,1,3,5},
    {1,2,4},
    {3,5},
    {0,2,4}
};
int Dist[Vertex_num] = {10000};
int Prev[Vertex_num] = {-1};
int q[Vertex_num];
int origin;
int main()
{
    cin>>origin;
    q[origin] = -1;
    Dist[origin] = 0;
}