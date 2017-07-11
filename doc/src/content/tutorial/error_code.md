+++
title = "Custom error code"
weight = 30
+++

TODO: This section will describe how you can plug your custom error enum, like:

```c++
enum class ConversionErrc
{
  EmptyString = 1;
  IllegalChar = 2;
  TooLong     = 3;
};
```

into the Standard Library's `std::error_code` system by specializing type trait
`std::is_error_code_enum` and defining an ADL-enabled function `make_error_code`.

For now, refer to this series of articles by Chris Kohlhoff:
- [System error support in C++0x - part 1](http://blog.think-async.com/2010/04/system-error-support-in-c0x-part-1.html)
- [System error support in C++0x - part 2](http://blog.think-async.com/2010/04/system-error-support-in-c0x-part-2.html)
- [System error support in C++0x - part 3](http://blog.think-async.com/2010/04/system-error-support-in-c0x-part-3.html)
- [System error support in C++0x - part 4](http://blog.think-async.com/2010/04/system-error-support-in-c0x-part-4.html)
- [System error support in C++0x - part 5](http://blog.think-async.com/2010/04/system-error-support-in-c0x-part-5.html)