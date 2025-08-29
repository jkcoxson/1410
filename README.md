# ECE 1410 work

USU recommends students use a cloud service to transfer their work to
and from lab computers.
I've never heard of a stupider way to avoid teaching students proper
software development habits.
Pound sand, everything is going in a repository.

## Reference

### WARNINGS

Add to Makefile templates

```
-pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-declarations -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused
```

I like [warnings](https://stackoverflow.com/questions/5088460/flags-to-enable-thorough-and-verbose-g-warnings).

### OPTIONALS

Copy and paste these headers right into the source code since we can't add headers.
I wrote them myself, it's not plagiarism, chill.
[option.hpp](https://github.com/jkcoxson/idevice/blob/master/cpp/include/idevice%2B%2B/option.hpp)
[result.hpp](https://github.com/jkcoxson/idevice/blob/master/cpp/include/idevice%2B%2B/result.hpp)

If we can't have modern C++ features, you'll get Jackson's custom
Rust features slapped into C++. Take your pick.
