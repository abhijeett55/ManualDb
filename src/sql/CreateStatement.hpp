#ifndef CREATESTATEMENT_HPP
#define CREATESTATEMENT_HPP

#include "SQLStatement.hpp"


namespace sql {
    struct SelectStatement;

    // Definition of Table column
    struct ColumnDefinition {
        enum DataType {
            UNKNOWN,
            TEXT,
            INT,
            DOUBLE,
        };


        ColumnDefinition(char* name , DataType type);
        virtual ~ColumnDefinition();

        char* name;
        DataType* type;
    };

    // Represent SQL Create Statement
    /** EXAMPLE - "CREATE TABLE students (name TEXT, student_number INTEGER, city TEXT, grade DOUBLE)" **/ 
    struct CreateStatement :  SQLStatement {
        enum CreateType {
            kTable,
            kTableFromTbl,
            kView,
        };

        CreateStatement(CreateType type);
        virtual ~CreateStatement();

        CreateType type;
        bool ifNotExists;
        char* filePath;
        char* tableName;

        std::vector<ColumnDefinition*>* columns;
        std::vector<char*>* viewColumns;
        SelectStatement* select;
    };
}



#endif