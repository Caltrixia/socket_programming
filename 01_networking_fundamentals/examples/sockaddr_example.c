/*
 * Example 1: Understanding Socket Address Structures
 * 
 * This example demonstrates the key data structures used in socket programming.
 * Compile: gcc -o sockaddr_example sockaddr_example.c
 * Run: ./sockaddr_example
 */

#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main() {
    // IPv4 address structure
    struct sockaddr_in addr4;
    
    // Initialize to zero
    memset(&addr4, 0, sizeof(addr4));
    
    // Set address family (IPv4)
    addr4.sin_family = AF_INET;
    
    // Set port number (convert to network byte order)
    addr4.sin_port = htons(8080);
    
    // Set IP address
    // Option 1: Any address (server will listen on all interfaces)
    addr4.sin_addr.s_addr = INADDR_ANY;
    
    // Option 2: Specific address
    // inet_pton(AF_INET, "192.168.1.100", &addr4.sin_addr);
    
    // Print the configuration
    printf("=== IPv4 Socket Address ===\n");
    printf("Family: %d (AF_INET = %d)\n", addr4.sin_family, AF_INET);
    printf("Port: %d (network order: 0x%04x)\n", ntohs(addr4.sin_port), addr4.sin_port);
    
    char ip_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &addr4.sin_addr, ip_str, sizeof(ip_str));
    printf("IP Address: %s\n", ip_str);
    
    printf("\n");
    
    // IPv6 address structure
    struct sockaddr_in6 addr6;
    memset(&addr6, 0, sizeof(addr6));
    
    addr6.sin6_family = AF_INET6;
    addr6.sin6_port = htons(8080);
    addr6.sin6_addr = in6addr_any;  // Listen on all IPv6 interfaces
    
    printf("=== IPv6 Socket Address ===\n");
    printf("Family: %d (AF_INET6 = %d)\n", addr6.sin6_family, AF_INET6);
    printf("Port: %d\n", ntohs(addr6.sin6_port));
    
    char ip6_str[INET6_ADDRSTRLEN];
    inet_ntop(AF_INET6, &addr6.sin6_addr, ip6_str, sizeof(ip6_str));
    printf("IPv6 Address: %s\n", ip6_str);
    
    return 0;
}
