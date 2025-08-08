/*
how to run: gcc pointer.c -o pointer && pointer
*/
int main() {
  int *a = 1; //a int pointer, havent assigned memoryto the pointer, no malloc
  //a=(int *)malloc(sizeof(int));
  //*a=1; //assigning value in the memory to 1

  printf("%d\n", a+1);  //&(a+1)=address of a+1, print 2
                        //a+1 =2, a+1 is pointer to second byte (char=byte)
                        //8-bit, 2byte=2address
                        //32-bit, packed construct, 2byte, if not 2nd-address, first/last depending in endianess of micro
                        //32-bit, little endian-MSB is stored at 0th,5th byte = 5

  return 0;
  
}
