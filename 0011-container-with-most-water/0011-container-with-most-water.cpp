class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int water=0;
        while(i<j)
        {
            int area=(j-i)*min(height[i],height[j]);
            water=max(water,area);
            if(height[i]<=height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return water;
        
    }
};