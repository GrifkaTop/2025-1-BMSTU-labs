#pragma once
#include <iostream>
#include <string>

class Article {
protected:
    std::string name;
public:
    Article(const std::string& name);
    virtual ~Article();
    virtual void show() const = 0;
};

class Product : public Article {
public:
    Product(const std::string& name);
    ~Product() override;
    void show() const override;
};

class Dairy : public Product {
public:
    Dairy(const std::string& name);
    ~Dairy() override;
    void show() const override;
};

class Toy : public Article {
public:
    Toy(const std::string& name);
    ~Toy() override;
    void show() const override;
};

class Bear : public Toy {
public:
    Bear(const std::string& name);
    ~Bear() override;
    void show() const override;
};