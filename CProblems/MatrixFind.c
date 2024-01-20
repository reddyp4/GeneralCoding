/**
nVidia
Monotonically increasing array
Example of Matrix(A): 5X4, 3X2 <
1 2 3 4
5 6 8 10
11 13 14 15
16 17 18 19
20 21 22 23
X rows
Y cols
[row, col]: If target is found 
[-1, -1]: if target is not found
*/ 

/*int search1D(int arr[12], int start, int end, int target)
{
    int mid = int((start+end)/2);  // start + (end-start)/2
    if(end==start)
        if(target==arr[mid])
            return index;
    if(target==arr[mid]) 
        return mid;
    if(end-start==1)    //two elements
    {
        if(target==arr[start])
            return start;
        if(target==arr[end])
            return end;
        else 
            return -1;
    }
    if(target < arr[mid])
    {
        int retindex = search1D( arr[12], start,mid-1, target);
    }
    else
    {
        int retindex=search1D(arr[12], mid+1,end, target);
    }
    return retindex;    
}*/

void search2D(int mat[3][4], int nROWS, int nCOLS, int* row, int* col, int target) {
    // start to end, mid point
    // row, col
    // index = nRows*(row-1)
    // m,n = index = nCOLS*m+n
    // index = m,n; m=int(index/nCOLS); n=(index%nCOLS)
    // Search in first column as binary search
    // Search in that row as binary search
    int row1=0;
    int row2=nROWS-1;
    int col1=0;
    int col2=nCOLS-1;
    //Search first column first as binary search
    int found=0;
    int mid=0;
    *row=-1;
    *col=-1;
    if(mat[nROWS-1][0]>=target)
    {
        while(row2-row1!=1 & found==0)
        {
            mid = row1 + (row2-row1)/2;
            printf("row1: %d; row2: %d; mid: %d\n", row1, row2, mid);
            if(mat[row1][0]==target)
            {
                found=1;
                *row=row1;
                *col=0;
                return;
            }
            if(mat[row2][0]==target)
            {
                found=1;
                *row=row2;
                *col=0;
                return;
            }
            else if(mat[mid][0]==target)
            {
                found=1;
                *row=mid;
                *col=0;
                return;
            }
            else if (mat[mid][0]>target)
            {
                row2=mid;
            }
            else
                row1=mid;
        }
    }
    else {
        row1=nROWS-1;
    }
    if(found)
    {
        *row = mid;
        *col = 0;
        return;
    }
    col1=0;
    col2=nCOLS-1;
    while(col2-col1!=1 & found==0)
    {
        mid = col1 + (col2-col1)/2;
        if(mat[row1][col1]==target)
        {
            found=1;
            *row=row1;
            *col=col1;
            return;
        }
        else if(mat[row1][col2]==target)
        {
            found=1;
            *row=row1;
            *col=col2;
            return;
        }
        else if(mat[row1][mid]==target)
        {
            found=1;
            *row=row1;
            *col=mid;
            return;
        }
        else if(mat[row1][mid]>target)
        {
            col2=mid;
        }
        else {
            col1=mid;
        }
    }
    return;
}

int main (){
    int mat[3][4] = {{1,2,3,4},{5,10,11,15},{16,18,20,21}};
    int rowToFind = 0;
    int colToFind = 0;
    search2D(mat, 3, 4, &rowToFind, &colToFind, 1);
    printf ("Result found at: [%d][%d]\n", rowToFind, colToFind);
    search2D(mat, 3, 4, &rowToFind, &colToFind, 3);
    printf ("Result found at: [%d][%d]\n", rowToFind, colToFind);
    search2D(mat, 3, 4, &rowToFind, &colToFind, 15);
    printf ("Result found at: [%d][%d]\n", rowToFind, colToFind);
    search2D(mat, 3, 4, &rowToFind, &colToFind, 21);
    printf ("Result found at: [%d][%d]\n", rowToFind, colToFind);
    search2D(mat, 3, 4, &rowToFind, &colToFind, 7);
    printf ("Result found at: [%d][%d]\n", rowToFind, colToFind);
    search2D(mat, 3, 4, &rowToFind, &colToFind, 22);
    printf ("Result found at: [%d][%d]\n", rowToFind, colToFind);
    search2D(mat, 3, 4, &rowToFind, &colToFind, 25);
    printf ("Result found at: [%d][%d]\n", rowToFind, colToFind);
    return 0;
}