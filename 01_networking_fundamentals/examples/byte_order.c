/*
 * Example 2: Byte Order Conversion Functions
 * 
 * This example demonstrates the importance of byte order conversion.
 * Compile: gcc -o byte_order byte_order.c
 * Run: ./byte_order
 */

#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

void print_bytes(const char* label, void* ptr, size_t size) {
    unsigned char* bytes = (unsigned char*)ptr;
    printf("%s: ", label);
    for (size_t i = 0; i < size; i++) {
        printf("%02x ", bytes[i]);
    }
    printf("\n");
}

int main() {
    printf("=== System Byte Order Detection ===\n");
    
    uint16_t test = 0x0102;
    unsigned char* ptr = (unsigned char*)&test;
    
    if (ptr[0] == 0x01) {
        printf("This system is BIG ENDIAN\n");
    } else {
        printf("This system is LITTLE ENDIAN\n");
    }
    
    printf("\n=== 16-bit Conversion (htons/ntohs) ===\n");
    
    uint16_t port_host = 8080;
    uint16_t port_network = htons(port_host);
    uint16_t port_back = ntohs(port_network);
    
    printf("Port value: %d\n", port_host);
    print_bytes("Host byte order     ", &port_host, sizeof(port_host));
    print_bytes("Network byte order  ", &port_network, sizeof(port_network));
    printf("Converted back: %d\n", port_back);
    
    printf("\n=== 32-bit Conversion (htonl/ntohl) ===\n");
    
    uint32_t ip_host = 0xC0A80164;  // 192.168.1.100
    uint32_t ip_network = htonl(ip_host);
    uint32_t ip_back = ntohl(ip_network);
    
    printf("IP value: 0x%08X\n", ip_host);
    print_bytes("Host byte order     ", &ip_host, sizeof(ip_host));
    print_bytes("Network byte order  ", &ip_network, sizeof(ip_network));
    printf("Converted back: 0x%08X\n", ip_back);
    
    printf("\n=== IP Address Conversion ===\n");
    
    // String to binary
    struct in_addr addr;
    inet_pton(AF_INET, "192.168.1.100", &addr);
    printf("IP '192.168.1.100' in network byte order: 0x%08X\n", addr.s_addr);
    print_bytes("Bytes", &addr.s_addr, sizeof(addr.s_addr));
    
    // Binary to string
    char ip_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &addr, ip_str, sizeof(ip_str));
    printf("Converted back to string: %s\n", ip_str);
    
    return 0;
}
