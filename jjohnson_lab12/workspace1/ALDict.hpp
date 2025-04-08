#ifndef AL_DICT_HPP
#define AL_DICT_HPP

#include "Dictionary.hpp"
#include "ArrayList.hpp"

template <typename Key, typename Val>
class ALDict : public Dictionary<Key, Val> {
    private:
        // an element in a dictionary, contains a key and a value
        struct Record {
            Key k;
            Val v;

            Record() : k(Key()), v(Val()) { }
            Record(Key x, Val y) : k(x), v(y) { }
        };

        // the underlying array-based list
        ArrayList<Record>* list;

        // sequential search algorithm (iterative)
        Val seqSearch(const Key&) const;

        // sequential search algorithm (recursive)
        Val seqSearchRec(const Key&, int = 0) const;

        // binary search algorithm (iterative)
        Val binSearch(const Key&, int, int) const;

        // binary search algorithm (recursive)
        Val binSearchRec(const Key&, int, int) const;

    public:
        // default constructor
        ALDict(int = 100);

        // destructor
        virtual ~ALDict();

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
ALDict<Key, Val>::ALDict(int i) {
    list = new ArrayList<Record>(i);
}

template <typename Key, typename Val>
ALDict<Key, Val>::~ALDict() {
    delete list;
}

template <typename Key, typename Val>
Val ALDict<Key, Val>::binSearch(const Key& target, int left, int right) const {
	while(left <= right) {
		int middle = left + (right - left)/2;
		if(list->getElement(middle).k == target)
			return list->getElement(middle).v;
		else if(list->getElement(middle).k < target)
			left = middle + 1;
		else if(list->getElement(middle).k > target)
			right = middle - 1;
	}
	cout << "The key you entered does not exist." << endl;
	return 0;
}

template <typename Key, typename Val>
Val ALDict<Key, Val>::binSearchRec(const Key& target, int left, int right) const {
	if(left <= right) {
		int middle = left + (right - left)/2;
		if(list->getElement(middle).k == target)
			return list->getElement(middle).v;
		else if(list->getElement(middle).k < target)
			return binSearchRec(target, middle + 1, right);
		else if(list->getElement(middle).k > target)
			return binSearchRec(target, left, middle - 1);
	}
	else {
		cout << "The key you entered does not exist." << endl;
		return 0;
	}

}

template <typename Key, typename Val>
void ALDict<Key, Val>::clear() {
    list->clear();
}

template <typename Key, typename Val>
Val ALDict<Key, Val>::find(const Key& k) const {
    try {
        // return seqSearch(k);
        // return seqSearchRec(k);
        // return binSearch(k, 0, list->getLength() - 1);
        // return binSearchRec(k, 0, list->getLength() - 1);
    }
    catch (int i) {
        cout << "ERROR: unable to find record\n";
        throw i;
    }
}

template <typename Key, typename Val>
void ALDict<Key, Val>::insert(const Key& k, const Val& v) {
    list->append(Record(k, v));
}

template <typename Key, typename Val>
void ALDict<Key, Val>::remove(const Key& k) {
    bool flag = false;

    for (int i = 0; i < list->getLength(); i++) {
        if (list->getElement(i).k == k) {
            list->remove(i);
            flag = true;
            break;
        }
    }

    if (!flag) {
        cout << "Unable to find record with matching key to remove\n";
    }
}

template <typename Key, typename Val>
Val ALDict<Key, Val>::seqSearch(const Key& target) const {
	for(int i = 0; i < list->getLength(); i++)
		if(list->getElement(i).k == target)
			return list->getElement(i).v;
	cout << "The key you entered does not exist." << endl;
	return 0;
}

template <typename Key, typename Val>
Val ALDict<Key, Val>::seqSearchRec(const Key& target, int i) const {
    //base case
	if(list->getElement(i).k == target)
		return list->getElement(i).v;
	//recursive case
	else if(i < list->getLength())
		return seqSearchRec(target, i + 1);
	cout << "The key you entered does not exist." << endl;
	return 0;

}

template <typename Key, typename Val>
int ALDict<Key, Val>::size() const {
    return list->getLength();
}

#endif
