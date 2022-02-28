#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include "simplex.h"

int main(void) {
    MATRIX *a;

    a = create(2, 2);

    entry(a, 1, 1, 1.0);
    entry(a, 1, 2, 2.0);
    entry(a, 2, 1, 3.0);
    entry(a, 2, 2, 4.0);

    display(a);

    delete(a);
}