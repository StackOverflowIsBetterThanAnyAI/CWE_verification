#pragma once

#include <stddef.h>
#include <stdlib.h>


/*
 * host_lookup函数
 */ 

#include <netdb.h> // 定义hostent结构体和 gethostbyaddr函数
#include <sys/socket.h> // 定义socklen_t宏
// 下面两个添加in_addr_t宏
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h> // 定义 inet_addr函数 


void validate_addr_form(char *user_supplied_addr);

// struct hostent *gethostbyaddr(const void *addr, socklen_t len, int type);


/*
 * copy_input函数
 */ 
#define MAX_SIZE 100

void die(const char*);

/*
 * select_item函数
 */ 

#include <stdio.h>

int GetUntrustedOffset(void);
