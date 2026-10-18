class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        for(int i=0; i<nums1.size(); i++){
            merge.push_back(nums1[i]);
        }

        for(int j=0; j<nums2.size(); j++){
            merge.push_back(nums2[j]);
        }

        sort(merge.begin(), merge.end());
        int left=0;
        int right= merge.size();
        while(left<right){
            int mid= left+(right-left)/2;
            if(merge.size()%2==0){
                double median= (merge[mid]+merge[mid-1])/2.0;
                return median;
            }else{
                double median= merge[mid];
                return median;
            }
        }
    }
};
