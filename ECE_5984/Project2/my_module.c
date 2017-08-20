#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/list.h>
#include <linux/random.h>


static int dstruct_size = -1;  // initial var
module_param(dstruct_size, int, 0644);

struct just_list {
	
	int data;
	struct list_head list;
	
};

struct just_list mylist;

/**
 * Init prototypes
 */
 
static void constructA(int size);
static void printB(void);
static void destructC(void);
static void all_in_oneABC(int size);

static int __init module_start(void)
{
	printk(KERN_ALERT "TEEEEST\n");
	printk(KERN_INFO ">>> Project2: module was loaded\n");
	printk(KERN_INFO ">>> ["%d"] arguments were passed\n", dstruct_size);
	
	if (dstruct_size < 0){
		
		printk(KERN_ALERT "Invalid argument\n");
		return -EPERM;
		
	}
	
	constructA(dstruct_size);
	
	
	
	
	
	return 0;

}

static void __exit exit_module(void)
{
	printk(KERN_ALERT "END TEEEST\n");

}


static void constructA(int size)
{
	struct just_list *mylistA;
	int random, i;
	
	for (i=0; i<size; i++){
		printk(KERN_INFO ">>> Entering the loop in constructA...\n");
		
		mylistA = kmalloc(sizeof(*mylistA), GFP_KERNEL);
			 
		get_random_bytes(&random, sizeof(int));
	}
	
}



module_init(module_start);
module_exit(exit_module);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Denis Nefedov");
MODULE_DESCRIPTION("Project2");
