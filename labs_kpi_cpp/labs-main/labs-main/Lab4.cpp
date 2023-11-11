#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <string>
using namespace std;

template<typename T>
class String {
    typedef typename list<T>::iterator it;
    list<T>* l;
public:
    String() {
        l = new list<T>();
        
    }
    String(char c) {
        if (typeid(T).name() == typeid('a').name()) {
            cout << "Enter string: ";
            string t;
            getline(cin, t);
            for (char c : t) {
                l->push_back(c);
            }
        }
    }
    String(String*& s) {
        this = s;
    }
    String(T value, int count) {
        l = new list<T>();
        for (int i = 0; i < count; i++) {
            l->push_back(value);
        }
    }
    String(T* array, int size) {
        for (int i = 0; i < size; i++) {
            l->push_back(array[i]);
        }
    }
    int GetLength() const {
        return l->size();
    }
    bool IsEmpty() const {
        return l->size() == 0 ? true : false;
    }
    void Clear() {
        l->clear();
    }
    T& operator[](int index) {
        it itr = l->begin();
        for (int i = 0; i < index; i++) {
            itr++;
        }
        return *itr;
    }
    void operator+(T value) {
        l->push_back(value);
    }
    String<T>* Substring(int index1, int index2) {
        String<T>* s = new String<T>();
        it itr = l->begin();
        for (int i = 0; i < index1; i++) {
            itr++;
        }
        for (int i = index1; i <= index2; i++) {
            (*s) + *itr;
            itr++;
        }
        return s;
    }
    void Show() {
        it itr = l->begin();
        for (; itr != l->end(); itr++) {
            cout << *itr;
        }
        cout << endl;
    }
    void operator+(pair<string, T> p) {
        if (p.first == "r") {
            l->push_back(p.second);
        }
        if (p.first == "l") {
            l->push_front(p.second);
        }
    }
    void operator+(pair<string, String<T>*> p) {
        String<T>* s = p.second;
        if (p.first == "r") {
            for (it itr = s->l->begin(); itr != s->l->end(); itr++) {
                l->push_back(*itr);
            }
        }
        if (p.first == "l") {
            for (it itr = s->l->begin(); itr != s->l->end(); itr++) {
                l->push_front(*itr);
            }
        }
    }
    String<T>* operator*(int t) {
        String<T>* s = new String<T>();
        for (int i = 0; i < t; i++) {
            for (it itr = l->begin(); itr != l->end(); itr++) {
                s->l->push_back(*itr);
            }
        }
        return s;
    }
    bool operator==(String<T> s) {
        if (s.l->size() != l->size()) {
            return false;
        }
        for (it itr1 = l->begin(), itr2 = s.l->begin(); itr1 != l->end(); itr1++, itr2++) {
            if (*itr1 != *itr2) {
                return false;
            }
        }
        return true;
    }
    bool operator!=(String<T> s) {
        if (s.l->size() != l->size()) {
            return true;
        }
        for (it itr1 = l->begin(), itr2 = s.l->begin(); itr1 != l->end(); itr1++, itr2++) {
            if (*itr1 != *itr2) {
                return true;
            }
        }
        return false;
    }
    bool operator>(String<T> s) {
        if (s.l->size() > l->size()) {
            return true;
        }
        for (it itr1 = l->begin(), itr2 = s.l->begin(); itr1 != l->end(); itr1++, itr2++) {
            if (*itr1 > *itr2) {
                return true;
            }
        }
    }
    bool operator<(String<T> s) {
        if (s.l->size() < l->size()) {
            return true;
        }
        for (it itr1 = l->begin(), itr2 = s.l->begin(); itr1 != l->end(); itr1++, itr2++) {
            if (*itr1 > *itr2) {
                return false;
            }
        }
    }
    vector<T> GenerateArray() {
        vector<T> v;
        for (it itr = l->begin(); itr != l->end(); itr++) {
            v.push_back(*itr);
        }
        return v;
    }
    String<T> SetString(pair<string, list<T>> p) {
        String<T>* s = new String<T>();
        if (p.first == "save") {
            *(s->l) = *l;
            *l = (p.second);
        }
        else {
            l->clear();
            *l = (p.second);
        }
        return s;
    }
};


void main() {

}

