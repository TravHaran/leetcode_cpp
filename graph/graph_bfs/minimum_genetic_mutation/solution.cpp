#include <vector>
#include <unordered_set>
#include <deque>
#include <string>
using namespace std;

class Solution {
    // Time: O(B), where B is the bank length, Space: O(1)
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // convert bank of genes into a set to make it more efficient to check values
        unordered_set<string> bank_set(bank.begin(), bank.end());
        // handle edge case
        if(!bank_set.count(endGene)) return -1;
        deque<string> q {startGene};
        unordered_set<string> visited {startGene};
        string curGeneString;
        string newGeneString;
        int curLevel = 0;
        int curStringLen;
        int size;
        // conduct bfs traversal
        while(!q.empty()){
            size = q.size();
            for(int i = 0; i < size; i++){
                curGeneString = q.front();
                q.pop_front();
                if(curGeneString==endGene) return curLevel;
                for(int i = 0; i < curGeneString.length(); i++){ // apply all mutations
                    curStringLen = curGeneString.length();
                    for(char c : "ACGT"){
                        newGeneString = curGeneString.substr(0, i) + c + curGeneString.substr(i+1, curStringLen);
                        if(!visited.count(newGeneString) && bank_set.count(newGeneString)){
                            q.push_back(newGeneString);
                            visited.insert(newGeneString);
                        }     
                    }
                }
            }
            curLevel++;
        }
        return -1;  
    }
};