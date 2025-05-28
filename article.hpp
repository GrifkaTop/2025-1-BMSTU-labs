#pragma once
#include <iostream>
#include <cstring>

class Article {
protected:
    char* name; 
public:
    Article(const char* name);
    virtual ~Article();
    virtual void show() const = 0;
};

class Product : public Article {
protected:
    char* production_date;
public:
    Product(const char* name, const char* date);
    virtual ~Product() override;
    void show() const override;
};

class Dairy : public Product {
private:
    int expiry_days;
public:
    Dairy(const char* name, const char* date, int expiry);
    ~Dairy() override;
    void show() const override;
};

class Toy : public Article {
protected:
    int recommended_age;
public:
    Toy(const char* name, int age);
    virtual ~Toy() override;
    void show() const override;
};

class Bear : public Toy {
private:
    char* color; 
public:
    Bear(const char* name, int age, const char* color);
    ~Bear() override;
    void show() const override;
};