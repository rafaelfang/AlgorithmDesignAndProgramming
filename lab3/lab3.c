#include <stdio.h>

typedef struct {
	int accountId;
	float balance;
}Account;


#define MAX_ACCOUNTS 20

Account* find_account(Account accounts[], int low, int high,int key){
	if(high<low){
		return NULL;	
	}else{
		int mid=(low+high)/2;
		int midVal=accounts[mid].accountId;
		//printf("%d",midVal);
		if(midVal>key){
			return find_account(accounts,low,mid-1,key);
		}else if(midVal<key){
			return find_account(accounts,mid+1,high,key);
		}else{
			return &accounts[mid];
		}	
	}

}

void run_transactions(Account accounts[], int length,char* fileName){
	FILE *ptr;
	ptr =fopen(fileName,"r");
	if (!ptr){
        	return;
	}
	int id;
	float transaction;
	Account * acc;
	while(fscanf(ptr, "%d %f", &id, &transaction)!=EOF){
		acc=find_account(accounts, 0,length-1 ,id);
		if(acc==NULL){
			printf("Invalid transaction; account %d does not exist\n",id);
			continue;		
		}
		if((accounts[id-1].balance)+transaction<0){
			printf("Invalid transaction; Withdrawing %f from account %d results in a negative balance\n",transaction,id);
			
		}else{
			accounts[id-1].balance=accounts[id-1].balance+transaction;
		}
		
		
	}
	
}


int load_accounts(Account accounts[], char* fileName){
	FILE *ptr_file;
    	//printf("my file name is %s",input);
	int num=0;
    	ptr_file =fopen(fileName,"r");
    	if (!ptr_file){
        	return -1;
	}
	

	while(num<MAX_ACCOUNTS && fscanf(ptr_file, "%d %f", &accounts[num].accountId, &accounts[num].balance)!=EOF){
		num++;
	}
	

	fclose(ptr_file);
    	return num;

}

void print(Account accounts[], int length){
	int i;
	for(i=0;i<length;i++){
		printf("%d %0.2f\n",accounts[i].accountId, accounts[i].balance);	
	}

}

void sort(Account accounts[], int length){
	int i;
	int j;
	Account temp;
	
	for(i=0;i<length;i++){
		for(j=0;j<length-1;j++){
			if(accounts[j].accountId>accounts[j+1].accountId){
				temp= accounts[ j ];   
				accounts[j]=accounts[ j+1 ]; 
				accounts[j+1]=temp;              
                           	
			}
		}
	}


}




int main(int args, char* argv[]){
	//printf("%d", args);
	//printf("first %s second %s",argv[0],argv[1]);
	if(args==1){
		printf("Incorrect number of command line arguments\n");
		printf("Correct usage: ./a.out input file\n");
		return -1;	
	}
	Account accounts [MAX_ACCOUNTS];
	int number=load_accounts(accounts,argv[1]);
	print(accounts,number);
	printf("After sorting:\n");
	sort(accounts,number);
	print(accounts,number);
	//printf("Enter a rating to search for: ");
	//int key;	
	//scanf("%d",&key);
	//Account* accountFound=find_account(accounts,0,2,key);
	//printf("result is %.2f\n",accountFound->balance);
	//printf("result is %.2f\n",(*accountFound).balance);
	run_transactions(accounts,number,argv[2]);	
	printf("Final balance sheet:\n");
	print(accounts,number);

	return 0;
}

