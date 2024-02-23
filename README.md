# lab_assignment_6
Write an efficient recursive function that takes in a sorted array of numbers, two integers, low and high, representing indexes into the array, and another integer, value, and returns the index in the array where value is found in the array in between index low and high, inclusive. If value is NOT found in the array in between indexes low and high, inclusive, then the function should return -1. 

Student: I included stdlib.h since malloc is called in main.
Student: I did not include a case for if low == high, since in such a situation, mid == low == high, and is covered by other cases. 