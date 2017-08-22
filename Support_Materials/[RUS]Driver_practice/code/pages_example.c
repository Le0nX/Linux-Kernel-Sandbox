#include <linux/gfp.h>
#include <linux/slab.h>

unsigned long pages;

pages = __get_free_pages(GFP_KERNEL, 3);  /* 2^3 pages == 8 */

if (!page){
	/* not enough of mem */
	return -ENOMEM;
}

/* now free them */

free_pages(pages, 3);



/* create new block in cache */

static void* kmem_get_pages(struct kmem_cache *cachep, gfp_t flags, int nodeid)
{
	struct page *page;
	void *addr;
	int i;
	
	flags |= cachep->gfpflags;
	if (likely(nodeid == -1)){
		addr = (void*) __get_free_pages(flags, cachep->gfporder);
	}
	
	if (!addr){
		return NULL;
		page = virt_to_page(addr);
	} else {
		page = alloc_pages_node(nodeid, flags, cachep->gfporder);
		if (!page){
			return NULL;
		}
	}
	
	i = (1 << cachep->gfporder);
	if (cachep->flags & SLAB_RECLAIM_ACCOUNT)
		atomic_add(i, &slab_reclaim_pages);
	add_page_state(nr_slab, i);
	
	while(i--){
		SetPageSlab(page);
		page++;
	}
	
	return addr;
}
	
