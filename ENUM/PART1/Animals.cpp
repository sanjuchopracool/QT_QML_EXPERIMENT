#include "Animals.h"

Animal::Animal(QObject *parent) : QObject(parent)
{

}

Animal::Type Animal::type() const
{
    return  Mammals;
}
