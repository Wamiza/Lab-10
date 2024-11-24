#include <stdio.h>
#include <string.h>

void reverse(char word[], int start, int end);

 int main() {
 	char word[100];
 	
 	printf("Enter word :");
 	scanf("%s", word);
 	
 	printf("\nOriginal String %s\n ", word);
 	
 	reverse(word, 0, strlen(word) - 1);
 	
    printf("\n Reverse String %s" , word);
  return 0;		
 }

void reverse(char word[], int start, int end) {
    if (start >= end) {
        return;
    }
    char temp = word[start];
    word[start] = word[end];
    word[end] = temp;
    reverse(word, start + 1, end - 1);
}
