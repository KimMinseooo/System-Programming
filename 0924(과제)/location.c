#include<stdio.h>
#include<stdlib.h>

int main(int argc ,char *argv[])
{
	FILE *fp1;
	FILE *fp2;
	int state1, state2;
	int count=0;
	char a,b;

	if(argc !=3){
		fprintf(stderr,"사용법 : %s file1 file2 \n",argv[0]);
		return 1;
	}

	if((fp1=fopen(argv[1],"r"))==NULL ||(fp2=fopen(argv[2],"r"))==NULL){
		perror("오류 발생");
		return 1;
	}

	while(1){
		if(feof(fp1) ==0 &&feof(fp2)==0){

		//한글자씩 꺼내서 출력
		a=fgetc(fp1);
		b=fgetc(fp2);
		count++;
		if( a!=b){

		printf("처음으로 달라지는 위치는 file1의 %c 부분과 file2의 %c부분 파일 처음부터 %d번째입니다.\n",a,b,count);
		break;
		}
	}
		else if(feof(fp1) !=0 &&feof(fp2)==0){
			printf("두개의 파일은 일치하지않습니다.\n");
			break;
		}
		else if(feof(fp1) ==0 && feof(fp2) !=0){
			printf("두개의 파일은 일치하지않습니다.\n");
			break;
		}
		else {
			printf("두개의 파일은 일치합니다.\n");
			break;
		}
	}
	state1 =fclose(fp1);
	state2 =fclose(fp2);
	if(state1 !=0|| state2 !=0){
		printf("스트림 제거시 오류발생");
		return 1;
	}

	return 0;
}

