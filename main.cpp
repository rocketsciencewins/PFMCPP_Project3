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



/*
Thing 1) Coffee shop
5 properties:
    1) Number of employees (int)
    2) Number of coffee maker machines (int)
    3) Open/closed state (bool)
    4) Name (std::string)
    5) Date established (int)
3 things it can do:
    1) Sell coffee
    2) Purchase coffee beans
    3) Toggle open/closed state
 */

struct CoffeeShop
{
    // number of employees
    int numEmployees = 10;
    // number of coffee maker machines
    int numCoffeeMachines = 2;
    // open/closed state boolean
    bool isOpen = true;
    // name
    std::string name = "The Nautical Bean";
    // date established
    int dateEstablished = 1995;

    struct Employee
    {
        std::string firstName = "Jane";
        std::string surname = "Doe";
        int age = 20;
        std::string role = "Cashier";
        int id = 0;

        void setRole(std::string newRole = "Generalist");
        void setSurname(std::string newSurname);
        bool isOlderThan(int ageToCompare = 0);   // returns true if employee age exceeds ageToCompare
    };

    Employee employeeOnDuty;

    Employee getEmployeeOnDuty();  // returns the employeeOnDuty
    void changeName(std::string newName);
    void setEmployeeOnDuty(Employee employee);
    void open();
    void close();
    void toggleOpenClosedState();
    double sellCoffee(int numCups); // returns revenue from sale in USD
    double purchaseCoffeeBeans(double weightInPounds); // returns purchase cost in USD
};

/*
Thing 2) Dog
5 properties:
    1) name (std::string)
    2) age in months (int)
    3) breed (std::string)
    4) weight (float)
    5) running speed (float)
3 things it can do:
    1) run
    2) eat food
    3) drink water
 */

struct Dog
{
    // name
    std::string name = "Watson";
    // age in months
    int ageInMonths = 26;
    // breed
    std::string breed = "Hound Mix";
    // weight
    float weightInPounds = 68.4f;
    // running speed
    float runningSpeed = 24.5f;

    void run();
    void eatFood();
    void drinkWater();
};

/*
Thing 3) Table
5 properties:
    1) number of legs (int)
    2) height (float)
    3) tabletop radius (float)
    4) color (std::string)
    5) weight (float)
3 things it can do:
    1) hold item
    2) collapse
    3) fold closed
 */

struct Table
{
    // number of legs
    int numLegs = 4;
    // height
    float height = 39.f;
    // tabletop radius
    float tabletopRadius = 14.f;
    // color
    std::string color = "White";
    // weight
    float weight = 68.5f;

    void holdItem(int itemWeight = 0);
    void collapse();
    void foldClosed();
};

/*
Thing 4)  Bank
5 properties:
    1) number of safe deposit boxes (int)
    2) number of tellers (int)
    3) total assets in USD (double)
    4) address (std::string)
    5) FDIC member ID (int)
3 things it can do:
    1) take deposit money
    2) give withdrawal money
    3) add more safety deposit boxes
 */

struct Bank
{
    // number of safe deposit boxes
    int numSafeDepositBoxes = 100;
    // number of tellers
    int numTellers = 3;
    // total assets in USD
    double totalAssets = 71893782.34;
    // address
    std::string address = "1 Some Place";
    // FDIC member ID 
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
        int getBillCount(); // returns billCount
        int getTensCount(); // returns number of tens in the ATM
        int getTwentiesCount(); // returns number of twenties in the ATM
        double getTotalDollarsInMachine(); // returns total value of bills in the ATM
    };

    ATM atm;

    void refillAtm(ATM atmToRefill);
    ATM getAtm(); // returns the bank's ATM instance
    void deposit(int accountNumber, double amount);
    void withdraw(int accountNumber, double amount);
    void addSafetyDepositBox(int numBoxesToAdd = 1);
};

