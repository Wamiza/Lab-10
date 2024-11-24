#include <stdio.h>

struct Flight_Information {
	int flight_number;
	char departure_city[4];
	char destination_city[4];
	int date;
	int available_seats;
};

int main() {
	
	struct Flight_Information flight[1];
	
	printf("--------->BOOK YOUR FLIGHT NOW<----------\n\n");
  for (int i = 0; i < 1; i++) {
	printf("Enter Flight Number:");
	scanf("%d", &flight[i].flight_number);
	
	printf("Enter Departure City :");
	scanf("%3s" , &flight[i].departure_city);
	
	printf("Enter Destination City :");
	scanf("%3s" ,&flight[i].destination_city);
	
	printf("Enter Flight Date :(DDMMYY)");
	scanf("%d" , &flight[i].date);
	
	printf("Enter Available Seats :");
	scanf("%d" ,&flight[i].available_seats);
  }
    
    printf("\n\n---------> FLIGHT INFORMATION <----------\n\n");
  for (int i = 0; i < 1; i++) {
	printf("Flight Number:%d\n" ,flight[i].flight_number);
	printf("Departure City : %3s\n" , flight[i].departure_city);
	printf("Destination City : %3s\n", flight[i].destination_city);
	printf("Flight Date : %d\n", flight[i].date);
	printf("Available Seats : %d\n", flight[i].available_seats-1);
  }
	return 0;
}