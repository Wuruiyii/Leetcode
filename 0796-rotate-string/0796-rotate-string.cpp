class Solution {
public:
    bool rotateString(string s, string goal)
    {
        string ns = s;
        ns+=s;
        int start = 0;
        int last = s.size()-1;
        while(last<ns.size())
        {
            string temp = ns.substr(start,s.size());
            if(temp == goal) return true;
            else 
            {
                last++;
                start++;
            }
        }
        return false;
    }
};