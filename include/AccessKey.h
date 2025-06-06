#ifndef ACCESSKEY_H
#define ACCESSKEY_H

namespace design {

template <typename T>
class AccessKey {
private:
    AccessKey() = default;
    friend T;
    
    template <typename TestFriend>
    friend struct TestAccess;
};

template <typename T>
struct TestAccess {
    static AccessKey<T> create() { return {}; }
};

} 

#endif 
