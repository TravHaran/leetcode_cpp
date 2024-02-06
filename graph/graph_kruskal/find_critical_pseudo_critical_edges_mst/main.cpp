#include <vector>
using namespace std;

/** Disjoint-set Weighted Union Find with Path Compression*/
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

        int getMaxRank(){
            int val = 0;
            for(auto& w : weights){
                val = max(val, w);
            }
            return val;
        }
        
        bool isInSameGroup(int a, int b){
            return Find(a) == Find(b);
        }

        DisjointSet(int N){
            this->weights.resize(N+1);
            this->parents.resize(N+1);
            for(int i = 1; i <= N; i++){
                this->parents[i] = i;
                this->weights[i] = 1;
            }
        }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        //update edges to store the original index
        for(int i = 0; i < edges.size(); i++){
            edges[i].push_back(i);
        }
        //sort edges by weight
        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        });
        DisjointSet* disjointSet = new DisjointSet(n);
        // keep track of total weight of edges added in MST
        int mst_weight = 0;
        for(int i = 0; i < edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            if(disjointSet->isInSameGroup(a, b)) continue;
            disjointSet->Union(a, b);
            mst_weight += edges[i][2];
        }

        vector<int> critical;
        vector<int> pseudo;
        for(int i = 0; i < edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];
            // try without curr edge
            int weight = 0;
            disjointSet = new DisjointSet(n);
            for(int j = 0; j < edges.size(); j++){
                int c = edges[j][0];
                int d = edges[j][1];
                if(i==j || disjointSet->isInSameGroup(c, d)) continue;
                disjointSet->Union(c, d);
                weight += edges[j][2];
            }
            if(weight != mst_weight){
                critical.push_back(edges[i][3]);
                continue;
            }
            // try with curr edge
            disjointSet = new DisjointSet(n);
            disjointSet->Union(a, b);
            weight = edges[i][2];
            for(int j = 0; j < edges.size(); j++){
                int c = edges[j][0];
                int d = edges[j][1];
                if(disjointSet->isInSameGroup(c, d)) continue;
                disjointSet->Union(c, d);
                weight += edges[j][2];
            }
            
            if(weight == mst_weight){
                pseudo.push_back(edges[i][3]);
            }     
        }
        return {critical, pseudo};
    }
};