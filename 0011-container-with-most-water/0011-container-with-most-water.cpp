class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,area=0;
        int j=height.size()-1;
        while(i<j)
        {
            area=max(area,(j-i)*min(height[i],height[j]));
            if(height[i]>height[j])
            {
                j--;

            }
            else
            {
                i++;
            }
        }
        return area;
    }
};