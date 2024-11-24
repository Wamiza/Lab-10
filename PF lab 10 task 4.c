#include <stdio.h>

struct Film {
	char title[20];
	char genre[15];
	char director[15];
	int releasing_year;
	int ratings;
};

int main() {
	int n;
	printf("Enter the number of Movies :");
	scanf("%d", &n);
	struct Film movie[n];
  for(int i=0; i<n; i++) {
	printf("\nEnter Movie Title :");
	scanf("%19s", movie[i].title);
	
	printf("Enter Movie Genre :");
	scanf("%14s", movie[i].genre);
	
	printf("Enter Director name :");
	scanf("%14s", movie[i].director);
	
	printf("Enter Releasing Year (DDMMYY):");
	scanf("%d", &movie[i].releasing_year);
	
	printf("Enter Movie Ratings :");
	scanf("%d", &movie[i].ratings);
  }
  
  for(int i=0; i<3; i++) {
  	printf("Movie Title : %19s\n", movie[i].title);
  	printf("Movie Genre : %14s\n", movie[i].genre);
  	printf("Director : %14s\n", movie[i].director);
  	printf("Releasing Year : %d\n", movie[i].releasing_year);
  	printf("Ratings : %d\n", movie[i].ratings);
  }
  return 0;
}