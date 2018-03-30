#include <iostream>
#include <sstream>
#include <string>

class tree_t
{
private:
    struct node_t {
        node_t * left;
        node_t * right;
        int value;
    };
private:
    node_t * root_;
public:
	tree_t() {
        root_ = nullptr;
    }
	
    void insert(int value);
    bool find(int value) const;
    void print(std::ostream & stream) const;
};

