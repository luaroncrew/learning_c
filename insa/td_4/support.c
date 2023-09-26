#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int allocated; /* current allcoation of array */
    int filled;    /* number of items present in the binheap */
    int *array;    /* array of values */
} BinaryHeap;


BinaryHeap * Init(int size);

/* InsertValue insert value into the binary heap
 * the array is reallocated if necessary (allocated changed
 * with respect to the new size )
 * filled is incremented by 1 */
void InsertValue(BinaryHeap * heap, int value);

/* ExtractMAx returns 0 if the binary heap is empty
 * otherwise it return 1 and fills *val with the maximum
 * value present in the binary heap
 * filled is decremented by 1  and the max value is removed
 * from the binary heap */
int ExtractMax(BinaryHeap * heap, int * val);

/* Destroy frees the structure and the array */
void Destroy(BinaryHeap * heap);


int main(void)
{
    char lecture[100];
    int val;
    BinaryHeap * heap;
    heap = Init(10);

    fscanf(stdin,"%99s",lecture);
    while (strcmp(lecture,"bye")!=0) {
        if (strcmp(lecture,"insert")==0) {
            fscanf(stdin,"%99s",lecture);
            val = strtol(lecture,NULL,10);
            InsertValue(heap,val);
        } else if (strcmp(lecture,"extract")==0) {
            if(ExtractMax(heap,&val))
            {
                printf("%d\r\n",val);
            }
        }
        fscanf(stdin,"%99s",lecture);
    }
    Destroy(heap);
    return 0;
}

BinaryHeap * Init(int size)
{
    BinaryHeap * heapAddress = malloc(sizeof(BinaryHeap));
    heapAddress->filled = 0;
    heapAddress->allocated = size;
    heapAddress->array = malloc(sizeof(int) * size);
    return heapAddress;
}

void InsertValue(BinaryHeap * heap, int value)
{
    int elementPlaced = 0;
    int newElementIndex = heap->filled;
    int parentElementIndex = ((newElementIndex - 1) / 2);
    int swapElementValue;

    // insert at the end of the heap
    (heap->array)[newElementIndex] = value;

    heap->filled += 1;

    printf("%d", heap->filled);
    // if element is the top of the heap, we finished the operation
    if (heap->filled == 1) {
        return;
    }

    // place element correctly parent = (i-1)/2

    while (!elementPlaced) {
        if (heap->array[parentElementIndex] > heap->array[newElementIndex]) {
            elementPlaced = 1;
        } else {
            swapElementValue = heap->array[parentElementIndex];
            heap->array[newElementIndex] = swapElementValue;
            heap->array[parentElementIndex] = value;
            newElementIndex = parentElementIndex;
            parentElementIndex = ((newElementIndex - 1) / 2);
        }
    }


    /* put your insert code here */
}

int ExtractMax(BinaryHeap * heap, int *res)
{
    /* put your extraction code here */
    return 0;
}

void Destroy(BinaryHeap * heap)
{
    for (int i = 0; i < (heap->filled); i++) {
        printf("%d\r\f", (heap->array)[i]);
    }
    free(heap->array);
    free(heap);
}
