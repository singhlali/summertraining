#include <stdio.h>

// Function declarations (prototypes)
void Quick_Sort(int a[], int p, int r);
int Partition(int a[], int p, int r);

int main() // main should return an int
{
    int a[100]; // Increased array size for safety
    int i, n;

    // clrscr() is non-standard and removed.
    printf("Program for QUICK SORT\n\n");
    printf("Enter no. of elements: "); // Input section
    scanf("%d", &n);

    // Input validation
    if (n <= 0 || n > 100) {
        printf("Invalid number of elements. Please enter a number between 1 and 100.\n");
        return 1; // Exit with an error code
    }

    printf("\n");
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1); // Use i+1 for user-friendly numbering
        scanf("%d", &a[i]);
    }

    Quick_Sort(a, 0, n - 1); // Calling function with correct arguments

    printf("\nSorted array:\n"); // Output section
    for (i = 0; i < n; i++) {
        printf("%6d", a[i]);
    }
    printf("\n");

    // getch() is non-standard. Using getchar() as a standard alternative to pause.
    printf("\nPress Enter to exit...");
    getchar(); // Consumes the newline left by the last scanf
    getchar(); // Waits for user input

    return 0; // Return 0 to indicate successful execution
}

// Function definition for Quick_Sort
void Quick_Sort(int a[], int p, int r) {
    int q;
    if (p < r) {
        q = Partition(a, p, r);      // Function calling another function
        Quick_Sort(a, p, q - 1); // Function calling itself (recursive call)
        Quick_Sort(a, q + 1, r); // Function calling itself (recursive call)
    }
}

// Function definition for Partition
int Partition(int a[], int p, int r) {
    int i, x, j, t;
    x = a[r]; // Choosing the last element as the pivot
    i = p - 1;

    for (j = p; j < r; j++) {
        if (a[j] <= x) // Comparison
        {
            i++;
            // Swapping values
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    // Swapping values to place the pivot in the correct position
    t = a[i + 1];
    a[i + 1] = a[r];
    a[r] = t;

    return (i + 1); // Return the pivot's final index
}