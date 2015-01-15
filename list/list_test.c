#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list.h>

void test_prepend() {
    list_t *list = list_create();
    char *e_trace = "1asasdbasdkasdlkjasd";

    for (char *c = e_trace + strlen(e_trace) - 1; c >= e_trace; c--) {
        //printf("\n prepeding to the list el %c ", c[0]);
        list_prepend(list, (void*)((long)c[0]));
    }

    int a_size = list->no_elements;
    int e_size = strlen(e_trace);
    char *a_trace = (char *) malloc(a_size + 1);
    a_trace[a_size] = '\0';

    int i = 0;
    for (struct list_el *l = list->first; l != NULL; l = l->next, i++) {
        a_trace[i] = (char)(l->data);
        //printf("\n el %c ", (int)l->data);
    }

    if (a_size == e_size && !strcmp(a_trace, e_trace)) {
        printf("\nprepend-TEST OK !!! (%d) values", a_size);
    } else {
        printf("\nprepend-TEST FAILED !!! expected %s[%d] but got %s[%d]",
            e_trace, e_size, a_trace, a_size);
    }
}

void test_append() {
    list_t *list = list_create();
    char *e_trace = "jasfjhalsdjkflaksjdf";

    for (char *c = e_trace ; c < e_trace + strlen(e_trace); c++) {
        //printf("\n appending to the list el %c ", c[0]);
        list_append(list, (void*)((long)c[0]));
    }

    int a_size = list->no_elements;
    int e_size = strlen(e_trace);
    char *a_trace = (char *) malloc(a_size + 1);
    a_trace[a_size] = '\0';

    int i = 0;
    for (struct list_el *l = list->first; l != NULL; l = l->next, i++) {
        a_trace[i] = (char)(l->data);
        //printf("\n el %c ", (int)l->data);
    }

    if (a_size == e_size && !strcmp(a_trace, e_trace)) {
        printf("\nappend-TEST OK !!! (%d) values", a_size);
    } else {
        printf("\nappend-TEST FAILED !!! expected %s[%d] but got %s[%d]",
            e_trace, e_size, a_trace, a_size);
    }
}

int main(int argc, char *argv[]) {
    test_prepend();
    test_append();
    return 0;
}
