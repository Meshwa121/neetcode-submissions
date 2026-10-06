class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        int product= 1;
        int zero =0;
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                zero++;
            }
            else{
                product= nums[i]*product;
            }
        }

        for(int i=0; i<n; i++){
            if(zero>1){
                ans[i]=0;
            }
            else if(zero==1){
                if(nums[i]==0){
                    ans[i]= product;
                }
                else{
                    ans[i]=0;
                }
            }
            else{
                ans[i]= product/nums[i];
            }
        }

        return ans;
    }
};
