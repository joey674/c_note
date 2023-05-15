#include <iostream>
#include <list>

class A {
public:
    int* p;
public:
    A() {
        p = new int(10);
        std::cout << "using A(),p= "
            << p
            << std::endl;
    }
    A(const A& a) {
        p = new int(10);
        memcpy(p, a.p, 10 * sizeof(int));
        std::cout << "using A(const A&),p= "
            << p
            << std::endl;
    }
    A(A&& a) {
        this->p = a.p;
        a.p = nullptr;
        std::cout << "using A(A&&),p= "
            << p
            << std::endl;
    }
    ~A() {
        if (p != nullptr) {
            delete[]p;
            p = nullptr;
            std::cout << "using ~A(),[a.p is now deleted]" << std::endl;
        }
        else {
            std::cout << "using ~A(),[a.p is already deleted]" << std::endl;
        }
    }
};


void test1() {
    std::cout << "...start test1..." << std::endl;

    std::list<A> list;
    list.push_back(A());//A()is right value
    auto& ref0 = list.front();
    std::cout << "list.push_back(A())" << ref0.p << std::endl;
    list.pop_back();
    
    A a;
    list.push_back(a);
    auto& ref1 = list.front();
    std::cout << "list.push_back(a)" << ref1.p << std::endl;
    list.pop_back();




    std::cout << "...end test1..." << std::endl;
}