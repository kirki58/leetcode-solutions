#include <stdio.h>
#include <stdlib.h>

// https://leetcode.com/problems/median-of-two-sorted-arrays/

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int totalSize = nums1Size + nums2Size;
    // Merge two arrays
    int mergedArray[totalSize];
    int mergedIndex = 0;

    int* nums1Tracker = nums1;
    int* nums2Tracker = nums2;

    const int* maxNums1Tracker = nums1 + nums1Size;
    const int* maxNums2Tracker = nums2 + nums2Size;

    while (nums1Tracker < maxNums1Tracker && nums2Tracker < maxNums2Tracker) {
        if (*nums1Tracker <= *nums2Tracker) {
            mergedArray[mergedIndex++] = *nums1Tracker++;
        } else {
            mergedArray[mergedIndex++] = *nums2Tracker++;
        }
    }

    // Copy remaining elements of nums1, if any
    while (nums1Tracker < maxNums1Tracker) {
        mergedArray[mergedIndex++] = *nums1Tracker++;
    }

    // Copy remaining elements of nums2, if any
    while (nums2Tracker < maxNums2Tracker) {
        mergedArray[mergedIndex++] = *nums2Tracker++;
    }

    // Find median of the merged array
    if (totalSize % 2 == 1) {
        return mergedArray[totalSize / 2];
    }

    double avg = (mergedArray[(totalSize / 2) - 1] + mergedArray[totalSize / 2]) / 2.0;
    return avg;
}

int main() {
    int nums1[] = {1, 3};
    int nums2[] = {2};

    double median = findMedianSortedArrays(nums1, 2, nums2, 1);
    printf("Median is: %f\n", median);

    return 0;
}