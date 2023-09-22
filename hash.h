

#ifndef SEARCH_ALGO_HASH_H
#define SEARCH_ALGO_HASH_H
// Specification of the class
template <class keyType, class dataType>


class hashTable
{
public:

    // Member Functions
    // Constructor with two arguments,
    // Table size is nelements, k is "empty" value of keyType
    hashTable(int nelements, const keyType &k);
    ~hashTable();                 // Destructor

    // Functions Prototype Definitions

    bool tableIsEmpty() const;    // return True if table is empty
    bool tableIsFull() const;     // return True if table is full
    int  occupancy() const;          // return no. of occupied slots
    // insert key and data at a hashed slot, return true if successful
    bool insert(const keyType &, const dataType & );

    // Search the table for the slot that matches key.
    // If found, return True, set current position to slot
    bool search(const keyType & ,int &Counter);       // Search given key


    void updateData(const dataType & );        // Update data part of current slot
    void retrieveData(dataType &) const;   // Retrieve data part of current slot
    void traverse() const;               // Traverse whole table

private:

    // Slot Class
    class slot
    {
    public:
        keyType key;      // key
        dataType data;    // Data
    }; // end of class slot declaration


    slot *T;               // Pointer to Storage Array
    int h;                // Index to a slot
    int MaxSize, csize;          // Maximum and Current Sizes
    keyType Empty;          // Key value to consider as "Empty"


    // Private Member function
    int hash(const keyType & ) const;     // Hashing function
}; // End of class hashTable definition
#endif //SEARCH_ALGO_HASH_H
