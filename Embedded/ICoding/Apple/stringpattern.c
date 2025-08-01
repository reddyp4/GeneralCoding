#include <stdio.h>
#include <string.h>
#include <stdint.h>

// To execute C, please define "int main()"

/* 

char *str = "aaabaabaddaaddaccdddeeeeesssssiiiiiiiiiiii";

a - 8 - 001
b - 2 - 0000001
c - 2 - 00000001
d - 7 - 0001
e - 7 - 00001
s - 4 - 000001
i - 10 - 01

output:

001 001 001 0000001 ...

1) Count occurences: parsing the string, update the count in array
    key-value
    character-occurence
2) Sorting the values, key-value based on a criteria
    decreasing order of occurence
    if same occurence, increasing lexicographically
3) Parse through each value, pick up the key, make the pattern
4) parse the string
    result string+=current+pattern[char]

*/

void sort(int *nums,int length)

string encode(string s) {
  //all lower case snake
  int occur[26][2]; //[i][0]=char, [i][1]=occurence
  int unsorted_occur[26],sorted_occur[26];  //loose char-occur
  string pattern[26];
  string result;
  int i;
  for(i=0;i<s.size();i++) {
    occur[s[i]-'a'][0]=0;
    occur[s[i]-'a'][1]=0;
  }
  for(i=0;i<s.size();i++) occur[s[i]-'a'][0]=i;
  //occurence map
  for(i=0;i<s.size();i++) occur[s[i]-'a'][1]++;
  //sorting by decreasing order of occur,
  sort(occur,occur.size());
  /* Now we have a sorted array, [count][char] */
  string p="1";
  for(i=0;i<26;i++) {
    //char
    char c=occur[i][0];
    p="0"+p;
    pattern[c-'a']=p;
  }
  /* Parse the string */
  for(i=0;i<s.size();i++) {
    char c=s[i];
    result+=pattern[c-'a'];
  }
  return result;
}


int main() {
  string s="aaabaabaddaaddaccdddeeeeesssssiiiiiiiiiiii";
  string result=encode(s);
  return 0;
}




