class Solution {
    // Merges two sorted halves: nums[left...mid] and nums[mid+1...right]
    void merge(vector<int>&nums , int left , int mid , int right)
    {
        vector<int>temp(right - left +1);//Temporary array to hold merged elements
        int i=left , j = mid+1 , k = 0;
        // Compare elements from both halves and pick the smaller one
        while(i<=mid && j<=right)
        {
            if(nums[i] <= nums[j])
            {
                temp[k++] = nums[i++];
            }
            else
            {
                temp[k++] = nums[j++];
            }
        }
        while(i <= mid) temp[k++] = nums[i++];  // Copy any remaining elements from the left half
        while(j <= right) temp[k++]= nums[j++]; // Copy any remaining elements from the right half

        for(int i=0 ; i<temp.size() ; ++i) //Copy the sorted elements into the original array
        {
            nums[left+i] = temp[i];
        }
    }
    // Divide and conquer: splits the array into halves recursively
    void mergesort(vector<int>&nums , int left , int right)
    {
        if(left >= right) return; //Base Case
        int mid = left + (right - left)/2;     //Finding Mid
        mergesort(nums , left , mid);          // Sort left half
        mergesort(nums , mid+1 , right);       //Sort Right half
        merge(nums , left , mid , right);      // Merge the two sorted halves.
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1); //Applying MergeSort on the entire array
        return nums;
    }
};