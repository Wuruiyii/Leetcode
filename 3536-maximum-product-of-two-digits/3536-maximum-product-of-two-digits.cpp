class Solution {
public:
    int maxProduct(int n)
    {
        vector<int> nums;
        int temp = n;
        while(temp>0)
        {
            int t = temp % 10;
            nums.push_back(t);
            temp /= 10;
        }
        sort(nums.begin(),nums.end());
        int size = nums.size();
        return nums[size-1]*nums[size-2];
    }
};