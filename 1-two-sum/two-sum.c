/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // We assume that each input would have exactly one solution
    int i = 0;
    int j = 0;
    bool test = false;
    while(!test && i < numsSize){
        j = i+1;
        while(!test && j < numsSize){ 
            if (nums[i] + nums[j] == target){
                test = true;
            }
            else
                j++;
        }
        if (!test)
            i++;
    }
    if (test){
        int* output = malloc(2*sizeof(int));
        output[0] = i;
        output[1] = j;
        *returnSize = 2;
        return output;
    }
    else{
        *returnSize=0;
        return NULL;
    }
    
}