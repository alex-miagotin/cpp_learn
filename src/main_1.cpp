// #include <iostream>

#include "Math.hpp"

#define STRINGIFY(TOKEN) #TOKEN
// #define TO_CHAR(TOKEN) #@TOKEN
#define CONCAT_IMPL(a, b) a##b
#define CONCAT(a, b) CONCAT_IMPL(a, b)

#define WARNING_LOCATION(Line) __FILE__ "(" STRINGIFY(Line) ")"
#define EMIT_CUSTOM_WARNING_AT_LINE(Line, Warning) \
    __pragma(message(WARNING_LOCATION(Line) " : " Warning))

#define DECLARE_PROPERTY(type, name) \
    private: \
        type m_##name; \
    public: \
        type get##name() const { return m_##name; } \
        void set##name(type value) { m_##name = value; }

// EMIT_CUSTOM_WARNING_AT_LINE(__LINE__, "Function is deprecated. Use newFunction instead.");
void deprecatedFunction() {}

class Monster {
    DECLARE_PROPERTY(char*, Name)
    DECLARE_PROPERTY(double, Health)
};

int main() {
    // std::cout << "Hello, World!" << std::endl;


    __LINE__;
    #pragma region Monster
        #pragma message("Creating a monster...");
        Monster monster1;
        monster1.setHealth(100.0);
    #pragma endregion Monster
    int x = 5;
    return 0;

    #line 777 __FILE__
    __LINE__;
}
