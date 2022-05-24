/* Pointer to structure */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct rectangle
{
    int length;
    int breadth;
};

int main(void)
{
    struct rectangle *q = (struct rectangle*)malloc(sizeof(struct rectangle));
    q->breadth = 22;
    q->length = 18;
    printf("q.breadth=%d,q.length=%d\n",q->breadth,q->length);
    free(q);

    struct rectangle rect = {10,5};
    struct rectangle *r;
    r=&rect;

    printf("r.breadth=%d,r.length=%d\n",r->breadth,r->length);

    r->breadth = 25;
    r->length = 10;

    printf("r.breadth=%d,r.length=%d\n",r->breadth,r->length);

    return 0;
}