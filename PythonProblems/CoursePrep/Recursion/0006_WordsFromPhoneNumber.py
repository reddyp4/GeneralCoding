'''
Words From Phone Number


Given a seven-digit phone number, return all the character combinations that can be generated according to the following mapping:

Graph

Return the combinations in the lexicographical order.

Example One
{
"phone_number": "1234567"
}
Output:

[
"adgjmp",
"adgjmq",
"adgjmr",
"adgjms",
"adgjnp",
...
"cfilns",
"cfilop",
"cfiloq",
"cfilor",
"cfilos"
]
First string "adgjmp" in the first line comes from the first characters mapped to digits 2, 3, 4, 5, 6 and 7 respectively. Since digit 1 maps to nothing, nothing is appended before 'a'. Similarly, the fifth string "adgjnp" generated from first characters of 2, 3, 4, 5 second character of 6 and first character of 7. All combinations generated in such a way must be returned in the lexicographical order.

Example Two
{
"phone_number": "1234567"
}
Output:

[""]
Notes
Return an array of the generated string combinations in the lexicographical order. If nothing can be generated, return a list with an empty string "".
Digits 0 and 1 map to nothing. Other digits map to either three or four different characters each.
Constraints:

Input string is 7 characters long; each character is a digit.
'''
phone = ["","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz","0"]

def recursive(current,count,phone_number,final):
    if(count==7):
        if(current!=""):
            final.append(current[:])
        return
    newcount=int(phone_number[count])
    if(newcount>1):
        for c in phone[newcount]:
            recursive(current+c,count+1,phone_number,final)
    else:
        recursive(current,count+1,phone_number,final)

def get_words_from_phone_number(phone_number):
    """
    Args:
     phone_number(str)
    Returns:
     list_str
    """
    # Write your code here.
    final=[]
    recursive("",0,phone_number,final)
    if(len(final)==0):
        final.append("")
    return final
