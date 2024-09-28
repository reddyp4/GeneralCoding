void memmove(char * dst, char * src, int n)
{
    // src.    src+n.     dst ...... dst+n
    // dst.    dst+n.     src ...... src+n
    
    //    src.    src+n
    //        dst ...... dst+n
    
    //    dst.    dst+n
    //        src ...... src+n

    //    src.    src+n
    //    dst     dst+n
    if(src==dst)
        return;

    if( ((src+n) > dst) && (dst>src) )
    {
        //Overlap
        // i = n-1 .... 0
        for(int i=(n-1);i >= 0;i--)    
            *(dst+i) = *(src+i);
    }
    else
    {
        // i = 0......n-1
        for(int i=0;i < n;i++)    
            *(dst+i) = *(src+i);
    }
}