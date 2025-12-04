
#ifdef DEFINITIONS_HPP
#define DEFINITIONS_HPP

#include <iostream>

#include <utility>
#include <algorithm>


// All standard Template Libraray
#include <vector>
#include <string>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <map>


#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cstdio>
#include <iomanip>
#include <iomanip>
#include <numeric>
#include <thread>
#include <chrono>

#include <fstream>



constexpr int  BTREE_SEARCH_NOT_FOUND -1
constexpr int  BTREE_MAX_FILE_PATH_SIZE 1000
constexpr int  BTREE_MAX_KEYS_PER_NODE 50


constexpr int ERROR 0
constexpr int SUCCESS 1


constexpr int VARCHAR 100
constexpr int MAX_ATTR 30
constexpr int MAX_NAME 50


#define MAX_NODE 30
using namespace std;

struct col_details{
    char col_name[20];
    int type;
    int size;
};

struct table {
    int prefix[MAX_ATTR + 1];
    col_details col[MAX_ATTR + 1];

    //Attributes
    int count = 0;
    char name[20]; //name of table
    int size;
    int data_size;
    int BLOCKSIZE;
    FILE *fp;
    void *blockbuf;
    int rec_count; // no of entries in table

};


//available
extern void create();
extern int search_table(char tab_name[]);
extern void insert();
extern void search();
extern void show_table();
extern int insert_record(int primary_key, int record_num);
extern FILE *open_file(char t_name[], char perm[]);
extern int store_meta_data(struct table *t_ptr);

#endif
