/*  Metrowerks Standard Library  Version 2.2  1997 October 17  */

/*
 *	pool_alloc.h
 *	
 *		Copyright © 1995-1997 Metrowerks, Inc.
 *		All rights reserved.
 */
 
#ifndef __pool_alloc__
#define __pool_alloc__

#include <ansi_parms.h>                 /* mm 970905*/

#pragma options align=native
#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import on
#endif

typedef signed long tag_word;

typedef struct block_header {
	tag_word				tag;
	struct block_header *	prev;
	struct block_header *	next;
} block_header;

typedef struct list_header {
	block_header *		rover;
	block_header		header;
} list_header;

typedef struct heap_header {
	struct heap_header* 	prev;
	struct heap_header*		next;
} heap_header;

typedef unsigned long	mem_size;

typedef void *	(*sys_alloc_ptr)(mem_size size, struct mem_pool_obj*);
typedef void	(*sys_free_ptr)(void * ptr, struct mem_pool_obj*);

typedef struct pool_options{
	sys_alloc_ptr	sys_alloc_func;
	sys_free_ptr	sys_free_func;
	mem_size		min_heap_size;
	int				always_search_first;
} pool_options;

typedef struct mem_pool_obj {
	list_header		free_list;
	pool_options	options;
	heap_header*	heap_list;
	void*			userData;
} mem_pool_obj;

#ifdef __cplusplus
extern "C" {
#endif

void	__init_pool_obj(mem_pool_obj * pool_obj);
int		__pool_preallocate(mem_pool_obj * pool_obj, mem_size size);
void	__pool_preassign(mem_pool_obj * pool_obj, void * ptr, mem_size size);
void *	__pool_alloc(mem_pool_obj * pool_obj, mem_size size);
void *	__pool_alloc_clear(mem_pool_obj * pool_obj, mem_size size);
void *	__pool_realloc(mem_pool_obj * pool_obj, void * ptr,	mem_size size);
void	__pool_free(mem_pool_obj * pool_obj, void * ptr);
void	__pool_free_all(mem_pool_obj * pool_obj);

void *	__sys_alloc(mem_size size, mem_pool_obj*);
void	__sys_free(void *ptr, mem_pool_obj*);

#ifdef __cplusplus
}
#endif

#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import reset
#endif
#pragma options align=reset

#endif

/*     Change record
 * mm 970905  added include of ansi_parms.h to avoid need for prefix file
 */
