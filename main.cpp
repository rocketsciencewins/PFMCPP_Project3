 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

struct Foot
{
    int strideLength;
    
    int stepSize() { return strideLength; }
    void stepForward() { /* step */ }
};

struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;
    Foot leftFoot;
    Foot rightFoot;

    void run(int howFast, bool startWithLeftFoot);
};

void Person::run(int howFast, bool startWithLeftFoot)
{
    if (startWithLeftFoot)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();
}




 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */




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

        void dispenseBills(int numTens = 0, int numTwenties = 0, int numHundreds = 0);
        void refill();
        double getFillPercentage();
    };

    ATM atm;

    void refillAtm(ATM atmToRefill);
    void deposit(int accountNumber, double amount);
    void withdraw(int accountNumber, double amount);
    void addSafeDepositBox(int numBoxesToAdd = 1);
};

void Bank::refillAtm(ATM atmToRefill)
{
    atmToRefill.refill();
}

void Bank::deposit(int accountNumber, double amount)
{
    // apply 'amount' to 'accountNumber' balance
}

void Bank::withdraw(int accountNumber, double amount)
{
    // subtract 'amount' from 'accountNumber' balance
}

void Bank::addSafeDepositBox(int numBoxesToAdd)
{
    numSafeDepositBoxes += numBoxesToAdd;
}

void Bank::ATM::dispenseBills(int numTens, int numTwenties, int numHundreds)
{
    // dispense tens
    // dispense twenties
    // dispense hundreds
}

void Bank::ATM::refill()
{
    billCount = billCapacity;
}

double Bank::ATM::getFillPercentage()
{
    return ( (double)billCount / (double)billCapacity );
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

    void magnifyImage(float magnificationFactor = 2.f);
    void focusLight();
    void flipImage();
};

void MagnifyingGlass::magnifyImage(float magnificationFactor)
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

    void combHair(int numStrokes = 1);
    void unfold();
    void fold();
    double getTeethPitch(float numTeethInComb, float length);
};

void HairComb::combHair(int numStrokes)
{
    // comb hair 'numStrokes' times!
}

void HairComb::unfold() { /* unfold impl */ }
void HairComb::fold() { /* fold impl */ }

double HairComb::getTeethPitch(float numTeethInComb, float lengthOfComb)
{
    return (double)lengthOfComb / (double)numTeethInComb;
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
    numTimesUsed++;
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
    std::cout << "good to go!" << std::endl;
}
