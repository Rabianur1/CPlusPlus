#include <iostream>
using namespace std;

//Tool class
class Tool{
protected:
  int strength;
  char type;

public:
  Tool() : strength(0), type(' '){} //Default constructor
  Tool(int str, char t) : strength(str), type(t){} //Constructor with parameters
  void setStrength(int str){ strength = str;}

  char getType() const{return type;}

  int getStrength() const{return strength;}

  virtual bool fight(Tool &opponent) = 0; //Pure virtual function, polymorphism
};

// Rock class
class Rock : public Tool{
public:
  Rock(int str){
    strength = str;
    type = 'r';
  }

  bool fight(Tool &opponent) override{
    int myStrength = strength;

    if (opponent.getType() == 's'){
      myStrength *= 2;}
    else if (opponent.getType() == 'p'){
      myStrength /= 2;}
    return myStrength > opponent.getStrength();
  }
};

// Paper class
class Paper : public Tool{
public:
  Paper(int str){
    strength = str;
    type = 'p';
  }

  bool fight(Tool &opponent) override{
    int myStrength = strength;

    if (opponent.getType() == 'r'){
      myStrength *= 2;}
    else if (opponent.getType() == 's'){
      myStrength /= 2;}
    
    return myStrength > opponent.getStrength();
  }
};

// Scissors class
class Scissors : public Tool{
public:
  Scissors(int str){
    strength = str;
    type = 's';
  }

  bool fight(Tool &opponent) override{
    int myStrength = strength;

    if (opponent.getType() == 'p'){
      myStrength *= 2;}
    else if (opponent.getType() == 'r'){
      myStrength /= 2;}
    
    return myStrength > opponent.getStrength();
  }
};

// Main function to test the fight logic
int main(){
  Scissors s1(5);
  Paper p1(7);
  Rock r1(15);

  cout << "Scissors(5) vs Paper(7): " << s1.fight(p1) << " / "<< "Paper(7) vs Scissors(5): " << p1.fight(s1) << endl;
  cout << "Paper(7) vs Rock(15): " << p1.fight(r1) << " /  "<< "Rock(15) vs Paper(7): " << r1.fight(p1) << endl;
  cout << "Rock(15) vs Scissors(5): " << r1.fight(s1) << " / "<< "Scissors(5) vs Rock(15): " << s1.fight(r1) << endl;

  return 0;}