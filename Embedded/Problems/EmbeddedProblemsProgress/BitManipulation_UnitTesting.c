//    Write a unit test for validatePointerAndData that exercises all code paths
//    and branch conditions
    
// @param dataPtr - int32_t pointer to data to be used
//
// @return TRUE if pointer is non-NULL, data value is positive, non-zero and not
//         equal to the sentinel value 0x7FFFFFFF, FALSE otherwise
//
#include<stdint.h>
#include<stdio.h>

bool validatePointerAndData(void* dataPtr)
{
    if(dataPtr!=NULL && *dataPtr>0 && *dataPtr!=0x7FFFFFFF)
        return TRUE;
    return FALSE;
}