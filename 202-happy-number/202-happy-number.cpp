class Solution {
public:
    bool happy(int n)
    {
        int temp=0;
        while(n!=0)
        {
            int d=n%10;
            temp+=pow(d,2);
            n=n/10;
        }
        n=temp;
        if(n==1)
            return true;
        if(n==89)
            return false;
       return happy(n);
    }
    bool isHappy(int n) {
        return happy(n);
    }
};