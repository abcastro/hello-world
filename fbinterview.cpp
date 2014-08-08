Q) You have an array of positive integers with no duplicates (say A). You need to find all sets of size 2 such that they add up to a given target 'K'

Ex : {600, 5 , 1 , 2, 4, 3} (A)
K = 5

{2,3}
{1,4}

ans = 2

int findSubset(int [] a, int target, int length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        for (int j = i + 1 ; j < length; j++) {
            if (a[i] + a[j] == target)
                count++;
     target - a[i] = in the array? in the set?
     
        }
    }
    return count;
}

Q) You have an array of positive integers with no duplicates (say A). You need to find all sets of size 'M' such that they add up to a given target 'K'

Ex : {600, 5 , 1 , 2, 4, 3} (A)
K = 6 // <- target
M = 3

{1, 2,3}

ans = 1

setSize = ?
setSize = M

int sumSubset(int [] a, int target, int length, int setSize) {
    std::vector<int> v;   // ?
    std::vector<int> idx; // <- index of the current subset trying to build
    int sum; // <- 
    
    if (setSize == 0 and target != 0)
        return 0; // false
    
    if (target == 0)
        return 1; // true

    int count = 0;
    for (int = 0; i < length; i++) {
        if (sumSubset(a, target - a[i], length, setSize - 1) == 1)
            count++;
    }

    return count;    
    
    sum = 0;
    for (int i = 0; i < setSize; i++) {
        idx.push_back(i);
        sum += a[i];
    }
    
    for (int i = 0; i < setSize; i++) {
        for (int j = 0; j < length; j++) 
        sumSubset(a, target - a[idx[i]], length, setSize-1); 
    }
}
