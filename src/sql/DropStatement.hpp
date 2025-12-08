#ifndef DROPSTATEMENT_HPP
#define DROPSTATEMENT_HPP
#include "SQLStatement.hpp"

namespace sql {

    // Represent SQL Delete Statements.
    // Example - "DROP TABLE students;"
    struct DropStatement : SQLStatement {
        enum EntityType {
            kTable,
            kSchema,
            kIndex,
            kView,
            kPreparedStatement
        };

        DropStatement(EntityType type);
        virtual ~DropStatement();

        EntityType type;
        char* name;
    };
}



#endif