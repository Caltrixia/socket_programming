/*
 * Exercise 3: TCP vs UDP Comparison
 * 
 * Objective: Understand the differences between TCP and UDP protocols.
 * 
 * Tasks:
 * 1. Complete the protocol characteristic functions
 * 2. Implement the recommend_protocol() function
 * 3. Answer the quiz questions correctly
 * 
 * Compile: gcc -o exercise_03 exercise_03_tcp_udp.c
 * Run: ./exercise_03
 */

#include <stdio.h>
#include <string.h>

// Protocol types
typedef enum {
    PROTO_TCP,
    PROTO_UDP
} Protocol;

// Protocol characteristics structure
typedef struct {
    const char* name;
    int connection_oriented;  // 1 = yes, 0 = no
    int reliable;             // 1 = yes, 0 = no
    int ordered;              // 1 = yes, 0 = no
    int has_flow_control;     // 1 = yes, 0 = no
    int has_congestion_ctrl;  // 1 = yes, 0 = no
    int header_size;          // bytes
} ProtocolInfo;

/*
 * TODO: Complete the protocol information
 * 
 * TCP characteristics:
 * - Connection-oriented
 * - Reliable (acknowledgments, retransmissions)
 * - Ordered delivery
 * - Flow control (sliding window)
 * - Congestion control
 * - 20-60 byte header
 * 
 * UDP characteristics:
 * - Connectionless
 * - Unreliable (no acknowledgments)
 * - No ordering guarantee
 * - No flow control
 * - No congestion control
 * - 8 byte header
 */
ProtocolInfo protocols[] = {
    // TODO: Fill in the correct values (1 or 0)
    {"TCP", 0, 0, 0, 0, 0, 20},  // Fill in 1s for TCP characteristics
    {"UDP", 0, 0, 0, 0, 0, 8}    // Fill in 1s for UDP characteristics
};

/*
 * TODO: Implement this function
 * 
 * Recommend either "TCP" or "UDP" based on the use case.
 * 
 * Use cases that need TCP:
 * - "file_transfer" (needs reliability)
 * - "web_browsing" (needs reliability and ordering)
 * - "email" (needs reliability)
 * - "database" (needs reliability)
 * 
 * Use cases that work better with UDP:
 * - "video_streaming" (speed over reliability)
 * - "online_gaming" (low latency important)
 * - "dns_lookup" (simple query/response)
 * - "voip" (real-time, can tolerate loss)
 */
const char* recommend_protocol(const char* use_case) {
    // Your code here
    return "Unknown";
}

void print_protocol_comparison() {
    printf("=== TCP vs UDP Comparison ===\n\n");
    printf("%-25s %-10s %-10s\n", "Characteristic", "TCP", "UDP");
    printf("---------------------------------------------------\n");
    
    printf("%-25s %-10s %-10s\n", "Connection-oriented",
           protocols[0].connection_oriented ? "Yes" : "No",
           protocols[1].connection_oriented ? "Yes" : "No");
    
    printf("%-25s %-10s %-10s\n", "Reliable delivery",
           protocols[0].reliable ? "Yes" : "No",
           protocols[1].reliable ? "Yes" : "No");
    
    printf("%-25s %-10s %-10s\n", "Ordered delivery",
           protocols[0].ordered ? "Yes" : "No",
           protocols[1].ordered ? "Yes" : "No");
    
    printf("%-25s %-10s %-10s\n", "Flow control",
           protocols[0].has_flow_control ? "Yes" : "No",
           protocols[1].has_flow_control ? "Yes" : "No");
    
    printf("%-25s %-10s %-10s\n", "Congestion control",
           protocols[0].has_congestion_ctrl ? "Yes" : "No",
           protocols[1].has_congestion_ctrl ? "Yes" : "No");
    
    printf("%-25s %-10d %-10d\n", "Header size (bytes)",
           protocols[0].header_size,
           protocols[1].header_size);
}

void print_recommendations() {
    printf("\n=== Protocol Recommendations ===\n\n");
    
    const char* use_cases[] = {
        "file_transfer",
        "video_streaming",
        "web_browsing",
        "online_gaming",
        "email",
        "dns_lookup",
        "voip",
        "database"
    };
    
    for (int i = 0; i < 8; i++) {
        printf("%-20s -> %s\n", use_cases[i], recommend_protocol(use_cases[i]));
    }
}

void run_quiz() {
    printf("\n=== TCP/UDP Quiz ===\n\n");
    
    int score = 0;
    char answer[10];
    
    printf("Q1: Which protocol would you use for a chat application\n");
    printf("    where message delivery is important? (TCP/UDP): ");
    scanf("%s", answer);
    if (strcasecmp(answer, "TCP") == 0) {
        printf("Correct! TCP ensures messages are delivered.\n\n");
        score++;
    } else {
        printf("Incorrect. TCP is better for reliable messaging.\n\n");
    }
    
    printf("Q2: Which protocol has lower latency? (TCP/UDP): ");
    scanf("%s", answer);
    if (strcasecmp(answer, "UDP") == 0) {
        printf("Correct! UDP has no connection setup overhead.\n\n");
        score++;
    } else {
        printf("Incorrect. UDP has lower latency.\n\n");
    }
    
    printf("Q3: Which protocol uses a 3-way handshake? (TCP/UDP): ");
    scanf("%s", answer);
    if (strcasecmp(answer, "TCP") == 0) {
        printf("Correct! TCP uses SYN, SYN-ACK, ACK handshake.\n\n");
        score++;
    } else {
        printf("Incorrect. TCP uses the 3-way handshake.\n\n");
    }
    
    printf("Your score: %d/3\n", score);
}

int main() {
    print_protocol_comparison();
    print_recommendations();
    run_quiz();
    
    return 0;
}

/*
 * Expected Output (after completing TODOs):
 * 
 * === TCP vs UDP Comparison ===
 * 
 * Characteristic           TCP        UDP       
 * ---------------------------------------------------
 * Connection-oriented      Yes        No        
 * Reliable delivery        Yes        No        
 * Ordered delivery         Yes        No        
 * Flow control             Yes        No        
 * Congestion control       Yes        No        
 * Header size (bytes)      20         8         
 * 
 * === Protocol Recommendations ===
 * 
 * file_transfer        -> TCP
 * video_streaming      -> UDP
 * web_browsing         -> TCP
 * online_gaming        -> UDP
 * email                -> TCP
 * dns_lookup           -> UDP
 * voip                 -> UDP
 * database             -> TCP
 */
