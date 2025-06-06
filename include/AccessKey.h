#ifndef ACCESSKEY_H
#define ACCESSKEY_H

namespace design {

template <typename T>
class AccessKey {
private:
    constexpr AccessKey() = default;
    friend T;
    
public:
    static constexpr AccessKey create() { return {}; }
};

}

#endif 
