
#include <stdio.h>
#include <unistd.h>

#define __NR_my_syscall 333
#define __NR_my_syscall2 334

int main(){
	
	printf("CALLING MY_SYSCALL...RETURNED VALUE: %d\n", syscall(__NR_my_syscall,45,45));
	
	char string_bad[] = "safkjas;lkdfj;laskdjf;laskjfksdfsdafasdfasdfasfasd fasdfsafasdf asdf asdfa sdf assdfasd fasdfasdfsafasdfasdfasdfasfdkasjfkljasdfaksldajdjfa;klsdfasjdhf";
	char string_good[] = "Rodrigo Sucks, oHoHoHo!";

	printf("CALLING MY_SYSCALL2...RETURNED VALUE: %d\n", syscall(__NR_my_syscall2,string_good)); 
	printf("CALLING MY_SYSCALL2...RETURNED VALUE: %d\n", syscall(__NR_my_syscall2,string_bad)); 
	
	return 0;
}
