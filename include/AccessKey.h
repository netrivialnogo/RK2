#ifndef ACCESSKEY_H
#define ACCESSKEY_H

namespace design {

template <typename T>
class AccessKey {
private:
    constexpr AccessKey() = default;
    friend T;
    
public:
    bool operator==(const AccessKey&) const { return true; }
    static constexpr AccessKey createForTesting() {
        return {};
    }
};

}

#endif 
