#include <iostream>
#include "fruits.hh"

int main(void)
{
    Apple *apple = new Apple;
    Orange *orange = new Orange;

    Fruit* appleFruit = dynamic_cast<Fruit*>(apple);

    if(appleFruit != nullptr)
        printf("the apple is fruit\n");

    Apple* appleFruit2 = dynamic_cast<Apple*>(appleFruit);
    if(appleFruit2 != nullptr)
        printf("the fruit is an apple\n");

    Orange *otherOrange = dynamic_cast<Orange*>(appleFruit);
    if(otherOrange != nullptr)
        printf("the fruit is an orange\n");   
    else
        printf("the fruit is not an orange\n");   

    std::cout << typeid(otherOrange).name() << std::endl;
    std::cout << typeid(appleFruit).name() << std::endl;
    std::cout << typeid(appleFruit2).name() << std::endl;

    //Get only the name of the type without PX
    const char* type_name = typeid(otherOrange).name();
    std::string long_name(type_name); 
    std::string short_name = long_name.substr(2, long_name.length());
    std::cout << short_name << std::endl;

}