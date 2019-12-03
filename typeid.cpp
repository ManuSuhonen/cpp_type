#include <typeinfo>
#include <cxxabi.h>
#include <string>
#include <memory>

using namespace std;

namespace type
{
    template<typename T>
    string get_type(T&& t)
    {
        std::size_t len = 0 ;
        int status = 0 ;
        std::unique_ptr< char, decltype(&std::free) > ptr(__cxxabiv1::__cxa_demangle( typeid(T).name(), nullptr, &len, &status ), &std::free ) ;
        return ptr.get() ;
    }
}
