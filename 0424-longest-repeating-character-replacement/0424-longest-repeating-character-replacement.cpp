class Solution {
public:
    int characterReplacement(string s, int k) {
       vector<int> arr(26,0);
       int i=0,j=0;
       int ans=0;
       while(i<s.size())
       {
           arr[s[i]-'A']++;
           while(i-j+1-*max_element(arr.begin(),arr.end())>k)
           {
               arr[s[j]-'A']--;
               j++;
           }
           ans=max(ans,i-j+1);
           i++;
       }
       return ans;
    }
};