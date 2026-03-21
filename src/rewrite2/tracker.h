#pragma once

#include <stdint.h>
#include <stddef.h>

#include "vector.h"

// Структура, описывающая одну навигационную точку
typedef struct {
    // Уникальный идентификатор точки
    size_t id;
    // Широта
    double latitude;
    // Долгота
    double longitude;
    // Уровень сигнала (от 0 до 255).
    // Чем меньше сигнал, тем выше вероятность ошибки.
    uint8_t signal;
} NavPoint;

// Фильтрует "надёжные" точки: signal >= minSignal.
// Возвращает указатель на НОВЫЙ динамический массив Vector*.
// Исходный массив не изменяется.
// В случае ошибки выделения памяти возвращает NULL.
struct Vector* filterReliablePoints(struct Vector* points, uint8_t minSignal);

// Анализирует отфильтрованные точки и печатает статистику в консоль.
// Если массив пуст или NULL, печатает "No reliable points to analyze."
void analyzeReliablePoints(struct Vector* reliablePoints);


