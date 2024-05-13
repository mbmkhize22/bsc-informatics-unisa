#include <iostream>
#include <stack>
#include <string>

using namespace std;

void displayClass(std::stack<std::string> myStack)
{
   while (!myStack.empty())
      {
         std::cout << myStack.top() << "\n";
         myStack.pop();
     }
}

int main()
{
    //Q!
    std::stack<std::string> stackClass;
    stackClass.push("John");
    stackClass.push("Peter");
    stackClass.push("Mary");
    stackClass.push("Fred");
    int size = stackClass.size();
    while (!stackClass.empty())
    {
        std::cout << stackClass.top();
        //stackClass.pop();
    }

    std::cout << "the size of the class: " << size;
    cout << "END Q1\n\n" << endl;

    //std::stack<std::string> stackClass2;
    stackClass.push("John");
    stackClass.push("Peter");
    stackClass.push("Mary");
    displayClass(stackClass);
    cout << "END Q2\n\n" << endl;

    return 0;
}
