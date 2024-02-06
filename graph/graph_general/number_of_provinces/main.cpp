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
            if(rootA==rootB) return;
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
            while(a != this->parents[a]){
                this->parents[a] = this->parents[parents[a]];
                a = this->parents[a];
            }
            return a;
        }

        int getCount(){
            return this->count;
        }

        DisjointSet(int N){
            this->parents.resize(N+1);
            this->weights.resize(N+1);
            this->count = N;
            for(int i = 1; i < N; i++){
                this->parents[i] = i;
                this->weights[i] = 1;
            }
        }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet* disjointSet = new DisjointSet(n);
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(isConnected[i][j]) disjointSet->Union(i, j);
            }
        }
        return disjointSet->getCount();
    }
};