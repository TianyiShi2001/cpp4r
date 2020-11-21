#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

vector<int> return_a_vector() {
    vector<int> res{ 1,2,3 };
    printf("res inside function: %p\n", &res);
    return res;
}

class MyClass
{
public:
    vector<int> inner;
    MyClass(vector<int> v) : inner{ v } {};
    // ~MyClass();
};


class Person {
public:
    Person() : name{ "" } {}
    string name;
    void set_name(string n) {
        name = n;
    }
};

class Post {
    string title, content;
public:
    Post(string t, string c) : title{ t }, content{ c }{};
};


int main() {
    string title = "some title";
    string content = "very long post...";
    Post post(title, content);

    auto v = return_a_vector();
    printf("res after assignment: %p\n", &v);

    MyClass obj(std::move(v));
    printf("addr of inner vec: %p\n", &obj.inner);
    // cout << v[0] << endl; // ! Segmentation Fault

    Person p;
    p.set_name("John");
}