/*
Thing 5) Knife
5 properties:
    1) length (float)
    2) sharpness (float)
    3) mass (foat)
    4) material (std::string)
    5) reflectivity (float)
3 things it can do:
    1) cut
    2) scratch
    3) whittle
 */

struct Knife
{
    // length
    float length = 3.0f;
    // sharpness
    float sharpness = 0.8f;
    // mass
    float mass = 0.50f;
    // material
    std::string material = "Stainless Steel";
    // reflectivity
    float reflectivity = 0.8f;

    void cut();
    void scratch();
    void whittle();
    std::string getMaterial();
    void setMaterial(std::string newMaterial);
};

/*
Thing 6) Nail clippers
5 properties:
    1) length (float)
    2) material (std::string)
    3) clipper mouth width (float)
    4) clipper mouth curve radius (float)
    5) clipper strength (float)
3 things it can do:
    1) clip nail
    2) unfold
    3) fold
 */

struct NailClippers
{
    // length
    float length = 3.0f;
    // material
    std::string material = "Stainless Steel";
    // mouth width
    float mouthWidth = 0.12f;
    // mouth curve radius
    float mouthCurveRadius = 0.65f;
    // clip strength
    float clipStrength = 24.5f;

    void clip(float requiredClipStrength = 20.f);
    bool canClip(float requiredClipStrength = 20.f); // returns whether these clippers' clip strength meets or exceeds the required clip strength
    void unfold();
    void fold();
};

/*
Thing 7) Magnifying glass
5 properties:
    1) lens major radius (float)
    2) lens light refraction angle (float)
    3) lens magnification factor (float)
    4) arm material (std::string)
    5) glass type (std::string)
3 things it can do:
    1) magnify image
    2) focus light
    3) flip image
 */

struct MagnifyingGlass
{
    // lens major radius
    float lensRadius = 1.f;
    // lens light refraction angle
    float refractionAngle = 30.f;
    // lens magnification factor
    float magFactor = 2.5f;
    // arm material
    std::string armMaterial = "Stainless Steel";
    // glass type
    std::string glassType = "Clear";

    void magnifyImage(float magnificationFactor = 2.f);
    void focusLight();
    void flipImage();
};

/*
Thing 8) Hair comb
5 properties:
    1) length (float)
    2) material (std::string)
    3) number of teeth (int)
    4) teeth pitch (float)
    5) teeth length (float)
3 things it can do:
    1) comb hair
    2) unfold
    3) fold
 */

struct HairComb
{
    // length
    float length = 5.5f;
    // material
    std::string material = "Aluminum";
    // number of teeth
    int numTeeth = 30;
    // teeth pitch
    float teethPitch = .0125f;
    // teeth length
    float teethLength = 1.125f;

    void combHair(int numStrokes = 1);
    void unfold();
    void fold();
    double getTotalTeethLength(float numTeeth, float pitch);
};

/*
Thing 9) Toothpick
5 properties:
    1) length (float)
    2) material (std::string)
    3) breaking strength (float)
    4) tip angle (float)
    5) number of times used (int)
3 things it can do:
    1) pick teeth
    2) poke hole
    3) snap
 */

struct Toothpick
{
    // length
    float length = 2.5f;
    // material
    std::string material = "Stainless Steel";
    // breaking strength
    float breakingStrength = 34.5f;
    // tip angle
    float tipAngle = 5.5f;
    // number of times used
    int numTimesUsed = 0;

    void pickTeeth(int numTimesToPick = 1);
    void pokeHole();
    void snap();
    int getNumTimesUsed(); // returns number of times this toothpick's been used
};

/*
Thing 10) Swiss Army Knife
5 properties:
    1) Knife
    2) Nail Clippers
    3) Magnifying Glass
    4) Hair comb
    5) Tooth pick
3 things it can do:
    1) Cut
    2) Clip nails
    3) Pick teeth
 */

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
    Knife getKnife();
};

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
