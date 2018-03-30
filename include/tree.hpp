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
	tree_t()
	{
        root_ = nullptr;
    }
	
    void insert(int value)
     {
        if (root_ == nullptr)
        {
            root_ = new node_t;
            root_->value = value;
            root_->left = nullptr;
            root_->right = nullptr;
        }
        else
        {
            node_t* ptr_ = root_;
            while (ptr_ != nullptr)
            {
                if (value < ptr_->value)
                {
                    if (ptr_->left == nullptr)
                    {
                        ptr_->left = new node_t;
                        ptr_ = ptr_->left;
                        ptr_->value = value;
                        ptr_->left = nullptr;
                        ptr_->right = nullptr;
                        return;
                    }
                    else
                    {
                        ptr_ = ptr_->left;
                    }
                }
                else if (value >= ptr_->value)
                {
                    if (ptr_->right == nullptr)
                    {
                        ptr_->right = new node_t;
                        ptr_ = ptr_->right;
                        ptr_->value = value;
                        ptr_->left = nullptr;
                        ptr_->right = nullptr;
                        return;
                    }
                    else
                    {
                        ptr_ = ptr_->right;
                    }
                }
            }
        }
    }
    
    bool find(int value) const
    {
        if (root_ == nullptr)
        {
            return false;
        }
        else
        {
            node_t* ptr_ = root_;
            while (ptr_ != nullptr)
            {
                if (ptr_->value == value)
                {
                    return true;
                }
                else if (ptr_->value < value)
                {
                    ptr_ = ptr_->right;
                }
                else if (ptr_->value > value)
                {
                    ptr_ = ptr_->left;
                }
            }
            return false;
        }
    }
   void print(std::ostream& stream, node_t* ptr_, size_t i) const
    {
        if (ptr_->right != nullptr)
        {
            i++;
            print(stream, ptr_->right, i);
            i--;
        }
        for (size_t k = 0; k < i; k++)
        {
            stream << "--";
        }
        stream << ptr_->value << std::endl;
        if (ptr_->left != nullptr)
        {
            i++;
            print(stream, ptr_->left, i);
            i--;
        }
    }
}
