#ifndef _LIST_H_
#define _LIST_H_

enum {
    L_OK,
    L_ERROR,
    L_NOT_FOUND
};

struct list_el {
    struct list_el *next;
    void *data;
};

typedef struct list_s {
    struct list_el *first;
    int no_elements;
} list_t ;

list_t* list_create();
int list_append(list_t *list, void *data);
int list_prepend(list_t *list, void *data);
int list_remove(list_t *list, void *data);
int list_destroy(list_t *list);
int get_no_elements(list_t *list);

#endif
