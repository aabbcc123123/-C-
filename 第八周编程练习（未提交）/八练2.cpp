#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main()
{
	
	char s[100];
	int yihuo=0;
	int hour=0;
	int min=0;
	int sec=0;
	
	do{
		//����һ������ 
		scanf("%s",&s);
		//����END����
		if (strcmp(s,"END")==0) break;
		//�ж�ID
		if (s[1]=='G'&&s[2]=='P'&&s[3]=='R'&&s[4]=='M'&&s[5]=='C'){
			int check=0;
			//У�� 
			for (int i=1;i<=strlen(s);i++){
				if (s[i]!='*') yihuo=yihuo^s[i];
				else if (s[i]=='*') {
					//��check�ĵ�һλŪ���� 
					if (s[i+1]>='0'&&s[i+1]<='9') check=16*(s[i+1]-'0');
					else if (s[i+1]>='A'&&s[i+1]<='F') check=16*(s[i+1]-'A'+10);
					//��check�ĵڶ�λŪ���� 
					if (s[i+2]>='0'&&s[i+2]<='9') check+=s[i+2]-'0';
					else if (s[i+2]>='A'&&s[i+2]<='F') check+=s[i+2]-'A'+10;
					break;
				}
			}
			
			 
			if (check==yihuo%65536){
				hour=10*(s[7]-'0')+s[8]-'0';
				min=10*(s[9]-'0')+s[10]-'0';
				sec=10*(s[11]-'0')+s[12]-'0';
			}
			
			//���
			if (hour>15) hour-=16;
			else hour+=8;
			
			printf("%02d:%02d:%02d",hour,min,sec); 
		} 
		
	}while(1);
	
	
	
	
	return 0;
}

