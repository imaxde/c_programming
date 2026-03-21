#include "vector.h"
#include <stdlib.h>

struct Vector {
    void** data;
    size_t size;
    size_t capacity;
};

int reserve(struct Vector* vector, size_t new_capacity)
{
    void** new_data;

    if (new_capacity <= vector->capacity)
        return 0;

    new_data = realloc(vector->data, new_capacity * sizeof(void*));
    if (!new_data)
        return -1;

    vector->data = new_data;
    vector->capacity = new_capacity;
    return 0;
}

struct Vector* newVector(void)
{
    struct Vector* vector = malloc(sizeof(struct Vector));

    if (!vector)
        return NULL;

    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;

    return vector;
}

void deleteVector(struct Vector* vector)
{
    if (!vector)
        return;

    free(vector->data);
    free(vector);
}

int pushBack(struct Vector* vector, void* value)
{
    size_t new_capacity;

    if (!vector)
        return -1;

    if (vector->size == vector->capacity) {
        new_capacity = vector->capacity ? vector->capacity * 2 : 4;
        if (reserve(vector, new_capacity) != 0)
            return -1;
    }

    vector->data[vector->size++] = value;
    return 0;
}

void* get(struct Vector* vector, size_t index)
{
    return vector->data[index];
}

void* at(struct Vector* vector, size_t index)
{
    if (!vector)
        return NULL;

    if (index >= vector->size)
        return NULL;

    return vector->data[index];
}

size_t size(struct Vector* vector)
{
    if (!vector)
        return 0;

    return vector->size;
}

size_t capacity(struct Vector* vector)
{
    if (!vector)
        return 0;

    return vector->capacity;
}


