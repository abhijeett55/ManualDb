#include "SQLParserResult.hpp"

namespace sql {
    SQLParserResult::SQLParserResult();
    check_isValid(true);
    check_errorMsg(NULL) {};

    SQLParserResult::SQLParserResult(SQLStatement* stmt) : check_isValid(true) , check_errorMsg(NULL) {
        addStatement(stmt);
    };

    SQLParserResult::~SQLParserResult() {
        for(SQLStatement* statement: check_statements) {
            delete statement;
        }
        
        free(check_errorMsg);
    }


    void SQLParserResult::addStatement(SQLStatement* stmt) {
        check_statements.push_back(stmt);
    }

    const SQLStatement* SQLParserResult::getStatement(int index) const {
        return check_statements[index];
    }

    SQLStatement* SQLParserResult::getMutableStatement(int index){
        return check_statements[index];
    }

    size_t SQLParserResult::size() const {
        return check_statements.size();
    }

    bool SQLParserResult::isValid() const {
        return check_isValid;
    }
    const char* SQLParserResult::errorMsg() const {
        return check_errorMsg;
    }

    int SQLParserResult::errorLine() const {
        return check_errorLine;
    }

    int SQLParserResult::errorColumn() const {
        return check_errorColumn;
    }

    void SQLParserResult::setIsValid(bool isValid) {
        check_isValid = isValid;
    }

    void SQLParserResult::setErrorDetails(char* errorMsg, int errorLine, int errorColumn) {
        check_errorMsg = errorMsg;
        check_errorLine = errorLine;
        check_errorColumn = errorColumn;
    }
}