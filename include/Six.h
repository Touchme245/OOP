#pragma once

#include <string>
#include <iostream>

class Six
{ 
public:
   Six();
   Six(const size_t &n, unsigned char t);
   Six(const std::initializer_list< unsigned char> &t);
   Six(const std::string &t);
   Six(const Six& other);
   Six(Six&& other) noexcept;      
   
   unsigned char* getArray();
   long long getSize();
   Six add(const Six& other);
   Six remove(const Six& other);
   bool equals(const Six& other) const;
   bool operator>(const Six& other) const;
   bool operator<(const Six& other) const;
   std::ostream& print(std::ostream& os);

   friend class SixBuilder;
   virtual ~Six() noexcept;
private:
    long long _size;
    unsigned char *_array;
};