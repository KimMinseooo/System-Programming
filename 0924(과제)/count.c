#include<stdio.h>
#include<stdlib.h>

int main(int argc , char *argv[])
{
	FILE *fp;
	char ch[1000];
	int i=0;
	char a;
	int linecount=0;
	int wordcount=0;
	int charcount=0;
	int nowstate=0;
	if(argc==1)	
	{
	printf("문자열을 입력하세요.\n");
	fgets(ch,sizeof(ch),stdin);

	while(ch[i]!='\0'){
		if((ch[i] >='A' && ch[i]<='z')||(ch[i]>='0'&&ch[i]<='9')){
			charcount++;

			if(nowstate ==0){
				nowstate =1;
			}
		}
	else{
			if(nowstate ==1){
				if(ch[i] =='('){
					nowstate =2;
				}
				else if(ch[i] ==' '||ch[i] ==','||ch[i]=='.'){
					nowstate=0;
					wordcount++;
				}
			}
			else if(nowstate ==2){
				if(ch[i]==')'){
					wordcount++;
					nowstate=0;

				}
			}
		}
		if(ch[i]=='\n'){
			wordcount++;
			linecount++;
		}
	i++;
	}
	
}
	else if(argc ==2){
	
	if((fp=fopen(argv[1],"r"))==NULL){
		perror(argv[1]);
		return 1;
	}
	
	while(feof(fp)==0){
		a=fgetc(fp);
		printf("%c", a);

		if((a >='A' && a<='z')||(a>='0'&&a<='9')){
			charcount++;
		if(nowstate ==0){
			nowstate =1;
			}
		}

		else{
			if(nowstate ==1){
				if(a =='('){
					nowstate =2;
				}
				else if(a ==' '||a ==','||a=='.'){
					nowstate=0;
					wordcount++;
				}
			}
			else if(nowstate ==2){
				if(a==')'){
					wordcount++;
					nowstate=0;

				}
			}
		}
		if(a=='\n'){
			wordcount++;
			linecount++;
		}
	}
	fclose(fp);

	}
	else{
		perror("argument error");
		return 1;
	}

	printf("문자 수: %d\t 단어 수: %d\t 줄 수: %d\n",charcount,wordcount,linecount);

	return 0;
}

