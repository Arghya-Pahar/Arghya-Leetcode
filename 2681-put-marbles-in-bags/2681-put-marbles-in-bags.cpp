class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<int> pairsum(weights.size()-1);
        for(int i=0;i<pairsum.size();i++)
        {
            pairsum[i]=weights[i]+weights[i+1];
        }
        sort(pairsum.begin(),pairsum.end());
        long mini=0,maxi=0;
        for(int i=0;i<k-1;i++)
        {
            mini=mini+pairsum[i];
            maxi=maxi+(pairsum[pairsum.size()-1-i]);
        }
        return maxi-mini;
    }
};