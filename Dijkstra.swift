import UIKit
//-----------------------Graph Data
let vertexNum:Int = 6
let edgeNum:Int = 9
let graph:[[Int]] = [
    [0, 1, 7],
    [0, 2, 9],
    [0, 5, 14],
    [1, 2, 10],
    [1, 3, 15],
    [2, 3, 11],
    [2, 5, 2],
    [3, 4, 6],
    [4, 5, 9],
]
//---------------------------------

//-----------------------Array & Variable

var neighbors = [[Int]](repeating: [Int](repeating: -1, count: vertexNum), count: vertexNum)
var dist = [Int](repeating: 1000000000, count: vertexNum)
var prev = [Int](repeating: -2, count: vertexNum)
var q = [Int](repeating: -1, count: vertexNum)
var origin:Int = 0 //starter point
let dest:Int = 4 //destination point

//--------------------------------------

//-----------------------Functions
func validation() -> Bool{
    for i in 0..<edgeNum{
        if graph[i][0] == graph[i][1] || graph[i][2] <= 0 {
            return false;
        }
    }
    return true;
}

func setNeighbors(){
    var counter = [Int](repeating: 0, count: vertexNum)
    for i in 0..<vertexNum{
        for j in 0..<vertexNum{
            neighbors[i][j] = -1;
        }
    }
    for i in 0..<edgeNum{
        neighbors[graph[i][0]][counter[graph[i][0]]] = graph[i][1];
        counter[graph[i][0]] += 1;
        neighbors[graph[i][1]][counter[graph[i][1]]] = graph[i][0];
        counter[graph[i][1]] += 1;
    }
}

func checkNil()->Bool{
    for i in 0..<vertexNum{
        if q[i] == -1 {
            return true;
        }
    }
    return false;
}

func findEdge(m:Int,d:Int)->Int{
    for i in 0..<edgeNum{
        if (graph[i][0] == m || graph[i][1] == m) && (graph[i][1] == d || graph[i][0] == d)
        {
            return graph[i][2];
        }
    }
    return -1
}

func checkNeighbors(){
    var i:Int = 0;
    while neighbors[origin][i] != -1{
        var n:Int = neighbors[origin][i];
        if (dist[n] > dist[origin] + findEdge(m: origin, d: n)){
            dist[n] = dist[origin] + findEdge(m: origin, d: n);
            prev[n] = origin;
        }
        i += 1
    }
    q[origin] = 1;
}

func nextVertexSelector()-> Int{
    var min:Int = 1000000000;
    var res:Int = -1;
    for i in 0..<vertexNum{
        if (dist[i] < min && q[i] == -1){
            min = dist[i];
            res = i;
        }
    }
    return res;
}
func printRoad(){
    var reRoad = [Int](repeating: -1, count: vertexNum)
    var pointer:Int = dest;
    var i:Int = 0
    var printExp:String = "0 => "
    while pointer != 0{
        reRoad[i] = pointer;
        pointer = prev[pointer];
        i += 1
    }
    i -= 1
    while(i >= 0){
        if i != 0 {
            printExp += "\(reRoad[i]) => "
        }
        else{
            printExp += String(reRoad[i])
        }
        i -= 1;
    }
    print(printExp)
}
//--------------------------------

//-----------------------Main
if validation(){
    setNeighbors()
    dist[origin] = 0;
    prev[origin] = -1;
    while(checkNil()){
        checkNeighbors()
        origin = nextVertexSelector()
    }
    printRoad()
}
//---------------------------
