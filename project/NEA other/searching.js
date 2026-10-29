let A = [1, 23, 134, 425, 3255, 6245, 7543, 9465, 10938];
let x = 10938;

function linear_search(A, x){
    let i = 0;
    while(i < A.length){
        if(A[i] == x){
            return i;
        }
        else{
            i ++;
        }
    }
    return "Not found in data";
}

console.log(linear_search(A, x));



function binary_search(A, x){
    low = 0;
    high = A.length - 1;
    while (low <= high){
        mid = Math.floor((low + high)/2);
        if (A[mid] == x){
            return mid;
        }
        else if(A[mid] > x){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return "Not found in data";
}

console.log(binary_search(A, x));