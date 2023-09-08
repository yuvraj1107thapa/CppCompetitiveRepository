// Problem link: https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int m = mat.size(); // no. of rows
        int n = mat[0].size(); // no. of cols
        
        
        // initialize i and j so that we can start iterating the matrix from  last row's first element
        int i = m - 1;
        int j = 0;
        
        // until we come to first row's last element
        while (i>=0 && j<n){
            
            // if element found to be equal to target, return true
            if (mat[i][j] == target) return true;
            
            // if element is lesser than  the target, move up because all  the smallest elements are above it,  as Integers in each row are sorted in ascending from left to right. Integers in each column are sorted in ascending from top to bottom. 
            else if (mat[i][j] < target) j++;
            
            
            // otherwise if element is lesser than the target move right, as all greater elements lives in right.
            else i--;
        }
        
        // if element is not found, return false
        return false;
        
    }
};