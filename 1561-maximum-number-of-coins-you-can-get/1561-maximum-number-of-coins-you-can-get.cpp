class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int sum=0;
        for(int i=piles.size()-2,j=0;i>=j;i-=2)
        {
            sum+=piles[i];
            j++;
        }
        return sum;
    }
};