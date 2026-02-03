/*
 * Example 3: IP Address Manipulation
 * 
 * This example shows various ways to work with IP addresses.
 * Compile: gcc -o ip_addresses ip_addresses.c
 * Run: ./ip_addresses
 */

#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

int main() {
    printf("=== IPv4 Address Examples ===\n\n");
    
    // Common IPv4 addresses
    struct {
        const char* name;
        const char* address;
    } ipv4_examples[] = {
        {"Localhost", "127.0.0.1"},
        {"Private (Class A)", "10.0.0.1"},
        {"Private (Class B)", "172.16.0.1"},
        {"Private (Class C)", "192.168.1.1"},
        {"Google DNS", "8.8.8.8"},
        {"Broadcast", "255.255.255.255"}
    };
    
    for (int i = 0; i < 6; i++) {
        struct in_addr addr;
        if (inet_pton(AF_INET, ipv4_examples[i].address, &addr) == 1) {
            printf("%-20s: %-15s (0x%08X)\n", 
                   ipv4_examples[i].name,
                   ipv4_examples[i].address,
                   ntohl(addr.s_addr));
        }
    }
    
    printf("\n=== IPv6 Address Examples ===\n\n");
    
    struct {
        const char* name;
        const char* address;
    } ipv6_examples[] = {
        {"Localhost", "::1"},
        {"Any address", "::"},
        {"IPv4-mapped", "::ffff:192.168.1.1"},
        {"Link-local", "fe80::1"},
        {"Documentation", "2001:db8::1"}
    };
    
    for (int i = 0; i < 5; i++) {
        struct in6_addr addr6;
        if (inet_pton(AF_INET6, ipv6_examples[i].address, &addr6) == 1) {
            char expanded[INET6_ADDRSTRLEN];
            inet_ntop(AF_INET6, &addr6, expanded, sizeof(expanded));
            printf("%-15s: %s\n", ipv6_examples[i].name, expanded);
        }
    }
    
    printf("\n=== Validating IP Addresses ===\n\n");
    
    const char* test_addresses[] = {
        "192.168.1.1",
        "256.1.1.1",      // Invalid (>255)
        "192.168.1",      // Invalid (incomplete)
        "::1",
        "not.an.ip",
        "2001:db8::1"
    };
    
    for (int i = 0; i < 6; i++) {
        struct in_addr addr4;
        struct in6_addr addr6;
        
        int is_ipv4 = inet_pton(AF_INET, test_addresses[i], &addr4);
        int is_ipv6 = inet_pton(AF_INET6, test_addresses[i], &addr6);
        
        printf("'%s': ", test_addresses[i]);
        if (is_ipv4 == 1) {
            printf("Valid IPv4\n");
        } else if (is_ipv6 == 1) {
            printf("Valid IPv6\n");
        } else {
            printf("Invalid\n");
        }
    }
    
    return 0;
}
