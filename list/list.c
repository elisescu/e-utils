#include <list.h>
#include <stdlib.h>

list_t* list_create() {
    list_t *l = (list_t *) malloc(sizeof(list_t));
    l->no_elements = 0;
    l->first = NULL;
    return l;
}

int list_append(list_t *list, void *data) {
    if (list == NULL) return L_ERROR;

    struct list_el *new_el =  (struct list_el *) malloc(sizeof(struct list_el));
    if (new_el == NULL) return L_ERROR;

    new_el->next = NULL;
    new_el->data = data;

    if (list->first == NULL) {
        list->first = new_el;
        list->no_elements = 1;
        return L_OK;
    }

    struct list_el *l;
    for (l = list->first; l->next != NULL; l = l->next);

    l->next = new_el;
    list->no_elements++;
    return L_OK;
}

int list_prepend(list_t *list, void *data) {
    if (list == NULL) return L_ERROR;

    struct list_el *new_el = (struct list_el *) malloc(sizeof(struct list_el));
    if (new_el == NULL) return L_ERROR;

    new_el->data = data;
    if (list->first == NULL) {
        new_el->next = NULL;
        list->first = new_el;
        list->no_elements = 1;
        return L_OK;
    }
    new_el->next = list->first;
    list->first = new_el;
    list->no_elements++;
    return L_OK;
}

int list_remove(list_t *list, void *data) {
    return L_ERROR;
}

int list_destroy(list_t *list) {
    return L_ERROR;
}

int get_no_elements(list_t *list) {
    return list->no_elements;
}
