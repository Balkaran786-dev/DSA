// o(n^2) time, o(1) space..
// use two loops,
// as you find the required elements that sum up to target, put their indices in a vector 
// and return it.

//using hashing..
// o(n) time and space
// at every index , calculate target-nums[i], find this in map,if presnt 
// return {mp[target-num[i]],i},
// else put that current ele in map corresponding to its index.


//o(nlogn) time  o(logn) space -> taken by inbuilt sorting.
// if i require to give indices, above is the most optimal,
// but if i'm required to give the pair of ele,
// use this,


// sort the ele,AND use two pointers, now you better know..