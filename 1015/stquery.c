#include<stdio.h>
#include<stdlib.h>
#include "student.h"

int main(int argc, char *argv[])
{
	struct student record;
	char c;
	int id;
	FILE *fp;
	if(argc !=2){
		fprintf(stderr,"사용법:%s 파일이름\n",argv[0]);
		exit(1);
	}

	if((fp=fopen(argv[1],"rb"))==NULL){
		fprintf(stderr,"파일 열기 오류\n");
		exit(2);
	}

	do{
		printf("검색할 학생의 학번 입력: ");
		if(scanf(" %d",&id)==1){
			fseek(fp,(id-START_ID) *sizeof(record),SEEK_SET);
			if((fread(&record, sizeof(record), 1 ,fp)>0) && (record.id !=0))
				printf("학번: %8d 이름: %4s 점수: %4d\n",record.id,record.name,record.score);
			else printf("레코드 %d 없음\n",id);
		}
		else printf("입력 오류");

		printf("계속하시겠습니까?(Y/N)");
		scanf(" %c",&c);
	}while(c =='Y');

	fclose(fp);
	exit(0);
}

