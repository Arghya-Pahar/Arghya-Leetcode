class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> newarr(nums1.size()+nums2.size());
        int i=0,j=0,k=0;
        while(i<nums1.size()&&j<nums2.size())
        {
            if(nums1[i]<nums2[j])
            {
                newarr[k]=nums1[i];
                i++;
                k++;
            }
            else
            {
                newarr[k]=nums2[j];
                j++;
                k++;
                
            }
        }
        if(i<nums1.size())
        {
            while(i<nums1.size())
            {
            newarr[k]=nums1[i];
            i++;
            k++;
            }
        }
        else if(j<nums2.size())
        {
            while(j<nums2.size())
            {
                newarr[k]=nums2[j];
                j++;
                k++;
            }
        }
        for(int i=0;i<newarr.size();i++)
        {
            cout<<newarr[i]<<" ";
        }
        int size=newarr.size();
        if(size%2!=0)
        {
            int idx=(size+1)/2;
            return newarr[idx-1];
        }
        else
        {
            int idx1=(size/2)-1;
            int idx2=idx1+1;
            float ans=(newarr[idx1]+newarr[idx2])/(float)2;
            return ans;
        }
       
        
        
    }
};