/**
 * Insira seu código para solucionar o trabalho neste arquivo.
 */

#include "lista.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>


void Lista_new(Lista* lista, int data_size, void (*free_data)(void*)) {
    if (lista) {
        lista->head = NULL;
        lista->tail = NULL;
        lista->cursor = NULL;
        lista->size = 0;
        lista->data_size = data_size;
        lista->free_data = free_data;
    }
}

void Lista_delete(Lista* lista) {
    ListaNodo* current = lista->head;
    while (current != NULL) {
        ListaNodo* next = current->next;

        if (lista->free_data != NULL) {
            lista->free_data(current->valor);
        }

        free(current->valor);
        free(current);
        current = next;
        
        lista->head = NULL;
        lista->tail = NULL;
        lista->cursor = NULL;
        lista->size = 0;
    }
}

int Lista_isEmpty(Lista* lista) {
    return lista->head == NULL;
}

int Lista_size(Lista* lista) {
    return lista->size;
}

void Lista_pushFront(Lista* lista, void* valor) {
    ListaNodo* novo = (ListaNodo*)malloc(sizeof(ListaNodo));
    novo->valor = malloc(lista->data_size);
    memcpy(novo->valor, valor, lista->data_size);
    novo->next = lista->head;
    novo->prev = NULL;
    if (lista->head != NULL) {
        lista->head->prev = novo;
    } else {
        lista->tail = novo;
    }
    lista->head = novo;
    lista->size++;
}

void Lista_pushBack(Lista* lista, void* valor) {
    ListaNodo* novo = (ListaNodo*)malloc(sizeof(ListaNodo));
    novo->valor = malloc(lista->data_size);
    memcpy(novo->valor, valor, lista->data_size);
    novo->next = NULL;
    novo->prev = lista->tail;
    if (lista->tail != NULL) {
        lista->tail->next = novo;
    } else {
        lista->head = novo;
    }
    lista->tail = novo;
    lista->size++;
}

int Lista_search(Lista* lista, void* chave, void* dest, int (*cmp)(void*, void*)) {
    ListaNodo* current = lista->head;
    while (current != NULL) {
        if (cmp(current->valor, chave) == 0) {
            memcpy(dest, current->valor, lista->data_size);
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void Lista_remove(Lista* lista, void* chave, int (*cmp)(void*, void*)) {
    ListaNodo* current = lista->head;
    while (current != NULL) {
        if (cmp(current->valor, chave) == 0) {
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                lista->head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            } else {
                lista->tail = current->prev;
            }
            if (lista->free_data != NULL) {
                lista->free_data(current->valor);
            }
            free(current->valor);
            free(current);
            lista->size--;
            return;
        }
        current = current->next;
    }
}

void Lista_first(Lista* lista) {
    lista->cursor = lista->head;
}

void Lista_last(Lista* lista) {
    lista->cursor = lista->tail
}

int Lista_next(Lista* lista) {
    if (lista->cursor != NULL && lista->cursor->next != NULL) {
        lista->cursor = lista->cursor->next;
        return 1;
    }
    return 0;
}

void Lista_current(Lista* lista, void* dest) {
    if (lista->cursor != NULL) {
        memcpy(dest, lista->cursor->valor, lista->data_size);
    }
}
void Lista_insertAfter(Lista* lista, void* dado) {
    if (lista->cursor != NULL) {
        ListaNodo* novo = (ListaNodo*)malloc(sizeof(ListaNodo));
        novo->valor = malloc(lista->data_size);
        memcpy(novo->valor, dado, lista->data_size);

        novo->prev = lista->cursor;
        novo->next = lista->cursor->next;

        if (lista->cursor->next != NULL) {
            lista->cursor->next->prev = novo;
        } else {
            lista->tail = novo;
        }
        lista->cursor->next = novo;
        lista->size++;
    }
}