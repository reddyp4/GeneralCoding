struct _NODE

{

    int     Value;

    struct _NODE* Previous;

    struct _NODE* Next;

} NODE;


/*
Create a function Producer that will generate 100 random integers, and share them with a function Consumer through a pipe. The Consumer function will then add those numbers to a linked list of NODEs.
*/


// Seems same as other?
