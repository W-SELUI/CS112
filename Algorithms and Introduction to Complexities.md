

Pass Sessions Notes compile by the PASS Leader - William Selui

---

## Introduction

This module introduces algorithm efficiency and complexity analysis before moving into fundamental sorting and searching techniques. Understanding how fast an algorithm performs is just as important as understanding how it works.

We begin with Big-O notation, which allows us to measure algorithm efficiency, then explore Bubble Sort, Linear Search, Binary Search, Recursive Binary Search, and Quicksort.

Throughout these notes, focus on both **how the algorithms work** and **their time complexities**, as these are commonly tested in exams.

---

# 1. What Is an Algorithm?

An algorithm is a step-by-step procedure used to solve a problem.

Examples include:

- Finding the largest value in an array
- Sorting a list of numbers
- Searching for a student ID
- Calculating an average

An algorithm is considered correct if it produces the correct result.

However, computer scientists are also interested in:

- How much time the algorithm takes
- How much memory it uses
- How its performance changes as the input size grows

This is where complexity analysis becomes important.

---

# 2. Why Study Complexity?

Consider the following program:

```c++
c = 0;  

sum = 0;  

cin >> num;  

  

while (num != -1)  

{  

sum += num;  

c++;  

cin >> num;  

}  

  

average = sum / c;  

cout << average;
```
Suppose:
- The loop runs 10 times
- The loop runs 100 times
- The loop runs 1,000 times

The amount of work increases as the number of loop iterations increases.

We can represent the number of operations as:

`4n + 5`  where: `n = number of loop iterations

For very large values of `n`, the term `4n` dominates the expression.
Therefore, then analyzing algorithms, we focus on the dominant growth rate rather than exact operation counts.

---

# 3. Big-O Notation

Big-O notation describes how an algorithm's running time grows as the problem size increases.

Rather than counting every individual operation, Big-O focuses on growth.

Common complexity classes:

```
O(1) Constant  

O(log n) Logarithmic  

O(n) Linear  

O(n log n) Linearithmic  

O(n²) Quadratic  

O(2ⁿ) Exponential
```
As n becomes larger:

```
O(log n) grows very slowly  

O(n) grows steadily  

O(n²) grows much faster  

O(2ⁿ) becomes extremely large
```

For large inputs:
``O(log n) < O(n) < O(n log n) < O(n²) < O(2ⁿ)

Therefore, algorithms with lower growth rates are generally preferred.

---

# 4. Bubble Sort

## What Is Bubble Sort?
Bubble Sort is a simple sorting algorithm that repeatedly compares adjacent elements and swaps them when they are in the wrong order.

Example:
```c++
Initial:  

5 3 8 1  

  
Compare 5 and 3  

Swap  


3 5 8 1  
 

Compare 5 and 8  

No swap  


3 5 8 1  


Compare 8 and 1  

Swap  


3 5 1 8
```

After each pass, the largest unsorted element "bubbles" toward its correct position.

This is the origin of the name Bubble Sort.

---

## Basic Bubble Sort Implementation

```
void bubbleSort(int x[], int n)  

{  

	for(int pass = 1; pass < n; pass++)  
	
	{  
	
		for(int i = 0; i < n - pass; i++)  
		
		{  
			
			if(x[i] > x[i + 1])  
			
			{  
			
				int temp = x[i];  
				
				x[i] = x[i + 1];  
				
				x[i + 1] = temp;  
				
			}  
		
		}  
	
	}  

}
```

### How It Works

Outer Loop:
Determines the number of passes.  

Inner Loop:
Compares neighbouring elements.

Swap:
Exchanges elements if they are out of order.

---

## Bubble Sort Complexity

### Average Case
O(n²)

**Reason:**
Nested loops perform many comparisons.

### Best Case
If the algorithm detects that no swaps occurred during a pass:
O(n)

Reason:
The array is already sorted.

---

## Bubble Sort Exam Hints

- Bubble Sort compares adjacent elements.
- Bubble Sort uses swapping.
- Largest element moves to the end after each pass.
- Average complexity = O(n²)
- Best complexity (optimized version) = O(n)

---

# 5. Linear Search

## What Is Linear Search?

Linear Search examines each element one at a time until the target value is found.

Example:
```
Array:  

10 20 30 40 50  

  

Search for 40  

  

10 -> Not found  

20 -> Not found  

30 -> Not found  

40 -> Found
```

---

## Linear Search Code

```
int linearSearch(int a[],  

int first,  

int last,  

int key)  

{  

for(int i = first; i <= last; i++)  

{  

if(key == a[i])  

return i;  

}  

  

return -1;  

}
```

---

## Linear Search Complexity

### Worst Case

**O(n)**

Reason:
Every element may need to be checked.

---

## Advantages

- Easy to understand
- Works on unsorted arrays
- Works on sorted arrays

## Disadvantages

- Slow on large arrays
- May need to check every element

---

# 6. Binary Search

## What Is Binary Search?
Binary Search is a much faster searching algorithm.

However:
The array MUST be sorted.

Instead of checking every element, Binary Search repeatedly divides the search space in half.

---

## Example

Array:
5 10 15 20 25 30 35

Search for: 25

Step 1: Middle = 20  
25 > 20  
Search right half.

Step 2: Middle = 30  
25 < 30  
Search left half.

Step 3: Middle = 25  
Found.

Notice that many elements were skipped entirely.
This is why Binary Search is much faster than Linear Search.

---

## Iterative Binary Search Code

```c++
int binarySearch(int array[],  

				int first,  
				
				int last,  
				
				int key)  

