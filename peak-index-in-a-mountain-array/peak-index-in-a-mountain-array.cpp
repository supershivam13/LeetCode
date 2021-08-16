class Solution {
public:
    int peakIndexInMountainArray(vector<int> A) {
    
        int n=A.size();
        int l = 0, r = A.size() - 1, mid;

        // Binary Search - O( logN )
        while (l <= r) {

            mid = l + ((r-l) / 2);
            
            if(A[mid]>A[(mid+1)%n] and A[mid]>A[(mid-1+n)%n])
                return mid;

            if (A[mid] < A[mid + 1])
                l = mid + 1;
            else
                r = mid - 1;
        }

        return l;
    }

};