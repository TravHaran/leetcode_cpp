#include <vector>
using namespace std;

/** Vanilla Disjoint-set Union Find*/
class DisjointSet{
    private:
        vector<int> parents;
    public:
        void Union(int a, int b){
            int rootA = Find(a);
            int rootB = Find(b);
            // if both a and b have the same root, i.e. they both belong to the same set
            // hence we dont need to take union
            if(rootA == rootB) return;
            // take union by assigning rootA as the parent of rootB
            this->parents[rootB] = rootA;
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
        }

        bool isInSameGroup(int a, int b){
            // return trye is both a and b belong to the same set,
            // otherwise resturn false
            return Find(a) == Find(b);
        }

        DisjointSet(int N){
            this->parents.resize(N+1);
            //Set the intial parent node to itself
            for(int i = 1; i <= N; i++){
                this->parents[i] = i;
            }
        }
};