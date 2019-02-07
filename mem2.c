#include <stdio.h>
#include <stdlib.h>

#define PRECHECK 0xAEAEAEAEAEAEAEAEL
#define POSTCHECK 0xEAEAEAEAEAEAEAEAL

//   +------------------------------------------+
//   +      Pointer to next memory block        +
//   +------------------------------------------+
//   +       Size of User Data, in bytes        +
//   +------------------------------------------+
//   +             PRECHECK sentinel            +
//   +------------------------------------------+
//   +                                          +
//   +                                          +
//   +                User Data                 +
//   +                                          +
//   +                                          +
//   +------------------------------------------+
//   +            POSTCHECK sentinel            +
//   +------------------------------------------+

unsigned long *firstMemoryBlock = NULL;
 typedef struct node{
        long data;
        struct *next;
  }node_t;
// Grab some memory
void *getMem(int numBytes) {
  // TODO: Implement
  node_t node=NULL;
  void* pVoid = malloc(3*node+numBytes);
  node->next = pVoid;
  long* pdata = pVoid+sizeof(node);
  *pData= numBytes;
  printf("%d\n", *pData);
}
// Check one memory block for integrity
void checkMem(unsigned long *longPtr) {
  // TODO: Implement
}


// Free memory allocated by getMem
void freeMem(void *userPtr) {
  // TODO: Implement
}


// Check all the un-freed memory
void finalMemoryCheck() {
  // TODO: Implement
}


int main(int argc, char *argv[]) {
  char *userPtr;
  
  printf("===== Test 1\n");
  userPtr = getMem(1);
  userPtr[0] = 'x';
  userPtr[1] = 'y';
  
  printf("===== Test 2\n");
  userPtr = getMem(100);
  userPtr[-30] = 'a';
  userPtr[230] = 'b';
  
  printf("===== Test 3\n");
  userPtr = getMem(10);
  userPtr[0] = 'x';
  userPtr[9] = 'y';
  freeMem(userPtr);
  
  printf("===== Test 4\n");
  userPtr = getMem(1000);
  userPtr[-1] = 'a';
  userPtr[1000] = 'b';

  finalMemoryCheck();  
  return 0;
}
