#ifndef HT_OPEN_HPP
#define HT_OPEN_HPP

#include "Dictionary.hpp"
#include "LinkedList.hpp"

template <typename Key, typename Val>
class HashTableOpen : public Dictionary<Key, Val> {
    private:
        // an element in a dictionary, contains a key and a value
        struct Record {
            Key k;
            Val v;

            Record() : k(Key()), v(Val()) { }
            Record(Key x, Val y) : k(x), v(y) { }
        };

        // the underlying (dynamic) array of (dynamic) linked lists
        LinkedList<Record>** ht;

        // the size of the hash table (total number of slots)
        int M;

        // hash function
        // folding method (assumes that Key = string)
        int hash(const Key&) const;

    public:
        // default constructor
        HashTableOpen(int = 100);

        // destructor
        virtual ~HashTableOpen();

        // remove all records in the dictionary
        virtual void clear() override;

        // retrieve the record that matches the argument key
        // if multiple records match, return an arbitrary one
        virtual Val find(const Key&) const override;

        // add the record as a key-value pair to the dictionary
        virtual void insert(const Key&, const Val&) override;

        // remove the record that matches the argument key from the dictionary
        // if multiple records match, remove an arbitrary one
        virtual void remove(const Key&) override;

        // return the number of records in the dictionary
        virtual int size() const override;
};

template <typename Key, typename Val>
HashTableOpen<Key, Val>::HashTableOpen(int i) {
    M = i;
    ht = new LinkedList<Record>*[M];
    for (int i = 0; i < M; i++) {
        ht[i] = new LinkedList<Record>;
    }
}

template <typename Key, typename Val>
HashTableOpen<Key, Val>::~HashTableOpen() {
    for (int i = 0; i < M; i++) {
        delete ht[i];
    }
    delete[] ht;
}

template <typename Key, typename Val>
void HashTableOpen<Key, Val>::clear() {
    for (int i = 0; i < M; i++) {
        ht[i]->clear();
    }
}

template <typename Key, typename Val>
Val HashTableOpen<Key, Val>::find(const Key& k) const {
    // TODO
	int slot = hash(k);
	LinkedList<Record> *ll = ht[slot];

	 if(ht[slot]->isEmpty()) //if the linked list is empty, throw error
		 throw -1;
	 else { //if it is not empty, try to find matching key
		for(int i = 0; i <= ll->getLength(); i++)
			if(ll->getElement(i).k == k)
				return ll->getElement(i).v;
		cerr << "No value found that matches the given key." << endl;
	 }
}

template <typename Key, typename Val>
int HashTableOpen<Key, Val>::hash(const Key& k) const {
    // how long should each fold be
    // changing this means you should also change the reinterpeted data type
    const int FOLD_LEN = 4;

    // if the fold length is 4, then must treat the string as unsigned numbers
    unsigned* ikey = (unsigned*) k.c_str();

    // calculate how many folds there are
    int ilen = k.length() / FOLD_LEN;

    // accumulator
    unsigned sum = 0;

    // for each fold, now treated as a number, add it to the running total
    for (int i = 0; i < ilen; i++) {
        sum += ikey[i];
    }

    // calculate how many leftover characters there are
    int extra = k.length() - ilen * FOLD_LEN;

    // create a temporary array that will hold those extra characters
    char temp[FOLD_LEN];

    // clear out that array with a 0 value
    ikey = (unsigned*) temp;
    ikey[0] = 0;

    // copy the extra characters over
    for (int i = 0; i < extra; i++) {
        temp[i] = k[ilen * FOLD_LEN + i];
    }

    // add these final characters as a number to the running total
    sum += ikey[0];

    // calculate the slot position
    int slot = sum % M;

    // display the hashing information
    cout << k << "\thashes to slot " << slot << endl;

    // return the valid slot position
    return slot;
}

template <typename Key, typename Val>
void HashTableOpen<Key, Val>::insert(const Key& k, const Val& v) {
    // TODO
	int slot = hash(k);
    Record  *r = new Record(k, v);

    if(ht[slot]->isEmpty()) //if the linked list is empty, append
    	ht[slot]->append(*r);
    else //if the linked list already has elements, insert at position 0
    	ht[slot]->insert(0, *r);

}

template <typename Key, typename Val>
void HashTableOpen<Key, Val>::remove(const Key& k) {
    // TODO
	int slot = hash(k);
	LinkedList<Record> *ll = ht[slot];
	bool flag = false;

	if(ht[slot]->isEmpty()) //if the linked list is empty, append
		 throw -1;
	 else { //if it isn't empty, check for a matching key
		for(int i = 0; i < ll->getLength(); i++)
			if(ll->getElement(i).k == k) {
				ll->remove(i);
				flag = true;
			}
		if(flag == false) //if no matching key exists, error
			cerr << "No value found that matches the given key." << endl;
	 }
}

template <typename Key, typename Val>
int HashTableOpen<Key, Val>::size() const {
    int total = 0;
    for (int i = 0; i < M; i++) {
        total += ht[i]->getLength();
    }
    return total;
}

#endif
