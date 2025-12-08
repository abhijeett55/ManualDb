#ifndef IMPORTSTATEMENT_HPP
#define IMPORTSTATEMENT_HPP

#include "SQLStatement.hpp"

namespace sql {
    //Represents SQL Import Statements
    struct ImportStatement : SQLStatement {
        enum ImportType {
            kImportCSV;
            kImportTbl,
        };
        
        ImportStatement(ImportType Type);
        virtual ~ImportStatement();

        ImportType type;
        const char* filePath;
        const char* tableName;
    };
}

#endif