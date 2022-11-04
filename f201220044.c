#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

void main(int argc, char *argv[]){
	if(argc < 3){
		printf("[HW1] Calistirilacak programin output uzantisiyla beraber dosya adi ve kac sn calisacagi bilgisini parametre olarak girmelisiniz.");
		return;
	}
	printf("[HW1] %s sn boyunca %s calisacak.\n",argv[2],argv[1]);
	int convertedSecond = atoi(argv[2]);
	pid_t pid = fork();
	if(pid==0){
		char x[]="./";
        	strcat(x,argv[1]);
		char *args[]={x,NULL};
		if(execv(args[0],args)){
			printf("[HW1] dosya bulunamadi!");
			return;
		}	
	}else if (pid>0){
		sleep(convertedSecond);
		kill(pid,SIGKILL);
		printf("[HW1]%d sn sona erdi %s kapatiliyor...\n",convertedSecond, argv[1]);
	}

	return;
}
