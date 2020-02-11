#include <stdio.h>
#include "hello.h"

int main() {
	int err = hello();
	if (err!=0){
		printf("warning\n");
	}
	return(0);
	}