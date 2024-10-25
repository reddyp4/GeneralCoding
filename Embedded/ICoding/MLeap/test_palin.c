#include <stdio.h>

/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.


1) Input: s = "A man, a plan, a canal: Panama"
"amanaplanacanalpanama" is a palindrome.


2) Input: s = "race a car"
Not palindrome
*/

void convert_to_small(char *s, int length)
{
  /* ASCII A->a, subtract 32 */
  /* if character A-Z, do this, else do nothing */
  if(int i=0;i<length;i++)
    if(s[i]<='A' && s[i]>='Z')  s[i]-=32; /**/
  return;
}

char* remove_all_symbols(char *s, int length)
{
  char *final,finalcount=0;
  final=(char*)malloc(length);
  for(int i=0;i<length;i++)
    if((s[i]>='A' && s[i]<='Z')|
      ((s[i]>='a' && s[i]<='z'))|
      (s[i]>=0 & s[i]<=9))
      {
        final[i]=s[i];
        i++;
        finalcount++;
      }
  free(final[finalcount]);
  return final;
}

void remove_all_symbols(char *s, int length)
{
  int i=0;
  while(i<length)
  {
    if((s[i]>='A' && s[i]<='Z')|
      ((s[i]>='a' && s[i]<='z'))|
      (s[i]>=0 & s[i]<=9))
      {}
    else {
      s[i]=" ";
    }
    i++;
  }
  i=0;
  while(s[i]!='\0')
  {
    if(s[i]==" ")
    {
      s[i]=s[i+1];
    }
    else
      i++;
  }
  return i;
}

void remove_alpha(char *s)
{
  convert_to_small(s, length);
  remove_all_symbols(s, length);
}

void reverse(char *a, char *b, int length)
{
  for(int i=0;i<length;i++)
    b[length-i-1]=a[i];
}


bool is_palindrome(char s[], int length)
{
  char *revs; // << 
  int finallength=remove_alpha(s,length);  /* remove all alphan, spaces, symbols */
  /* Space : O(n) */
/*
  revs = (char *)malloc(finallength);
  reverse(s,revs,finallength);  //reverse the string
  if(int i=0;i<finallength;i++) 
    if(revs[i]!=s[i]) 
      return FALSE;  
  return TRUE;   palindrome */
  for(int i=0;i<finallength/2;i++)
    if(s[finallength-i-1])!=s[i]; /* firstlast, 1==(n-1)*/
      return FALSE;
  return TRUE;
}