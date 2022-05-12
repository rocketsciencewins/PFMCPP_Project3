/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

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

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
    - if your functions return something other than 'void', add a comment explaining what is being returned.  see the example code below.
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a [-Wpadded] warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

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

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips); //3) returns the number of miles traveled
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage); //3) returns the total amount charged.
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};


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
    1) hold items
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

    void supportItem(int itemWeight = 0);
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
    3) open new accounts
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

    bool canClip(float requiredClipStrength = 20.f); // returns whether these clippers' clip strength meets or exceeds the required clip strength
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
    void breakTeeth(int numTeethToBreak = 1);
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