{  

	while(first <= last)  
	
	{  
	
		int mid = (first + last) / 2;  
		
		  
		
		if(key > array[mid])  
			first = mid + 1;  
		
		else if(key < array[mid])  
			last = mid - 1;  
			
		else  
			return mid;  
	
	}  
	
	  
	
	return -1;  

}
```

---

## Binary Search Complexity

Each comparison removes roughly half the remaining elements.

Example:

```
n  

n/2  

n/4  

n/8  

...
```
Therefore:

**O(log n)**

---

## Binary Search Exam Hints

- Array must be sorted.
- Searches the middle first.
- Eliminates half the elements each comparison.
- Complexity = O(log n).

---

# 7. Recursive Binary Search

Binary Search can also be implemented using recursion.

---

## Recursive Binary Search Code

```c++
int binarySearch(int array[],  

				int first,  
				
				int last,  
				
				int key)  

{  

	if(first > last)  
	return -1;  

	int middle = (first + last) / 2;  

	if(key == array[middle])  
		return middle;  

	else if(key < array[middle])  
		return binarySearch(array,  
	
							first,  
							
							middle - 1,  
							
							key);  
							
	  
	
	else  
		return binarySearch(array,  
	
							middle + 1,  
							
							last,  
							
							key);  

}
```

---

## Base Case

```c++
if(first > last)  
return -1;
```

Meaning: The key does not exist in the array.

---

## Recursive Cases

Search left side:
```
binarySearch(array,  

first,  

middle - 1,  

key);
```
Search right side:
```
binarySearch(array,  

middle + 1,  

last,  

key);
```

---

## Complexity

**O(log n)**
Just like iterative Binary Search.

---

## Exam Hints

Every recursive function requires:

- Base case
- Recursive case

The search range becomes smaller with every call.

---

# 8. Quicksort

## What Is Quicksort?
Quicksort is one of the fastest sorting algorithms.

It uses:
```
Recursion  +  Divide and Conquer
```
The main idea is:

1. Select a pivot.
2. Partition the array.
3. Recursively sort both partitions.

---

# 9. The Pivot

The pivot is a chosen element used to divide the array.

Example:

8 4 7 2 9 1 5

Choose:
Pivot = 7

Partition result:
**4 2 1 5 | 7 | 8 9**

Everything smaller than the pivot:
Left side

Everything larger than the pivot:
Right side

The pivot is now in its correct position.

---

# 10. How Quicksort Works

Suppose:
8 4 7 2 9 1 5

Choose pivot:
7  

Partition:
4 2 1 5 | 7 | 8 9

Then recursively sort:
4 2 1 5

and
8 9

The exact same process is repeated on the smaller arrays.

This continues until each partition contains one element.

---

# 11. Quicksort Algorithm

1. Choose a pivot.  

2. Partition the array.  

3. Place the pivot in its correct position.  

4. Recursively sort the left partition.  

5. Recursively sort the right partition.

This is a classic Divide-and-Conquer algorithm.

---

# 12. Quicksort Complexity

## Best Case

Occurs when partitions are evenly balanced.

Example:

n/2 elements on left  
n/2 elements on right

Recursion depth:
log n

Work performed on each level:
n

Complexity: O(n log n)

---

## Worst Case

Occurs when partitions are extremely uneven.

Example:

1 element  
n - 1 elements

Recursion depth: n

Complexity:
O(n²)

---

## Quicksort Exam Hints

- Uses recursion.
- Uses divide-and-conquer.
- Requires a pivot.
- Best case = O(n log n)
- Worst case = O(n²)

---

# 13. Common Exam Questions

## What is the difference between Linear Search and Binary Search?

Linear Search:
- Checks elements one-by-one.  
- Works on sorted or unsorted arrays.  
- O(n)

Binary Search:
- Requires a sorted array.  
- Repeatedly halves the search space.  
- O(log n)

---

## Why is Binary Search faster?

Because each comparison removes approximately half of the remaining elements.

---

## Why is Quicksort recursive?

Because after partitioning, it must solve the same sorting problem on two smaller subarrays.

---

## Why is Bubble Sort slow?

Because it performs many repeated comparisons and swaps, giving it O(n²) complexity.

---

# 14. Quick Reference Summary

- Algorithm = step-by-step procedure to solve a problem.
- Big-O measures how running time grows with input size.
- O(1) = Constant
- O(log n) = Logarithmic
- O(n) = Linear
- O(n log n) = Linearithmic
- O(n²) = Quadratic
- O(2ⁿ) = Exponential

### Sorting
- Bubble Sort compares adjacent elements.
- Bubble Sort average complexity = O(n²).
- Bubble Sort best complexity = O(n).

### Searching
- Linear Search = O(n).
- Works on sorted and unsorted arrays.
- Binary Search = O(log n).
- Requires sorted arrays.

### Recursive Binary Search
- Base case: item not found.
- Recursive case: search left or right half.
- Complexity = O(log n).

### Quicksort
- Uses recursion and divide-and-conquer.
- Choose pivot.
- Partition array.
- Recursively sort left and right partitions.
- Best Case = O(n log n)
- Worst Case = O(n²)

---

# Final Exam Focus

Prioritize these topics:

1. Big-O notation and growth rates.
2. Identifying algorithm complexities.
3. Bubble Sort tracing.
4. Linear Search vs Binary Search.
5. Recursive Binary Search base and recursive cases.
6. Quicksort pivot selection and partitioning.
7. Complexity values:
    - O(n)
    - O(log n)
    - O(n²)
    - O(n log n)

If you can trace Bubble Sort, Binary Search, and Quicksort by hand while understanding why their complexities differ, you'll be in a very strong position for the exam.