In a system, file permissions are represented as a 3-digit octal number (e.g., 0754), where each digit corresponds to user, group, and others permissions, respectively. Each digit is a combination of read (4), write (2), and execute (1) bits.  For example, 0755 indicates that the user has read/write/execute permissions while group and others can only read and execute.  An input of "0755" for a file would result in a long listing format of "-rwxr-xr-x".
 
For example:
```
$ ls -al
total 7336
drwxrwxr-x  4 user user    4096 Jun  2 17:19 .
drwxr-x--- 24 user user    4096 May 21 10:25 ..
drwxr-xr-x  2 user user    4096 May 20 16:58 files
-rwxr-xr-- 46 user user    4096 May 20 16:59 file
```
  u  gr  all
 111 = 7, 101=5, 011 = 3
 
Write C functions or a small C++ class `Permission` that:
1. Accepts an octal integer string (e.g., "0754") in its constructor/argument as a string or character pointer.
  a. For example, `Permission(const std::string& encodedPermission)`

class {

public:
int num1,num2,num3;

void persmission(char* data)  //length 4 characters
{
  char++;
  //get the number from char at each posn, three posn
  int num1 = (*char-'0');
  char++;
  int num2 = (*char-'0');
  //num = 7 - rwx - 
  char++;
  int num3 = (*char-'0');
  //
}




2. Has a method/function bool canRead(char who) where who is 'u', 'g', or 'o'.
rwx = 100 = 4
      111 = 7
bool canRead(char c)
{
  if(c=='u')  return(num1>=4)   return(num1&0x4)
  else if(c=='g') return(num2>=4)   return(num2&0x4)
  else if(c=='o') return(num3>=4)   return(num3&0x4)
  return false;
}

}