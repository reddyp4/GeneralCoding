/* Malloc in FreeRTOS can use pvPortMalloc call */
void *malloc(size_t size)
{
    void *ptr = NULL;
    if(ptr>0)
    {
        ptr = pvPortMalloc(size);
    }
    return ptr;
}