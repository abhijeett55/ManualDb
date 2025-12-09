#ifndef SQLHELPER_HPP
#define SQLHELPER_HPP

//imports

namespace sql {
    //Summary of the given SQLStatement
    void printStatementInfo(const SQLStatement* stmt);
    
    void printSelectStatementInfo(const SelectStatement* stmt);

    void printImportStatementInfo(const ImportStatement* stmt);

    void printInsertStatementInfo(const InsertStatement* stmt);

    void printCreateStatementInfo(const CreateStatement* stmt);

    void printExperssion(Expr* expr, uintmax_t num_indent);
}


#endif