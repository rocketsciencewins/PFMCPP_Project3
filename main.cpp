/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.







struct CoffeeShop
{
    int numEmployees = 10;
    int numCoffeeMachines = 2;
    bool isOpen = true;
    std::string name = "The Nautical Bean";
    int dateEstablished = 1995;
    double pricePerCup = 3;

    struct Employee
    {
        std::string firstName = "Jane";
        std::string surname = "Doe";
        int age = 20;
        std::string role = "Cashier";
        int id = 0;

        void setRole(std::string newRole = "Generalist");
        void setSurname(std::string newSurname);
        bool isOlderThan(int ageToCompare = 0);
    };

    Employee employeeOnDuty;

    void open();
    void close();
    void toggleOpenClosedState();
    double sellCoffee(int numCups);
    double purchaseCoffeeBeans(double weightInPounds, double pricePerPound);
};

void CoffeeShop::open() { isOpen = true; }
void CoffeeShop::close() { isOpen = false; }
void CoffeeShop::toggleOpenClosedState()
{
    isOpen = isOpen ? false : true;
}

double CoffeeShop::sellCoffee(int numCups)
{
    double revenue = numCups * pricePerCup;
    return revenue;
}

double CoffeeShop::purchaseCoffeeBeans(double weightInPounds, double pricePerPound)
{
    double cost = weightInPounds * pricePerPound;
    return cost;
}

void CoffeeShop::Employee::setRole(std::string newRole)
{
    role = newRole;
}

void CoffeeShop::Employee::setSurname(std::string newSurname)
{
    surname = newSurname;
}

bool CoffeeShop::Employee::isOlderThan(int ageToCompare)
{
    return (age > ageToCompare) ? true : false;
}

struct Dog
{
    std::string name = "Watson";
    int ageInMonths = 26;
    std::string breed = "Hound Mix";
    float weightInPounds = 68.4f;
    float runningSpeed = 24.5f;

    void run();
    void eatFood();
    void drinkWater();
};

void Dog::run() { /* run impl */ }
void Dog::eatFood() { /* eat food impl */ }
void Dog::drinkWater() { /* drink water impl */ }

struct Table
{
    int numLegs = 4;
    float height = 39.f;
    float tabletopRadius = 14.f;
    std::string color = "White";
    float weight = 68.5f;
    float heldWeight = 0.f;
    float maxHoldWeight = 100.f;

    void holdItem(int itemWeight = 0);
    void collapse();
    void foldClosed();
};

void Table::holdItem(int itemWeight)
{
    heldWeight += itemWeight;

    if (heldWeight > maxHoldWeight) 
        collapse();
}

void Table::collapse()
{
    // collapse impl
}

void Table::foldClosed()
{
    // fold closed impl
}

struct Bank
{
    int numSafeDepositBoxes = 100;
    int numTellers = 3;
    double totalAssets = 71893782.34;
    std::string address = "1 Some Place";
    int id = 0;

    struct ATM
    {
        int billCapacity = 2000;
        int billCount = 0;
        int paperCheckCapacity = 200;
        int paperCheckCount = 0;
        int serialNumber = 0;
        std::string identifier = "UNNAMED";

        void dispenseBills(int numBills = 0);
        void refill();
        float getFillPercentage();
    };

    ATM atm;

    void refillAtm(ATM atmToRefill);
    void deposit(double amount);
    void withdraw(double amount);
    void addSafeDepositBox(int numBoxesToAdd = 1);
};

void Bank::refillAtm(ATM atmToRefill)
{
    atmToRefill.refill();
}

void Bank::deposit(double amount)
{
    totalAssets += amount;
}

void Bank::withdraw(double amount)
{
    totalAssets -= amount;
}

void Bank::addSafeDepositBox(int numBoxesToAdd)
{
    numSafeDepositBoxes += numBoxesToAdd;
}

void Bank::ATM::dispenseBills(int numBills)
{
    billCount -= numBills;
}

