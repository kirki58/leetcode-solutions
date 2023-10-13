#include <stdio.h>
#include <limits.h>


/* 
    remove targets from a given array.
    https://leetcode.com/problems/destroy-sequential-targets/
*/

int isInteger(double val){
    int truncated = (int) val;
    return(truncated == val);
}

int destroyTargets(int* nums, int numsSize, int space){
    int maxNumbers = INT_MIN;
    int scIndex;
    int count;
    for(int i = 0; i<numsSize; i++){
        count = 0;
        for(int j = 0; j<numsSize; j++){
            int isCPosInt = isInteger( (nums[j]-nums[i]) / space) && ( (nums[j]-nums[i]) / space ) >= 0;
            if(isCPosInt){
                count++;
            }
        }
        if(count > maxNumbers){
            maxNumbers = count;
            scIndex = nums[i];
        }
    }
    return scIndex;
}

int main(){
    int arr[3] = {6,2,5};

    printf("%d",destroyTargets(arr,3,100));
    return 0;
}