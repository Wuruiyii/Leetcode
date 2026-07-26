class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {

        sort(nums.begin(),nums.end());
        int cnt = 0;
        int size = nums.size()-1;
        for(int i = 0;i < nums.size();i++)
        {
            if(nums[i]<0) cnt++;
            if(nums[i]>0) break;
        }
        if(cnt>=2) return max(nums[0]*nums[1]*nums[size],nums[size]*nums[size-1]*nums[size-2]);
        return nums[size]*nums[size-1]*nums[size-2];
    }
};