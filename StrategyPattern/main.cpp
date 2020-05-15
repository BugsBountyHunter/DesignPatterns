#include <iostream>
#include <memory>

#define   __interface class

using namespace std;

//************************* Design Patterns - Strategy Pattern *************************//
/*
 * In Strategy pattern, a class behavior or its algorithm can be changed at run time. This type of design pattern comes under behavior pattern.
 * In Strategy pattern, we create objects which represent various strategies and a context object whose behavior varies as per its strategy object. The strategy object changes the executing algorithm of the context object.
 */

//************************* Implementation *************************//
/*
 * We are going to create a "IStrategy" interface defining an action and concrete strategy classes implementing the "IStrategy" interface.
 * "Context" is a class which uses a "IStrategy" interface.
 * "main", will use "Context" and "IStrategy" objects to demonstrate change in Context behaviour based on strategy it deploys or uses.
 */
//1-create strategy interface that's defining an action
__interface IStrategy {
public:
    virtual int doOperation(int num1, int num2) = 0;

    //virtual destructor
    //~IStrategy();
};

//2-  strategy classes (concrete strategy classes) that's implementing the Strategy interface
class OperationAdd : public IStrategy {
public:
    int doOperation(int num1, int num2) override {
        return num1 + num2;
    }
};

class OperationSubstract : public IStrategy {
public:
    int doOperation(int num1, int num2) override {
        return num1 - num2;
    }
};

class OperationMultiply : public IStrategy {
public:
    int doOperation(int num1, int num2) override {
        return num1 * num2;
    }
};

//3- context is a class which uses a Strategy.
class Context {
    //using  strategy
private:
    //NOTE: IStrategy:  is abstract, you can never create an object of that type. However, you can store a pointer to "IStrategy"  as a member of  "Context"class , this pointer member could then point to an instance of a (concrete) subclass of "IStrategy" interface.
    shared_ptr<IStrategy> strategy;

public:
    Context(IStrategy *strategy) : strategy(strategy) {}

    int executeStrategy(int num1, int num2) {
        return strategy->doOperation(num1, num2);
    }

};

// 4- In main method will use Context and strategy objects to demonstrate change in Context behaviour based on strategy it deploys or uses.
int main() {
    OperationAdd operationAdd;
    OperationSubstract operationSubstract;
    OperationMultiply operationMultiply;

    shared_ptr<Context> context = make_shared<Context>(&operationAdd);
    cout << context->executeStrategy(10, 5) << endl;

    context = make_shared<Context>(&operationSubstract);
    cout << context->executeStrategy(10, 5) << endl;

    context = make_shared<Context>(&operationMultiply);
    cout << context->executeStrategy(10, 5) << endl;
    return 0;


}
