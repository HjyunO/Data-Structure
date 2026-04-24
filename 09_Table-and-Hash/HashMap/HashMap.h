#pragma once

template<typename K,typename V>
class MyHashMap {
    private:
        int _size;

        class Node {
                K key;
                // Key
                V val;
                // Value
                int hash;
                // hash
                Node* next;
                // next ptr
                Node(K key, V val);
                // Node constructor
        };

        Node** table;
        // if resize -> can not use Node*[] type 


    public:
        MyHashMap() { _size = 0 }
        
        ~MyHashMap() { delete[] table };

        Node(cosnt K& key, const V& val) {
            this.key = key;
            this.val = val;
            this.hash = (key*2654435761) % capacity;
            this.next = nullptr; 
        };

        ~Node();
        
        static constexpr int capacity = 8; // if resize -> can not use constexpr
        
        int size() {
            return _size;
        }

        bool isEmpty() {
            return _size == 0;
        }

        bool put(const K& key, const V& val) {
            if(isEmpty()) {
                table = new Node*[capacity];
                for(int i = 0; i < capacity; i++) {
                    table[i] = nullptr;
                }
            }
            
            Node* newNode = new Node(key, val);

            int index = newNode->hash & (capacity - 1);
            Node* cur = table[index];
            Node* prev = cur;

            if(cur == nullptr) {
                table[index] = newNode;
                return true;
            }
            
            while(cur != nullptr) {
                if(cur->key == key) {
                    cur->val = val;
                    return false;
                }
                prev = cur;
                cur = cur->next;
            }
            prev->next = newNode;
            _size++;
            return true;
        }

        V* get(const K& key) {
            int index = (key*2654435761) % capacity;
            Node* cur = table[index];

            while(cur != nullptr) {
                if(cur->key == key) {
                    return &cur->val;
                }
                cur = cur->next;
            }
            return nullptr;
        }

        bool containsKey(const K& key) {
            int index = (key*2654435761) % capacity;
            Node* cur = table[index];

            while(cur != nullptr) {
                if(cur->key = key) {
                    return true;
                }
            }
            return false;
        }

        bool remove(const K& key) {
            int index = (key*2654435761) % capacity;
            Node* cur = table[index];
            Node* prev = cur;
            
            if(cur->key == key) {
                table[index] = nullptr;
                return true;
            }

            while(cur != nullptr) {
                if(cur->key == key) {
                    prev->next = nullptr;
                    return true;
                }
                prev = cur;
                cur = cur->next;
            }
            return false;
        }

};