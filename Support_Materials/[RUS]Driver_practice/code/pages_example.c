#include <linux/gfp.h>

unsigned long pages;

pages = __get_free_pages(GFP_KERNEL, 3);  /* 2^3 pages == 8 */

if (!page){
	/* not enough of mem */
	return -ENOMEM;
}

/* now free them */

free_pages(pages, 3);

