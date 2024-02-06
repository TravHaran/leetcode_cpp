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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        if(dislikes.size()==0) return true;
        DisjointSet* disjointSet = new DisjointSet(n);
        vector <vector <int>> m(n + 1);
        for (auto &z : dislikes) {
            m[z[0]].push_back(z[1]);
            m[z[1]].push_back(z[0]);
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < m[i].size(); j++){
                if(disjointSet->isInSameGroup(i, m[i][j])) return false;
                disjointSet->Union(m[i][0], m[i][j]);
            }
        }
        return true;
    }
};