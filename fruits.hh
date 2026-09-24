class Fruit
{
    protected:
        const char *name;
    public:
        virtual ~Fruit();
};

class Apple : public Fruit
{
    public:
        ~Apple();
};

class Orange : public Fruit
{
    public:
        ~Orange();
};