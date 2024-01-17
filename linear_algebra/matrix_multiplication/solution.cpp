#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    vector<vector<int>> x = {
        {1, 2},
        {2, 3},
    };
    vector<vector<int>> y = {
        {4, 5},
        {7, 8},
    };
    int res;
    for(int r = 0; r < x.size(); r++){
        for(int c = 0; c < x[0].size(); c++){
            for(int i = 0; i < x[0].size(); i++){
                res += x[r][i] * y[i][c];
            }
            cout<<res<<endl;
            res= 0;
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}