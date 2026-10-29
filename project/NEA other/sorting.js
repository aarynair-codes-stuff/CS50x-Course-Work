let A = [132412412, 245, 2, 512451246, 356, 324512, 65327, 1255123, 5215, 2145, 55, 13, 21, 5]


function bubble_sort(A){
    for(let i = 0; i < A.length; i ++){
        for(let j = 0; j < A.length - 1; j++){
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    return A
}


function insertion_sort(A){
    for(let i = 1; i < A.length; i ++){
        elem = A[i];
        j = i -1
        while(j>=0 || A[j] > elem){
            A[j+1] = A[j]
            j = j - 1
        }
        A[j+1] = elem
    }
}

console.log(insertion_sort(A));

function quick_sort(A){
    if(A.length <= 1){
        return A
    }
    pivot = A[0]
    left = []
    right = []
    for(let i = 1; i <A.length - 1; i++){
        if(A[i] <= pivot){
            left.push(A[i])
        }
        else{
            right.push(A[i])
        }
    }
    sorted_left = quick_sort(left)
    sorted_right = quick_sort(right)
    return sorted_left.concat([pivot], sorted_right)
}

console.log(A);