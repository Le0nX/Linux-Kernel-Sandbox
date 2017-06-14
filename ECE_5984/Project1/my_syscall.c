#include <linux/syscalls.h>
#include <linux/string.h>
#include <linux/uaccess.h>

SYSCALL_DEFINE2 (my_syscall,
		 int, x,
		 int, y)
{
	int res;
	res = x + y;
	printk(KERN_INFO "MY_SYSCALL RETURNED: ", res);
	return res;	
}


