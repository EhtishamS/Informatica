#include<stdio.h>
#include<string.h>

int strcmp(const char *str1, const char *str2);

int main(){
	char str1[] = "casa";
	char str2[] = "casa1";
	int ris;
	
	ris = strcmp(str1,str2);
	
	printf("%d", ris);
	
	return 0;
}

int strcmp(const char *str1, const char *str2){
	int i;
	
	for(i=0;i<=strlen(str1);i++){
		if(*(str1+i)>*(str2+i))
			return 1;
		else if(*(str1+i)<*(str2+i))
			return -1;
	}
	
	return 0;
}
