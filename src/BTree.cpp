
#include "Btree.hpp"

// class Btreenode;
// class BTree {
//     private:
//         int files_till_now, root_num;
//         char tablename[BPTREE_MAX_FILE_PATH_SIZE];;
//     void write_node(int file_num, Btreenode n);
//     void update_meta_deta();

// public:
//     BTree();
//     BTree(char tablename[]);

//     void read_node(int filenum, Btreenode& n);
//     int insert_record(int primary_key, int record_num);
//     Btreenode search_leaf(int primary_key);
//     int get_record(int primary_key);
// };

class Btreenode {
private:
    bool leaf;
    std::vector<int> pointers;
    std::vector<int> keys;
    int next_node;
public:
    Btreenode();
    Btreenode(bool makeleaf) {
        leaf = makeleaf;
        next_node = -1;
    }

    bool isleaf() {
        return leaf;
    }

    void set_leaf(bool val) {
        leaf = val;
    }

    int num_keys() {
        return keys.size();
    }

    int num_pointers() {
        return pointers.size();
    }

    int get_keys(int i) {
        return keys[i-1];
    }
    
    int get_pointers(int i) {
        return pointers[i-1];
    }

    void set_next(int x) {
        next_node = x;
    }

    int get_next() {
        return next_node;
    }

    void push_key(int val) {
        keys.push_back(val);
    }

    void push_pointers(int val) {
        pointers.push_back(val);
    }

    void clear_data() {
        keys.clear();
        pointers.clear();
    }

    int* get_keys_add() {
        return &keys[0];
    }

    int* get_pointers_add() {
        return &pointers[0];
    }

    ~Btreenode() {
        clear_data();
    }


    int get_next_key(int search_key) {
        return (std::lower_bound(keys.begin(), keys.end(), search_key) - keys.begin());
    }

    int search_key(int search_key) {
        return std::binary_search(keys.begin(), keys.end(), search_key);
    }

    bool full() {
        if(leaf) {
            if(pointers.size() < BTREE_MAX_PER_KEYS_NODE - 1) return false;
            else return true;
        }
        if(pointers.size() < BTREE_MAX_PER_KEYS_NODE) return false;
        else return true;
    }



    void insert_key(int key, int point) {
        int pos = get_next_key(key);
        keys.insert(keys.begin() + pos, key);

        if(leaf) pointers.insert(pointers.begin()+pos, point);
        else pointers.insert(pointers.begin()+pos+1, point);
    }



    void copy_first(Btreenode *node , int n) {
        keys.clear();
        pointers.clear();

        int limit = node.num_pointers();
        for(int  i = n+1; i <= limit; i++) {
            pointers.push_back(node.get_pointers(i));
        }

        int limit = node.num_keys();
        for(int i = n+1; i <= limit; i++) {
            keys.push_back(node.get_keys(i));
        }
    }


    friend std::ofstream& operator<<(std::ofstream& os , const Btreenode& en) {
        os << en.leaf <<" ";
        os << (int) en.keys.size() << " ";

        for (unsigned int i = 0; i <en.keys.size(); i++) {
            os << en.keys[i] << " ";
        }

        os << (int) en.pointers.size() << " ";

        for (unsigned int i = 0; i < en.pointers.size(); i++) {
            os << en.pointers[i] << " ";
        }

        os << en.next_node;
        return os;
    }


    friend std::ifstream& operator>>(std::ifstream& is, const Btreenode en) {
        int ts;
        is >> en.leaf;
        is >> ts;
        en.keys.resize(ts);
        for(int i = 0; i < ts; i++) {
            is >> en.keys[i];
        }

        is >> ts;
        en.pointers.resize(ts);
        for(int i = 0; i < ts; i++) {
            is >> en.pointers[i];
        }

        is >> en.next_node;
        return is;
    }

    Btreenode& operator=(const Btreenode& en) {
        if(this!= &en) {
            leaf = en.leaf;
            keys.assign(en.keys.begin(), en.keys.end());
            pointers.assign(en.pointers.begin(), en.pointers.end())
        }
        return *this;
    }
};