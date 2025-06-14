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

private:
	struct Entry {
		Key key;
		Value value;
	};

	std::vector<Entry> data;

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



