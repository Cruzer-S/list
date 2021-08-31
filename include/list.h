#ifndef LIST_H__
#define LIST_H__

#include <stddef.h>	// to use offsetof

#define container_of(PTR, TYPE, MEMBER) \
	((TYPE *) (((void *) PTR) - offsetof(TYPE, MEMBER)))

struct list_head {
	struct list_head *prev, *next;
};

#endif
