#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    // Recursive dfs approach
    // create a map of old nodes to newly created nodes for the deep copy
    // if the node doesn't exist in the map then we create it and update the map, else we reference the node in the map
    // we do this recursively for every neighbor of the node
    // Time: O(N + M) where N is the number of nodes (vertices) and M is the number of edges
    // Space: O(N) where N is the number of nodes, the recursion stack doesn't exceed O(H) where H is the height of the graph
public:
    unordered_map<Node*, Node*> clone_map;
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        Node* newNode;
        if(!clone_map.count(node)){
            newNode = new Node(node->val);
            clone_map[node] = newNode;
        } else {
            newNode = clone_map[node];
        }
        Node* neighbor;
        for(auto el : node->neighbors){
            if(!clone_map.count(el))
                neighbor = cloneGraph(el);
            else {
                neighbor = clone_map[el];
            }
            newNode->neighbors.push_back(neighbor);
        }
        return newNode;
    }
};