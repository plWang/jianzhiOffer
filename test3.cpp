public int InversePairs(int [] array) {
// Can solve by using divide and conquer
    if(array == null){
        return 0;
    }
    int len = array.length;
    return InversePairs(array,0,len-1);
}
 
private int InversePairs(int[] array, int start, int end){
    if(start >= end){
        return 0;
    }
     
    int mid = (start + end) / 2;
    int leftPairs = InversePairs(array,start,mid);
    int rightPairs = InversePairs(array,mid+1,end);
    int leftRightPairs = mergePairs(array,start,mid,end);
     
    return leftPairs + rightPairs + leftRightPairs;
}
 
private int mergePairs(int[] array,int start,int mid,int end){
    int[] tmp = new int[end - start + 1];
    int i = start;
    int j = mid + 1;
    int k = 0;
    int count = 0;
     
    while(i <= mid && j <= end){
        if(array[i] > array[j]){
            count += (end - j + 1);
            tmp[k++] = array[i++];
        }else{
            tmp[k++] = array[j++];
        }
    }
     
    while(i <= mid){
        tmp[k++] = array[i++];
    }
     
    while(j <= end){
        tmp[k++] = array[j++];
    }
     
    k = 0;
    for(int m = start;m<=end;m++){
        array[m] = tmp[k++];
    }
     
    return count;
}