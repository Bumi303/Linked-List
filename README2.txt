1. Name and ONID
Name Hayden Henderson 
ONID henderha 
ID# 934352652
Assignment 5, due 7/4/2022

2. Descrition of program
Hi! Welcome to part 2 of this assingment. For this part of the Assignment we will look at how a linked list works and how we can
interact with them. This program will give the user the ability to print the linked list, add values to it, sort it, count the 
number of prime numbers, print it's length, and clear it. The goal if this program is to give the user a better understanding on
how a linked list works. Have fun!

3. Instructions

Step 1. accessing
After you have unziped assign5.zip enter into the terminal: ls
After this is done you should see 4 diffent files. Those files are Makefile, README1.txt, README2.txt, part1, and part2.

To use part2 you will need to type in the terminal: cd part2
Then type: unzip part2.zip

Step 2. compiling
To compile the code you will have to type in the terminal: make

Next to run the code you will need to type in the terminal: ./r2

Step 3. running
After you run the program the first thing you should see is a message that reads: List successfully created!!
Next you will see a test being ran of the program. Test 1 just checks the length and Test 2 populates the list.

As you can see the linked list has been created and it is working properly

Now the after those test the program is currently paused and should read: Press <enter> to continue...

You will need to press enter on the keyboard to continue the program.
After you press enter the program will keep showing tests and the results of those test. As you can see the tests is inserting 
values at different positions in the list.

If you press enter again it will show you some more tests.

Once you get to Test 3 you will see that the program has sorted the linked list. If you press enter one more time it will 
show that the linked list has been sorted in descending order.

To achieve this the program uses a recursive sorting algorithm call Merge sort.

----------------------------------------------------------
How merge sort works (for both ascending and descending):

As we can see in the function "merge_sort" a call to "find_middle_node". what this does is return the middle node of the function and the moves it to the right 1

What this does split up the function into two sides. I labled these sides as first half and second half. 

After this is done we want to break the list up again into smaller parts.
This is done will recursion. As we can see first half is equal to a call of merger sort which creates recursion and splits up the function again into smaller parts.
The same is done with second half.

Once this is done we are left with a completely split up list and now we have to start putting it back together.

The function merge_sorted_list is called. This function will compare the first value in the first half to the first value of second half. Which ever half has a smaller value (bigger if sorting in descending order) is assigned to the next value in a sorted linked list. Then that half is moved to the next position and the function is called again recursively and the next value is compared to ]the previously bigger value (or smaller if sorting in descending order).

After this is done for all the values it will be sorted:

here is a diagram for reference (for descending bigger is added to temp): 
5 4 6 3
// unsorted list
5 4       6 3
// split up in the middle
4
// since 4 is bigger it is added to a temp list
4 5
// there is no next value so 5 is added
4 5       3 6
//same is done for other half
3
// 4 and 3 are compared since 3 is smaller it is added to temp
3 4
// 4 and 6 are compared since 4 is smaller it is added to temp
3 4 5
// 5 and 6 are compared since 5 is smaller it is added to temp
3 4 5 6
// there are no other values so 6 is added

Merge Sort time Complexity = O(n log n)
this is because we must both split the function down and then put it back together
which causes time complexity to increase at the rate n log n as the size of the list 
increases.
---------------------------------------------------------------------

After this press enter again to see the some tests and the menu pop up

If you scroll back up you will see two tests. The first checks how many prime numbers there are and the second shows that the funciton was cleared

Lets talk about prime number algorithm

------------------------------------------------------------------------
This algorithm is relatively simple

First this algorithm checks if the list is empty
Next it checks if the value is even or greater than 0

After this it loops counting up checking every number to see if it is divisible by that number

If there are no numbers that are divisible then it is a prime number

The time complexity of this would be O(n * n^2)
This is because we loop through every number possible and divide to check if it is prime and we also loop through the list
------------------------------------------------------------------------------

After all the test you will see this menu

How would you like to manipulate the linked list?
1. Get length of linked list
2. Print linked list
3. Push front
4. Push back
5. Insert
6. Sort ascending
7. Sort descending
8. Get prime count
9. Clear linked list
q. Quit
Enter Choice:

Since the list is empty now you will have to populate it again (use '3', '4', or '5')
Play around with these options to create linked list

When you are done enter 'q' 

4. Limitations

Do not try to enter a value that is not '1', '2', '3', '4', '5', '6', '7', '8', '9', or 'q'

Do not press anything but enter when doing tests

5.extra credit

TA Guess extra credit: Stefan Ene