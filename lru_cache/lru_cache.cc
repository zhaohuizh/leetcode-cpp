#include <list>
#include <unordered_map>

using namespace std;

class LRUCache{
private:
  int cap;
  unordered_map<int, int> cache;
  unordered_map<int, list<int>::iterator> ref;
  list<int> order;
public:
  LRUCache(int capacity) {
    cap = capacity;
  }
  
  int get(int key) {
    auto it = cache.find(key);
    if (it == cache.end()) return -1;
    order.erase(ref[key]);
    order.push_front(key);
    ref[key] = order.begin();
    return it->second;
  }
  
  void set(int key, int value) {
    auto it = cache.find(key);
    if (it == cache.end()){
      if(cache.size() >= cap){
        cache.erase(order.back());
        ref.erase(order.back());
        order.pop_back();
      }
    }else{
      order.erase(ref[key]);
    }
    order.push_front(key);
    ref[key] = order.begin();
    cache[key] = value;
  }
};
