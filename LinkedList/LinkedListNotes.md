# Singly LinkedList
 - InsertAtHead
 - InsertAtTail 
 - InsertInMiddle
 - Deletion

# Reverse a LinkedList
- There are 2 approach exist
  - Itrative 
  - Recursive
  - Resursive (chotihead)

# Middle of LL
- there are 2 approach of fast and slow

#  Reverse LL in k order
 - Recursive approach

# Circular List or Not (Detect Cycle)
 - Itravive approach time: O(n), space: O(1)
 - Map 
 - Floyd Detection Algo [fast and slow]
  
# find starting node of Loop [IMP]
 - [fast and slow ] [A + B = x time of C]

# Remove Loop from Linked List


Note: There are 5 ways to remove a loop and there are 3 ways to detect cycle  

# Remove duplicate from sorted | Unsorted LL
- Sorted -> Itrative O(n^2)
- Unsorted -> O(n^2): itrative, O(nlogn): sort and remove, O(n): map

# [HW]: split circualar list into 2 circular list

# check Palindrom in LL
- there are 2 approach
  -  time: O(n), space: O(n) -> store data of LL into vector and check palindrom in vetctor (using two pointer approach [start++ and end-- untill start <= end])
  - time: O(n), space: -> O(1) traverse till mid and reverse after the middle and then using two pointer compare both the haves.

# Add 2 numbers rep by LL

# Sort 0s 1s and 2s in LL (Dutch National Flag Problem)
  - approach 1 - count #0s, 1s, 2s and update the LL
  - approach 2: make 3 sperate lists for 0s 1s and 2s then merge them accordingly

# Merge 2 sorted LL
- 

# Copy List with Random pointer 
- Approach 1: O(n^2) ->>
- Approach 2: Time: O(n) , Space: O(n)
  - create a clone list
  - Link original nodes to clone nodes using maps
  - Update random pointers
- Approach 3: Time: O(n) , Space: O(1)
  - create a clone list 
  - Add cloneNode in between original Nodes
  - Copy Random pointers 
  - revert changes done in step 2
  - return answer
