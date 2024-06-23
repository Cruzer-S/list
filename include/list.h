#ifndef LIST_H__
#define LIST_H__

#include <stddef.h> // offsetof

#define LIST_IS_LAST(HEAD, POS) ((POS)->next == (HEAD))
#define LIST_IS_EMPTY(HEAD)	((HEAD) == (HEAD)->next)
#define LIST_IS_HEAD(HEAD, POS) ((HEAD) == (POS))

#define LIST_ENTRY_IS_HEAD(HEAD, POS, MEMBER)				\
	LIST_IS_HEAD((HEAD), &POS->MEMBER)

#define LIST_ENTRY_IS_LAST(HEAD, POS, MEMBER)				\
	LIST_IS_LAST((HEAD), &POS->MEMBER)

#define LIST_FOREACH(HEAD, POS) 					\
	for (struct list *POS = (HEAD)->next;				\
	     (HEAD) != (POS);						\
	     (POS) = (POS)->next)

#define LIST_FOREACH_SAFE(HEAD, POS) 					\
	for (struct list *POS = (HEAD)->next, *N = (POS)->next; 	\
	     (POS) != (HEAD); 						\
	     (POS) = N, N = (POS)->next)

#define LIST_ENTRY(PTR, TYPE, MEMBER) 					\
	((TYPE *)(((void *)(PTR)) - ((void *)offsetof(TYPE, MEMBER))))

#define LIST_FIRST_ENTRY(PTR, TYPE, MEMBER)				\
	LIST_ENTRY((PTR)->next, TYPE, MEMBER)

#define LIST_LAST_ENTRY(PTR, TYPE, MEMBER)				\
	LIST_ENTRY((PTR)->prev, TYPE, MEMBER)

#define LIST_NEXT_ENTRY(POS, TYPE, MEMBER)				\
	LIST_ENTRY((POS)->MEMBER.next, TYPE, MEMBER)

#define LIST_FOREACH_ENTRY(HEAD, POS, TYPE, MEMBER)		       	\
	for (TYPE *POS = LIST_FIRST_ENTRY(HEAD, TYPE, MEMBER);		\
	     !LIST_ENTRY_IS_HEAD(HEAD, POS, MEMBER);			\
	     POS = LIST_NEXT_ENTRY(POS, TYPE, MEMBER))

#define LIST_FOREACH_ENTRY_SAFE(HEAD, POS, TYPE, MEMBER)		\
	for (TYPE *POS = LIST_FIRST_ENTRY(HEAD, TYPE, MEMBER),		\
		  *N = LIST_NEXT_ENTRY(POS, TYPE, MEMBER);		\
	     !LIST_ENTRY_IS_HEAD(HEAD, POS, MEMBER);			\
	     POS = N, N = LIST_NEXT_ENTRY(N, TYPE, MEMBER))

#define LIST_HEAD_INIT(HEAD) { &HEAD, &HEAD }

struct list {
	struct list *next, *prev;
};

void list_init_head(struct list *head);
void list_add_new(struct list *prev, struct list *new, struct list *next);
void list_add(struct list *head, struct list *new);
void list_add_tail(struct list *head, struct list *new);

#endif
