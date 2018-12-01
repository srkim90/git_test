#include "main.h"
#include "commDb.hpp"


/*
 * Process Main Function
 * ====================================
 */
int main(int argv, char * argc[])
{

    CommonSqliteDb * pDb = new CommonSqliteDb(string("./"));
    
    pDb->dbConnection(string("example.db"));
    pDb->dbCreateTable(string("CPG_ROUTE_RULE"), string(""));

    printf("1111112\n");
    printf("1111112111 new\n");

    return 0;
}

