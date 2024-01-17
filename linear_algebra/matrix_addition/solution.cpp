#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    vector<vector<int>> x = {
        {1, 2, 3},
        {2, 3, 4},
        {1, 1, 1}
    };
    vector<vector<int>> y = {
        {4, 5, 6},
        {7, 8, 9},
        {4, 5, 7}
    };

    for(int r = 0; r < x.size(); r++){
        for(int c = 0; c < x[0].size(); c++){
            cout<<x[r][c] + y[r][c]<<endl;
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}