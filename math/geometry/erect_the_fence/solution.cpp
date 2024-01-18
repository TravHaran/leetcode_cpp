#include <vector>
#include <set>
#include <math.h>
using namespace std;

class Solution {
    // Convex Hull: Jarvis March Algorithm (aka gift wrapping algo)
    // Refer to Animation: https://editor.p5js.org/nitroglycerine/full/9TdE-ZFuD
    /**
     * We want to surround a set of trees with as little fencing as possible
     * to do this we need to find the convex hull of the set of trees
     * the convex hull of a set of points is the smallest convex polygon that contains all the points
     * A convex polygon is a polygon in which all interier angles are <= 180°
     * Refer to https://www.youtube.com/watch?v=nBvCZi34F_o&ab_channel=Insidecode
    */
   // Time: O(n*h) where n is the number of trees, and h is the number of points on the hull
   // Space: O(h)
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        int n = trees.size();
        //handle edge case
        // if there is less than three trees all trees lie on the fence
        if(n < 4) return trees;

        // get the index of the leftmost tree: tree with the smallest x coordinate
        int leftMostTreeIdx;
        int lowestX = INT32_MAX;
        int x;
        for(int i = 0; i < n; i++){
            x = trees[i][0];
            lowestX = min(lowestX, x);
            if(x==lowestX) leftMostTreeIdx = i;
        }
        // starting at the leftMost tree keep finding the most clockwise tree and update the fence accordingly
        int cur = leftMostTreeIdx;
        set<vector<int>> fence;
        while(true){
            int candidate = 0; // set candidate to dummy reference point
            // find most clockwise tree from our current tree. For each point...
                // check if we need to update candidate to the next point
                    // move to the next point when the orientation is counter clockwise, as we wan't the most clockwise point
                    // or if the next point is the same as the last point we added to the hull which is defined by candidate
                    // also handle edge case where orientation is colinear in which case we'd move to next point that has a greater distance
            for(int i = 0; i < n ; i++){
                int o = orientation(trees[cur], trees[candidate], trees[i]);
                if(i==candidate || o == 1 || (o==0 && euclideanDist(trees[cur], trees[i]) > euclideanDist(trees[cur], trees[candidate]))){
                    candidate = i;
                }
            }
            // we've now set cur and candidate which defines an edge of a fence
            // now we add all the trees that are on the fence to our set
            for(int i = 0; i < n; i++){
                if(orientation(trees[cur], trees[candidate], trees[i])==0){
                    fence.insert(trees[i]);
                }
            }
            // continue building the fence
            cur = candidate;
            if(cur==leftMostTreeIdx) break; // we've returned back to our starting point and the fence is enclosed
        }
        return {fence.begin(), fence.end()};
    }
    int euclideanDist(vector<int> p1, vector<int> p2){
        int x1 = p1[0];
        int x2 = p2[0];
        int y1 = p1[1];
        int y2 = p2[1];
        return sqrt((y2-y1)*(y2-y1) + (x2-x1)*(x2-x1));
    }
    int orientation(vector<int> p1, vector<int> p2, vector<int> p3){
        // define two vectors
        vector<int> a = {p2[0]-p1[0], p2[1]-p1[1]};
        vector<int> b = {p3[0]-p2[0], p3[1]-p2[1]};
        // get the cross product
        int cross = a[0]*b[1] - a[1]*b[0];
        if(cross>0) return 1; // counterclockwise
        if(cross<0) return -1; // clockwise
        return 0; // colinear
    }
};