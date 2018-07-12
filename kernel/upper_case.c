#include <linux/string.h>
#include <linux/syscalls.h>


long __upper_case(char *in, char* out){
	int len = strlen(in);
	int i;
	for(i=0; i<len; i++){
		if(in[i]>=0x61 && in[i]<=0x7a){
			out[i] = in[i] - 0x20;
		}
		else{
			out[i] = in[i];
		}
	}
	return 0;
}

SYSCALL_DEFINE2(upper_case,char *,from,char *,to)
{
	return __upper_case(from, to);
}
