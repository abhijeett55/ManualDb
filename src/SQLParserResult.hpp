#ifndef SQLPARSERRESULT_HPP
#define SQLPARSERRESULT_HPP

namespace sql {
    class SQLParserResult {
    public:
        SQLParserResult();

        SQLParserResult(SQLStatement* stmt);

        virtual ~SQLParserResult();

        bool isValid() const;

        size_t size() const;

        const char* errorMsg() const;

        int errorLine() const;

        int errorColumn() const;

        const SQLStatement* getStatement(int index )const;

        SQLStatement* getMutableStatement(int index);

        void addStatement(SQLStatement* stmt);

        void setIsValid(bool isValid);

        void setErrorDetails(char* errorMsg, int errorLine, int errorColumn);

        private:
            std::vector<SQLStatement*> check_statements;

            bool check_isValid;

            char* check_Msg;

            int check_errorLine;

            int check_errorColumn;
    };
}


#endif
