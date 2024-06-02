#include "list.h"

void list_init_head(struct list *head)
{
	head->next = head->prev = head;
}

void list_del_between(struct list *prev, struct list *next)
{
	next->prev = prev;
	prev->next = next;
}

void list_del(struct list *entry)
{
	list_del_between(entry->prev, entry->next);
}

void list_add_new(struct list *prev, struct list *new, struct list *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

void list_add(struct list *head, struct list *new)
{
	list_add_new(head, new, head->next);
}

void list_add_tail(struct list *head, struct list *new)
{
	list_add_new(head->prev, new, head);
}

