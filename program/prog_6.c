#include <malloc.h>
#include <stdio.h>
// Declare a heap structure
struct Heap {
    int* arr;
    int size;
    int capacity;
};

// define the struct Heap name
typedef struct Heap heap;

// forward declarations
heap* createHeap(int capacity, int* nums);
heap* createMinHeap(int capacity, int* nums);
void insertHelper(heap* h, int index);
void insertMinHelper(heap* h, int index);
void maxHeapify(heap* h, int index);
void minHeapify(heap* h, int index);
int extractMax(heap* h);
int extractMin(heap* h);
void insert(heap* h, int data);
void insertMin(heap* h, int data);

// Define a createHeap function
heap* createHeap(int capacity, int* nums)
{
    // Allocating memory to heap h
    heap* h = (heap*)malloc(sizeof(heap));

    // Checking if memory is allocated to h or not
    if (h == NULL) {
        printf("Memory error");
        return NULL;
    }
    // set the values to size and capacity
    h->size = 0;
    h->capacity = capacity;

    // Allocating memory to array
    h->arr = (int*)malloc(capacity * sizeof(int));

    // Checking if memory is allocated to h or not
    if (h->arr == NULL) {
        printf("Memory error");
        return NULL;
    }
    int i;
    for (i = 0; i < capacity; i++) {
        h->arr[i] = nums[i];
    }

    h->size = i;
    i = (h->size - 2) / 2;
    while (i >= 0) {
        maxHeapify(h, i);
        i--;
    }
    return h;
}

// Defining maxHeapify_bottom_up function
void insertHelper(heap* h, int index)
{

    // Store parent of element at index
    // in parent variable
    int parent = (index - 1) / 2;

    if (h->arr[parent] < h->arr[index]) {
        // Swapping when child is smaller
        // than parent element
        int temp = h->arr[parent];
        h->arr[parent] = h->arr[index];
        h->arr[index] = temp;

        // Recursively calling maxHeapify_bottom_up
        insertHelper(h, parent);
    }
}

void maxHeapify(heap* h, int index)
{
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int max = index;

    // Checking whether our left or child element
    // is at right index of not to avoid index error
    if (left >= h->size || left < 0)
        left = -1;
    if (right >= h->size || right < 0)
        right = -1;

    // store left or right element in max if
    // any of these is smaller that its parent
    if (left != -1 && h->arr[left] > h->arr[max])
        max = left;
    if (right != -1 && h->arr[right] > h->arr[max])
        max = right;

    // Swapping the nodes
    if (max != index) {
        int temp = h->arr[max];
        h->arr[max] = h->arr[index];
        h->arr[index] = temp;

        // recursively calling for their child elements
        // to maintain max heap
        maxHeapify(h, max);
    }
}

int extractMax(heap* h)
{
    int deleteItem;

    // Checking if the heap is empty or not
    if (h->size == 0) {
        printf("\nHeap id empty.");
        return -999;
    }

    // Store the node in deleteItem that
    // is to be deleted.
    deleteItem = h->arr[0];

    // Replace the deleted node with the last node
    h->arr[0] = h->arr[h->size - 1];
    // Decrement the size of heap
    h->size--;

    // Call maxheapify_top_down for 0th index
    // to maintain the heap property
    maxHeapify(h, 0);
    return deleteItem;
}

// Define a insert function
void insert(heap* h, int data)
{

    // Checking if heap is full or not
    if (h->size < h->capacity) {
        // Inserting data into an array
        h->arr[h->size] = data;
        // Calling maxHeapify_bottom_up function
        insertHelper(h, h->size);
        // Incrementing size of array
        h->size++;
    }
}

void printHeap(heap* h)
{

    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

void insertMinHelper(heap* h, int index)
{
    int parent = (index - 1) / 2;

    if (h->arr[parent] > h->arr[index]) {
        int temp = h->arr[parent];
        h->arr[parent] = h->arr[index];
        h->arr[index] = temp;
        insertMinHelper(h, parent);
    }
}

void minHeapify(heap* h, int index)
{
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int min = index;

    if (left >= h->size || left < 0)
        left = -1;
    if (right >= h->size || right < 0)
        right = -1;

    if (left != -1 && h->arr[left] < h->arr[min])
        min = left;
    if (right != -1 && h->arr[right] < h->arr[min])
        min = right;

    if (min != index) {
        int temp = h->arr[min];
        h->arr[min] = h->arr[index];
        h->arr[index] = temp;
        minHeapify(h, min);
    }
}

heap* createMinHeap(int capacity, int* nums)
{
    heap* h = (heap*)malloc(sizeof(heap));

    if (h == NULL) {
        printf("Memory error");
        return NULL;
    }

    h->size = 0;
    h->capacity = capacity;
    h->arr = (int*)malloc(capacity * sizeof(int));

    if (h->arr == NULL) {
        printf("Memory error");
        return NULL;
    }

    int i;
    for (i = 0; i < capacity; i++) {
        h->arr[i] = nums[i];
    }

    h->size = i;
    i = (h->size - 2) / 2;
    while (i >= 0) {
        minHeapify(h, i);
        i--;
    }
    return h;
}

void insertMin(heap* h, int data)
{
    if (h->size < h->capacity) {
        h->arr[h->size] = data;
        insertMinHelper(h, h->size);
        h->size++;
    }
}

int extractMin(heap* h)
{
    int deleteItem;

    if (h->size == 0) {
        printf("\nHeap is empty.");
        return -999;
    }

    deleteItem = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    minHeapify(h, 0);
    return deleteItem;
}

void main()
{
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    heap* hp = createHeap(9, arr);
    heap* minHp = createMinHeap(9, arr);

    printf("Max heap: ");
    printHeap(hp);
    extractMax(hp);
    printf("After extract max: ");
    printHeap(hp);

    printf("Min heap: ");
    printHeap(minHp);
    extractMin(minHp);
    printf("After extract min: ");
    printHeap(minHp);
}