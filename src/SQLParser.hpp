#ifndef SQLPARSER_HPP
#define SQLPARSER_HPP

//imports



namespace sql {
    class SQLParser {
    public:
        static SQLParserResult* parseSQLString(const char* sql);

        static SQLParserResult* parseSQLString(const std::string& sql);

    private:
        SQLParser();
    };
}


#endif