/*
when defining a pointer variable:
    (type) *(name);
-> the * symbol is to show that this is a pointer; the type shows the type of value at the reference of pointed by the pointer.

when calling a variable:
    * is to get value
    & is to get reference (address)
*/

// Arrays are created and accessed by using pointers.

#include <stdio.h>
int main(void){ 
    int i;
    int *iptr = &i;
    scanf("%d", &i);
    printf("iptr = %p\n", iptr);
    printf("&iptr = %p\n", &iptr);
    printf("*iptr = %d\n", *iptr);
    printf("*(&iptr) = %p\n", *(&iptr));
    printf("&(*iptr) = %p\n", &(*iptr));
    printf("*(*(&iptr)) = %d\n", *(*(&iptr)));
    printf("*(&(*iptr)) = %d\n", *(&(*iptr)));
    printf("&(*(&iptr)) = %p\n", &(*(&iptr)));
    printf("i = %d\n", i); /* errorcase */ printf("&i = %p\n", &i);
    
    /*printf("*i = %p\n", *i); do not do this */
    printf("*(&i) = %d\n", *(&i)); 
    /*printf("&(*i) = %p\n", &(*i)); 
    do not do this either */
    return 0; 
}
