///////////////////////////////////////graph Data
const vertexNum = 6;
const edgeNum = 9;
const graph = [
    [0, 1, 7],
    [0, 2, 9],
    [0, 5, 14],
    [1, 2, 10],
    [1, 3, 15],
    [2, 3, 11],
    [2, 5, 2],
    [3, 4, 6],
    [4, 5, 9],
];
/////////////////////////////////////////////////

//////////////////////////////////Array & Variable
let neighbors = new Array(vertexNum);
for(let i = 0 ; i < neighbors.length;i++){
    neighbors[i] = new Array(vertexNum).fill(-1)
}
let dist = new Array(vertexNum).fill(1000000000);
let prev = new Array(vertexNum).fill(-2);
let q = new Array(vertexNum).fill(-1);

let origin = 0; //starter point
const dest = 4; //destination point
//////////////////////////////////////////////////

/////////////////////////////////////////Functions
function setNeighbors() {
    let counter = new Array(vertexNum).fill(0);
    for (let i = 0; i < edgeNum; i++){
        neighbors[graph[i][0]][counter[graph[i][0]]] = graph[i][1];
        counter[graph[i][0]]++;
        neighbors[graph[i][1]][counter[graph[i][1]]] = graph[i][0];
        counter[graph[i][1]]++;
    }
}

function findEdge(m,d)
{
    for (let i = 0; i < edgeNum; i++){
        if ((graph[i][0] == m || graph[i][1] == m) && (graph[i][1] == d || graph[i][0] == d)){
            return graph[i][2];
        }
    }
    return -1;
}

function checkNeighbors()
{
    for (let i = 0; neighbors[origin][i] != -1; i++){
        let n = neighbors[origin][i];
        if (dist[n] > dist[origin] + findEdge(origin, n)){
            dist[n] = dist[origin] + findEdge(origin, n);
            prev[n] = origin;
        }
    }
    q[origin] = 1;
}
function nextVertexSelector()
{
    let min = 1000000000;
    let res = -1;
    for (let i = 0; i < vertexNum; i++){
        if (dist[i] < min && q[i] == -1){
            min = dist[i];
            res = i;
        }
    }
    return res;
}

function checkNull(){
    for (let i = 0; i < vertexNum; i++){
        if (q[i] == -1)
            return true;
    }
    return false;
}

function printRoad()
{
    let reRoad = [];
    let pointer = dest;
    let i;
    let printExp = ""
    for (i = 0; pointer != -1; i++){
        reRoad.push(pointer);
        pointer = prev[pointer];
    }
    for (i--; i >= 0; i--){
        printExp +=  i != 0 ? `${reRoad[i]} => ` : reRoad[i]
    }
    console.log(printExp); 
}

function validation(){
    for(let i = 0;i < edgeNum;i++){
        if(graph[i][0] == graph[i][1] || graph[i][2] <= 0)
            return false;
    }
    return true;
}
////////////////////////////////////////////////////

////////////////////////////////////////////////Main
if(validation()){
    setNeighbors();
    dist[origin] = 0;
    prev[origin] = -1;
    while (checkNull()){
        checkNeighbors();
        origin = nextVertexSelector();
    }
    printRoad();
}
else
    console.log("Your graph its wrong");