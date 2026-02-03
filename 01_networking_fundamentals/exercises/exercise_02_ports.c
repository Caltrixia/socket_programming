/*
 * Exercise 2: Port Number Classification
 * 
 * Objective: Learn about well-known ports and port number ranges.
 * 
 * Port Ranges:
 * - Well-known ports: 0-1023 (require root/admin)
 * - Registered ports: 1024-49151
 * - Dynamic/Private ports: 49152-65535
 * 
 * Tasks:
 * 1. Complete the get_port_category() function
 * 2. Complete the get_service_name() function for common ports
 * 3. Implement port validation
 * 
 * Compile: gcc -o exercise_02 exercise_02_ports.c
 * Run: ./exercise_02
 */

#include <stdio.h>
#include <string.h>

/*
 * TODO: Implement this function
 * 
 * Return:
 *   "Well-known" for ports 0-1023
 *   "Registered" for ports 1024-49151
 *   "Dynamic/Private" for ports 49152-65535
 *   "Invalid" for ports < 0 or > 65535
 */
const char* get_port_category(int port) {
    // Your code here
    return "Not implemented";
}

/*
 * TODO: Complete this function
 * 
 * Return the service name for well-known ports.
 * Add at least 5 more port mappings.
 */
const char* get_service_name(int port) {
    switch (port) {
        case 20: return "FTP (Data)";
        case 21: return "FTP (Control)";
        case 22: return "SSH";
        case 23: return "Telnet";
        case 25: return "SMTP";
        // TODO: Add more ports:
        // 53 = DNS
        // 80 = HTTP
        // 110 = POP3
        // 143 = IMAP
        // 443 = HTTPS
        // 3306 = MySQL
        // 5432 = PostgreSQL
        // 6379 = Redis
        default: return "Unknown";
    }
}

/*
 * TODO: Implement this function
 * 
 * Check if a port is valid (0-65535).
 * Return 1 if valid, 0 if invalid.
 */
int is_valid_port(int port) {
    // Your code here
    return 0;
}

void print_port_info(int port) {
    printf("Port %-5d: %-20s [%s]\n",
           port,
           get_service_name(port),
           get_port_category(port));
}

int main() {
    printf("=== Port Number Classification Exercise ===\n\n");
    
    // Well-known ports
    printf("--- Well-Known Ports (0-1023) ---\n");
    int well_known[] = {20, 21, 22, 23, 25, 53, 80, 110, 143, 443};
    for (int i = 0; i < 10; i++) {
        print_port_info(well_known[i]);
    }
    
    printf("\n--- Registered Ports (1024-49151) ---\n");
    int registered[] = {3306, 5432, 6379, 8080, 27017};
    for (int i = 0; i < 5; i++) {
        print_port_info(registered[i]);
    }
    
    printf("\n--- Dynamic Ports (49152-65535) ---\n");
    int dynamic[] = {50000, 55555, 65535};
    for (int i = 0; i < 3; i++) {
        print_port_info(dynamic[i]);
    }
    
    printf("\n--- Validation Tests ---\n");
    int test_ports[] = {-1, 0, 80, 1024, 49152, 65535, 65536, 100000};
    for (int i = 0; i < 8; i++) {
        printf("Port %6d: %s\n",
               test_ports[i],
               is_valid_port(test_ports[i]) ? "Valid" : "Invalid");
    }
    
    return 0;
}

/*
 * Expected Output (after completing TODOs):
 * 
 * --- Well-Known Ports (0-1023) ---
 * Port 20   : FTP (Data)           [Well-known]
 * Port 21   : FTP (Control)        [Well-known]
 * Port 22   : SSH                  [Well-known]
 * Port 23   : Telnet               [Well-known]
 * Port 25   : SMTP                 [Well-known]
 * Port 53   : DNS                  [Well-known]
 * Port 80   : HTTP                 [Well-known]
 * Port 110  : POP3                 [Well-known]
 * Port 143  : IMAP                 [Well-known]
 * Port 443  : HTTPS                [Well-known]
 * 
 * --- Registered Ports (1024-49151) ---
 * Port 3306 : MySQL                [Registered]
 * Port 5432 : PostgreSQL           [Registered]
 * ...
 * 
 * --- Validation Tests ---
 * Port     -1: Invalid
 * Port      0: Valid
 * Port     80: Valid
 * Port   1024: Valid
 * Port  49152: Valid
 * Port  65535: Valid
 * Port  65536: Invalid
 * Port 100000: Invalid
 */
