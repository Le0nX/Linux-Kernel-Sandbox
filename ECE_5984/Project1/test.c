
#include <stdio.h>
#include <unistd.h>

#define __NR_my_syscall 333
#define __NR_my_syscall2 334

int main(){
	
	printf("CALLING MY_SYSCALL...RETURNED VALUE: %d", syscall(__NR_my_syscall,45,45));
	
	char string[] = "Rodrigo sucks! oHoHoH";
  	int x =	syscall(__NR_my_syscall2,string);	
	
	printf("%d", x);
	return 0;
}
