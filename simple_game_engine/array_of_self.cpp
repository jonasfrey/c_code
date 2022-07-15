#include <vector>
#include <string>
#include <iostream>

class O_containing_o_obj;

class O_obj
{
    public: 
    std::string s_name;

    void f_print_names(
        std::vector< O_containing_o_obj > *a_o_containing_o_obj
    );
};

class O_containing_o_obj
{
   public: 
      O_obj o_obj; 
};

void O_obj::f_print_names(
        std::vector< O_containing_o_obj > *a_o_containing_o_obj
    )
{
    for (auto & o_containing_o_obj : *a_o_containing_o_obj) {
        std::cout << o_containing_o_obj.o_obj.s_name;
    }
}

int main(){
    O_obj o_obj; 
    o_obj.s_name = "test";
    O_containing_o_obj o_containing_o_obj; 
    o_containing_o_obj.o_obj = o_obj;

    std::vector< O_containing_o_obj > a_o_containing_o_obj;
    a_o_containing_o_obj.push_back(o_containing_o_obj);

    o_obj.f_print_names(&a_o_containing_o_obj);

    return 0;
}
// g++ -o array_of_self array_of_self.cpp