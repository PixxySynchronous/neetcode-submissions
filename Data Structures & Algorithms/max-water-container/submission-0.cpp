class Solution {
public:
    int maxArea(vector<int>& heights) {
        //Approach is simple,using 2 pointer. width will always decrease by 1, so to increase the 
        //area we need to move the pointer pointing to the bar with the smaller bar as only then
        //can the area increase. 
        int i = 0; 
        int j = heights.size()-1; 
        int maxArea = 0; 
        while (i<j){
            int width = j-i; 
            int length = min(heights[i],heights[j]);
            int area = length*width; 
            maxArea = max(maxArea,area);
            if (heights[i]<heights[j]) i++;
            else j--; 
        }
        return maxArea; 
    }
};
