#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "list.h"

typedef struct entry {
	int number;

	struct list list;
} *Entry;

int main(int argc, char *argv[])
{
	struct list head = LIST_HEAD_INIT(head);

	for (int i = 0; i < 10; i++) {
		Entry entry = malloc(sizeof(struct entry));
		if (entry == NULL)
			exit(EXIT_FAILURE);

		entry->number = i + 1;

		list_add_tail(&head, &entry->list);
	}

	LIST_FOREACH_ENTRY(&head, entry, struct entry, list) {
		printf("%d ", entry->number);
	} putchar('\n');

	LIST_FOREACH_ENTRY_SAFE(&head, entry, struct entry, list)
		free(entry);

	return 0;
}
