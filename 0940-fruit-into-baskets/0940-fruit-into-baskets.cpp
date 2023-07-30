class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> mp;
        int i=0,j=0,ans=0;
        while(i<fruits.size()&& j<fruits.size())
        {
            mp[fruits[i]]++;
            if(mp.size()<=2)
            {
                ans=max(ans,i-j+1);
            }
            while(mp.size()>2)
            {
                if(mp[fruits[j]]==1)
                {
                    mp.erase(fruits[j]);
                }
                else
                {
                    mp[fruits[j]]--;
                }
                j++;
            }
            i++;
            

        }
        return ans;
    }
};