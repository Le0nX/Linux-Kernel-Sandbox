#include <linux/syscalls.h>
#include <linux/string.h>
#include <linux/slab.h>

SYSCALL_DEFINE1 (my_syscall2,
		 char*, buf)
{
	int 		counter = 0;
	size_t 		len = strlen(buf);
	char 		*buffy = (char*)kmalloc((sizeof(char) * len + 1), GFP_KERNEL);

	
	printk(KERN_INFO "Entered into my_syscall2\n");
	if (copy_from_user(buffy, buf, len)){
		kree(buffy);
		return -EFAULT;	
	}

	if (len > 128){
		
		printk(KERN_ERR "mysyscall2 too long string\n");
		kfree(buffy);
		return -1;
	
	} else {
		printk(KERN_INFO "Passed len_check\n");
		while(*(buffy++)){
			
			if (*buffy == 'o' || *buffy == 'O'){
				*buffy = '0';
				counter++; 
			}
			
		}
		
		if (copy_to_user(buf, buffy,len)){
			kfree(buffy);
			return -EFAULT;
		}

		printk(KERN_INFO "Returning result...\n");
		kfree(buffy);
		return counter;
	}

	
	printk(KERN_ERR "ERROR: something went wrong!");
}
 
