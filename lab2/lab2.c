#include <stdio.h>

typedef struct {
	char title[20];
	char author[20];
	int rating;
}Book;


#define MAX_LIBRARY_SIZE 30

int binary_search(Book library[], int low, int high,int key){
	if(high<low){
		return -1;	
	}else{
		int mid=(low+high)/2;
		int midVal=library[mid].rating;
		//printf("%d",midVal);
		if(midVal>key){
			return binary_search(library,low,mid-1,key);
		}else if(midVal<key){
			return binary_search(library,mid+1,high,key);
		}else{
			return mid;
		}	
	}

}


int populate_array(Book library[], char* input){
	FILE *ptr_file;
    	//printf("my file name is %s",input);
	int num;
    	ptr_file =fopen(input,"r");
    	if (!ptr_file){
        	return 1;
	}
	fscanf(ptr_file,"%d", &num);

	if(num>MAX_LIBRARY_SIZE){
		num=MAX_LIBRARY_SIZE;
	}

	int i;
	for(i=0;i<num;i++){
    		fscanf(ptr_file, "%s %s %d", library[i].title, library[i].author, &library[i].rating);
		
	}

	fclose(ptr_file);
    	return num;

}

void print(Book library[], int length, int key){
	int i;
	for(i=0;i<length;i++){
		if(library[i].rating==key){
			printf("***%s %s %d ",library[i].title, library[i].author, library[i].rating);	
			printf("\n");
		}else{
			printf("%s %s %d ",library[i].title, library[i].author, library[i].rating);
			printf("\n");
		}
		
	}

}

void sort(Book library[], int length){
	
	int j;
	int flag =1;
	Book temp;
	
	while(flag){
		flag=0;
		for(j=0;j<length-1;j++){
			if(library[j].rating>library[j+1].rating){
				temp= library[ j ];   
				library[j]=library[ j+1 ]; 
				library[j+1]=temp;              
                           	
                          	flag = 1;   
			}
		}
	}


}

void sortByAuthor(Book library[], int length){
	
	int j;
	int flag =1;
	Book temp;
	
	while(flag){
		flag=0;
		for(j=0;j<length-1;j++){
			if(strcmp(library[j].author,library[j+1].author)>0){
				temp= library[ j ];   
				library[j]=library[ j+1 ]; 
				library[j+1]=temp;              
                           	
                          	flag = 1;   
			}else if(strcmp(library[j].author,library[j+1].author)==0&&strcmp(library[j].title,library[j+1].title)>0){
				temp= library[ j ];   
				library[j]=library[ j+1 ]; 
				library[j+1]=temp;              
                           	
                          	flag = 1;   
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
	Book library [MAX_LIBRARY_SIZE];
	int number=populate_array(library,argv[1]);
	//print(library,number,0);
	//sort(library,number);
	sortByAuthor(library,number);
	printf("Enter a rating to search for: ");
	int key;	
	scanf("%d",&key);
	print(library,number,key);
	//printf("result is %d\n",binary_search(library,0,2,10));
	//printf("result is %d\n",binary_search(library,0,2,11));

	return 0;
}

