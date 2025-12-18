#include "tracker.h"

#include <stdint.h>
#include <stdio.h>

struct Vector*
filterReliablePoints(struct Vector* points, uint8_t minSignal)
{
    struct Vector* reliable;
    size_t i;
    size_t n;

    reliable = newVector();
    if (!reliable)
        return NULL;

    if (!points)
        return reliable;

    n = size(points);

    for (i = 0; i < n; ++i) {
        NavPoint* point = (NavPoint*)at(points, i);

        if (!point)
            continue;

        if (point->signal >= minSignal) {
            if (pushBack(reliable, point) != 0) {
                deleteVector(reliable);
                return NULL;
            }
        }
    }

    return reliable;
}

void
analyzeReliablePoints(struct Vector* reliablePoints)
{
    size_t n;
    size_t i;
    size_t count;
    double sumSignal;
    uint8_t maxSignal;
    size_t maxId;
    int hasMax;

    if (!reliablePoints) {
        printf("No reliable points to analyze.\n");
        return;
    }

    n = size(reliablePoints);

    if (n == 0) {
        printf("No reliable points to analyze.\n");
        return;
    }

    count = 0;
    sumSignal = 0.0;
    maxSignal = 0;
    maxId = 0;
    hasMax = 0;

    for (i = 0; i < n; ++i) {
        NavPoint* point = (NavPoint*)at(reliablePoints, i);

        if (!point)
            continue;

        ++count;
        sumSignal += (double)point->signal;

        if (!hasMax || point->signal > maxSignal) {
            hasMax = 1;
            maxSignal = point->signal;
            maxId = point->id;
        }
    }

    if (count == 0) {
        printf("No reliable points to analyze.\n");
        return;
    }

    printf("Reliable points: %zu\n", count);
    printf("Average signal: %.2f\n", sumSignal / (double)count);
    printf("Max signal id: %zu\n", maxId);
}


