#include <stdio.h>       
#include <stdlib.h>      
#include <string.h>      
#include <errno.h>       
#include <unistd.h>      
#include <strings.h>     
#include <signal.h>      
#include <pthread.h>     
#include <strings.h>     
                         
#include <sys/stat.h>    
#include <sys/time.h>    
#include <sys/types.h>   
#include <sys/socket.h>  
#include <sys/ipc.h>     
#include <sys/shm.h>     
                         
#include <sys/socket.h>
#include <netinet/in.h>  
#include <arpa/inet.h>   
#include <stdint.h>


#include <iostream>
#include <vector>
#include <list>


#include <string>
#include <iostream>
#include "util.hpp"
#if 0
enum {
    LOG_NONE = 0, 
    LOG_CRT,
    LOG_MAJ,
    LOG_MIN,
    LOG_INF,
    LOG_DBG,
    LOG_TRC
} LOG_LEVEL;
#endif

#define LOG(l,f,a...)   printf("< %-12s : %4d > [%s] "f,__FILE__,__LINE__,__func__,##a)
//sa_log(l,"< %-12s : %4d > "f,__FILE__,__LINE__,##a);

using namespace std;

std::string format(const char* format, ...);



