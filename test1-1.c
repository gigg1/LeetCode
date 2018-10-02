#include <stdio.h>

int result[2];
int* twoSum(int* nums, int numsSize, int target) {
    int count=numsSize;
    int i,j;
    for(i=0;i<count-1;i++){
        for(j=i+1;j<count;j++){
            if(nums[i]+nums[j]==target){
                result[0]=i;
                result[1]=j;
                return result;
            }
        }
    }
    return result;
}
int main(){
    int nums[5]={-3,4,3,9,0};
    int numsSize=5;
    int target=0;
    twoSum(nums,numsSize,target);
    printf("[%d,%d]\n",result[0],result[1]);


    return 0;
}