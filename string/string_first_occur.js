//LEETCODE: 28. Find the Index of the First Occurrence in a String

var strStr = function(ha, ne) {
    const length = ne.length
    if(length==0) return 0;

    for(i=0; i<ha.length; i++){
        if(ha.substring(i, i+length)==ne){
            return i;
        }
    }
    return -1
};
