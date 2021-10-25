#include <vector>
#include <functional>
#include <map>
 
namespace numbers
{
    complex eval(const std::vector<std::string> &args, const complex &z)
    {
        std::map<char, std::function<complex_stack(complex_stack, complex, std::string)> > mp;
        mp.emplace('(', [](complex_stack a, complex z, std::string b){ return a << complex(b); });
        mp.emplace('z', [](complex_stack a, complex z, std::string b){ return a << z; });
        mp.emplace('+', [](complex_stack a, complex z, std::string b){ return (~(~a)) << ((+(~a)) + (+a)); });
        mp.emplace('-', [](complex_stack a, complex z, std::string b){ return (~(~a)) << ((+(~a)) - (+a)); });
        mp.emplace('*', [](complex_stack a, complex z, std::string b){ return (~(~a)) << ((+(~a)) * (+a)); });
        mp.emplace('/', [](complex_stack a, complex z, std::string b){ return (~(~a)) << ((+(~a)) / (+a)); });
        mp.emplace('!', [](complex_stack a, complex z, std::string b){ return a << (+a); });
        mp.emplace(';', [](complex_stack a, complex z, std::string b){ return ~a; });
        mp.emplace('~', [](complex_stack a, complex z, std::string b){ return (~a) << (~(+a)); });
        mp.emplace('#', [](complex_stack a, complex z, std::string b){ return (~a) << (-(+a)); });
        complex_stack a;
        for (size_t i = 0; i < args.size(); ++i) {
            a = mp[args[i][0]](a, z, args[i]);
        }
        return +a;
    };
}
