// create class 
#include <string>
using namespace std;

class IntegerSet { 
    private:
        int size;
        int *arr;
    public:
        // constructors
        IntegerSet();
        IntegerSet(int[], int);

        // deconstructor
        ~IntegerSet();

        // functions
        IntegerSet unionOfsets(const IntegerSet&) const;
        IntegerSet intersectOfsets(const IntegerSet&) const;
        void insertElement(int);
        void deleteElement(int);
        void printSet() const;
        bool isEqualTo(const IntegerSet&) const;
        void emptySet();
        void inputSet();
        bool validEntry(int) const;

};
