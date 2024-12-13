/* 
Name: Lydia Myla
Date: 11/12/24
Title: Lab 8 - Step 3
Description: LRU page replacement algorithm simulation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct {
    int pageno;   // Stores the page number
    int counter;  // Tracks the time of last access
} ref_page;

int main(int argc, char *argv[]) {
    // Ensure cache size is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <cache size>\n", argv[0]);
        return 1;
    }

    int CACHE_SIZE = atoi(argv[1]);
    if (CACHE_SIZE <= 0) {
        fprintf(stderr, "Cache size must be a positive integer.\n");
        return 1;
    }

    ref_page cache[CACHE_SIZE]; // The cache array
    char pageCache[100];        // Buffer to store page requests

    int totalFaults = 0;
    int time_counter = 0;  // Counter for tracking the time of access
    int i;

    // Initialize cache to empty (pageno = -1)
    for (i = 0; i < CACHE_SIZE; i++) {
        cache[i].pageno = -1;
        cache[i].counter = 0;
    }

    // Process page requests from stdin
    while (fgets(pageCache, 100, stdin)) {
        int page_num = atoi(pageCache);
        bool foundInCache = false;

        // Check if page is in cache (cache hit)
        for (i = 0; i < CACHE_SIZE; i++) {
            if (cache[i].pageno == page_num) {
                foundInCache = true;
                cache[i].counter = time_counter++;  // Update counter on cache hit
                break;
            }
        }

        // Handle cache miss
        if (!foundInCache) {
            totalFaults++;
            printf("Cache miss: %d\n", page_num);

            // Find the Least Recently Used (LRU) page by checking the lowest counter
            int lruIndex = 0;
            for (i = 1; i < CACHE_SIZE; i++) {
                if (cache[i].counter < cache[lruIndex].counter) {
                    lruIndex = i;
                }
            }

            // Replace the LRU page with the new page
            cache[lruIndex].pageno = page_num;
            cache[lruIndex].counter = time_counter++; // Update counter for the new page
        }
    }

    // Print total page faults after the simulation ends
    printf("\nSimulation completed:\n");
    printf("Total Page Faults: %d\n", totalFaults);

    return 0;
}
