#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache{
    public:
        LRUCache(int cp) : Cache(){
            this->cp = cp;
            this->head = nullptr;
            this->tail = nullptr;
        }
        void set(int k, int val){
            // SI CACHE LLENA 
            if(mp.size()==cp){
                auto iter = this->mp.find(k);
                
                //SI HAY CACHE HIT 
                if(iter != mp.end()){
                    Node* n = this->head;
                    while( n->key!= iter->first && n->next!=nullptr){
                        n = n->next;
                    } 
                    n->value = val; 
                    
                //NO HAY CACHE HIT   
                }else{
                Node* n = new Node(k,val);
                n->next = this->head;
                this->head->prev = n;
                this->head = n;
                this->tail->prev->next = nullptr;
                delete this->tail;
                mp.erase(this->tail->key);
                this->tail = this->tail->prev;
                mp.insert(make_pair(k,n)); 
                }
                
                // SI TODAVIA NO ESTA LLENA 
            }else if(mp.size()>0){
                auto iter = this->mp.find(k);
                // SI HAY CACHE HIT 
                if(iter != mp.end()){
                    Node* n = this->head;
                    while( n->key!= iter->first && n->next!=nullptr){
                        n = n->next;
                    } 
                    n->value = val;  
                    
                // NO HAY CACHE HIT   
                }else{
                Node* n = new Node(k,val);
                n->next = this->head;
                this->head->prev = n;
                this->head = n;
                mp.insert(make_pair(k,n)); 
                }
            
            // PRIMER ELEMENTO DE LA CACHE 
            }else{
                Node* n = new Node(k,val);
                this->head = n;
                this->tail = n;
                mp.insert(make_pair(k,n));
            }
        }
        int get(int k){
            auto iter = this->mp.find(k);
            int value = -1;
                // SI HAY CACHE HIT 
                if(iter != mp.end()){
                    value = iter->second->value;
                // NO HAY CACHE HIT   
                }else{
                
                }
            return value;
        }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}