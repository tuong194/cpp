#ifndef OBSERVER_H__
#define OBSERVER_H__

#include <vector>

class Observer{
    public:
    virtual void update(int x) = 0;
    virtual ~Observer(){};
};

class Display : public Observer{
    public:
        void update(int x) override;
};

class Logger : public Observer{
    public:
        void update(int x) override;
};

class Subject{
    private:
        std::vector<Observer*> obs;
        int state = 0;
        void notify(int x);
    public:
        void attach(Observer* o);
        void detach(Observer* o);
        void setState(int x);
        int getState() const { return state;};
};

#endif /*  */