void Bank::ATM::refill()
{
    billCount = billCapacity;
}

float Bank::ATM::getFillPercentage()
{
    return ( billCount / billCapacity );
}

struct Knife
{
    float length = 3.0f;
    float sharpness = 0.8f;
    float mass = 0.50f;
    std::string material = "Stainless Steel";
    float reflectivity = 0.8f;

    void cut();
    void scratch();
    void whittle();
};

void Knife::cut() { /* cut! */ }
void Knife::scratch() { /* scratch! */ }
void Knife::whittle() { /* whittle! */ }

struct NailClippers
{
    float length = 3.0f;
    std::string material = "Stainless Steel";
    float mouthWidth = 0.12f;
    float mouthCurveRadius = 0.65f;
    float clipStrength = 24.5f;

    void clip(float requiredClipStrength = 20.f);
    bool canClip(float requiredClipStrength = 20.f);
    void unfold();
    void fold();
};

void NailClippers::clip(float requiredClipStrength)
{
    if ( canClip(requiredClipStrength) )
    {
        // clip the nail!
    }
}

bool NailClippers::canClip(float requiredClipStrength)
{
    return ( requiredClipStrength < clipStrength ) ? true : false;
}

void NailClippers::unfold() { /* unfold impl */ }
void NailClippers::fold() { /* fold impl */ }

struct MagnifyingGlass
{
    float lensRadius = 1.f;
    float refractionAngle = 30.f;
    float magFactor = 2.5f;
    std::string armMaterial = "Stainless Steel";
    std::string glassType = "Clear";

    void magnifyImage();
    void focusLight();
    void flipImage();
};

void MagnifyingGlass::magnifyImage()
{
    // magnify impl
}

void MagnifyingGlass::focusLight()
{
    // focus light impl
}

void MagnifyingGlass::flipImage()
{
    // flippy stuff
}

struct HairComb
{
    float length = 5.5f;
    std::string material = "Aluminum";
    int numTeeth = 30;
    float teethLength = 1.125f;
    int totalNumStrokes = 0;

    void combHair(int numStrokes = 1);
    void unfold();
    void fold();
    double getTeethPitch(double numTeethInComb, double length);
};

void HairComb::combHair(int numStrokes)
{
    totalNumStrokes += numStrokes;
}

void HairComb::unfold() { /* unfold impl */ }
void HairComb::fold() { /* fold impl */ }

double HairComb::getTeethPitch(double numTeethInComb, double lengthOfComb)
{
    return ( lengthOfComb / numTeethInComb );
}

struct Toothpick
{
    float length = 2.5f;
    std::string material = "Stainless Steel";
    float breakingStrength = 34.5f;
    float tipAngle = 5.5f;
    int numTimesUsed = 0;

    void pickTeeth(int numTimesToPick = 1);
    void pokeHole();
    void snap();
};

void Toothpick::pickTeeth(int numTimesToPick)
{
    //pick teeth!
    numTimesUsed += numTimesToPick;
}

void Toothpick::pokeHole()
{
    //poke a hole!
    numTimesUsed++;
}

void Toothpick::snap()
{
    // snap impl
    // render toothpick useless
    // delete from inventory or whatever
}

struct SwissArmyKnife
{
    Knife knife;
    NailClippers nailClippers; 
    MagnifyingGlass magnifyingGlass;
    HairComb hairComb;
    Toothpick toothpick;

    void cut();
    void clipNails(float requiredClipStrength = 20.f);
    void pickTeeth(int numTimesToPick = 1);
};

void SwissArmyKnife::cut()
{
    knife.cut();
}

void SwissArmyKnife::clipNails(float requiredClipStrength)
{
    nailClippers.clip(requiredClipStrength);
}

void SwissArmyKnife::pickTeeth(int numTimesToPick)
{
    toothpick.pickTeeth(numTimesToPick);
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    Example::main(); 
    
    
    std::cout << "good to go!" << std::endl;
}
