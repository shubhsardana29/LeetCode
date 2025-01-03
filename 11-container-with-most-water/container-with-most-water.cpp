class Solution {
public:
    int maxArea(vector<int>& height) {
        // int ans=0;
        // for(int left=0;left<height.size();left++){
        //     for(int right=left+1;right<height.size();right++){
        //         int area = (right - left) * min(height[left],height[right]);
        //         ans=max(ans,area);
        //     }
        // }
        // return ans;

        int ans=0;
        int n=height.size();
        int l=0;
        int r=n-1;
        while(l<r){
            int area = (r - l) * min(height[l],height[r]);
            ans=max(ans,area);
            if(height[l]<height[r]){
                l++;
            }
            else if(height[l]>height[r]){
                r--;
            }
            else{
                l++ || r--;
            }
        }
        return ans;
    }
};