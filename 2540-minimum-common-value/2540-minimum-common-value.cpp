class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) 
    {
        int i = 0;
        int j = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        while(i < len1 && j < len2)
        {
            if(nums1[i] == nums2[j]) return nums2[j];
            else if(nums1[i] < nums2[j]) i++;
            else j++;
        }
        return -1;
    }
};