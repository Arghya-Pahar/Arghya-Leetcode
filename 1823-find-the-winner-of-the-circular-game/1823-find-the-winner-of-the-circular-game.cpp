class Solution {
public:
    int josephus(int n,int k)
    {
        if(n==1)
            return 0;
        else
        {
            int ans=josephus(n-1,k);
            return (ans+k)%n;
        }
    }
    int findTheWinner(int n, int k) {
        int ans=josephus(n,k);
        return ans+1;
    }
};