#include <vector>
using namespace std;

class DisjointSet{
    private:
        vector<int> parents;
        vector<int> weights;
        int count;
    public:
        void Union(int a, int b){
            int rootA = Find(a);
            int rootB = Find(b);
            if(rootA == rootB) return; // there in the same group we dont need to union
            if(this->weights[rootA] > this->weights[rootB]){
                this->parents[rootB] = rootA;
                this->weights[rootA] += this->weights[rootB];
            } else {
                this->parents[rootA] = rootB;
                this->weights[rootB] += this->weights[rootA];
            }
            this->count--;

        }

        int Find(int a){
            // traverse to the top with path compression
            while(a != this->parents[a]){
                this->parents[a] = this->parents[parents[a]];
                a = this->parents[a];
            }
            return a;
        }

        bool isInSameGroup(int a, int b){
            return Find(a)==Find(b);
        }

        int getCount(){
            return this->count;
        }

        DisjointSet(int N){
            this->weights.resize(N+1);
            this->parents.resize(N+1);
            this->count = N;
            for(int i = 1; i < N; i++){
                this->parents[i] = i;
                this->weights[i] = 1;
            }
        }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        DisjointSet* disjointSet = new DisjointSet(n);
        for(auto& e : edges){
            int a = e[0];
            int b = e[1];
            if(disjointSet->isInSameGroup(a, b)) return false;
            disjointSet->Union(a, b);
        }
        return disjointSet->getCount()==1;
        
    }
};