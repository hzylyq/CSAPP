#include "header.h"

int main(int argc, char const *argv[])
{
    struct addrinfo *p, *listp, hints;

    char buf[MAXLINE];

    int rc, flags;

    if (argc != 2)
    {
        fprintf(stderr, "usage: %s <domain name>""\n", argv[0]);
    }

    // Get a list of addrinfo records
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if ((rc = getaddrinfo(argv[1], NULL, &hints, &listp)) != 0)
    {
        fprintf(stderr, "getaddrinfo error:%s\n", gai_strerror(rc));
        exit(1);
    }

    // Walk the list and display each IP address
    flags = NI_NUMERICHOST;
    
    for(p = listp; p ; p = p->ai_next)
    {
        Getnameinfo(p->ai_addr, p->ai_addrlen, buf, MAXLINE, NULL, 0, flags);
        printf("%s\n", buf);
    }
    
    Freeaddrinfo(listp);

    return 0;
}