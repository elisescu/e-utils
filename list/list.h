#ifndef _LIST_H_
#define _LIST_H_

enum {
    L_OK,
    L_ERROR,
    L_NOT_FOUND
};

typedef struct list_s {
    void *data;
    struct list_s *next;
} list_t ;

list_t* list_create();
int list_insert(list_t *list, void *data);
int list_delete(list_t *list, void *data);

#endif
