/*
 * Solutions to Module 1 Exercises
 * 
 * This file contains the complete solutions to all exercises.
 * Try to solve the exercises yourself before looking at these solutions!
 */

// =============================================================================
// Exercise 1 Solutions: OSI Model Layers
// =============================================================================

/*
 * Complete layer_names array:
 */
const char* layer_names_solution[] = {
    "",              // Index 0 (unused)
    "Physical",      // Layer 1
    "Data Link",     // Layer 2
    "Network",       // Layer 3
    "Transport",     // Layer 4
    "Session",       // Layer 5
    "Presentation",  // Layer 6
    "Application"    // Layer 7
};

/*
 * get_layer_name() solution:
 */
const char* get_layer_name_solution(int layer) {
    if (layer < 1 || layer > 7) {
        return "Invalid";
    }
    return layer_names_solution[layer];
}

/*
 * get_protocol_layer() solution:
 */
#include <string.h>
#include <strings.h>

int get_protocol_layer_solution(const char* protocol) {
    // Application Layer (7)
    if (strcasecmp(protocol, "HTTP") == 0 ||
        strcasecmp(protocol, "HTTPS") == 0 ||
        strcasecmp(protocol, "FTP") == 0 ||
        strcasecmp(protocol, "SMTP") == 0 ||
        strcasecmp(protocol, "DNS") == 0 ||
        strcasecmp(protocol, "SSH") == 0) {
        return 7;
    }
    // Presentation Layer (6)
    if (strcasecmp(protocol, "SSL") == 0 ||
        strcasecmp(protocol, "TLS") == 0 ||
        strcasecmp(protocol, "JPEG") == 0) {
        return 6;
    }
    // Session Layer (5)
    if (strcasecmp(protocol, "NetBIOS") == 0 ||
        strcasecmp(protocol, "RPC") == 0) {
        return 5;
    }
    // Transport Layer (4)
    if (strcasecmp(protocol, "TCP") == 0 ||
        strcasecmp(protocol, "UDP") == 0) {
        return 4;
    }
    // Network Layer (3)
    if (strcasecmp(protocol, "IP") == 0 ||
        strcasecmp(protocol, "ICMP") == 0 ||
        strcasecmp(protocol, "ARP") == 0) {
        return 3;
    }
    // Data Link Layer (2)
    if (strcasecmp(protocol, "Ethernet") == 0 ||
        strcasecmp(protocol, "WiFi") == 0 ||
        strcasecmp(protocol, "PPP") == 0) {
        return 2;
    }
    return -1;
}

// =============================================================================
// Exercise 2 Solutions: Port Number Classification
// =============================================================================

/*
 * get_port_category() solution:
 */
const char* get_port_category_solution(int port) {
    if (port < 0 || port > 65535) {
        return "Invalid";
    }
    if (port <= 1023) {
        return "Well-known";
    }
    if (port <= 49151) {
        return "Registered";
    }
    return "Dynamic/Private";
}

/*
 * get_service_name() solution (complete):
 */
const char* get_service_name_solution(int port) {
    switch (port) {
        case 20: return "FTP (Data)";
        case 21: return "FTP (Control)";
        case 22: return "SSH";
        case 23: return "Telnet";
        case 25: return "SMTP";
        case 53: return "DNS";
        case 80: return "HTTP";
        case 110: return "POP3";
        case 143: return "IMAP";
        case 443: return "HTTPS";
        case 993: return "IMAPS";
        case 995: return "POP3S";
        case 3306: return "MySQL";
        case 5432: return "PostgreSQL";
        case 6379: return "Redis";
        case 8080: return "HTTP Alternate";
        case 27017: return "MongoDB";
        default: return "Unknown";
    }
}

/*
 * is_valid_port() solution:
 */
int is_valid_port_solution(int port) {
    return (port >= 0 && port <= 65535) ? 1 : 0;
}

// =============================================================================
// Exercise 3 Solutions: TCP vs UDP Comparison
// =============================================================================

