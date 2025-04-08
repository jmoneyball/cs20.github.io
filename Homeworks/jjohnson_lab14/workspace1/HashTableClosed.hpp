#ifndef HT_CLOSED_H
#define HT_CLOSED_H

#include "Dictionary.hpp"
#include <iomanip>
#include <iostream>
using namespace std;

template <typename Key, typename Val>
class HashTableClosed : public Dictionary<Key, Val> {
    private:
        // an element in a dictionary, contains a key and a value
        struct Record {
            Key k;
            Val v;

            Record() : k(Key()), v(Val()) { }
            Record(Key x, Val y) : k(x), v(y) { }
        };

        // the underlying (dynamic) array of records
        Record* ht;

        // the size of the hash table (total number of slots)
        int M;

        // special markers
        Key EMPTY_KEY, TOMBSTONE;

        // hash function
        // folding method (assumes that Key = string)
        int hash(const Key&) const;

        // probe function
        // linear probing method
        int linearProbe(const Key&, int) const;

    public:
        // constructor
        // argument 1 is the key to represent an empty key
        // argument 2 is the key to represent a tombstone
        HashTableClosed(const Key&, const Key&, int = 100);

        // destructor
        virtual ~HashTableClosed();

        // remove all records in the dictionary
        virtual void clear() override;

        // retrieve the record that matches the argument key
        // if multiple records match, return an arbitrary one
        virtual Val find(const Key&) const override;

        // add the record as a key-value pair to the dictionary
        virtual void insert(const Key&, const Val&) override;

        // print a visual representation of the hash table
        void print(bool = false) const;

        // remove the record that matches the argument key from the dictionary
        // if multiple records match, remove an arbitrary one
        virtual void remove(const Key&) override;

        // return the number of records in the dictionary
        virtual int size() const override;
};

template <typename Key, typename Val>
HashTableClosed<Key, Val>::HashTableClosed(const Key& e, const Key& t, int i) {
    M = i;
    EMPTY_KEY = e;
    TOMBSTONE = t;
    ht = new Record[M];
    
    for (int i = 0; i < M; i++) {
        ht[i].k = EMPTY_KEY;
    }
}

template <typename Key, typename Val>
HashTableClosed<Key, Val>::~HashTableClosed() {
    delete[] ht;
}

template <typename Key, typename Val>
void HashTableClosed<Key, Val>::clear() {
    for (int i = 0; i < M; i++) {
        ht[i].k = EMPTY_KEY;
        ht[i].v = Val();
    }
}

template <typename Key, typename Val>
Val HashTableClosed<Key, Val>::find(const Key& target) const {
	//declarations
	int home = hash(target);
	int i = 1;

	//if empty, throw error
	if(size() == 0) {
		cout << "Your dictionary is currently empty."  << endl;
		throw -1;
	}
	//if not empty, try to find matching key
	else {
		//if home is target, return
		if(ht[home].k == target)
			return ht[home].v;
		//if home is not target, probe
		else {
			while(i != M) {
				int probe = linearProbe(ht[home].k, i);
				if(ht[(home + probe) % M].k == target)
					return ht[(home + probe) % M].v;
			i++;
			}
		}
	}
	//if no matching key is found, throw error
	cout << "No value found that matches the given key." << endl;
	throw -1;
}

template <typename Key, typename Val>
int HashTableClosed<Key, Val>::hash(const Key& k) const {
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
void HashTableClosed<Key, Val>::insert(const Key& k, const Val& v) {
    //declarations
	Record r(k, v);
	int home = hash(k);
	int i = 1;

	//if full, throw error
	if(size() == M) {
		cout << "Your dictionary is currently full."  << endl;
		throw -1;
	}
	//if not full, insert at next open spot
	else {
		//if home is empty, insert
		if(ht[home].k == EMPTY_KEY || ht[home].k == TOMBSTONE)
			ht[home] = r;
		//if home is full, probe
		else {
			while(i != M) {
				int probe = linearProbe(k, i);
				if(ht[(home + probe) % M].k == EMPTY_KEY || ht[(home + probe) % M].k == TOMBSTONE) {
					ht[(home + probe) % M] = r;
					return;
				}
			i++;
			}
		}
	}
}

template <typename Key, typename Val>
int HashTableClosed<Key, Val>::linearProbe(const Key& k, int i) const {
    return i;
}

template <typename Key, typename Val>
void HashTableClosed<Key, Val>::print(bool tombFlag) const {
    const char FILL = '-';
    const int WIDTH = 80;
    const int SLOT_WIDTH = 4;
    const int KEY_WIDTH = 25;

    cout << setfill(FILL) << setw(WIDTH) << "" << endl << setfill(' ');

    for (int i = 0; i < M; i++) {
        cout << right << setw(SLOT_WIDTH) << i << " | "
             << left << setw(KEY_WIDTH)
             << (ht[i].k != TOMBSTONE || tombFlag ? ht[i].k : "")
             << " | "
             << (ht[i].k != TOMBSTONE || tombFlag ? ht[i].v : "")
             << endl;
    }

    cout << setfill(FILL) << setw(WIDTH) << "" << endl;
}

template <typename Key, typename Val>
void HashTableClosed<Key, Val>::remove(const Key& target) {
	//declarations
	int home = hash(target);
	int i = 1;

	//if empty, throw error
	if(size() == 0) {
		cout << "Your dictionary is currently empty." << endl;
		throw -1;
	}
	//if not empty, try to remove using key
	else {
		//if home is target, remove
		if(ht[home].k == target) {
			ht[home].k = TOMBSTONE;
			ht[home].v = "";
		}
		//if home is not target, probe
		else {
			while(i != M) {
				int probe = linearProbe(ht[home].k, i);
				if(ht[(home + probe) % M].k == target) {
					ht[(home + probe) % M].k = TOMBSTONE;
					ht[(home + probe) % M].v = "";
					return;
				}
			i++;
			}
		}
	}
	//if no matching key exists, output error message
	cout << "No value found that has matches the given key." << endl;
}

template <typename Key, typename Val>
int HashTableClosed<Key, Val>::size() const {
    int total = 0;
    for (int i = 0; i < M; i++) {
        if (ht[i].k != EMPTY_KEY && ht[i].k != TOMBSTONE) {
            total++;
        }
    }
    return total;
}

#endif
