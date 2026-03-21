#pragma once
#include <stddef.h>

struct Vector;

// Создает пустой вектор
struct Vector* newVector(void);

// Удаляет структуру вектора и очищает память
void deleteVector(struct Vector* vector);

// Добавляет элемент в конец вектора (возвращает 0 если ок)
int pushBack(struct Vector* vector, void* value);

// Берет элемент по индексу
void* get(struct Vector* vector, size_t index);

// Возвращает элемент с указанным индексом или NULL если выходит за границы
void* at(struct Vector* vector, size_t index);

// Текущее количество элементов в списке
size_t size(struct Vector* vector);

// Количество элементов, которые помещаются без распределения
size_t capacity(struct Vector* vector);


