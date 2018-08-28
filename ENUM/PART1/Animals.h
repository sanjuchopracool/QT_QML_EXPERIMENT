#ifndef ANIMALS_H
#define ANIMALS_H

#include <QObject>

class Animal : public QObject
{
    Q_OBJECT
public:
    explicit Animal(QObject *parent = nullptr);

    enum Type
    {
        Mammals = 5,
        Birds = 8,
        Reptiles,
        Fish = 200,
        Amphibians
    };
    Q_ENUM(Type)

    Type type() const;

    enum TypeSmallLetter
    {
        mammals,
        birds,
        reptiles,
        fish,
        amphibians
    };
    Q_ENUM(TypeSmallLetter)
};

#endif // ANIMALS_H
