class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int cnt = nums[0].size();
        int num = 0;
        while (1) {
            string x = bitset<16>(num).to_string().substr(16 - cnt);
            int c = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (x == nums[i])
                    c++;
            }
            if (c > 0) {
                num += 1;
                x = bitset<16>(num).to_string().substr(16 - cnt);
            } else
                return x;
        }
        return "";
    }
};