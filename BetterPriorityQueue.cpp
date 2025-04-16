#include "Graph.h"
#include <queue>
#include <iostream>
#include <vector>
#include <string>
#include "BetterPriorityQueue.h"

using namespace std;

bool BetterPriorityQueue::Contains(BPQNode node) {
    bool contains = false;

    for(size_t ii = 0; ii < this->c.size(); ii++) {
        if(node.gnode == this->c.at(ii).gnode) {
            contains = true;
            break;
        }
    }
    return contains;
}

bool BetterPriorityQueue::Update(BPQNode node) {
    bool update = false;

    for (size_t ii = 0; ii < this->c.size(); ii++) {
        if (this->c.at(ii).gnode == node.gnode) {
            if (node.pri < this->c.at(ii).pri) {
                update = true;

                this->c.erase(this->c.begin() + ii);
                this->c.push_back(node);
                push_heap(this->c.begin(), this->c.end(), this->comp);
            }
            break;
        }
    }
    return update;
}

string BetterPriorityQueue::ToString() {
    string bpq = "[";

    for (size_t ii = 0; ii < this->c.size(); ii++) {
        if (ii == this->c.size() - 1) {
            bpq = bpq + "(" + to_string(this->c[ii].gnode) + ", pri: " + to_string(this->c[ii].pri) + ")";
        }
        else {
            bpq = bpq + "(" + to_string(this->c[ii].gnode) + ", pri: " + to_string(this->c[ii].pri) + "), ";
        }
    }
    bpq += "]";
    return bpq;
}

string BetterPriorityQueue::BPQNodeToString(BPQNode node) {
    return "(" + to_string(node.gnode) + ", pri " + to_string(node.pri) + ")";
}