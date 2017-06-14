
#include <stdio.h>
#include <unistd.h>

#define __NR_my_syscall 333

int main(){
	
	printf("CALLING MY_SYSCALL...RETURNED VALUE: %d", syscall(__NR_my_syscall,45,45));
	
	return 0;
}
