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
    int minSwapsCouples(vector<int>& row) {
        DisjointSet* disjointSet = new DisjointSet(row.size());
        for (int i = 0; i < row.size(); i += 2){
            disjointSet->Union(i, i+ 1);
        }
        int counter = 0;
        for (int i = 0; i < row.size(); i += 2){
            if(disjointSet->isInSameGroup(row[i], row[i+ 1])) continue;
            disjointSet->Union(row[i], row[i+ 1]);
            counter++;
        }
        return counter;   
    }
};