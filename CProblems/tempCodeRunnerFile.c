    int i;
    int checked[numsSize+1];
    // Method-1 Brute: Full search and check-off the number in seperate list
    for(i=0;i<numsSize;i++)
    {
        checked[*(nums+i)] = 1;
    }

    // Return index of zero number
    for(i=0;i<=numsSize;i++)
    {
        if(checked[i]==1)
        {
        }
        else
        {
            return i;
        }
    }
