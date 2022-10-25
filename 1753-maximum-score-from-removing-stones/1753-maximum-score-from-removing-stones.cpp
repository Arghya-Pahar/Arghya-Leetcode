class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int m=max(a,max(b,c));
        if(a+b+c<=2*m)
            return a+b+c-m;
        else
            return (a+b+c)/2;
    }
};