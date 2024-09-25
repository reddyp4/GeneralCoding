/* Detect if loop is in linked list */
bool loop(ptr* list)
{
    ptr *slow, *fast;
    slow=fast=list;
    while(slow!=fast && fast->next!=NULL && fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    if(slow==fast)  return TRUE;
    return FALSE;
}