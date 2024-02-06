#include <vector>
using namespace std;

class DisjointSet{
    private:
        vector<int> parents;
        vector<int> weights;
    public:
        void Union(int a, int b){
            int rootA = Find(a);
            int rootB = Find(b);
            if(rootA==rootB) return;
            if(this->weights[rootA] > this->weights[rootB]){
                this->parents[rootB] = rootA;
                this->weights[rootA] += this->weights[rootB];
            } else {
                this->parents[rootA] = rootB;
                this->weights[rootB] += this->weights[rootA];
            }
        }

        int Find(int a){
            while(a != this->parents[a]){
                this->parents[a] = this->parents[parents[a]];
                a = this->parents[a];
            }
            return a;
        }

        bool isInSameGroup(int a, int b){
            return Find(a)==Find(b);
        }

        DisjointSet(int N){
            this->parents.resize(N+1);
            this->weights.resize(N+1);
            for(int i = 1; i < N; i++){
                this->parents[i] = i;
                this->weights[i] = 1;
            }
        }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        DisjointSet* disjointSet = new DisjointSet(graph.size());
        for(int i = 0; i < graph.size(); i++){
            for(int j = 0; j < graph[i].size(); j++){
                if(disjointSet->isInSameGroup(i, graph[i][j])) return false;
                disjointSet->Union(graph[i][0], graph[i][j]);
            }
        }
        return true;
    }
};