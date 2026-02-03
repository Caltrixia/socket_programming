/*
 * Module 1 Mini-Project: Network Information Tool
 * 
 * Description:
 *   Build a command-line tool that provides network information,
 *   validates IP addresses, identifies port services, and displays
 *   protocol comparisons.
 * 
 * Features to implement:
 *   1. IP address validation (IPv4 and IPv6)
 *   2. Private/Public IP classification
 *   3. Port service identification
 *   4. TCP/UDP protocol comparison
 *   5. Interactive menu system
 * 
 * Compile: gcc -o netinfo network_info_tool.c
 * Run: ./netinfo
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

/* ============================================
 * Part 1: IP Address Functions
 * ============================================ */

int validate_ip(const char* ip, int* version) {
    struct in_addr addr4;
    struct in6_addr addr6;
    
    if (inet_pton(AF_INET, ip, &addr4) == 1) {
        *version = 4;
        return 1;
    }
    if (inet_pton(AF_INET6, ip, &addr6) == 1) {
        *version = 6;
        return 1;
    }
    *version = 0;
    return 0;
}

const char* classify_ipv4(const char* ip) {
    struct in_addr addr;
    if (inet_pton(AF_INET, ip, &addr) != 1) {
        return "Invalid";
    }
    
    unsigned int ip_int = ntohl(addr.s_addr);
    unsigned char first = (ip_int >> 24) & 0xFF;
    unsigned char second = (ip_int >> 16) & 0xFF;
    
    // Loopback
    if (first == 127) return "Loopback";
    
    // Private ranges
    if (first == 10) return "Private (Class A)";
    if (first == 172 && second >= 16 && second <= 31) return "Private (Class B)";
    if (first == 192 && second == 168) return "Private (Class C)";
    
    // Link-local
    if (first == 169 && second == 254) return "Link-Local";
    
    // Multicast
    if (first >= 224 && first <= 239) return "Multicast";
    
    // Broadcast
    if (ip_int == 0xFFFFFFFF) return "Broadcast";
    
    return "Public";
}

void analyze_ip(const char* ip) {
    int version;
    
    printf("\n--- IP Address Analysis ---\n");
    printf("Input: %s\n", ip);
    
    if (!validate_ip(ip, &version)) {
        printf("Status: INVALID\n");
        return;
    }
    
    printf("Status: Valid\n");
    printf("Version: IPv%d\n", version);
    
    if (version == 4) {
        printf("Classification: %s\n", classify_ipv4(ip));
        
        // Show binary representation
        struct in_addr addr;
        inet_pton(AF_INET, ip, &addr);
        unsigned int ip_int = ntohl(addr.s_addr);
        printf("Numeric: %u (0x%08X)\n", ip_int, ip_int);
    }
}

/* ============================================
 * Part 2: Port Service Functions
 * ============================================ */

typedef struct {
    int port;
    const char* service;
    const char* protocol;
    const char* description;
} PortInfo;

PortInfo common_ports[] = {
    {20, "FTP-DATA", "TCP", "File Transfer Protocol (data)"},
    {21, "FTP", "TCP", "File Transfer Protocol (control)"},
    {22, "SSH", "TCP", "Secure Shell"},
    {23, "TELNET", "TCP", "Telnet (unencrypted)"},
    {25, "SMTP", "TCP", "Simple Mail Transfer Protocol"},
    {53, "DNS", "TCP/UDP", "Domain Name System"},
    {67, "DHCP", "UDP", "DHCP Server"},
    {68, "DHCP", "UDP", "DHCP Client"},
    {80, "HTTP", "TCP", "Hypertext Transfer Protocol"},
    {110, "POP3", "TCP", "Post Office Protocol v3"},
    {123, "NTP", "UDP", "Network Time Protocol"},
    {143, "IMAP", "TCP", "Internet Message Access Protocol"},
    {443, "HTTPS", "TCP", "HTTP Secure"},
    {465, "SMTPS", "TCP", "SMTP Secure"},
    {993, "IMAPS", "TCP", "IMAP Secure"},
    {995, "POP3S", "TCP", "POP3 Secure"},
    {3306, "MySQL", "TCP", "MySQL Database"},
    {5432, "PostgreSQL", "TCP", "PostgreSQL Database"},
    {6379, "Redis", "TCP", "Redis Database"},
    {8080, "HTTP-ALT", "TCP", "HTTP Alternate"},
    {27017, "MongoDB", "TCP", "MongoDB Database"},
    {0, NULL, NULL, NULL}  // Sentinel
};

