#include <stdio.h>
#include <unistd.h>
#include <emscripten/emmalloc.h>
#include <emscripten/heap.h>

int main()
{
	printf("heap size: %zu\n", emscripten_get_heap_size());

	void *ptr = malloc(32*1024*1024);
	void *ptr2 = malloc(4*1024*1024);
	printf("%d\n", (int)(ptr && ptr2));
	printf("dynamic heap 1: %zu\n", emmalloc_dynamic_heap_size());
	printf("free dynamic memory 1: %zu\n", emmalloc_free_dynamic_memory());
	printf("unclaimed heap memory 1: %zu\n", emmalloc_unclaimed_heap_memory());
	printf("sbrk 1: %p\n", sbrk(0));

	int success = emmalloc_trim(0);
	printf("1st trim: %d\n", success);
	printf("dynamic heap 1: %zu\n", emmalloc_dynamic_heap_size());
	printf("free dynamic memory 1: %zu\n", emmalloc_free_dynamic_memory());
	printf("unclaimed heap memory 1: %zu\n", emmalloc_unclaimed_heap_memory());
	printf("sbrk 1: %p\n", sbrk(0));

	success = emmalloc_trim(0);
	printf("2nd trim: %d\n", success);
	printf("dynamic heap 2: %zu\n", emmalloc_dynamic_heap_size());
	printf("free dynamic memory 2: %zu\n", emmalloc_free_dynamic_memory());
	printf("unclaimed heap memory 2: %zu\n", emmalloc_unclaimed_heap_memory());
	printf("sbrk 2: %p\n", sbrk(0));
	free(ptr2);

	success = emmalloc_trim(100000);
	printf("3rd trim: %d\n", success);
	printf("dynamic heap 3: %zu\n", emmalloc_dynamic_heap_size());
	printf("free dynamic memory 3: %zu\n", emmalloc_free_dynamic_memory());
	printf("unclaimed heap memory 3: %zu\n", emmalloc_unclaimed_heap_memory());
	printf("sbrk 3: %p\n", sbrk(0));

	success = emmalloc_trim(100000);
	printf("4th trim: %d\n", success);
	printf("dynamic heap 4: %zu\n", emmalloc_dynamic_heap_size());
	printf("free dynamic memory 4: %zu\n", emmalloc_free_dynamic_memory());
	printf("unclaimed heap memory 4: %zu\n", emmalloc_unclaimed_heap_memory());
	printf("sbrk 4: %p\n", sbrk(0));

	success = emmalloc_trim(0);
	printf("5th trim: %d\n", success);
	printf("dynamic heap 5: %zu\n", emmalloc_dynamic_heap_size());
	printf("free dynamic memory 5: %zu\n", emmalloc_free_dynamic_memory());
	printf("unclaimed heap memory 5: %zu\n", emmalloc_unclaimed_heap_memory());
	printf("sbrk 5: %p\n", sbrk(0));
}