/*
 * Complete protocol information:
 */
typedef struct {
    const char* name;
    int connection_oriented;
    int reliable;
    int ordered;
    int has_flow_control;
    int has_congestion_ctrl;
    int header_size;
} ProtocolInfoSolution;

ProtocolInfoSolution protocols_solution[] = {
    {"TCP", 1, 1, 1, 1, 1, 20},  // All features enabled
    {"UDP", 0, 0, 0, 0, 0, 8}    // No features
};

/*
 * recommend_protocol() solution:
 */
const char* recommend_protocol_solution(const char* use_case) {
    // TCP for reliability-critical applications
    if (strcasecmp(use_case, "file_transfer") == 0 ||
        strcasecmp(use_case, "web_browsing") == 0 ||
        strcasecmp(use_case, "email") == 0 ||
        strcasecmp(use_case, "database") == 0 ||
        strcasecmp(use_case, "ssh") == 0 ||
        strcasecmp(use_case, "ftp") == 0) {
        return "TCP";
    }
    // UDP for real-time/speed-critical applications
    if (strcasecmp(use_case, "video_streaming") == 0 ||
        strcasecmp(use_case, "online_gaming") == 0 ||
        strcasecmp(use_case, "dns_lookup") == 0 ||
        strcasecmp(use_case, "voip") == 0 ||
        strcasecmp(use_case, "live_streaming") == 0) {
        return "UDP";
    }
    return "Unknown";
}

// =============================================================================
// Exercise 4 Solutions: IP Address Validation and Conversion
// =============================================================================

#include <arpa/inet.h>

/*
 * validate_ipv4() solution:
 */
int validate_ipv4_solution(const char* ip) {
    struct in_addr addr;
    return inet_pton(AF_INET, ip, &addr) == 1 ? 1 : 0;
}

/*
 * validate_ipv6() solution:
 */
int validate_ipv6_solution(const char* ip) {
    struct in6_addr addr;
    return inet_pton(AF_INET6, ip, &addr) == 1 ? 1 : 0;
}

/*
 * is_private_ip() solution:
 */
int is_private_ip_solution(const char* ip) {
    struct in_addr addr;
    if (inet_pton(AF_INET, ip, &addr) != 1) {
        return -1;  // Invalid IP
    }
    
    unsigned int ip_int = ntohl(addr.s_addr);
    unsigned char first = (ip_int >> 24) & 0xFF;
    unsigned char second = (ip_int >> 16) & 0xFF;
    
    // 10.0.0.0/8
    if (first == 10) return 1;
    
    // 172.16.0.0/12
    if (first == 172 && second >= 16 && second <= 31) return 1;
    
    // 192.168.0.0/16
    if (first == 192 && second == 168) return 1;
    
    // 127.0.0.0/8 (loopback)
    if (first == 127) return 1;
    
    return 0;  // Public
}

/*
 * ip_version() solution:
 */
int ip_version_solution(const char* ip) {
    struct in_addr addr4;
    struct in6_addr addr6;
    
    if (inet_pton(AF_INET, ip, &addr4) == 1) {
        return 4;
    }
    if (inet_pton(AF_INET6, ip, &addr6) == 1) {
        return 6;
    }
    return 0;  // Invalid
}

/*
 * ipv4_to_int() solution:
 */
unsigned int ipv4_to_int_solution(const char* ip) {
    struct in_addr addr;
    if (inet_pton(AF_INET, ip, &addr) != 1) {
        return 0;
    }
    return ntohl(addr.s_addr);
}

/*
 * int_to_ipv4() solution:
 */
char* int_to_ipv4_solution(unsigned int ip_int, char* buffer, size_t size) {
    struct in_addr addr;
    addr.s_addr = htonl(ip_int);
    
    if (inet_ntop(AF_INET, &addr, buffer, size) == NULL) {
        return NULL;
    }
    return buffer;
}
