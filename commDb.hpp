
#include "main.h"
#include "sqlite3.h"


class CommonSqliteDb
{
private:
    sqlite3        *m_db;
    string          m_lsDataPath;

public:
    CommonSqliteDb(string lsDataPath) {
        m_db = NULL;
    }

    ~CommonSqliteDb() {
        if(m_db != NULL) {
            sqlite3_close(m_db);
        }
    }

    bool dbConnection(string lsDbFile) {
        int nErr;

        string lsDbPath = this->m_lsDataPath + lsDbFile;

        if(this->m_db) {
            LOG(LOG_CRT,"Error: DB Connection state is already up\n");
            return true;
        }
        nErr = sqlite3_open(lsDbPath.c_str(), &m_db);
        if (nErr != SQLITE_OK) {

            LOG(LOG_CRT, "Cannot open database: %s\n", sqlite3_errmsg(m_db));
            sqlite3_close(m_db);

            return false;
        }

        return true;

    }

    bool dbCreateTable(string lsTableName, string lsCreateSql) {
        int nErr;
        char *err_msg = 0;
        string check_sql = format("SELECT name FROM sqlite_master WHERE type='table' AND name='{%s}'", lsTableName.c_str());

        nErr = sqlite3_exec(m_db, check_sql.c_str(), 0, 0, &err_msg);

        if (nErr != SQLITE_OK ) {

            LOG(LOG_CRT, "SQL error: %s\n", err_msg);

            sqlite3_free(err_msg);        
            sqlite3_close(m_db);

            return false;
        }
    }



};


