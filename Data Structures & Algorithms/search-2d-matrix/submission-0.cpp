class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //everything is the same. Just use the formula to access the middle 
        //element rather than simple matrix[mid][mid]
        int start = 0; 
        int total = matrix[0].size()*matrix.size(); 
        int end = total - 1; 
        int cols = matrix[0].size(); 
        while (end>=start){
            int mid = start + (end - start)/2; 
            int element = matrix[mid/cols][mid%cols]; 
            if (element>target){
                end = mid - 1; 
            }
            else if ( element < target){
                start = mid + 1; 
            }
            else return true; 
        }
        return false; 
    }
};
