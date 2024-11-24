#include <stdio.h>

#define MAX_TEMPERATURE 35.0

void Temperature(double temperature) {

    static int exceedCount = 0;

    if (temperature > MAX_TEMPERATURE) {
        exceedCount++;
        printf("\nTemperature %.2f exceeds the maximum allowable limit of %.2f°C.\n\n", temperature, MAX_TEMPERATURE);
    } 
	else {
        printf("Temperature %.2f is within the allowable limit.\n\n", temperature);
    }
    printf("Number of times the limit has been exceeded: %d\n", exceedCount);
}

int main() {
    int numTemperatures;
    printf("Enter the number of temperatures : ");
    scanf("%d", &numTemperatures);

    for (int i = 0; i < numTemperatures; i++) {
        double temperature;
        printf("Enter temperature %d: ", i + 1);
        scanf("%lf", &temperature);
        Temperature(temperature);
    }

    return 0;
}
