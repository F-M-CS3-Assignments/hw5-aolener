/*
In the worst case:
1. Dijkstra loop runs with complexity of O(V)
2. There are O(V) neighbors
3. The Update() function runs with max elements for O(V) time

Therefore, I believe that for my implementation, the time complexity is O(V^3)

*/

#include "Dijkstra.h"
#include "BetterPriorityQueue.h"

using namespace std;

int dijkstra(nodekey_t start, nodekey_t end, const Graph *g) {

    //Check if the start and end are actually in existence
    if (!(g->IsPresent(start)) || !(g->IsPresent(end))) {
        throw invalid_argument("The nodes at the start and end must be present!");
    }

    BetterPriorityQueue bpq;

    set<nodekey_t> nodes = g->GetNodes();
    //iterates and creates the priority queue
    for (nodekey_t node : nodes) {
        BPQNode current;

        current.gnode = node;

        if (node == start) {
            current.pri = 0;
        }

        bpq.push(current);
    }

    vector<BPQNode> results;

    //From the node with the lowest pri through the entire graph, checks all the verticies and updates paths
    while (!bpq.empty()) {
        BPQNode current = bpq.top();
        bpq.pop();

        results.push_back(current);

        set<const GraphEdge*> edges = g->GetOutwardEdgesFrom(current.gnode);

        for (const GraphEdge* edge : edges) {
            BPQNode adjVertex;
            adjVertex.gnode = edge->to;

            int weight = edge->weight;
            adjVertex.pri = weight + current.pri;

            bpq.Update(adjVertex);
        }
    }

    int length = INT_MAX;
    
    
    //Finds the distance from the start to the end, solving the problem with the algorithm
    //also is for returning the length of the optimal solution
    for (size_t ii = 0; ii < results.size(); ii++) {
        if (results.at(ii).gnode == end) {
            length = results.at(ii).pri;
        }
    }
    return length;
}