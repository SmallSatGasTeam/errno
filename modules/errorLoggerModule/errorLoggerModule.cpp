#include"errorLoggerModule.hpp"

static int ErrorLoggerModule::callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

bool ErrorLoggerModule::receive(Message* message){
    if(!message){return 0;}

    unsigned int action = message->action;
    std::string body = message->body;

    switch(action){
      case ERROR:
        writeToDatabase(body);
        break;
      // default:
      //   printf("Unmatching Message Recieved By ErrorLogger\n");
    }
    return 1;
}

bool ErrorLoggerModule::status(){
  return 1; //TODO This needs to do appropriate checks
}

bool ErrorLoggerModule::writeToDatabase(std::string messageBody){
  // printf("ErrorLoggerModule:PSEUDO write to database\n"); //TODO needs to actually write to database
  printf("Writing error to database\n");

  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;
  std::string sql;

  /* Open database */
  rc = sqlite3_open("test.db", &db);
  if( rc ){
     fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
     return(0);
  }else{
     fprintf(stderr, "Opened database successfully\n");
  }

  /* Create SQL statement */
  sql = "INSERT INTO errors (one) "  \
        "VALUES (\"" + messageBody +"\");";

  /* Execute SQL statement */
  rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
  if( rc != SQLITE_OK ){
     fprintf(stderr, "SQL error: %s\n", zErrMsg);
     sqlite3_free(zErrMsg);
  }else{
     fprintf(stdout, "Records created successfully\n");
  }
  sqlite3_close(db);

  return 1;
}
