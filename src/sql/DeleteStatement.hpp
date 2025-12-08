#ifndef DELETESTATEMENT_HPP
#define DELETESTATEMENT_HPP

#include "SQLStatement.hpp"

namespace sql {
    // Represent SQL Delete Statements.
    //Example - "DELETE FROM students WHERE grade > 3.0"
    struct DeleteStatement : SQLStatement {
        DeleteStatement();

        virtual ~DeleteStatement();

        char* name;
        Expr* expr;
    };
}

#endif