class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        vector<int> ans;
        int i=0;
        int j=0;
        while(j<nums.size()){
            while(!d.empty() && d.back()<nums[j]){
                d.pop_back();
            }
            d.push_back(nums[j]);
            if(j-i+1<k){
                j++;
            }
            else if(j-i+1==k){
                ans.push_back(d.front());
                if(d.front()==nums[i]){
                    d.pop_front();
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};