void lookup_port(int port) {
    printf("\n--- Port %d Information ---\n", port);
    
    if (port < 0 || port > 65535) {
        printf("Status: INVALID (must be 0-65535)\n");
        return;
    }
    
    // Classify port range
    const char* category;
    if (port <= 1023) {
        category = "Well-known (requires root)";
    } else if (port <= 49151) {
        category = "Registered";
    } else {
        category = "Dynamic/Private";
    }
    
    printf("Category: %s\n", category);
    
    // Find service
    for (int i = 0; common_ports[i].service != NULL; i++) {
        if (common_ports[i].port == port) {
            printf("Service: %s\n", common_ports[i].service);
            printf("Protocol: %s\n", common_ports[i].protocol);
            printf("Description: %s\n", common_ports[i].description);
            return;
        }
    }
    
    printf("Service: Unknown\n");
}

void list_common_ports() {
    printf("\n--- Common Network Ports ---\n");
    printf("%-6s %-12s %-8s %s\n", "Port", "Service", "Protocol", "Description");
    printf("--------------------------------------------------------------\n");
    
    for (int i = 0; common_ports[i].service != NULL; i++) {
        printf("%-6d %-12s %-8s %s\n",
               common_ports[i].port,
               common_ports[i].service,
               common_ports[i].protocol,
               common_ports[i].description);
    }
}

/* ============================================
 * Part 3: Protocol Comparison
 * ============================================ */

void compare_protocols() {
    printf("\n--- TCP vs UDP Comparison ---\n\n");
    
    printf("%-25s %-15s %-15s\n", "Feature", "TCP", "UDP");
    printf("-------------------------------------------------------\n");
    printf("%-25s %-15s %-15s\n", "Connection", "Connection-based", "Connectionless");
    printf("%-25s %-15s %-15s\n", "Reliability", "Guaranteed", "Best-effort");
    printf("%-25s %-15s %-15s\n", "Ordering", "Ordered", "No guarantee");
    printf("%-25s %-15s %-15s\n", "Error Checking", "Yes + Recovery", "Checksum only");
    printf("%-25s %-15s %-15s\n", "Flow Control", "Yes", "No");
    printf("%-25s %-15s %-15s\n", "Congestion Control", "Yes", "No");
    printf("%-25s %-15s %-15s\n", "Speed", "Slower", "Faster");
    printf("%-25s %-15s %-15s\n", "Header Size", "20-60 bytes", "8 bytes");
    printf("%-25s %-15s %-15s\n", "Handshake", "3-way", "None");
    
    printf("\n--- Use Cases ---\n");
    printf("TCP: Web, Email, File Transfer, SSH, Database\n");
    printf("UDP: Streaming, Gaming, VoIP, DNS, NTP\n");
}

/* ============================================
 * Part 4: Menu System
 * ============================================ */

void print_menu() {
    printf("\n========================================\n");
    printf("     Network Information Tool v1.0\n");
    printf("========================================\n");
    printf("1. Analyze IP Address\n");
    printf("2. Lookup Port Service\n");
    printf("3. List Common Ports\n");
    printf("4. Compare TCP vs UDP\n");
    printf("5. Batch IP Validation\n");
    printf("0. Exit\n");
    printf("----------------------------------------\n");
    printf("Enter choice: ");
}

void batch_ip_validation() {
    char ip[64];
    
    printf("\n--- Batch IP Validation ---\n");
    printf("Enter IP addresses (one per line, 'done' to finish):\n\n");
    
    while (1) {
        printf("> ");
        if (scanf("%63s", ip) != 1) break;
        
        if (strcmp(ip, "done") == 0 || strcmp(ip, "quit") == 0) {
            break;
        }
        
        int version;
        if (validate_ip(ip, &version)) {
            printf("  ✓ Valid IPv%d", version);
            if (version == 4) {
                printf(" (%s)", classify_ipv4(ip));
            }
            printf("\n");
        } else {
            printf("  ✗ Invalid\n");
        }
    }
}

int main() {
    int choice;
    char input[64];
    int port;
    
    printf("Welcome to the Network Information Tool!\n");
    
    while (1) {
        print_menu();
        
        if (scanf("%d", &choice) != 1) {
            // Clear invalid input
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        
        switch (choice) {
            case 0:
                printf("Goodbye!\n");
                return 0;
                
            case 1:
                printf("Enter IP address: ");
                scanf("%63s", input);
                analyze_ip(input);
                break;
                
            case 2:
                printf("Enter port number: ");
                if (scanf("%d", &port) == 1) {
                    lookup_port(port);
                } else {
                    printf("Invalid port number.\n");
                    while (getchar() != '\n');
                }
                break;
                
            case 3:
                list_common_ports();
                break;
                
            case 4:
                compare_protocols();
                break;
                
            case 5:
                batch_ip_validation();
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
