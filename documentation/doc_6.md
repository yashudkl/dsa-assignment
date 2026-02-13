
## Data Structures Defined

Queue has array implementation and is defined as strucutre with size , front index, rear index, and an array.

Code for reference: 

1) Line no 4 (Defining Heap) <br>
```
struct Heap {
    int* arr;
    int size;
    int capacity;
}; 
and 
typedef struct Heap heap;
```


## Function Implementation

Here are list of functions implemented with their purpose

Here are list of functions implemented with their purpose

## Max Heap Functions

1) <b>createHeap</b> <br>
Uses an array of integers to create and initialise a max heap. The heap structure and its internal array are allocated memory, input array elements are copied into the heap, and a valid max heap is constructed by calling maxHeapify on every non-leaf node from bottom to top.

* Purpose: It initializes a max heap data structure from an existing array.

2) <b>insertHelper</b> <br>
It is a recursive function that bubbles up an element to preserve max heap property. It recursively moves upward until the heap property is met after comparing the element at a given index with its parent and swapping if the child is larger than parent.

* Purpose: To preserve max heap property by moving an element up.

3) <b>maxHeapify</b> <br>
It maintains max heap property by moving down an element. Compares the element at the given index with its left and right children. It finds the largest among them, swaps the parent with the largest child if needed, and keeps going down recursively to maintain the heap property in the entire subtree.

* Purpose: To preserve max heap property by moving an element down.

4) <b>extractMax</b> <br>
It removes and returns the maximum element, or root, from the max heap. It retrieves the root element and replaces it with the last element in the heap. Then, it decreases the heap size by 1 and calls maxHeapify on the root to restore the heap property.

* Purpose: To delete and return the maximum element from the max heap.

5) <b>insert</b><br>
Inserts a new element into the max heap. It checks if the heap has room for the new element. Then, it places the new element at the end of the array. It calls insertHelper to move the element up to its correct spot and increases the heap size.

* Purpose: Adding new element and also maintaining max heap property.

## Min Heap Functions

6) <b>createMinHeap</b> <br>
Uses an array of integers to create and initialise a min heap. The heap structure and its internal array are allocated memory, input array elements are copied into the heap, and a valid min heap is constructed by calling minHeapify on every non-leaf node from bottom to top.

7) <b>insertMinHelper</b> <br>
It is a recursive function that bubbles up an element to preserve min heap property. It recursively moves upward until the heap property is met after comparing the element at a given index with its parent and swapping if the child is smaller than parent.

* Purpose: To preserve min heap property by moving an element up.

8) <b>minHeapify</b> <br>
It maintains min heap property by moving down an element. Compares the element at the given index with its left and right children. It finds the smallest among them, swaps the parent with the smallest child if needed, and keeps going down recursively to maintain the heap property in the entire subtree.

* Purpose: To preserve min heap property by moving an element down.

9) <b>extractMin</b> <br>
It removes and returns the minimum element, or root, from the min heap. It retrieves the root element and replaces it with the last element in the heap. Then, it decreases the heap size by 1 and calls minHeapify on the root to restore the heap property.

* Purpose: To delete and return the minimum element from the min heap.

10) <b>insertMin</b><br>
Inserts a new element into the min heap. It checks if the heap has room for the new element. Then, it places the new element at the end of the array. It calls insertMinHelper to move the element up to its correct spot and increases the heap size.

* Purpose: Adding new element and also maintaining min heap property.


11) <b>printHeap</b> <br>
Prints heap elements by iterating through each element in the array from index 0 to size-1 and displays them separated by spaces.

* Purpose: To print the heap elements.


## Orgranization of main function 
Integer array is created first, heap is created by calling createheap function.After that heap is initialized. Displaying heap affter creation by using printHeap function. Then maximum is extracted by calling extractMax. After that modified heap is also printed. Then mean of original array is calculated 


## Sample Output

1) Max Heap and Min Heap of given array.<br>
<img src = "media/{A9755A48-2989-420C-97AD-B3139773C968}.png" width = "400"> <br>
<img src="media/{CF5F8139-458B-40D0-BE30-EDB5CDC4940A}.png" width="400"/>



