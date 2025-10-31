#ifndef B6BAAFF0_63CD_496F_B091_EF0218030E77
#define B6BAAFF0_63CD_496F_B091_EF0218030E77

class Observer{
    public:
    virtual void update(int x) = 0;
    virtual ~Observer(){};
};

class Display : public Observer{
    public:
        void update(int x) override;
};

void say_hello();

#endif /*  */
