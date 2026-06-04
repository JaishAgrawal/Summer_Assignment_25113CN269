//wap to print armstrong numbers in a range.
#include<stdio.h>
#include<math.h>

int main() {
    int start, end, i, original, remainder, result, n;
    
    printf("Enter starting number: ");
    scanf("%d", &start);
    printf("Enter ending number: ");
    scanf("%d", &end);
    
    printf("Armstrong numbers between %d and %d are:\n", start, end);
    
    for(i = start; i <= end; i++) {
        original = i;
        result = 0;
        n = 0;
        
        // Count digits
        while(original != 0) {
            original /= 10;
            n++;
        }
        
        original = i;
        
        // Calculate sum of power of digits
        while(original != 0) {
            remainder = original % 10;
            result += pow(remainder, n);
            original /= 10;
        }
        
        if(result == i) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}
