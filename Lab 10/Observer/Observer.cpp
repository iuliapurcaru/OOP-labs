#include <iostream>
#include <list>

using namespace std;

class Subscriber 
{
public:

    virtual void update(string& message_update) = 0;
};

class Publisher
{
private:
    list<Subscriber*> subscribers_list;
    string message;

public:

    void subscribe(Subscriber* subscriber)
    {
        subscribers_list.push_back(subscriber);
    }

    void unsubscribe(Subscriber* subscriber) 
    {
        subscribers_list.remove(subscriber);
    }

    void notifySubscribers() 
    {
        list<Subscriber*>::iterator iterator = subscribers_list.begin();

        while (iterator != subscribers_list.end())
        {
            (*iterator)->update(message);
            iterator++;
        }
    }

    void action() 
    {
        this->message = "New action from publisher!";
        cout << "Subscriber notifications:" << endl;
        notifySubscribers();
    }

    void mainBusinessLogic() 
    {
        this->message = "Business message...";
        notifySubscribers();
    }
};

class ConcreteSubscriber : public Subscriber 
{
private:
    string message_update;
    Publisher& publisher;
    static int static_number;
    int number;

public:
    ConcreteSubscriber(Publisher& pub) : publisher(pub) 
    {
        this->publisher.subscribe(this);
        cout << "User " << ++ConcreteSubscriber::static_number << " just subscribed!"  << endl;
        this->number = ConcreteSubscriber::static_number;
    }

    ~ConcreteSubscriber() {}

    void update(string& msg) 
    {
        message_update = msg;
        notification();
    }

    void unsubscribe() 
    {
        publisher.unsubscribe(this);
        cout << "User " << number << " unsubscribed." << endl;
    }

    void notification()
    {
        cout << "Subscriber " << this->number << " -> New notification: " << this->message_update << endl;
    }
};

int ConcreteSubscriber::static_number = 0;

int main() 
{
    
    Publisher* publisher = new Publisher;

    ConcreteSubscriber* user1 = new ConcreteSubscriber(*publisher);
    ConcreteSubscriber* user2 = new ConcreteSubscriber(*publisher);

    cout << endl;

    publisher->action();
    cout << endl;

    user2->unsubscribe();
    ConcreteSubscriber* user3 = new ConcreteSubscriber(*publisher);
    cout << endl;

    publisher->action();
    cout << endl;

    user2->unsubscribe();
    ConcreteSubscriber* user4 = new ConcreteSubscriber(*publisher);
    ConcreteSubscriber* user5 = new ConcreteSubscriber(*publisher);
    cout << endl;

    publisher->action();
    cout << endl;

    user1->unsubscribe();
    user3->unsubscribe();

    delete user1;
    delete user2;
    delete user3;
    delete user4;
    delete user5;
    delete publisher;

    return 0;
}

/*
Avantaje:
- pot fi adaugati membrii noi (subscribers) foarte usor
- ofera creatorului obiectului (publisher) un grad de independenta fata de subscriber

Dezavantaje:
- pattern-ul trimite notificari tuturor membrilor desi unii membri nu au nevoie de aceste notificari

*/