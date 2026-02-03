/*
 * Exercise 1: OSI Model Layers
 * 
 * Objective: Understand the OSI model by implementing a quiz program
 * that tests knowledge of the 7 layers.
 * 
 * Tasks:
 * 1. Complete the layer_descriptions array with correct descriptions
 * 2. Implement the get_layer_name() function
 * 3. Add error handling for invalid layer numbers
 * 
 * Compile: gcc -o exercise_01 exercise_01_osi_layers.c
 * Run: ./exercise_01
 */

#include <stdio.h>
#include <string.h>

// TODO: Complete this array with the correct layer names (1-7)
// Layer 1 = Physical, Layer 7 = Application
const char* layer_names[] = {
    "",              // Index 0 (unused)
    "Physical",      // Layer 1
    "???",           // Layer 2 - TODO: Fill this
    "Network",       // Layer 3
    "???",           // Layer 4 - TODO: Fill this
    "???",           // Layer 5 - TODO: Fill this
    "???",           // Layer 6 - TODO: Fill this
    "Application"    // Layer 7
};

// Layer descriptions
const char* layer_descriptions[] = {
    "",
    "Handles electrical signals, cables, and physical transmission",
    "Manages MAC addresses and frame transmission",
    "Handles IP addressing and routing",
    "Provides reliable end-to-end delivery (TCP/UDP)",
    "Manages sessions between applications",
    "Handles data encryption and format conversion",
    "Provides network services to user applications"
};

/*
 * TODO: Implement this function
 * 
 * Given a layer number (1-7), return the layer name.
 * Return "Invalid" for numbers outside 1-7.
 */
const char* get_layer_name(int layer) {
    // Your code here
    return "Not implemented";
}

/*
 * TODO: Implement this function
 * 
 * Given a protocol name, return which OSI layer it belongs to.
 * Examples:
 *   - "HTTP" -> 7 (Application)
 *   - "TCP" -> 4 (Transport)
 *   - "IP" -> 3 (Network)
 *   - "Ethernet" -> 2 (Data Link)
 */
int get_protocol_layer(const char* protocol) {
    // Your code here
    return -1;
}

void run_quiz() {
    printf("=== OSI Model Quiz ===\n\n");
    
    int score = 0;
    int answer;
    
    printf("Question 1: Which layer handles IP addressing?\n");
    printf("Enter layer number (1-7): ");
    scanf("%d", &answer);
    if (answer == 3) {
        printf("Correct! Network layer handles IP addressing.\n\n");
        score++;
    } else {
        printf("Incorrect. The answer is Layer 3 (Network).\n\n");
    }
    
    printf("Question 2: Which layer does TCP operate at?\n");
    printf("Enter layer number (1-7): ");
    scanf("%d", &answer);
    if (answer == 4) {
        printf("Correct! TCP operates at the Transport layer.\n\n");
        score++;
    } else {
        printf("Incorrect. The answer is Layer 4 (Transport).\n\n");
    }
    
    printf("Question 3: Which layer is closest to the physical medium?\n");
    printf("Enter layer number (1-7): ");
    scanf("%d", &answer);
    if (answer == 1) {
        printf("Correct! Physical layer is Layer 1.\n\n");
        score++;
    } else {
        printf("Incorrect. The answer is Layer 1 (Physical).\n\n");
    }
    
    printf("Your score: %d/3\n", score);
}

int main() {
    printf("=== OSI Model Exercise ===\n\n");
    
    // Print all layers and descriptions
    printf("OSI Model Layers:\n");
    printf("%-5s %-15s %s\n", "Layer", "Name", "Description");
    printf("-----------------------------------------------------------\n");
    
    for (int i = 7; i >= 1; i--) {
        printf("%-5d %-15s %s\n", i, layer_names[i], layer_descriptions[i]);
    }
    
    printf("\n");
    run_quiz();
    
    return 0;
}

/*
 * Expected Output (after completing TODOs):
 * 
 * OSI Model Layers:
 * Layer Name            Description
 * -----------------------------------------------------------
 * 7     Application     Provides network services to user applications
 * 6     Presentation    Handles data encryption and format conversion
 * 5     Session         Manages sessions between applications
 * 4     Transport       Provides reliable end-to-end delivery (TCP/UDP)
 * 3     Network         Handles IP addressing and routing
 * 2     Data Link       Manages MAC addresses and frame transmission
 * 1     Physical        Handles electrical signals, cables, and physical transmission
 */
