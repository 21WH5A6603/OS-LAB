#include<stdio.h>
#include<stdlib.h>
int full=0,empty=5,mutex=1,x=0;
int wait(int s){
s--;
return s;
}
int signal(int s){
s++;
return s;
}
void producer(){
mutex = wait(mutex);
full = signal(full);
empty = wait(empty);
x++;
printf("producers produces the items %d",x);
mutex = signal(mutex);
}
void consumers(){
mutex = wait(mutex);
full = wait(full);
empty = signal(empty);
printf("consumers consumes items %d",x);
x--;
mutex = signal(mutex);
}
int main(){
int ch;
printf(" 1-producers \n 2-consumers \n 3-exit");
while(1){
printf("\nenter your choice");
scanf("%d",&ch);
switch(ch){
case 1:if(mutex == 1 && (empty!=0))
		producer();
		else
			printf("buffer is full");
			break;
case 2:if(mutex == 1 && (full!=0))
		consumers();
		else
		printf("buffer is empty");
		break;
case 3:exit(0);
}
}
}

output:


1-producers
2-consumers
3-exit
enter your choice 1
producers produces the items 1
enter your choice 2
consumers consumes items 1
enter your choice 3



