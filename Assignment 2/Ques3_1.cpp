//Question 3 — Game Engine Entity System
//Part A —this Pointer and Method Chaining

#include<iostream>
using namespace std;

class Entity{
    string name;
    int health;
    int level;
    string type;

    public:

    Entity& setName(const string& name){
        this-> name = name;
        return *this;
    }
    Entity& setHealth(int health){
        this -> health= health;
        return *this;
    }
    Entity& setLevel(int level){
        this-> level = level;
        return *this;
    }
    Entity& setType(const string& type){
        this->type = type;
        return *this;
    }
    
    string getName() const{
        return name;
    }

    int getHealth() const {
        return health;
    }

    int getLevel()const{
        return level;
    }

    string getType() const{
        return type;
    }

    

    void displayInfo() const{
        cout<< "------------------------------" << endl;
        cout<< "Name\t : " << getName() << endl;
        cout<< "Health\t : " << getHealth() << endl;
        cout<< "Level\t : "<< getLevel() << endl;
        cout<< "Type\t : "<<getType() << endl;
        cout<< "------------------------------"<<endl; 
    }

    

};

int main(){

    Entity player , enemy, item;
    player.setName("Aragorn").setHealth(100).setLevel(10).setType("Player");
    enemy.setName("Orc").setHealth(60).setLevel(5).setType("Enemy");
    item.setName("HealthPotion").setHealth(0).setLevel(1).setType("Item");

    player.displayInfo();
    enemy.displayInfo();
    item.displayInfo();
}