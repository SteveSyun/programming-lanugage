#include <stdio.h>
#include <stdlib.h>

#define PRECHECK 0xAEAEAEAEAEAEAEAEL
#define POSTCHECK 0xEAEAEAEAEAEAEAEAL

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
int num=0;
// Grab some memory
void *getMem(int numBytes) {
  // TODO: Allocation memory, fill in the two blocks at the top, and the block at the bottom
  // Return a pointer to the User Data
  // End of getMem
  void* pVoid;
  num=numBytes;
  while((num%8)!=0){
	  num++;
  }
  pVoid = malloc((3*sizeof(long))+(num));
  long *pData = pVoid;
   *pData = num; 
  //find local of pre
  long* precheck= pVoid+sizeof(long);
  *precheck=0xAEAEAEAEAEAEAEAEL;
  //find local of post
  long* postcheck=pVoid+(2*sizeof(long))+num; 
  *postcheck=0xEAEAEAEAEAEAEAEAL;
  printf("print numBytes = %d\n", num);
  //printf("signed precheck = %p\n", *precheck);
  //printf("get precheck in decimal = %lu\n", *precheck);
  //printf("signed postcheck = %p\n", *postcheck);
  //printf("get postcheck in decimal = %lu\n", *postcheck);
  //printf("mem addres = %p\n", *precheck);
  return pVoid+(2*sizeof(long));
}

// Free memory allocated by getMem
void freeMem(void *ptr) {
  // TODO: Check the two sentinels. If there are any problems, print an error message to stderr.
  // Release (free) the memory
  // End of freeMem
  long* pVoid = ptr-sizeof(long);
  long* pVoid2= (ptr+ *((long*)ptr-2));

  printf("________freeMem________\n\n");
  printf("%lx\n", *pVoid);
  printf("%lx\n", *pVoid2);
  if(*pVoid != PRECHECK){
  printf("Memory Corruption at %p, bytes= %lu, sentinel =%lx instead of %lx, \n", pVoid, *((long*)ptr-2), *pVoid, PRECHECK);
  }
  if(*pVoid2 !=POSTCHECK){
  printf("Memory Corruption at %p, bytes= %lu, sentinel =%lx instead of %lx, \n", pVoid2,  *((long*)ptr-2), *pVoid2, POSTCHECK);
  }
  printf("ptr= %ld\n", *((long*)ptr-2));
  void *f = ptr-(2*sizeof(long));
  free(f);
}
 
int main(int argc, char *argv[]) {
  char *ptr;
  
  printf("===== Test 1\n");
  ptr = getMem(10);
  ptr[0] = 'x';
  ptr[9] = 'y';
  freeMem(ptr);
  
  printf("===== Test 2\n");
  ptr = getMem(1);
  ptr[0] = 'x';
  ptr[1] = 'y';
  freeMem(ptr);
  
  printf("===== Test 3\n");
  ptr = getMem(100);
  ptr[-100] = 'a';
  ptr[200] = 'b';
  freeMem(ptr);
  
  printf("===== Test 4\n");
  ptr = getMem(1000);
  ptr[-1] = 'a';
  ptr[1000] = 'b';
  freeMem(ptr);
  
  return 0;
}
