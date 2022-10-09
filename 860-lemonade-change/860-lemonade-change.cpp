class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> mp;
        for(int i=0;i<bills.size();i++)
        {
            cout<<i<<" ";
            if(bills[i]==5)
            {
                mp[5]++;
            }
            else if(bills[i]==10)
            {
                if(mp.find(5)==mp.end())
                {
                    return false;
                }
                else
                {
                    mp[10]++;
                    mp[5]--;
                    if(mp[5]==0)
                        mp.erase(5);
                }
            }
            else if(bills[i]==20)
            {
                if(mp.find(5)==mp.end())
                {
                    return false;
                }
                if(mp.find(10)!=mp.end())
                {
                    mp[10]--;
                    mp[5]--;
                    if(mp[5]==0)
                        mp.erase(5);
                    if(mp[10]==0)
                        mp.erase(10);
                }
                else if(mp[5]>=3)
                {
                    mp[5]=mp[5]-3;
                    if(mp[5]==0)
                        mp.erase(5);
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};