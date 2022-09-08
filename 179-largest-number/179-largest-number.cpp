class Solution {
public:
    bool static sorting(string &a,string &b)
    {
        return (a+b)>(b+a);
    }
    string largestNumber(vector<int>& nums) {
        vector<string> num;
        for(int i=0;i<nums.size();i++)
        {
            num.push_back(to_string(nums[i]));
        }
        sort(num.begin(),num.end(),sorting);
        string ans="";
        for(int i=0;i<num.size();i++)
        {
            ans+=num[i];
        }
        if(ans[0]=='0') return "0";
        return ans;
        
    }
};