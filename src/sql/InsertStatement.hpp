#ifndef INSERTSTATEMENT_HPP
#define INSERTSTATEMENT_HPP


#include "SQLStatement.hpp"

namespace sql {
    struct InsertStatement : SQLStatement {
        /** 
         * Represent SQL Insert Statements.
         * Example - "INSERT INTO students VALUES('Abhijeet', 123456,'Mumbai', 0.99)"
         */
        enum InsertType {
            kInsertValues,
            kInsertSelect
        };

        InsertStatement(InsertType type);
        virtual ~InsertStatement();

        InsertType type;
        char* tableName;
        std::vector<char*>* columns;
        std::vector<Expr*>* values;
        SelectStatement* select;
    };
}

#endif