class Solution {
public:
    int minElement(vector<int>& nums) 
    {
        int min_ = 1001;
        for(int i = 0;i < nums.size();i++)
        {
            int sum = 0;
            int temp = nums[i];
            while(temp > 0)
            {
                int t = temp % 10;
                sum += t;
                temp /=10;
            }
            nums[i] = sum;
            if(nums[i] < min_) min_ = nums[i];
        }
        return min_;
    }
};