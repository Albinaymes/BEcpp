#ifndef LEDBUTTUN_H
#define LEDBUTTUN_H


class LedButtun  {
public:
    LedButtun();  
    ~LedButtun(); 
    int readValue() const;
    void allumerLed();
    void eteindreLed();

   
};

#endif 
