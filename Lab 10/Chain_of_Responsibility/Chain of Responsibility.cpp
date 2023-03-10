#include <iostream>

using namespace std;

class Handler 
{
public:
    virtual Handler* setNext(Handler* handler) = 0;
    virtual string handleAction(string request) = 0;
};

class BaseHandler : public Handler 
{
public:
    Handler* next_handler;

    Handler* setNext(Handler* handler) 
    {
        this->next_handler = handler;
        return handler;
    }
    
    string handleAction(string request)
    {
        if (this->next_handler) 
        {
            return this->next_handler->handleAction(request);
        }

        return {};
    }
};

class ConcreteHandler1 : public BaseHandler 
{
public:
    string handleAction(string request) override 
    {
        if (request == "type 1") 
        {
            return "Handler 1 can handle type 1!\n";
        }
        else 
        {
            return BaseHandler::handleAction(request);
        }
    }
};

class ConcreteHandler2 : public BaseHandler 
{
public:
    string handleAction(string request)
    {
        if (request == "type 2") 
        {
            return "Handler 2 can handle type 2!\n";
        }
        else 
        {
            return BaseHandler::handleAction(request);
        }
    }
};

class ConcreteHandler3 : public BaseHandler
{
public:
    string handleAction(string request) 
    {
        if (request == "type 3")
        {
            return "Handler 3 can handle type 3!\n";
        }
        else 
        {
            return BaseHandler::handleAction(request);
        }
    }
};

void Client(Handler& handler, string request[]) 
{
    for (int i = 0; i < 3; i++) 
    {
        cout << "Request for " << request[i] << "." << endl;
        string result = handler.handleAction(request[i]);

        if (!result.empty()) 
        {
            cout << result;
        }
        else 
        {
            cout << "No one can handle " << request[i] << "." << endl;
        }
    }
}

int main() 
{
    string request_1[] = { "type 1", "type 4", "type 3" };
    string request_2[] = { "type 3", "type 2", "type 1" };
    
    ConcreteHandler1* one = new ConcreteHandler1;
    ConcreteHandler2* two = new ConcreteHandler2;
    ConcreteHandler3* three = new ConcreteHandler3;
    one->setNext(two)->setNext(three);

    cout << "Chain: one > two > three" << endl;
    Client(*one, request_1);
    cout << endl;
    Client(*one, request_2);
    cout << endl;

    delete one;
    delete two;
    delete three;

    return 0;
}

/*
Avantaje:
- sarcinile obiectelor sunt impartite ceea ce usureaza adaugarea si stergerea de noi sarcini
- utilizatorul care trimite cererea este separat de handler-ul care primeste cerinta

Dezavantaje:
- trecerea de la un handler la altul poate scade eficienta 
- exista riscul ca programul sa se blocheze daca nu exista niciun handler pentru un request primit
*/