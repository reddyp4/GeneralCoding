/*
556. Next Greater Element III
Solved
Medium
Topics
Companies
Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

 

Example 1:

Input: n = 12
Output: 21
Example 2:

Input: n = 21
Output: -1
 

Constraints:

1 <= n <= 231 - 1
*/

class Solution {
    public:
        int nextGreaterElement(int n) {
            if(n<10) return -1;
            int printflag=0;
            int index=2, newnumber=n,numberIndices=1,found=0;
            //Convert into an array
            vector<int> arrn(32);
            for(int i=0;i<32;i++)
            {
                arrn[31-i]=newnumber%10;
                newnumber=(int)(newnumber/10);
                if(printflag==1)
                    cout<<newnumber<<"digit"<<arrn[31-i]<<endl;
                if(newnumber==0 && numberIndices==1)
                {
                    //cout<<"done"<<endl;
                    numberIndices=i+1;
                    if(printflag==1)
                        cout<<"number of indices:"<<numberIndices<<endl;
                    //break;
                }
            }
            //std::sort(arrn.begin(),arrn.begin()+32);    //sort not working
            //print the array
            if(printflag==1)
            {
                cout<<"array:";
                for(int i=numberIndices;i>0;i--)
                {
                    cout<<arrn[32-i]<<",";
                }
                cout<<endl;
            }
            int nextbiggerindex=-1;
            for(int i=30;i>=32-numberIndices;i--)
            {
                nextbiggerindex=-1;
                //number to check is from i to 31
                //find next bigger digit than one at 0
                for(int j=i+1;j<=31;j++)
                {
                    if(arrn[j]>arrn[i])
                    {
                        if(nextbiggerindex==-1) nextbiggerindex=j;
                        else
                            nextbiggerindex=(arrn[j]>arrn[nextbiggerindex])?nextbiggerindex:j;
                    }
                }
                if(nextbiggerindex!=-1) //found an index
                {
                    if(printflag==1)
                        cout<<"current index:"<<i<<",val:"<<arrn[i]<<",next bigger at index:"<<nextbiggerindex<<",val:"<<arrn[nextbiggerindex]<<endl;
                    //arrange rest of numbers in ascending, i to 31, except nextbiggerindex
                    //swap indices, in array to make it easier to sort
                    int temp1=arrn[nextbiggerindex];
                    arrn[nextbiggerindex]=arrn[i];
                    arrn[i]=temp1;
                    if(printflag==1)
                        cout<<"sort range:"<<i+1<<","<<31<<endl;
                    //std::sort(arrn+i+1,arrn+31);
                    std::sort(arrn.begin()+i+1,arrn.begin()+32);
                    //also break
                    break;
                }            
            }
            if(printflag==1)
                cout<<"next bigger at index:"<<nextbiggerindex<<endl;
            if(nextbiggerindex==-1) return -1;
            if(printflag==1)
            {
                cout<<"sorted array:";
                for(int i=numberIndices;i>0;i--)
                {
                    cout<<arrn[32-i]<<",";
                }
                cout<<endl;
            }
            //build the number
            for(int i=numberIndices;i>0;i--)
            {
                if(214748364<newnumber) return -1;
                newnumber=newnumber*10;
                if((2147483648-newnumber)<=arrn[32-i])   return -1;
                if(printflag==1)
                    cout<<(2147483648-newnumber)<<",arrn[32-i]="<<arrn[32-i]<<endl;
                newnumber+=arrn[32-i];
                if(printflag==1)
                    cout<<"arrn[32-i]="<<arrn[32-i]<<",newnumber:"<<newnumber<<endl;
            }
            return newnumber;
        }
    };

/*
Runtime 0ms
Beats 100.00%

Memory 7.80MB
Beats 62.07%


*/