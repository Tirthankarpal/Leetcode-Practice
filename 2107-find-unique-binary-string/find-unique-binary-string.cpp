#include <bitset>
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        set<int> st;
        for(int i=0;i<n;i++){
            st.insert(stoi(nums[i], nullptr, 2));
        }
        string res="";
        for(int i=0;i<(1<<n);i++){
            if(st.find(i)==st.end()){
                res=bitset<16>(i).to_string();
                break;
            }
        }
        return res.substr(16-n);
    }
};