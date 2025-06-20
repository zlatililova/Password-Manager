#ifndef MYMAP_HPP
#define MYMAP_HPP

#include <iostream>
#include <vector>

template <class Key, class Value>
class MyMap {
public:
	bool insert(const Key& key, const Value& val);
	bool remove(const Key& key);
	Value* get(const Key& key);
	const Value* get(const Key& key) const;
	bool contains(const Key& key) const;

	const Key& getByValue(const Value val) const;

	int getSize() const;

	
private:
	struct Entry {
		Key key;
		Value value;
	};

	std::vector<Entry> data;

public:
	typename std::vector<Entry>::iterator begin() { return data.begin(); }
	typename std::vector<Entry>::iterator end() { return data.end(); }

	typename std::vector<Entry>::const_iterator begin() const { return data.begin(); }
	typename std::vector<Entry>::const_iterator end() const { return data.end(); }

};


template<class Key, class Value>
bool MyMap<Key, Value>::insert(const Key& key, const Value& val)
{
	if (contains(key)) {
		return false;
	}
	Entry newData{ key, val };
	data.push_back(newData);
	return true;
}

template<class Key, class Value>
bool MyMap<Key, Value>::remove(const Key& key)
{
	for (int i = 0; i < data.size(); i++) {
		if (data[i].key == key) {
			data.erase(data.begin() + i);
			return true;
		}
	}
	return false;
}

template<class Key, class Value>
Value* MyMap<Key, Value>::get(const Key& key)
{
	for (int i = 0; i < data.size(); i++) {
		if (data[i].key == key) {
			return &data[i].value;
		}
	}
	return nullptr;
}

template<class Key, class Value>
const Value* MyMap<Key, Value>::get(const Key& key) const
{
	for (int i = 0; i < data.size(); i++) {
		if (data[i].key == key) {
			return &data[i].value;
		}
	}
	return nullptr;
}

template<class Key, class Value>
bool MyMap<Key, Value>::contains(const Key& key) const
{
	for (int i = 0; i < data.size(); i++) {
		if (data[i].key == key) {
			return true;
		}
	}

	return false;
}

template<class Key, class Value>
inline const Key& MyMap<Key, Value>::getByValue(const Value val) const
{
	for (int i = 0; i < data.size(); i++) {
		if (data[i].value == val) {
			return data[i].key;
		}
	}

	return Key();
}

template<class Key, class Value>
inline int MyMap<Key, Value>::getSize() const
{
	return data.size();
}



#endif // MYMAP_HPP