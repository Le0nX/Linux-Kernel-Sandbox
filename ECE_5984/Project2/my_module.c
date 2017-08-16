#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init first_func(void)
{
	printk(KERN_ALERT "TEEEEST\n");
	return 0;

}

static void __exit exit_func_lol(void)
{
	printk(KERN_ALERT "END TEEEST\n");

}

module_init(first_func);
module_exit(exit_func_lol);
