# Module 1: Fundamentals of Networking

## Learning Objectives

By the end of this module, you will understand:
- The OSI and TCP/IP networking models
- What sockets are and how they work
- IP addresses and port numbers
- The difference between TCP and UDP
- Client-server architecture

---

## 1.1 What is a Network?

A network is a collection of computers and devices connected together to share resources and communicate.

### OSI Model (7 Layers)

```
Layer 7: Application    - HTTP, FTP, SSH, DNS
Layer 6: Presentation   - SSL/TLS, encryption, compression
Layer 5: Session        - Session management
Layer 4: Transport      - TCP, UDP (ports)
Layer 3: Network        - IP (addressing, routing)
Layer 2: Data Link      - Ethernet, MAC addresses
Layer 1: Physical       - Cables, wireless signals
```

### TCP/IP Model (4 Layers)

```
Layer 4: Application    - HTTP, FTP, SSH (combines OSI 5-7)
Layer 3: Transport      - TCP, UDP
Layer 2: Internet       - IP, ICMP
Layer 1: Network Access - Ethernet, Wi-Fi (combines OSI 1-2)
```

---

## 1.2 IP Addresses

### IPv4
- 32-bit address
- Format: `xxx.xxx.xxx.xxx` (e.g., 192.168.1.1)
- Range: 0.0.0.0 to 255.255.255.255
- ~4.3 billion possible addresses

### IPv6
- 128-bit address
- Format: `xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:xxxx:xxxx`
- Example: `2001:0db8:85a3:0000:0000:8a2e:0370:7334`
- Vastly more addresses

### Special Addresses
| Address | Purpose |
|---------|---------|
| 127.0.0.1 | Localhost (loopback) |
| 0.0.0.0 | All interfaces |
| 255.255.255.255 | Broadcast |
| 192.168.x.x | Private network |
| 10.x.x.x | Private network |

---

## 1.3 Port Numbers

A port is a 16-bit number (0-65535) that identifies a specific service.

### Port Ranges
| Range | Name | Description |
|-------|------|-------------|
| 0-1023 | Well-known | System services (requires root) |
| 1024-49151 | Registered | User applications |
| 49152-65535 | Dynamic | Temporary/ephemeral ports |

### Common Ports
| Port | Service |
|------|---------|
| 20, 21 | FTP |
| 22 | SSH |
| 23 | Telnet |
| 25 | SMTP (email) |
| 53 | DNS |
| 80 | HTTP |
| 443 | HTTPS |
| 3306 | MySQL |
| 5432 | PostgreSQL |

---

## 1.4 What is a Socket?

A **socket** is an endpoint for communication. It's like a telephone - you need two endpoints to have a conversation.

### Socket = IP Address + Port Number

```
Socket Address: 192.168.1.100:8080
                ↑            ↑
             IP Address   Port
```

### Types of Sockets

1. **Stream Sockets (SOCK_STREAM)**
   - Uses TCP
   - Connection-oriented
   - Reliable, ordered delivery
   - Like a phone call

2. **Datagram Sockets (SOCK_DGRAM)**
   - Uses UDP
   - Connectionless
   - No guarantee of delivery
   - Like sending postcards

3. **Raw Sockets (SOCK_RAW)**
   - Direct access to lower-level protocols
   - Requires root privileges

---

## 1.5 TCP vs UDP

### TCP (Transmission Control Protocol)
- ✅ Reliable delivery
- ✅ Ordered packets
- ✅ Error checking
- ✅ Flow control
- ❌ Higher overhead
- ❌ Slower

**Use for:** Web, email, file transfer, SSH

### UDP (User Datagram Protocol)
- ✅ Low overhead
- ✅ Faster
- ✅ No connection setup
- ❌ No delivery guarantee
- ❌ Packets may arrive out of order
- ❌ No built-in error recovery

**Use for:** Gaming, VoIP, video streaming, DNS

### TCP Three-Way Handshake
```
Client                    Server
   |                         |
   |------- SYN ------------>|
   |                         |
   |<------ SYN-ACK ---------|
   |                         |
   |------- ACK ------------>|
   |                         |
   |  Connection Established |
```

---

## 1.6 Client-Server Architecture

### Server
1. Creates a socket
2. Binds to an address/port
3. Listens for connections
4. Accepts incoming connections
5. Receives/sends data
6. Closes connection

### Client
1. Creates a socket
2. Connects to server address/port
3. Sends/receives data
4. Closes connection

```
        Server                          Client
          |                               |
    socket()                         socket()
          |                               |
     bind()                               |
          |                               |
    listen()                              |
          |                               |
    accept() <-------- connect() ---------|
          |                               |
     recv() <--------- send() ------------|
          |                               |
     send() ---------- recv() ----------->|
          |                               |
    close()                          close()
```

---

## 1.7 Byte Order (Endianness)

Different computers store bytes in different orders:

- **Big Endian:** Most significant byte first (network byte order)
- **Little Endian:** Least significant byte first (x86, ARM)

### Conversion Functions
```c
htons() - Host to Network Short (16-bit)
htonl() - Host to Network Long (32-bit)
ntohs() - Network to Host Short
ntohl() - Network to Host Long
```

---

## 1.8 Key Data Structures

### sockaddr_in (IPv4)
```c
struct sockaddr_in {
    sa_family_t    sin_family;  // AF_INET
    in_port_t      sin_port;    // Port number (network byte order)
    struct in_addr sin_addr;    // IP address
};

struct in_addr {
    uint32_t s_addr;            // IP address (network byte order)
};
```

### sockaddr_in6 (IPv6)
```c
struct sockaddr_in6 {
    sa_family_t     sin6_family;   // AF_INET6
    in_port_t       sin6_port;     // Port number
    uint32_t        sin6_flowinfo; // Flow information
    struct in6_addr sin6_addr;     // IPv6 address
    uint32_t        sin6_scope_id; // Scope ID
};
```

---

## Tips & Notes

💡 **Tip:** Use `netstat -tuln` to view open ports on your system

💡 **Tip:** Use `ping` to test network connectivity

💡 **Tip:** Use `nslookup` or `dig` to query DNS

📝 **Note:** Ports below 1024 require root/administrator privileges

📝 **Note:** Always use network byte order for addresses and ports

⚠️ **Warning:** Never hardcode IP addresses in production code

---

## Summary

- Networks allow computers to communicate
- Sockets are endpoints identified by IP:Port
- TCP provides reliable, ordered delivery
- UDP provides fast, connectionless communication
- Servers listen, clients connect
- Always convert to network byte order

---

## Next Module

In Module 2, we'll start writing actual TCP socket code!
