#include "loop_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    LoopList* list = loopListNew();

    for (int i = 1; i <= n; ++i)
        loopListInsert(list, i);

    if (!list->head) {
        loopListDelete(list);
        return 0;
    }

    LoopListNode* current = list->head;
    
    LoopListNode* prev = list->head;
    while (prev->next != list->head)
        prev = prev->next;

    printf("Порядок удаления: ");
    while (list->head->next != list->head) {
        for (int i = 0; i < m - 1; ++i) {
            prev = current;
            current = current->next;
        }

        printf("%d ", current->value);
        LoopListNode* toDelete = current;

        if (toDelete == list->head)
            list->head = toDelete->next;
        
        prev->next = toDelete->next;
        current = toDelete->next;
        free(toDelete);
    }

    printf("\nПоследний оставшийся: %d\n", list->head->value);

    loopListDelete(list);

    return 0;
}
