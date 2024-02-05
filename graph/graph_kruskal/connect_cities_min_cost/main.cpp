#include <vector>
using namespace std;

/** Disjoint-set Weighted Union Find with Path Compression*/
class DisjointSet{
    private:
        vector<int> parents;
        vector<int> weights;
    public:
    /**
     * We can optimize Union using a technique called Weighted Union
     * in addition to the parent nodes, we also keep the weights of each of the nodes.
     * Every time we take union, the root node with more weight (i.e. having more elements in the corresponding set)
     * is used as the parent node of the other node.
     * We initialize the weight corresponding to each node as 1 initially,
     * as each elemtn belongs to it's own set in the beginning.
    */
        void Union(int a, int b){
            int rootA = Find(a);
            int rootB = Find(b);
            // if both a and b have the same root, i.e. they both belong to the same set
            // hence we dont need to take union
            if(rootA == rootB) return;
            // Weighted union
            if(this->weights[rootA] > this->weights[rootB]){
                //In this case rootA has more weight
                // 1. make rootA as the parent of rootB
                // 2. increment the weight of rootA by rootB's weight
                this->parents[rootB] = rootA;
                this->weights[rootA] += this->weights[rootB];
            } else {
                // Otherwise
                // 1. Make rootB as the parent of rootA
                // 2. increment the weight of rootB by rootA's weight
                this->parents[rootA] = rootB;
                this->weights[rootB] += this->weights[rootA];
            }
        }
        /**
         * With Path compression we can make the the Find function faster
         * while obtaining the root we compress the path by assigning the grandparents 
         * of the source node as the parent (thereby skipping connections and moving closer to the root)
        */

        int Find(int a){
            //Traverse all the way to the top (root) going through the parent nodes
            // Path compression
            // a's grandparent is now a's parent
            while(a != this->parents[a]){
                this->parents[a] = this->parents[parents[a]];
                a = this->parents[a];
            }
            return a;
        }

        bool isInSameGroup(int a, int b){
            // return true if both a and b belong to the same set,
            // otherwise resturn false
            return Find(a) == Find(b);
        }

        DisjointSet(int N){
            this->weights.resize(N+1);
            this->parents.resize(N+1);
            //Set the intial parent node to itself
            //Set the initial weights to 1
            for(int i = 1; i <= N; i++){
                this->parents[i] = i;
                this->weights[i] = 1;
            }
        }
};

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        DisjointSet* disjointSet = new DisjointSet(n);
        // Sort connections bassed on their weights (in increasing order)
        sort(connections.begin(), connections.end(), [](const vector<int> &a, const vector<int> &b){
            return a[2] < b[2];
        });
        // keep track of total edges added in MST & cost to add the edges
        int total = 0;
        int cost = 0;
        for(int i = 0; i < connections.size(); i++){
            int a = connections[i][0];
            int b = connections[i][1];
            // don't add the edge from a to b it is already connected
            if(disjointSet->isInSameGroup(a, b)) continue;
            // if a and b are not connected take union
            disjointSet->Union(a, b);
            cost += connections[i][2];
            //increment number of edges added in MST
            total++;
        }
        if(total==n-1) return cost;
        return -1;
    }
};