#include <stdio.h>

typedef struct {
char title[20];
int yearReleased;
int sales;
int ticketsSold;
}Movie;


#define MAX_ARR_LEN 20

Movie movie_catalog [MAX_ARR_LEN];

int populate_movie_catalog(){
	FILE *ptr_file;
    	char buf[1000];

    	ptr_file =fopen("data.txt","r");
    	if (!ptr_file){
        	return 1;
	}
	fgets(buf,1000, ptr_file);

	int i;
	int num=atoi(buf);
	if(num>MAX_ARR_LEN){
		num=MAX_ARR_LEN;
	}

	char title[10];
	int year,sales,tickets;

	for(i=0;i<num;i++){
    		fscanf(ptr_file, "%s %d %d %d", movie_catalog[i].title, &movie_catalog[i].yearReleased, &movie_catalog[i].sales, &movie_catalog[i].ticketsSold);
		
		
        	
	}

	fclose(ptr_file);
    	return num;

}

void print_catalog(int length){
	int i;
	for(i=0;i<length;i++){
		printf("%s: %d ",movie_catalog[i].title,movie_catalog[i].yearReleased);
		
		//printf("%d ",movie_catalog[i].sales);
		//printf("%d ",movie_catalog[i].ticketsSold);
		printf("\n");
	}

}

float average_ticket_price(int length){
	int i;
	int totalTickets=0;
	int totalSales=0;
	for(i=0;i<length;i++){
		totalTickets+=movie_catalog[i].ticketsSold;
		totalSales+=movie_catalog[i].sales;
	}
	return (float)totalSales/totalTickets;
	
}

int find_highest_grossing_movie(int length){
	int maxIndex=0;
	int maxVal=-99;
	int i;
	for(i=0;i<length;i++){
		if(movie_catalog[i].sales>maxVal){
			maxVal=movie_catalog[i].sales;
			maxIndex=i;
		}
	}
	return maxIndex;
}

void sort(int length){
	
	int j;
	int flag =1;
	Movie temp;
	
	while(flag){
		flag=0;
		for(j=0;j<length-1;j++){
			if(movie_catalog[j].yearReleased>movie_catalog[j+1].yearReleased){
				temp= movie_catalog[ j ];   
				movie_catalog[j]=movie_catalog[ j+1 ]; 
				movie_catalog[j+1]=temp;              
                           	
                          	flag = 1;   
			}
		}
	}


}

int main(){

	int number=populate_movie_catalog();
	printf("There are %d movies\n",number);
	printf("List of Movies:\n");
	print_catalog(number);
	printf("Average Ticket Price: $ %0.2f\n",average_ticket_price(number));
    	printf("Highest Grossing Movie: %s\n",movie_catalog[find_highest_grossing_movie(number)].title);
	sort(number);
	printf("After sorting:");
	print_catalog(number);
	return 0;
}

