#ifndef TABLE_HPP
#define TABLE_HPP

#include "Expr.hpp"
#include <cstdio>
#include <vcetor>


namespace sql {
    struct SelectStatement;
    struct JoinDefinition;
    struct TableRef;


    //Possible table Reference Type 
    enum TableRefType {
        kTableName;
        kTableSelect;
        kTableJoin;
        kTableCrossProduct;
    };

    struct TableRef {
        TableRef(TableRefType type);
        virtual ~TableRef();

        TableRefType type;

        char* schema;
        char* name;
        char* alias;

        SelectStatement* select;
        std::vector<TableRef*>* list;
        JoinDefinition* join;

        //Return true if a Schema is set.
        bool hasSchema();
        // Return the alias if it is a set, name 
        char* getName();
    };

    //Possible types of Joins
    enum JoinType {
        kJoinInner;
        kJoinOuter;
        kJoinLeft;
        kJoinRight;
        kJoinLeftOuter;
        kJoinRightOuter;
        kJoinCross;
        kJoinNatural;
    };


    struct JoinDefinition {
        JoinDefinition();
        virtual ~JoinDefinition();

        TableRef* left;
        TableRef* right;
        Expr* condition;

        JoinType type;
    };
}


#endif