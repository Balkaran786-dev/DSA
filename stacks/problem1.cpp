/*approach 1: bruteforce solution-o(n) both time and space complexity: when you need to find min ele,you need to read the whole stack.
  you maintain a min_ele variable.you keep reading the top ele in the stack and comparing it with the prev min ele,before poping out,you store the top ele 
  in another stack and then you pop out it.In this way,ou maintain an additional stack of size n.
  */


/*approach 2 -o(n) for space complexity and o(1) for time complexity: you need to push[7,4,5,2,9,8,1]  
  you need to maintain two stack,1. original stack that contains original elements. 2. whose top gives us the min of all the elements stored in the stack.


  when you push 1st ele in 1st,push it in 2nd too. when you push second ele in 1st stack,check if it is
  smaller than the top ele of 2nd stack,if yes push second ele in the 2nd stack,otherwise push the top ele again in the stack.
  when you pop out the ele from 1st stack,you must do it from 2nd stack too.*/
  /*push 7 in both,push 4 in both,push 5 in 1st and 4 in 2nd, push 2 in both,push 9 in 1st and 2 in 2nd,
  push 8 in 1st and 2 in 2nd,push 1 in both...*/

