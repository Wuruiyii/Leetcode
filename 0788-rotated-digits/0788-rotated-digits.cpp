class Solution {
public:
    int rotatedDigits(int n)
     {
        int cnt = 0;
        for (int i = 1; i <= n; i++) 
        {
            int temp = i;
            bool c = false;
            while (temp > 0) {
                int t = temp % 10;
                if (t == 3 || t == 4 || t == 7) 
                {
                    c = false;
                    break;
                } 
                else if (t == 2 || t == 5 || t == 6 || t == 9) 
                {
                    c = true;
                }
                temp /= 10;
            }
            if (c) 
            {
                cnt++;
            }
        }
        return cnt;
    }
};