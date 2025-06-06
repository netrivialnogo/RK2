#ifndef ACCESSKEY_H
#define ACCESSKEY_H

namespace design {

template <typename T>
class AccessKey {
private:
    AccessKey() = default;
    friend T;
};

} 

#endif 
