/*
 * Exercise 4: IP Address Validation and Conversion
 * 
 * Objective: Practice working with IP addresses and network functions.
 * 
 * Tasks:
 * 1. Implement validate_ipv4() function
 * 2. Implement validate_ipv6() function
 * 3. Implement is_private_ip() function
 * 4. Implement ip_version() function
 * 
 * Compile: gcc -o exercise_04 exercise_04_ip_validation.c
 * Run: ./exercise_04
 */

#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

/*
 * TODO: Implement this function
 * 
 * Validate if the given string is a valid IPv4 address.
 * Use inet_pton() for validation.
 * 
 * Return: 1 if valid, 0 if invalid
 */
int validate_ipv4(const char* ip) {
    // Your code here
    // Hint: Use inet_pton(AF_INET, ip, &addr)
    return 0;
}

/*
 * TODO: Implement this function
 * 
 * Validate if the given string is a valid IPv6 address.
 * Use inet_pton() for validation.
 * 
 * Return: 1 if valid, 0 if invalid
 */
int validate_ipv6(const char* ip) {
    // Your code here
    // Hint: Use inet_pton(AF_INET6, ip, &addr)
    return 0;
}

/*
 * TODO: Implement this function
 * 
 * Check if an IPv4 address is a private address.
 * 
 * Private IP ranges:
 * - 10.0.0.0 to 10.255.255.255 (Class A)
 * - 172.16.0.0 to 172.31.255.255 (Class B)
 * - 192.168.0.0 to 192.168.255.255 (Class C)
 * - 127.0.0.0 to 127.255.255.255 (Loopback)
 * 
 * Return: 1 if private, 0 if public, -1 if invalid
 */
int is_private_ip(const char* ip) {
    // Your code here
    // Hint: Parse the octets and check the ranges
    return -1;
}

/*
 * TODO: Implement this function
 * 
 * Determine the IP version of an address string.
 * 
 * Return: 4 for IPv4, 6 for IPv6, 0 for invalid
 */
int ip_version(const char* ip) {
    // Your code here
    return 0;
}

/*
 * TODO: Implement this function
 * 
 * Convert an IPv4 address from string to 32-bit integer (host byte order).
 * 
 * Return: The 32-bit integer representation, or 0 on error
 */
unsigned int ipv4_to_int(const char* ip) {
    // Your code here
    return 0;
}

/*
 * TODO: Implement this function
 * 
 * Convert a 32-bit integer (host byte order) to IPv4 string.
 * 
 * Parameters:
 *   - ip_int: the 32-bit integer
 *   - buffer: output buffer for the string
 *   - size: size of the buffer
 * 
 * Return: pointer to buffer on success, NULL on failure
 */
char* int_to_ipv4(unsigned int ip_int, char* buffer, size_t size) {
    // Your code here
    return NULL;
}

void test_validation() {
    printf("=== IP Address Validation Tests ===\n\n");
    
    const char* test_ips[] = {
        "192.168.1.1",
        "10.0.0.1",
        "256.1.1.1",
        "192.168.1",
        "::1",
        "2001:db8::1",
        "invalid",
        "192.168.1.1.1"
    };
    
    for (int i = 0; i < 8; i++) {
        int v4 = validate_ipv4(test_ips[i]);
        int v6 = validate_ipv6(test_ips[i]);
        int ver = ip_version(test_ips[i]);
        
        printf("%-20s: IPv4=%s, IPv6=%s, Version=%d\n",
               test_ips[i],
               v4 ? "Yes" : "No",
               v6 ? "Yes" : "No",
               ver);
    }
}

void test_private_ip() {
    printf("\n=== Private IP Tests ===\n\n");
    
    const char* test_ips[] = {
        "10.0.0.1",
        "172.16.0.1",
        "172.32.0.1",
        "192.168.1.1",
        "8.8.8.8",
        "127.0.0.1"
    };
    
    for (int i = 0; i < 6; i++) {
        int result = is_private_ip(test_ips[i]);
        printf("%-15s: %s\n",
               test_ips[i],
               result == 1 ? "Private" : (result == 0 ? "Public" : "Invalid"));
    }
}

void test_conversion() {
    printf("\n=== IP Conversion Tests ===\n\n");
    
    const char* test_ips[] = {"192.168.1.1", "10.0.0.1", "8.8.8.8"};
    
    for (int i = 0; i < 3; i++) {
        unsigned int ip_int = ipv4_to_int(test_ips[i]);
        char buffer[INET_ADDRSTRLEN];
        char* result = int_to_ipv4(ip_int, buffer, sizeof(buffer));
        
        printf("%-15s -> 0x%08X -> %s\n",
               test_ips[i],
               ip_int,
               result ? result : "Error");
    }
}

int main() {
    test_validation();
    test_private_ip();
    test_conversion();
    
    return 0;
}

/*
 * Expected Output (after completing TODOs):
 * 
 * === IP Address Validation Tests ===
 * 
 * 192.168.1.1         : IPv4=Yes, IPv6=No, Version=4
 * 10.0.0.1            : IPv4=Yes, IPv6=No, Version=4
 * 256.1.1.1           : IPv4=No, IPv6=No, Version=0
 * 192.168.1           : IPv4=No, IPv6=No, Version=0
 * ::1                 : IPv4=No, IPv6=Yes, Version=6
 * 2001:db8::1         : IPv4=No, IPv6=Yes, Version=6
 * invalid             : IPv4=No, IPv6=No, Version=0
 * 192.168.1.1.1       : IPv4=No, IPv6=No, Version=0
 * 
 * === Private IP Tests ===
 * 
 * 10.0.0.1       : Private
 * 172.16.0.1     : Private
 * 172.32.0.1     : Public
 * 192.168.1.1    : Private
 * 8.8.8.8        : Public
 * 127.0.0.1      : Private
 * 
 * === IP Conversion Tests ===
 * 
 * 192.168.1.1     -> 0xC0A80101 -> 192.168.1.1
 * 10.0.0.1        -> 0x0A000001 -> 10.0.0.1
 * 8.8.8.8         -> 0x08080808 -> 8.8.8.8
 */
