class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int sum=0;
        int dist=0;
        for(int i=0;i<plants.size();i++)
        {
            sum+=plants[i];
            dist++;
            if(sum>capacity)
            {
                dist+=2*i;
                sum=plants[i];
            }
        }
        return dist;
    }
};