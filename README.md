Building
========

```shell
mkdir .cmake && cd .cmake
cmake .. -DCMAKE_BUILD_TYPE=releaselto -G Ninja
ninja
```

And you will get:
```
[1/1] Linking CXX executable build/bin/options
FAILED: build/bin/options
: && /usr/sbin/c++  -g3 -O3 -DNDEBUG -fuse-ld=gold -flto -Wall -Werror -Wunknown-pragmas -Wextra -Wwrite-strings -rdynamic -std=c++1z  -Wl,--as-needed -Wl,--allow-shlib-undefined  -rdynamic CMakeFiles/options.dir/src/lines.cpp.o CMakeFiles/options.dir/src/options.cpp.o  -o build/bin/options  -Wl,-Bstatic -lboost_program_options -Wl,-Bdynamic && :
/usr/lib/gcc/x86_64-pc-linux-gnu/7.1.1/../../../../lib/libboost_program_options.a(value_semantic.o):function _GLOBAL__sub_I_value_semantic.cpp: error: undefined reference to 'std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::~basic_string()'
/usr/sbin/ld.gold: the symbol should have been defined by a plugin
collect2: error: ld returned 1 exit status
ninja: build stopped: subcommand failed.
```

This error is gone if:
----------------------
- use shared boost libraries
- move `lines.cpp` into `options.cpp` (i.e. leave only one CU)
