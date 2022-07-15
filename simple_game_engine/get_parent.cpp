#include <iostream>
#include <string>
#include <vector>

class O_parent; //Forward declare parent class, usable in limited contexts
class O_child {
public:
    std::string s_name_child;
    const O_parent& o_parent;

    //Declare relevant function, a definition wouldn't be valid while
    //parent is an incomplete type
    void f_print_parent_name(const O_parent& o_parent);
};
class O_parent {
public:
    O_child o_child;
    std::string s_name_parent;
};

//Now that parent is a complete type, define the function
void O_child::f_print_parent_name(const O_parent& o_parent) {
    o_parent = o_parent;
    // std::cout << o_parent.s_name_parent;
}

int main() {
    O_child o_child;
    o_child.s_name_child = "childname";
    O_parent o_parent;
    o_parent.s_name_parent = "parentname";

    o_parent.o_child = o_child;

    o_child.f_print_parent_name(o_parent);

    return 0;
} 
//g++ -o get_parent get_parent.cpp