class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left= 1;
        int right= *max_element(piles.begin(), piles.end());
        int n= piles.size();
        while(left<=right){
            int mid= left+(right- left)/2;
            int hr= 0;
            for(int i=0; i<n; i++){
                hr+= (piles[i]+mid-1)/mid;
            }
            if(hr<=h){
                right= mid-1;
            }else{
                left= mid+1;
            }
        }
        return left;
    }
};
