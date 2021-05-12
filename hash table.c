//CHAINING FOR WORDS IN SENTENCE


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node{
	char* word;
	struct node* next;
};


struct node* NewNode(char word[]){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->word = (char*)malloc(sizeof(char)*strlen(word));
	strcpy(temp->word,word);
	temp->next = NULL;
	return temp;
}


struct node* INSERT(struct node* T,char word[],int k){
	int val = strlen(word)*strlen(word);
	val = val%k;
	if(T[val].word == "-"){
		(T+val)->word = (char*)malloc(strlen(word)*sizeof(char));
		strcpy((T+val)->word,word);
		return T;
	}
	else{
		struct node* temp = (T+val);
		if(strcmp(temp->word,word) == 0)return T;
		while(temp->next != NULL){
			
			if(strcmp(temp->word,word) == 0)return T;
			temp = temp->next;
		}
		temp->next = NewNode(word);

		return T;
	}

}



void PRINT(struct node* T,int k){
	for(int i =0;i<k;++i){
		struct node* temp = (T+i);
		printf("%d:",i);
		while(temp!=NULL){
			if(*(temp->word) == '-'){
				printf("null");
				temp = NULL;
				
			}
			else{
				printf("%s",temp->word);
				if(temp->next!=NULL)printf("-");
				temp=temp->next;
			}
		}
		printf("\n");
	}
}


void main(){
	int k,i,j;
	char string[500];
	scanf("%d",&k);
	i=0;
	j=0;
	char c;
	char word[20];
	scanf("%c",&c);
	scanf("%[^\n]%*c",string);
	
	struct node* T =(struct node*)malloc(k*sizeof(struct node));
	for(i=0;i<k;i++){
		T[i].word="-";
		T[i].next = NULL;
	}

	for(i=0;i<=strlen(string);i++){
		if(string[i] == ' ' ||string[i] == '\0'){
			word[j] = '\0';
			//printf("%s\n",word);
			T = INSERT(T,word,k);
			j = 0;
		}
		else{
			word[j++]=string[i];
		}
	}
	
	PRINT(T,k);
	
}
