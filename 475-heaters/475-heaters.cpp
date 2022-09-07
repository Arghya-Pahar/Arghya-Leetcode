class Solution {
public:
    pair<int,int> binsearch(int key,vector<int> & heaters)
    {
        int low=0;
        int high=heaters.size()-1;
        pair<int,int> ans;
        ans.second=-1;
        ans.first=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(heaters[mid]==key)
            {
                ans.first=mid;
                ans.second=mid;
                return ans;
            }
            else if(heaters[mid]>key)
            {
                ans.second=mid;
                high=mid-1;
            }
            else
            {
                ans.first=mid;
                low=mid+1;
            }
        }
        return ans;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(),heaters.end());
        int ans=INT_MIN;
        for(int i=0;i<houses.size();i++)
        {
            pair<int,int> recv=binsearch(houses[i],heaters);
            int dist;
            cout<<recv.first<<" "<<recv.second;
            if(recv.first==-1)
            {
                dist=heaters[recv.second]-houses[i];
            }
            else if(recv.second==-1)
            {
                dist=houses[i]-heaters[recv.first];
            }
            else
            {
                dist=min(houses[i]-heaters[recv.first],heaters[recv.second]-houses[i]);
            }
            ans=max(ans,dist);
            
        }
        return ans;
        
    }
};